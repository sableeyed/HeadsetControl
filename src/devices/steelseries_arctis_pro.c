#include "../device.h"
#include "../utility.h"

#include <hidapi.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>
#include <stdio.h>

static struct device device_arctis;

#define ID_ARCTIS_PRO 0x1252

static const uint16_t PRODUCT_IDS[] = { ID_ARCTIS_PRO };

void arctis_pro_init(struct device **device) {
    device_arctis.idVendor = VENDOR_STEELSERIES;
    device_arctis.idProductsSupported = PRODUCT_IDS;
    device_arctis.numIdProducts = sizeof(PRODUCT_IDS) / sizeof(PRODUCT_IDS[0]);

    strncpy(device_arctis.device_name, "Steelseries Arctis Pro", sizeof(device_arctis.device_name));

    device_arctis.capabilities = B(CAP_SIDETONE);
    device_arctis.send_sidetone = &arctis_pro_send_sidetone;

    *device = &device_arctis;
}