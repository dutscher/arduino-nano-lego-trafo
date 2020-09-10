#include <Arduino_JSON.h>

JSONVar parseJSON(String _json) {
	JSONVar json = JSON.parse(_json);

	if (json.length() == -1) {
		Serial.println("json error: " + _json);
		Serial.println("JSON: " + String(json.length()));
	}

	return json;
}

String routesRaw = R"(
[
  {"action":"Power",    "label":"on",           "link":"beameron"},
  {"action":"Power",    "label":"off",          "link":"beameroff"},
  {"action":"Power",    "label","off directly", "link":"beameroffwithoutdelay"}
]
)";
JSONVar routes = parseJSON(routesRaw);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("");
  Serial.println(routesRaw);
}

void loop() {
  // put your main code here, to run repeatedly:

}
