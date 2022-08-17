
#include <cassert>
#include <fstream>
#include "dsi_serial_generic.hpp"
#include "ant_receive_ch.h"

USHORT power1, power2;

static void _pw1_callback(UCHAR *p_aucData) {

	UCHAR ucPageNum = p_aucData[0];

	//printf("Dev 0 Page: %d received\n", ucPageNum);

	// Page specific data
	switch(ucPageNum) // Removing the toggle bit
	{
		case 16:
		{
			power1 = p_aucData[6] + p_aucData[7]*0xFF;
			printf("Dev 0 Page: power %u received\n", power1);
		}
			break;

		default:

			break;

	}
}

static void _pw2_callback(UCHAR *p_aucData) {

	UCHAR ucPageNum = p_aucData[0];

	//printf("Dev 1 Page: %d received\n", ucPageNum);

	// Page specific data
	switch(ucPageNum) // Removing the toggle bit
	{
		case 16:
		{
			power2 = p_aucData[6] + p_aucData[7]*0xFF;
			printf("Dev 1 Page: power %u received\n", power2);
		}
			break;

		default:

			break;

	}
}

#define PW_PERIOD_COUNTS 8182u
#define PW_DEVICE_TYPE   0x0Bu

static void Loop();

BOOL bMyDone = FALSE;


DSI_THREAD_RETURN _io_task(void *pvParameter_)
{
	std::ofstream fParameters;

	fParameters.open("com.txt");

	fParameters << "power1 - power2" << std::endl;

	while (!bMyDone) {
		DSIThread_Sleep(500);

		fParameters << power1;
		fParameters << " - ";
		fParameters << power2 << std::endl;

		fParameters.flush();

	}

	fParameters.close();
	return NULL;
}

int main(int argc, char *argv[]) {

	ANTrxService *pANTsrv = new ANTrxService();
	assert(pANTsrv);

	sANTrxServiceInit sInit1 = {
			.ucAntChannel = 0,
			.ucTransType = 0,
			.ucDeviceType = PW_DEVICE_TYPE,
			.usDeviceNum = 15568u,
			.usMessagePeriod = PW_PERIOD_COUNTS,
	};

	sANTrxServiceInit sInit2 = {
			.ucAntChannel = 1,
			.ucTransType = 0,
			.ucDeviceType = PW_DEVICE_TYPE,
			.usDeviceNum = 0xEFAC,
			.usMessagePeriod = PW_PERIOD_COUNTS,
	};

	int ret = 0;

	pANTsrv->AddSlave(sInit1, _pw1_callback);
	pANTsrv->AddSlave(sInit2, _pw2_callback);

	// Create message thread.
	DSI_THREAD_ID uiDSIThread = DSIThread_CreateThread(_io_task, NULL);
	assert(uiDSIThread);

	if(ret == 0 && pANTsrv->Init() ) {

		pANTsrv->Start();

		Loop();

	} else {
		delete pANTsrv;
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


static void Loop()
{
	BOOL bStatus = TRUE;

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
//					// Retrieve info
//					if(pclMessageObject->GetDeviceUSBVID(usDeviceVID))
//					{
//						printf("  VID: 0x%X\n", usDeviceVID);
//					}
//					if(pclMessageObject->GetDeviceUSBPID(usDevicePID))
//					{
//						printf("  PID: 0x%X\n", usDevicePID);
//					}
//					if(pclMessageObject->GetDeviceUSBInfo(pclSerialObject->GetDeviceNumber(), aucDeviceDescription, aucDeviceSerial, USB_MAX_STRLEN))
//					{
//						printf("  Product Description: %s\n", aucDeviceDescription);
//						printf("  Serial String: %s\n", aucDeviceSerial);
//					}
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

	return;
}
