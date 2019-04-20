#include "head.h"

static char TAG[] = "socket_server";
static int sock;
static struct sockaddr_in source_addr;

 void socket_server(void *pvParameters)
{
    char rx_buffer[128];
    char addr_str[128];
    int addr_family;
    int ip_protocol;

    while (1) {
        // Filling server information
        struct sockaddr_in dest_addr;
        dest_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = htons(PORT_NUMBER);
        addr_family = AF_INET;
        ip_protocol = IPPROTO_IP;
        inet_ntoa_r(dest_addr.sin_addr, addr_str, sizeof(addr_str) - 1);

         sock = socket(addr_family, SOCK_DGRAM, ip_protocol);
        if (sock < 0) {
            ESP_LOGE(TAG, "Unable to create socket: errno %d", errno);
            break;
        }
        ESP_LOGI(TAG, "Socket created");

        int err = bind(sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
        if (err < 0) {
            ESP_LOGE(TAG, "Socket unable to bind: errno %d", errno);
        }
        ESP_LOGI(TAG, "Socket bound, port %d", PORT_NUMBER);

        while (1) {

                      socklen_t socklen = sizeof(source_addr);
           /* get Socet_Client via recvfrom in source_addr*/
            int len = recvfrom(sock, rx_buffer, sizeof(rx_buffer) - 1, 0,(struct sockaddr *)&source_addr, &socklen);

            if(rx_buffer[0]=='s'  &&  rx_buffer[1]=='t' )
            {
				rx_buffer[len] = 0; // Null-terminate whatever we received and treat like a string...

            	ESP_LOGI(TAG, "start 1");
            	for(int j=0 ;j<1000;j++){
					for(int i=32;i<34;i++){
						rx_buffer[0]=i;
						rx_buffer[len] = 0; // Null-terminate whatever we received and treat like a string...
						int err = sendto(sock, rx_buffer, len, 0, (struct sockaddr *)&source_addr, sizeof(source_addr));
						vTaskDelay(10/ portTICK_PERIOD_MS);
						if (err < 0) {
							ESP_LOGE(TAG, "Error occurred during sending: errno %d", errno);
							break;
						}
					}
            	}
            	ESP_LOGI(TAG, "end 1");

            }
            else{
				// Error occurred during receiving
				if (len < 0) {
					ESP_LOGE(TAG, "recv failed: errno %d", errno);
					break;
				}
				// Data received
				else {

					rx_buffer[len] = 0; // Null-terminate whatever we received and treat like a string...
					ESP_LOGI(TAG, "Received %d bytes from %s:", len, addr_str);
					ESP_LOGI(TAG, "%s", rx_buffer);
					for(int i=0;i<2;i++){
						int err = sendto(sock, rx_buffer, len, 0, (struct sockaddr *)&source_addr, sizeof(source_addr));
					//	vTaskDelay(10 / portTICK_PERIOD_MS);
						if (err < 0) {
							ESP_LOGE(TAG, "Error occurred during sending: errno %d", errno);
							break;
						}
					}
				}
            }
        }

        if (sock != -1) {
            ESP_LOGE(TAG, "Shutting down socket and restarting...");
            shutdown(sock, 0);
            close(sock);
        }
    }
    vTaskDelete(NULL);
}

