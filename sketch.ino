#include <DHT.h>
#define DHTPIN  15      
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE);

float h = 0.0;  
float t = 0.0;  

void setup() {
  Serial.begin(115200);
  dht.begin();  
}

void loop() {
  h = dht.readHumidity();
  t = dht.readTemperature();  

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C"));

  delay(500);  
}
