// 
// 
// 

#include "JsonUtil.h"
#include <ArduinoJson.h>



//Json버퍼를 만든다
StaticJsonBuffer<200> jsonBuffer; // 200: 버퍼크기


// 인코딩
// 한번에 하나만 보낼 수 있음
String jsonEnc(jsonEncoder_t process) {
	jsonBuffer.clear();
	JsonObject &root = jsonBuffer.createObject();

	process(root);

	/*
	String name, float value
	root["name"] = name;
	root["value"] = value;
	*/

	String jsondata = "";
	root.printTo(jsondata); //String으로 변환

	return jsondata;
}

// 디코딩
void jsonDec(String jsondata, jsonDecoder_t process) {
	jsonBuffer.clear();
	JsonObject& root = jsonBuffer.parseObject(jsondata);

	process(root);

	/*
	String name = root["name"];
	float value = root["value"];

	Serial.println(name);
	Serial.println(value);*/
}


// 배열인코딩
// 배열을 통해 한번에 여러개 보내기
String jsonEncArr(int size, jsonArrDecoder_t process ) {
	jsonBuffer.clear();
	JsonArray& root = jsonBuffer.createArray();

	for (int i = 0; i < size; i++) {
		JsonObject &element = root.createNestedObject();

		process(i, element);

		/*
		element["name"] = "temp" + String(i);
		element["value"] = i;*/
	}

	String jsondata = "";
	root.printTo(jsondata); // String반환
	return jsondata;

}

// 배열디코딩
void jsonDecArr(String jsondata, jsonArrDecoder_t process) {
	jsonBuffer.clear();
	auto &root = jsonBuffer.parseArray(jsondata);

	int index = 0;

	for (auto &element : root) { // &element 깊은 복사

		// 인덱스 없으므로 직접 지정
		process(index++ , element);
		
		/*
		String name = element["name"];
		float value = element["value"];
		Serial.println(name);
		Serial.println(value);*/
	}
}


