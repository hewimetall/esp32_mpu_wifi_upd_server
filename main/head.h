/*
 * head.h
 *
 *      Author: s
 */

#ifndef MAIN_HEAD_H_
#define MAIN_HEAD_H_
#include <esp_event.h>
#include <esp_event_loop.h>
#include <esp_log.h>
#include <esp_system.h>
#include <esp_wifi.h>
#include <freertos/FreeRTOS.h>
#include "freertos/task.h"
#include <nvs_flash.h>
#include <stdio.h>
#include <lwip/sockets.h>
#include <string.h>
#include <errno.h>

//////////////////////////////////////////////////////////////////////////////////////
///
#define IF_ERR(X,MASS,ERR_MASS) if(X==ESP_OK) ESP_LOGE(TAG, #MASS);\
	 else  ESP_LOGE(TAG, #ERR_MASS)

//////////////////////////////////////////////////////////////////////////////////////
/* WIFI  Block*/
#define SSID  "ESP32_TESTAP"
#define PASS ""
#define TIP_WIFI_AUTH_OPEN WIFI_AUTH_OPEN
//  USED FOR IP STATIC
// The IP address that we want our device to have.
#define DEVICE_IP          "10.0.0.1"

// The Gateway address where we wish to send packets.
// This will commonly be our access point.
#define DEVICE_GW          "10.1.0.3"

// The netmask specification.
#define DEVICE_NETMASK     "255.0.0.0"
/* END WIFI  Block*/
//////////////////////////////////////////////////////////////////////////////////////
///
#endif /* MAIN_HEAD_H_ */
