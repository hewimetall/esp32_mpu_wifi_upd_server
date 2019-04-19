#include "head.h"
extern void access_point_task(void *ignore);

void app_main()
{

    printf("Hello world!\n");

	nvs_flash_init();
	tcpip_adapter_init();
    xTaskCreate(access_point_task, "udp_server", 4096, NULL, 5, NULL);

}
