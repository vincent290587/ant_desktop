//
// Created by vgol on 17/08/2022.
//

#ifndef ANT_TEST_ANT_RECEIVE_CH_H
#define ANT_TEST_ANT_RECEIVE_CH_H

#include "types.h"
#include "ant_receive_defines.h"
#include "dsi_framer_ant.hpp"
//#include "dsi_thread.h"
#include "dsi_serial_generic.hpp"
//#include "dsi_debug.hpp"
#include <stdio.h>
//#include <stdlib.h>
#include <assert.h>
//#include <string.h>

class ANTrxService {
public:
	ANTrxService(DSISerialGeneric* serialObject,
	             DSIFramerANT* pclMessageObject,
				 std::function<void(UCHAR *p_aucData)> callback);
	virtual ~ANTrxService();
	BOOL Init(sANTrxServiceInit sInit);

	void Close();

private:

	// Starts the Message thread.
	static DSI_THREAD_RETURN RunMessageThread(void *pvParameter_);

	// Listens for a response from the module
	void MessageThread();

	// Decodes the received message
	void ProcessMessage(ANT_MESSAGE stMessage, USHORT usSize_);

	// Detect transmitter device type: current or legacy
	void DetectDevice(UCHAR &ucDeviceType_, BOOL &bOldToggleBit_, UCHAR &ucToggleAttempts_, BOOL bToggleBit);

	// Network variables
	UCHAR ucTransType;
	UCHAR ucAntChannel;
	UCHAR ucDeviceType;
	USHORT usDeviceNum;
	USHORT usMessagePeriod;

	BOOL bBursting; // Holds whether the bursting phase of the test has started
	BOOL bBroadcasting;
	BOOL bMyDone;
	BOOL bDone;
	UCHAR ucChannelType;
	DSISerialGeneric* pclSerialObject;
	DSIFramerANT* pclMessageObject;
	DSI_THREAD_ID uiDSIThread;
	DSI_CONDITION_VAR condTestDone;
	DSI_MUTEX mutexTestDone;

	std::function<void(UCHAR *p_aucData)> msg_callback;

	BOOL bDisplay;
	BOOL bProcessedData;
};

#endif //ANT_TEST_ANT_RECEIVE_CH_H
