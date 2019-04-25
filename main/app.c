#include "head.h"
extern void access_point_task(void *ignore);

extern void socket_server( void * pvParameters );
extern void vTask_test_Queue( void * pvParameters );
static char TAG[] = "App";

void app_main()
{

    printf("Star my program\n");

	nvs_flash_init();
	tcpip_adapter_init();
    // Create a queue capable of containing 10 uint32_t values.
    xQueue1 = xQueueCreate( 5, sizeof( struct data ) );
    wifi_group = xEventGroupCreate();

    /* Configure and run Access Point */
    xTaskCreatePinnedToCore(
    		access_point_task,                  /* pvTaskCode */
       "udp_server",            /* pcName */
	   4096,                   /* usStackDepth */
       NULL,                   /* pvParameters */
       1,                      /* uxPriority */
       &access_point_task,                 /* pxCreatedTask */
       0);                     /* xCoreID */

/* socket_server is responsible for creating and maintaining incoming connections */
    xTaskCreatePinnedToCore(
    		socket_server,                  /* pvTaskCode */
       "socket_server",            /* pcName */
	   4096,                   /* usStackDepth */
       NULL,                   /* pvParameters */
       5,                      /* uxPriority */
       &socket_server,                 /* pxCreatedTask */
       0);                     /* xCoreID */
	 xEventGroupWaitBits(
	            wifi_group,   /* The event group being tested. */
	            BIT_1, /* The bits within the event group to wait for. */
	            pdTRUE,        /* BIT_0 & BIT_4 should be cleared before returning. */
	            pdFALSE,       /* Don't wait for both bits, either bit will do. */
				portMAX_DELAY );/* Wait a maximum of 100ms for either bit to be set. */
	    ESP_LOGI(TAG, "vTask_test_Queue" );

    xTaskCreatePinnedToCore(
    		vTask_test_Queue,                  /* pvTaskCode */
       "vTask_test_Queue",            /* pcName */
       2048,                   /* usStackDepth */
       NULL,                   /* pvParameters */
       1,                      /* uxPriority */
       &vTask_test_Queue,                 /* pxCreatedTask */
       1);                     /* xCoreID */

}
