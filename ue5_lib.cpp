//
// Created by vince on 26/12/2022.
//

#include "ue5_lib.h"

#include <cassert>
#include <fstream>
//#include "dsi_serial_generic.hpp"
#include "ant_receive_ch.h"

//Exported method that iterates a given int value.
#if defined _WIN32 || defined _WIN64
#include <windows.h>

#define EXAMPLELIBRARY_EXPORT __declspec(dllexport)
#else
#include <stdio.h>
#endif

#ifndef EXAMPLELIBRARY_EXPORT
#define EXAMPLELIBRARY_EXPORT
#endif

#define VERIFY(COND, RET)    if (!(COND)) { return (RET); }

static ANTrxService *pANTsrv = nullptr;
static UCHAR m_current_channel = 0;

int ue5_lib__startupAntPlusLib(void) {
    pANTsrv = new ANTrxService();
    VERIFY(pANTsrv, -1);

    m_current_channel = 0u;

    return 0;
}

int ue5_lib__endAntPlusLib(void) {
    return 0;
}

int ue5_lib__addDeviceID(unsigned short usDeviceNum,
                unsigned char ucDeviceType,
                unsigned short usMessagePeriod,
                std::function<void(UCHAR *p_aucData)> callback) {

    VERIFY(pANTsrv, -1);

    sANTrxServiceInit sInit1;
    sInit1.ucAntChannel = m_current_channel;
    sInit1.ucTransType = 0;
    sInit1.ucDeviceType = ucDeviceType;
    sInit1.usDeviceNum = usDeviceNum;
    sInit1.usMessagePeriod = usMessagePeriod;

    pANTsrv->AddSlave(sInit1, callback);

    return m_current_channel++;
}

int ue5_lib__sendBytes(unsigned char ucChannel, unsigned char *p_aucData) {

    VERIFY(pANTsrv, -1);

    pANTsrv->TransmitMessage(ucChannel, p_aucData); // only channel 0 supported so far

    return 0;
}

int ue5_lib__startANT(void) {

    VERIFY(pANTsrv, -1);

    if( pANTsrv->Init() ) {

        pANTsrv->Start();

        //Loop(pANTsrv);

        return 0;

    } else {

        delete pANTsrv;
        pANTsrv = nullptr;

        return -2;
    }

    return 0;
}

