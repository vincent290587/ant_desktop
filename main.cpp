
#include <cassert>
#include "dsi_serial_generic.hpp"
#include "ant_receive_ch.h"

static void _pw1_callback(UCHAR *p_aucData) {

	UCHAR ucPageNum = p_aucData[0];

	printf("Page: %d received\n", ucPageNum);

	// Page specific data
	switch(ucPageNum) // Removing the toggle bit
	{
		case 0:

			break;

		default:

			break;

	}
}

static void _pw2_callback(UCHAR *p_aucData) {

	UCHAR ucPageNum = p_aucData[0];

	printf("Page: %d received\n", ucPageNum);

	// Page specific data
	switch(ucPageNum) // Removing the toggle bit
	{
		case 0:

			break;

		default:

			break;

	}
}

#define PW_PERIOD_COUNTS 8182u
#define PW_DEVICE_TYPE   0x0Bu

static void Start();

BOOL bMyDone = FALSE;
DSISerialGeneric* pclSerialObject = nullptr;
DSIFramerANT* pclMessageObject = nullptr;

int main(int argc, char *argv[]) {

	BOOL bStatus;

	{
		// Create Serial object.
		pclSerialObject = new DSISerialGeneric();
		assert(pclSerialObject);

		// Create Framer object.
		pclMessageObject = new DSIFramerANT(pclSerialObject);
		assert(pclMessageObject);

		// Initialize Serial object.
		// The device number depends on how many USB sticks have been
		// plugged into the PC. The first USB stick plugged will be 0
		// the next 1 and so on.
		//
		// The Baud Rate depends on the ANT solution being used. AP1
		// is 50000, all others are 57600
		bStatus = pclSerialObject->Init(USER_BAUDRATE, 0);
		assert(bStatus);

		// Initialize Framer object.
		bStatus = pclMessageObject->Init();
		assert(bStatus);

		// Let Serial know about Framer.
		pclSerialObject->SetCallback(pclMessageObject);

		// Open Serial.
		bStatus = pclSerialObject->Open();

		// If the Open function failed, most likely the device
		// we are trying to access does not exist, or it is connected
		// to another program
		if(!bStatus)
		{
			printf("Failed to connect to device at USB port %d\n", 0);
			return -3;
		}
	}

	ANTrxService *pPWR1srv = new ANTrxService(
			pclSerialObject,
			pclMessageObject,
			_pw1_callback);
	assert(pPWR1srv);

	sANTrxServiceInit sInit1 = {
			.ucAntChannel = 0,
			.ucTransType = 0,
			.ucDeviceType = PW_DEVICE_TYPE,
			.usDeviceNum = 15568u,
			.usMessagePeriod = PW_PERIOD_COUNTS,
	};

	ANTrxService *pPWR2srv = new ANTrxService(
			pclSerialObject,
			pclMessageObject,
			_pw2_callback);
	assert(pPWR2srv);

	sANTrxServiceInit sInit2 = {
			.ucAntChannel = 1,
			.ucTransType = 0,
			.ucDeviceType = PW_DEVICE_TYPE,
			.usDeviceNum = 0xEFAC,
			.usMessagePeriod = PW_PERIOD_COUNTS,
	};

	int ret = 0;

	//Start();
	if(ret == 0 && pPWR1srv->Init(sInit1) /* && pPWR2srv->Init(sInit2) */) {
		Start();
	} else {
		delete pPWR1srv;
		delete pPWR2srv;
		delete pclSerialObject;
		delete pclMessageObject;
		ret--;
	}

	return ret;
}

////////////////////////////////////////////////////////////////////////////////
// PrintMenu
//
// Start the Test program.
//
////////////////////////////////////////////////////////////////////////////////
static void PrintMenu()
{

	// Printout options
	printf("\n");
	printf("U - Request USB Descriptor\n");
	printf("Q - Quit\n");
	printf("\n");
	fflush(stdout);
}


static void Start()
{
	BOOL bStatus = TRUE;

	printf("Resetting module...\n");
	bStatus = pclMessageObject->ResetSystem();
	DSIThread_Sleep(1000);

	// Request capabilites.
	ANT_MESSAGE_ITEM stResponse;
	pclMessageObject->SendRequest(MESG_CAPABILITIES_ID, 0, &stResponse, 0);


	// Start the test by setting network key
	printf("Setting network key...\n");
	UCHAR ucNetKey[8] = USER_NETWORK_KEY;

	bStatus &= pclMessageObject->SetNetworkKey(0, ucNetKey, MESSAGE_TIMEOUT);

	// If the Open function failed, most likely the device
	// we are trying to access does not exist, or it is connected
	// to another program
	if(!bStatus)
	{
		printf("ANT initialisation failed!\n"); fflush(stdout);
		return;
	}

	if(bStatus) {
		printf("ANT initialisation was successful!\n"); fflush(stdout);
		PrintMenu();

		while(!bMyDone)
		{
			UCHAR ucChar;
			char st[1024];
			fgets(st, sizeof(st), stdin);
			sscanf(st, "%c", &ucChar);

			switch(ucChar)
			{
				case 'Q':
				case 'q':
				{
					// Quit
					printf("Closing channels...\n");
					pclMessageObject->CloseChannel(0, MESSAGE_TIMEOUT);
					pclMessageObject->CloseChannel(1, MESSAGE_TIMEOUT);
					bMyDone = TRUE;
					break;
				}

				case 'u':
				case 'U':
				{
					// Print out information about the device we are connected to
					printf("USB Device Description\n");
					USHORT usDevicePID;
					USHORT usDeviceVID;
					UCHAR aucDeviceDescription[USB_MAX_STRLEN];
					UCHAR aucDeviceSerial[USB_MAX_STRLEN];
					// Retrieve info
					if(pclMessageObject->GetDeviceUSBVID(usDeviceVID))
					{
						printf("  VID: 0x%X\n", usDeviceVID);
					}
					if(pclMessageObject->GetDeviceUSBPID(usDevicePID))
					{
						printf("  PID: 0x%X\n", usDevicePID);
					}
					if(pclMessageObject->GetDeviceUSBInfo(pclSerialObject->GetDeviceNumber(), aucDeviceDescription, aucDeviceSerial, USB_MAX_STRLEN))
					{
						printf("  Product Description: %s\n", aucDeviceDescription);
						printf("  Serial String: %s\n", aucDeviceSerial);
					}
					break;
				}

				default:
				{
					break;
				}
			}
			DSIThread_Sleep(0);
		}
	}

	//Disconnecting from module
	printf("Disconnecting module...\n");

	pclSerialObject->Close();

	printf("Closing the Receiver!\n");

	return;
}
