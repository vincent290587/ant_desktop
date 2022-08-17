
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

int main(int argc, char *argv[]) {

	// Create Serial object.
	DSISerialGeneric* pclSerialObject = new DSISerialGeneric();
	assert(pclSerialObject);

	ANTrxService *pPWR1srv = new ANTrxService(pclSerialObject, _pw1_callback);
	assert(pPWR1srv);

	sANTrxServiceInit sInit1 = {
			.ucAntChannel = 0,
			.ucTransType = 5,
			.ucDeviceType = 120, // HRM
			.usDeviceNum = 1234, // TODO
			.usMessagePeriod = 8192, // TODO
	};

	ANTrxService *pPWR2srv = new ANTrxService(pclSerialObject, _pw2_callback);
	assert(pPWR2srv);

	sANTrxServiceInit sInit2 = {
			.ucAntChannel = 0,
			.ucTransType = 5,
			.ucDeviceType = 120, // HRM
			.usDeviceNum = 1234, // TODO
			.usMessagePeriod = 8192, // TODO
	};

	int ret = 0;

	if(ret == 0 && pPWR1srv->Init(sInit1))
		pPWR1srv->Start();
	else {
		delete pPWR1srv;
		delete pPWR2srv;
		delete pclSerialObject;
		ret--;
	}

	if(ret == 0 && pPWR2srv->Init(sInit2))
		pPWR2srv->Start();
	else {
		ret--;
	}

	return ret;
}
