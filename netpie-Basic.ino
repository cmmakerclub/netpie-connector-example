#define MQTT_MAX_PACKET_SIZE 1024

#include <AuthClient.h>
#include <MicroGear.h>
#include <ArduinoJson.h>
#include <MQTTClient.h>
#include <SHA1.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include <MicroGear.h>
#include "timer.hpp"

const char* ssid     = "ESPERT-002";
const char* password = "espertap";


#define APPID       "HelloCMMC"
#define KEY         ""
#define SECRET      ""

#define ALIAS       "esp8266gear"
#define CHAT_WITH   "htmlgear"
#define PUBLISH_EVERY (2*1000)


WiFiClient client;
AuthClient *authclient;
CMMC_Interval timer001;

// MQTT CONNECTOR CONCEPT
char jsonStrbuffer[1024];
JsonObject *cmmc_root;
JsonObject *d;
JsonObject *cmmc_info;

StaticJsonBuffer<800> jsonRootBuffer;
StaticJsonBuffer<512> jsonDBuffer;


int timer = 0;
MicroGear microgear(client);

#include "_publish.h"
#include "_receive.h"
#include "utils.h"


void setup() {
  _constructor();
  init_hardware();
  init_wifi();
  init_netpie();
}

void loop() {
  microgear_loop();
  delay(100);
}
