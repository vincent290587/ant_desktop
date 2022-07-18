/*
This software is subject to the license described in the License.txt file
included with this software distribution. You may not use this file except
in compliance with this license.

Copyright (c) Dynastream Innovations Inc. 2016
All rights reserved.
*/

/*
 * VCS Information - autogenerated - do not modify
 *
 *
 **************************************************************************
 *
 *
 **************************************************************************
 */
#include "types.h"

//#include "antdefines.h"
//#include "antmessage.h"
#include "ant_dll.h"


//////////////////////////////////////////////////////////////////////////////////
// Public Variables
//////////////////////////////////////////////////////////////////////////////////

// Function Pointers
P_ANT_INIT           ANT_Init;
P_ANT_CLOSE          ANT_Close;
P_ANT_ARF            ANT_AssignResponseFunction;
P_ANT_AEF            ANT_AssignChannelEventFunction;
P_ANT_UNASSIGN       ANT_UnAssignChannel;
P_ANT_ASSIGN         ANT_AssignChannel;
P_ANT_SETID          ANT_SetChannelId;
P_ANT_SETPER         ANT_SetChannelPeriod;
P_ANT_SETTIME        ANT_SetChannelSearchTimeout;
P_ANT_SETFREQ        ANT_SetChannelRFFreq;
P_ANT_SETKEY         ANT_SetNetworkKey;
P_ANT_SETPWR         ANT_SetTransmitPower;
P_ANT_RST            ANT_ResetSystem;
P_ANT_OPENCHNL       ANT_OpenChannel;
P_ANT_CLOSECHNL      ANT_CloseChannel;
P_ANT_REQMSG         ANT_RequestMessage;
P_ANT_ENABLEEXT      ANT_RxExtMesgsEnable;
P_ANT_TX             ANT_SendBroadcastData;
P_ANT_TXA            ANT_SendAcknowledgedData;
P_ANT_TXB            ANT_SendBurstTransfer;
P_ANT_ADDID          ANT_AddChannelID;
P_ANT_CONFIGLIST     ANT_ConfigList;
P_ANT_CHANTXPWR      ANT_SetChannelTxPower;
P_ANT_LOWPRITIME     ANT_SetLowPriorityChannelSearchTimeout;
P_ANT_SERIALID       ANT_SetSerialNumChannelId;
P_ANT_SETLED         ANT_EnableLED;
P_ANT_SETCRYSTAL     ANT_CrystalEnable;
P_ANT_SETAGILITY     ANT_ConfigFrequencyAgility;
P_ANT_SETPROX        ANT_SetProximitySearch;
P_ANT_SETSCAN        ANT_OpenRxScanMode;
P_ANT_SETSLEEP       ANT_SleepMessage;
P_ANT_CWINIT         ANT_InitCWTestMode;
P_ANT_CWMODE         ANT_SetCWTestMode;
P_ANT_TXEXT          ANT_SendExtBroadcastData;
P_ANT_TXAEXT         ANT_SendExtAcknowledgedData;
P_ANT_TXBEXT         ANT_SendExtBurstTransferPacket;
P_ANT_BURSTTFR       ANT_SendExtBurstTransfer;








//////////////////////////////////////////////////////////////////////////////////
// Private Variables
//////////////////////////////////////////////////////////////////////////////////

static HMODULE hANTdll;
static BOOL bLoaded = FALSE;


//////////////////////////////////////////////////////////////////////////////////
// Public Functions
//////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
BOOL ANT_Load(void)
{
   if (bLoaded)
      return TRUE;

   hANTdll = LoadLibraryA("ANT_DLL.dll");
   if (hANTdll == NULL)
      return FALSE;

   ANT_Init = (P_ANT_INIT) GetProcAddress(hANTdll, "ANT_Init");
   ANT_Close = (P_ANT_CLOSE) GetProcAddress(hANTdll, "ANT_Close");
   ANT_AssignResponseFunction = (P_ANT_ARF) GetProcAddress(hANTdll, "ANT_AssignResponseFunction");
   ANT_AssignChannelEventFunction = (P_ANT_AEF) GetProcAddress(hANTdll, "ANT_AssignChannelEventFunction");
   ANT_UnAssignChannel = (P_ANT_UNASSIGN) GetProcAddress(hANTdll, "ANT_UnAssignChannel");
   ANT_AssignChannel = (P_ANT_ASSIGN) GetProcAddress(hANTdll, "ANT_AssignChannel");
   ANT_SetChannelId =(P_ANT_SETID) GetProcAddress(hANTdll, "ANT_SetChannelId");
   ANT_SetChannelPeriod = (P_ANT_SETPER) GetProcAddress(hANTdll, "ANT_SetChannelPeriod");
   ANT_SetChannelSearchTimeout = (P_ANT_SETTIME) GetProcAddress(hANTdll, "ANT_SetChannelSearchTimeout");
   ANT_SetChannelRFFreq = (P_ANT_SETFREQ) GetProcAddress(hANTdll, "ANT_SetChannelRFFreq");
   ANT_SetNetworkKey = (P_ANT_SETKEY) GetProcAddress(hANTdll, "ANT_SetNetworkKey");
   ANT_SetTransmitPower = (P_ANT_SETPWR) GetProcAddress(hANTdll, "ANT_SetTransmitPower");
   ANT_ResetSystem = (P_ANT_RST) GetProcAddress(hANTdll, "ANT_ResetSystem");
   ANT_OpenChannel = (P_ANT_OPENCHNL) GetProcAddress(hANTdll, "ANT_OpenChannel");
   ANT_CloseChannel = (P_ANT_CLOSECHNL) GetProcAddress(hANTdll, "ANT_CloseChannel");
   ANT_RequestMessage = (P_ANT_REQMSG) GetProcAddress(hANTdll, "ANT_RequestMessage");
   ANT_RxExtMesgsEnable = (P_ANT_ENABLEEXT) GetProcAddress(hANTdll, "ANT_RxExtMesgsEnable");
   ANT_SendBroadcastData = (P_ANT_TX) GetProcAddress(hANTdll, "ANT_SendBroadcastData");
   ANT_SendAcknowledgedData = (P_ANT_TXA) GetProcAddress(hANTdll, "ANT_SendAcknowledgedData");
   ANT_SendBurstTransfer = (P_ANT_TXB) GetProcAddress(hANTdll, "ANT_SendBurstTransfer");
   ANT_AddChannelID = (P_ANT_ADDID) GetProcAddress(hANTdll, "ANT_AddChannelID");
   ANT_ConfigList = (P_ANT_CONFIGLIST) GetProcAddress(hANTdll, "ANT_ConfigList");
   ANT_SetChannelTxPower = (P_ANT_CHANTXPWR) GetProcAddress(hANTdll, "ANT_SetChannelTxPower");
   ANT_SetLowPriorityChannelSearchTimeout = (P_ANT_LOWPRITIME) GetProcAddress(hANTdll, "ANT_SetLowPriorityChannelSearchTimeout");
   ANT_SetSerialNumChannelId = (P_ANT_SERIALID) GetProcAddress(hANTdll, "ANT_SetSerialNumChannelId");
   ANT_EnableLED = (P_ANT_SETLED) GetProcAddress(hANTdll, "ANT_EnableLED");
   ANT_CrystalEnable = (P_ANT_SETCRYSTAL) GetProcAddress(hANTdll, "ANT_CrystalEnable");
   ANT_ConfigFrequencyAgility = (P_ANT_SETAGILITY) GetProcAddress(hANTdll, "ANT_ConfigFrequencyAgility");
   ANT_SetProximitySearch = (P_ANT_SETPROX) GetProcAddress(hANTdll, "ANT_SetProximitySearch");
   ANT_OpenRxScanMode = (P_ANT_SETSCAN) GetProcAddress(hANTdll, "ANT_OpenRxScanMode");
   ANT_SleepMessage = (P_ANT_SETSLEEP) GetProcAddress(hANTdll, "ANT_SleepMessage");
   ANT_InitCWTestMode = (P_ANT_CWINIT) GetProcAddress(hANTdll, "ANT_InitCWTestMode");
   ANT_SetCWTestMode = (P_ANT_CWMODE) GetProcAddress(hANTdll, "ANT_SetCWTestMode");
   ANT_SendExtBroadcastData = (P_ANT_TXEXT) GetProcAddress(hANTdll, "ANT_SendExtBroadcastData");
   ANT_SendExtAcknowledgedData = (P_ANT_TXAEXT) GetProcAddress(hANTdll, "ANT_SendExtAcknowledgedData");
   ANT_SendExtBurstTransferPacket = (P_ANT_TXBEXT) GetProcAddress(hANTdll, "ANT_SendExtBurstTransferPacket");
   ANT_SendExtBurstTransfer = (P_ANT_BURSTTFR) GetProcAddress(hANTdll, "ANT_SendExtBurstTransfer");

   if (ANT_Init == NULL)
      return FALSE;
   if (ANT_Close == NULL)
      return FALSE;
   if (ANT_AssignResponseFunction == NULL)
      return FALSE;
   if (ANT_AssignChannelEventFunction == NULL)
      return FALSE;
   if (ANT_UnAssignChannel == NULL)
      return FALSE;
   if (ANT_AssignChannel == NULL)
      return FALSE;
   if (ANT_SetChannelId == NULL)
      return FALSE;
   if (ANT_SetChannelPeriod == NULL)
      return FALSE;
   if (ANT_SetChannelSearchTimeout == NULL)
      return FALSE;
   if (ANT_SetChannelRFFreq == NULL)
      return FALSE;
   if (ANT_SetNetworkKey == NULL)
      return FALSE;
   if (ANT_SetTransmitPower == NULL)
      return FALSE;
   if (ANT_ResetSystem == NULL)
      return FALSE;
   if (ANT_OpenChannel == NULL)
      return FALSE;
   if (ANT_CloseChannel == NULL)
      return FALSE;
   if (ANT_RequestMessage == NULL)
      return FALSE;
   if (ANT_SendBroadcastData == NULL)
      return FALSE;
   if (ANT_SendAcknowledgedData == NULL)
      return FALSE;
   if (ANT_SendBurstTransfer == NULL)
      return FALSE;
   if(ANT_RxExtMesgsEnable == NULL)
      return FALSE;
   if(ANT_AddChannelID == NULL)
      return FALSE;
   if(ANT_ConfigList == NULL)
      return FALSE;
   if(ANT_SetChannelTxPower == NULL)
      return FALSE;
   if(ANT_SetLowPriorityChannelSearchTimeout == NULL)
      return FALSE;
   if(ANT_SetSerialNumChannelId == NULL)
      return FALSE;
   if(ANT_EnableLED == NULL)
      return FALSE;
   if(ANT_CrystalEnable == NULL)
      return FALSE;
   if(ANT_ConfigFrequencyAgility == NULL)
      return FALSE;
   if(ANT_SetProximitySearch == NULL)
      return FALSE;
   if(ANT_OpenRxScanMode == NULL)
      return FALSE;
   if(ANT_SleepMessage == NULL)
      return FALSE;
   if(ANT_InitCWTestMode == NULL)
      return FALSE;
   if(ANT_SetCWTestMode == NULL)
      return FALSE;
   if(ANT_SendExtBroadcastData == NULL)
      return FALSE;
   if(ANT_SendExtAcknowledgedData == NULL)
      return FALSE;
   if(ANT_SendExtBurstTransferPacket == NULL)
      return FALSE;
   if(ANT_SendExtBurstTransfer == NULL)
      return FALSE;


   bLoaded = TRUE;
   return TRUE;
}

///////////////////////////////////////////////////////////////////////
void ANT_UnLoad(void)
{
   if (hANTdll != NULL)
   {
      FreeLibrary(hANTdll);
   }
   bLoaded = FALSE;
}
