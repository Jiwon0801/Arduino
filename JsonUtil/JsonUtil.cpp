// 
// 
// 

#include "JsonUtil.h"
#include <ArduinoJson.h>



//Json���۸� �����
StaticJsonBuffer<200> jsonBuffer; // 200: ����ũ��


// ���ڵ�
// �ѹ��� �ϳ��� ���� �� ����
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
	root.printTo(jsondata); //String���� ��ȯ

	return jsondata;
}

// ���ڵ�
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


// �迭���ڵ�
// �迭�� ���� �ѹ��� ������ ������
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
	root.printTo(jsondata); // String��ȯ
	return jsondata;

}

// �迭���ڵ�
void jsonDecArr(String jsondata, jsonArrDecoder_t process) {
	jsonBuffer.clear();
	auto &root = jsonBuffer.parseArray(jsondata);

	int index = 0;

	for (auto &element : root) { // &element ���� ����

		// �ε��� �����Ƿ� ���� ����
		process(index++ , element);
		
		/*
		String name = element["name"];
		float value = element["value"];
		Serial.println(name);
		Serial.println(value);*/
	}
}


