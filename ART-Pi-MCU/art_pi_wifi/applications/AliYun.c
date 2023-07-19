//#include "rtthread.h"
//#include "dev_sign_api.h"
//#include "mqtt_api.h"
//
//char DEMO_PRODUCT_KEY[IOTX_PRODUCT_KEY_LEN + 1] = {0};
//char DEMO_DEVICE_NAME[IOTX_DEVICE_NAME_LEN + 1] = {0};
//char DEMO_DEVICE_SECRET[IOTX_DEVICE_SECRET_LEN + 1] = {0};
//
//void *HAL_Malloc(uint32_t size);
//void HAL_Free(void *ptr);
//void HAL_Printf(const char *fmt, ...);
//int HAL_GetProductKey(char product_key[IOTX_PRODUCT_KEY_LEN + 1]);
//int HAL_GetDeviceName(char device_name[IOTX_DEVICE_NAME_LEN + 1]);
//int HAL_GetDeviceSecret(char device_secret[IOTX_DEVICE_SECRET_LEN]);
//uint64_t HAL_UptimeMs(void);
//int HAL_Snprintf(char *str, const int len, const char *fmt, ...);
////float Humi = 50.4;
////float Temp = 26.7;
////int lux = 1500;
//int id_cnt = 100;
//
//#define EXAMPLE_TRACE(fmt, ...)  \
//    do { \
//        HAL_Printf("%s|%03d :: ", __func__, __LINE__); \
//        HAL_Printf(fmt, ##__VA_ARGS__); \
//        HAL_Printf("%s", "\r\n"); \
//    } while(0)
//
//static void example_message_arrive(void *pcontext, void *pclient, iotx_mqtt_event_msg_pt msg)
//{
//    iotx_mqtt_topic_info_t     *topic_info = (iotx_mqtt_topic_info_pt) msg->msg;
//
//    switch (msg->event_type) {
//        case IOTX_MQTT_EVENT_PUBLISH_RECEIVED:
//            /* print topic name and topic message */
//            EXAMPLE_TRACE("Message Arrived:");
//            EXAMPLE_TRACE("Topic  : %.*s", topic_info->topic_len, topic_info->ptopic);
//            EXAMPLE_TRACE("Payload: %.*s", topic_info->payload_len, topic_info->payload);
//            EXAMPLE_TRACE("\n");
//            break;
//        default:
//            break;
//    }
//}
//
//int example_subscribe(void *handle)
//{
//    int res = 0;
//    const char *fmt = "/%s/%s/user/get";
//    char *topic = NULL;
//    int topic_len = 0;
//
//    topic_len = strlen(fmt) + strlen(DEMO_PRODUCT_KEY) + strlen(DEMO_DEVICE_NAME) + 1;
//    topic = HAL_Malloc(topic_len);
//    if (topic == NULL) {
//        EXAMPLE_TRACE("memory not enough");
//        return -1;
//    }
//    memset(topic, 0, topic_len);
//    HAL_Snprintf(topic, topic_len, fmt, DEMO_PRODUCT_KEY, DEMO_DEVICE_NAME);
//
//    res = IOT_MQTT_Subscribe(handle, topic, IOTX_MQTT_QOS0, example_message_arrive, NULL);
//    if (res < 0) {
//        EXAMPLE_TRACE("subscribe failed");
//        HAL_Free(topic);
//        return -1;
//    }
//
//    HAL_Free(topic);
//    return 0;
//}
//
//static int example_publish(void *handle)
//{
//    int             res = 0;
//    const char     *fmt = "/sys/%s/%s/thing/event/property/post";    //订阅消息
//    char           *topic = NULL;
//    int             topic_len = 0;
//
//    char           *payload="";
//    int             payload_len = 0;
//
//    char           *fmt2 = "{%s,%s,%s,%s}";
//    char           *method = "\"method\": \"thing.event.property.post\"";// 方法
//    char            id[16] = "";// 唯一ID
//    char            params[128] = "";// 参数
//    char           *version = "\"version\":\"1.0\"";
//
//    id_cnt++;
//    float Humi = 50.5;
//    float Temp = 26.5;
//    float lux = 1550.7;
//    HAL_Snprintf(id, 16, "\"id\": \"%d\"", id_cnt);
////    HAL_Snprintf(params, 128, "\"params\":{\"Humidity\":%d,\"Temperature\":\%d,\"LightLux\":\%d}",
////                    Humi,Temp,lux);
////    HAL_Snprintf(params, 256,
////                  "\"params\":{\"Humidity\":%f,\"Temperature\":%f,\"LightLux\":%f}",
////                  Humi, Temp, lux);
//    sprintf(params,"\"params\":{\"Humidity\":%.1f,\"Temperature\":%.1f,\"LightLux\":%.1f}",
//                Humi, Temp, lux);
//
//
//    payload_len = strlen(fmt2) + strlen(method) + strlen(id) + strlen(params) + strlen(version) + 1;
//    payload = HAL_Malloc(payload_len);
//    if (payload == NULL) {
//        EXAMPLE_TRACE("memory not enough");
//        return -1;
//    }
//    memset(payload, 0, payload_len);
//    HAL_Snprintf(payload, payload_len, fmt2, method, id, params, version);
//
//    topic_len = strlen(fmt) + strlen(DEMO_PRODUCT_KEY) + strlen(DEMO_DEVICE_NAME) + 1;
//    topic = HAL_Malloc(topic_len);
//    if (topic == NULL) {
//        EXAMPLE_TRACE("memory not enough");
//        return -1;
//    }
//    memset(topic, 0, topic_len);
//    HAL_Snprintf(topic, topic_len, fmt, DEMO_PRODUCT_KEY, DEMO_DEVICE_NAME);
//
//    res = IOT_MQTT_Publish_Simple(0, topic, IOTX_MQTT_QOS0, payload, strlen(payload));
//    if (res < 0) {
//        EXAMPLE_TRACE("publish failed, res = %d", res);
//        HAL_Free(topic);
//        return -1;
//    }
//
//    HAL_Free(topic);
//    return 0;
//}
//
//void example_event_handle(void *pcontext, void *pclient, iotx_mqtt_event_msg_pt msg)
//{
//    EXAMPLE_TRACE("msg->event_type : %d", msg->event_type);
//}
//
//int mqtt_example_main(int argc, char *argv[])
//{
//    void                   *pclient = NULL;
//    int                     res = 0;
//    int                     loop_cnt = 0;
//    iotx_mqtt_param_t       mqtt_params;
//
//    HAL_GetProductKey(DEMO_PRODUCT_KEY);
//    HAL_GetDeviceName(DEMO_DEVICE_NAME);
//    HAL_GetDeviceSecret(DEMO_DEVICE_SECRET);
//
//    EXAMPLE_TRACE("mqtt example");
//
//    mqtt_params.handle_event.h_fp = example_event_handle;
//
//    pclient = IOT_MQTT_Construct(&mqtt_params);
//    if (NULL == pclient) {
//        EXAMPLE_TRACE("MQTT construct failed");
//        return -1;
//    }
//
//    res = example_subscribe(pclient);
//    if (res < 0) {
//        IOT_MQTT_Destroy(&pclient);
//        return -1;
//    }
//
//    while (1) {
//        if (0 == loop_cnt % 20) {
//            example_publish(pclient);
//        }
//
//        IOT_MQTT_Yield(pclient, 200);
//
//        loop_cnt += 1;
//    }
//
//    return 0;
//}

//MSH_CMD_EXPORT_ALIAS(mqtt_example_main,Sensor_Trans,transmit the senosr data);

