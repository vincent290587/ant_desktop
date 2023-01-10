#include "AntPlusPluginBPLibrary.h"
#include "AntPlusPlugin.h"
#include "AntPlusPluginLibrary/ue5_lib.h"

static unsigned short power1 = 0u;

static void _pw1_callback(unsigned char *p_aucData) {

    unsigned char ucPageNum = p_aucData[0];

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define PW_PERIOD_COUNTS 8182u
#define PW_DEVICE_TYPE   0x0Bu

UAntPlusPluginBPLibrary::UAntPlusPluginBPLibrary(const FObjectInitializer& ObjectInitializer)
        : Super(ObjectInitializer)
{

}

int UAntPlusPluginBPLibrary::connectPowerMeterDeviceID(int devID)
{
    return ue5_lib__addDeviceID(devID,
                                PW_DEVICE_TYPE,
                                PW_PERIOD_COUNTS,
                                _pw1_callback);
}

int UAntPlusPluginBPLibrary::getRawPower(void)
{
    return power1;
}

int UAntPlusPluginBPLibrary::sendBytes(void)
{
    return power1;
}

