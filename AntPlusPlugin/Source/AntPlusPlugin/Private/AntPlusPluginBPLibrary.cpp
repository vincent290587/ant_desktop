#include "AntPlusPluginBPLibrary.h"
#include "AntPlusPlugin.h"
#include "AntPlusPluginLibrary/ue5_lib.h"

UAntPlusPluginBPLibrary::UAntPlusPluginBPLibrary(const FObjectInitializer& ObjectInitializer)
        : Super(ObjectInitializer)
{

}

int UAntPlusPluginBPLibrary::connectDeviceID(int devID)
{
    return addDeviceID(devID);
}

int UAntPlusPluginBPLibrary::getRawPower(void)
{
    return getPower();
}

