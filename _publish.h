#include <DHT.h>

#define DHTPIN 12
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);

static float t_dht;
static float h_dht;

void read_sensor();

void on_prepare_data(JsonObject * root) {
    read_sensor();
    JsonObject& data = (*root)["d"];
    JsonObject& info = (*root)["info"];

    data["myName"] = ALIAS;
    data["temp"] = t_dht;
    data["humid"] = h_dht;
};

void read_sensor() {
    static float _t_dht;
    static float _h_dht;
    _t_dht = dht.readTemperature();
    _h_dht = dht.readHumidity();

    if (!isnan(_t_dht)) {
      t_dht = _t_dht;
      h_dht = _h_dht;
    }
}
