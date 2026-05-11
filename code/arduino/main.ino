#include <DHT.h>

constexpr int DHT_PIN = 2;
constexpr int DHT_TYPE = DHT22;
constexpr int RELAY_PIN = 8;
constexpr int LASER_SCATTER_PIN = A0;

// Initial commissioning defaults; tune with field calibration logs for site-specific fog behavior.
constexpr float HUMIDITY_THRESHOLD = 85.0f;
constexpr int SCATTER_THRESHOLD = 600;

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  pinMode(LASER_SCATTER_PIN, INPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int scatterValue = analogRead(LASER_SCATTER_PIN);

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("DHT22 read failed");
    delay(2000);
    return;
  }

  bool shouldTrigger = humidity >= HUMIDITY_THRESHOLD || scatterValue >= SCATTER_THRESHOLD;
  digitalWrite(RELAY_PIN, shouldTrigger ? HIGH : LOW);

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("% | Temp: ");
  Serial.print(temperature);
  Serial.print("C | Scatter: ");
  Serial.print(scatterValue);
  Serial.print(" | Relay: ");
  Serial.println(shouldTrigger ? "ON" : "OFF");

  // 2s cadence balances control responsiveness and relay/Peltier switching stability.
  delay(2000);
}
