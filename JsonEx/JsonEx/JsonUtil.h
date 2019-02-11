// JsonUtil.h

#ifndef _JSONUTIL_h
#define _JSONUTIL_h

#include <ArduinoJson.h>

typedef void(*jsonEncoder_t ) (JsonObject &root);
typedef void(*jsonDecoder_t) (JsonObject &root);

typedef void(*jsonArrEncoder_t) (int index, JsonObject &element);
typedef void(*jsonArrDecoder_t) (int index, JsonObject &element);

// 窜老 JSON 按眉 贸府 
String jsonEnc(jsonEncoder_t process);
void jsonDec(String jsondata, jsonDecoder_t process);


// 硅凯 JSON 按眉 贸府
String jsonEncArr(int size, jsonArrDecoder_t process);
void jsonDecArr(String jsondata, jsonArrDecoder_t process);

#endif

