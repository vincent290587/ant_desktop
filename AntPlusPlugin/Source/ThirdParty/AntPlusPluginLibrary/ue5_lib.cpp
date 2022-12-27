//
// Created by vince on 26/12/2022.
//

#include "ue5_lib.h"

#include <cassert>
#include <fstream>
#include "dsi_serial_generic.hpp"
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

static ANTrxService *pANTsrv = nullptr; // TODO new ANTrxService();

int getIntPlusPlus(int lastInt)
{
#if defined _WIN32 || defined _WIN64
    MessageBox(NULL, TEXT("Hi there"), TEXT("Third Party Plugin"), MB_OK);
#else
    printf("Loaded ExampleLibrary from Third Party Plugin sample");
#endif
    return int(++lastInt);
}

