deps_config := \
	/home/s/eclipse/esp-idf/components/app_trace/Kconfig \
	/home/s/eclipse/esp-idf/components/aws_iot/Kconfig \
	/home/s/eclipse/esp-idf/components/bt/Kconfig \
	/home/s/eclipse/esp-idf/components/driver/Kconfig \
	/home/s/eclipse/esp-idf/components/esp32/Kconfig \
	/home/s/eclipse/esp-idf/components/esp_adc_cal/Kconfig \
	/home/s/eclipse/esp-idf/components/esp_event/Kconfig \
	/home/s/eclipse/esp-idf/components/esp_http_client/Kconfig \
	/home/s/eclipse/esp-idf/components/esp_http_server/Kconfig \
	/home/s/eclipse/esp-idf/components/esp_https_ota/Kconfig \
	/home/s/eclipse/esp-idf/components/ethernet/Kconfig \
	/home/s/eclipse/esp-idf/components/fatfs/Kconfig \
	/home/s/eclipse/esp-idf/components/freemodbus/Kconfig \
	/home/s/eclipse/esp-idf/components/freertos/Kconfig \
	/home/s/eclipse/esp-idf/components/heap/Kconfig \
	/home/s/eclipse/esp-idf/components/libsodium/Kconfig \
	/home/s/eclipse/esp-idf/components/log/Kconfig \
	/home/s/eclipse/esp-idf/components/lwip/Kconfig \
	/home/s/eclipse/esp-idf/components/mbedtls/Kconfig \
	/home/s/eclipse/esp-idf/components/mdns/Kconfig \
	/home/s/eclipse/esp-idf/components/mqtt/Kconfig \
	/home/s/eclipse/esp-idf/components/nvs_flash/Kconfig \
	/home/s/eclipse/esp-idf/components/openssl/Kconfig \
	/home/s/eclipse/esp-idf/components/pthread/Kconfig \
	/home/s/eclipse/esp-idf/components/spi_flash/Kconfig \
	/home/s/eclipse/esp-idf/components/spiffs/Kconfig \
	/home/s/eclipse/esp-idf/components/tcpip_adapter/Kconfig \
	/home/s/eclipse/esp-idf/components/unity/Kconfig \
	/home/s/eclipse/esp-idf/components/vfs/Kconfig \
	/home/s/eclipse/esp-idf/components/wear_levelling/Kconfig \
	/home/s/eclipse/esp-idf/components/app_update/Kconfig.projbuild \
	/home/s/eclipse/esp-idf/components/bootloader/Kconfig.projbuild \
	/home/s/eclipse/esp-idf/components/esptool_py/Kconfig.projbuild \
	/home/s/eclipse/esp-idf/components/partition_table/Kconfig.projbuild \
	/home/s/eclipse/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)

ifneq "$(IDF_TARGET)" "esp32"
include/config/auto.conf: FORCE
endif
ifneq "$(IDF_CMAKE)" "n"
include/config/auto.conf: FORCE
endif

$(deps_config): ;
