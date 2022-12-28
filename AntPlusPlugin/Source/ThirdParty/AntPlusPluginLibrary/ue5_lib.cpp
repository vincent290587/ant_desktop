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

static void _pw1_callback(UCHAR *);
static void Loop(ANTrxService *const);

static ANTrxService *pANTsrv = nullptr;

static volatile USHORT power1;
static volatile BOOL bMyDone = FALSE;

int startupAntPlusLib(void) {
    pANTsrv = new ANTrxService();
    VERIFY(pANTsrv, -1);

#if defined _WIN32 || defined _WIN64
    MessageBox(NULL, TEXT("Started!"), TEXT("AntPlus Plugin"), MB_OK);
#else
    printf("Loaded ExampleLibrary from Third Party Plugin sample");
#endif

    return 0;
}

int endAntPlusLib(void) {
    bMyDone = TRUE;

//    if (pANTsrv != nullptr) {
//
//        pANTsrv->Close();
//        delete pANTsrv;
//        pANTsrv = nullptr;
//    }

    return 0;
}

#define PW_PERIOD_COUNTS 8182u
#define PW_DEVICE_TYPE   0x0Bu

int addDeviceID(unsigned short devID) {

    VERIFY(pANTsrv, -1);

    sANTrxServiceInit sInit1;
    sInit1.ucAntChannel = 0;
    sInit1.ucTransType = 0;
    sInit1.ucDeviceType = PW_DEVICE_TYPE;
    sInit1.usDeviceNum = devID;
    sInit1.usMessagePeriod = PW_PERIOD_COUNTS;

    pANTsrv->AddSlave(sInit1, _pw1_callback);

    if( pANTsrv->Init() ) {

        pANTsrv->Start();

        //Loop(pANTsrv);

        return 0;

    } else {

        delete pANTsrv;
        pANTsrv = nullptr;

        return -2;
    }
}

int getIntPlusPlus(int lastInt)
{
#if defined _WIN32 || defined _WIN64
    MessageBox(NULL, TEXT("Hi there"), TEXT("Third Party Plugin"), MB_OK);
#else
    printf("Loaded ExampleLibrary from Third Party Plugin sample");
#endif
    return int(++lastInt);
}

unsigned short getPower(void) {
    return power1;
}

/////////////////////////////////////////////////////////////////////////////////

static void _pw1_callback(UCHAR *p_aucData) {

    UCHAR ucPageNum = p_aucData[0];

    //printf("Dev 0 Page: %d received\n", ucPageNum);

    // Page specific data
    switch(ucPageNum) // Removing the toggle bit
    {
        case 16:
        {
            power1 = p_aucData[6] + p_aucData[7]*0xFF;
            //printf("Dev 0 Page: power %u received\n", power1);
        }
            break;

        default:

            break;

    }
}

//static void Loop(ANTrxService *const p_srv)
//{
//
//    while(!bMyDone)
//    {
////        UCHAR ucChar;
////        char st[1024];
////        fgets(st, sizeof(st), stdin);
////        sscanf(st, "%c", &ucChar);
////
////        switch(ucChar)
////        {
////            case 'Q':
////            case 'q':
////            {
////                // Quit
////                printf("Closing channels...\n");
////                bMyDone = TRUE;
////                break;
////            }
////
////            case 'u':
////            case 'U':
////            {
////                // Print out information about the device we are connected to
////                pANTsrv->PrintUsbDescr();
////                break;
////            }
////
////            default:
////            {
////                break;
////            }
////        }
//
//        DSIThread_Sleep(100);
//    }
//
//    pANTsrv->Close();
//
//    delete pANTsrv;
//
//    pANTsrv = nullptr;
//}


