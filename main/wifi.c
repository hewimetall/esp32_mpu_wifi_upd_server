#include "head.h"
static char TAG[] = "access-point";
extern void socket_server(void *ignore) ;
esp_err_t esp32_wifi_eventHandler(void *ctx, system_event_t *event) {
	// Your event handling code here...
    switch (event->event_id) {
    	case SYSTEM_EVENT_AP_START:
			ESP_LOGE(TAG, "evente SYSTEM_EVENT_AP_START");
		break;
    	    default:
    	        break;
    }
	return ESP_OK;
}

void access_point_task(void *ignore) {
	nvs_flash_init();
	tcpip_adapter_init();

	ESP_ERROR_CHECK( esp_event_loop_init(esp32_wifi_eventHandler, NULL) );

	wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
	ESP_ERROR_CHECK( esp_wifi_init(&cfg) );

	//ESP_ERROR_CHECK( esp_wifi_set_storage(WIFI_STORAGE_RAM) );
	ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_AP) );
	wifi_config_t apConfig = {
	   .ap = {
	      .ssid="ESP32_TESTAP",
	      .ssid_len=0,
	      .password="",
	      .channel=0,
	      .authmode=WIFI_AUTH_OPEN,
	      .ssid_hidden=0,
	      .max_connection=4,
	      .beacon_interval=100
	   }
	};
	ESP_ERROR_CHECK( esp_wifi_set_config(WIFI_IF_AP, &apConfig) );

	ESP_ERROR_CHECK( esp_wifi_start() );
    xTaskCreate( socket_server, "udp_server", 4096, NULL, 5, NULL);
vTaskDelete(NULL);
}
