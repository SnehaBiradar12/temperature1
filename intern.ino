#define SENSOR_PIN A0
#define LED_PIN 13

int temperature;
unsigned long previousMillis = 0;
int interval = 250; // Initial interval for temperature below 30 degrees Celsius
int iterationCounter = 0;

void setup() {
  pinMode (SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);//Serial communication
}

void loop() {
  temperature = readTemperature();
  
  if (temperature < 30) {
    interval = 250; // Set interval to 250 milliseconds
  } else {
    interval = 500; // Set interval to 500 milliseconds
  }

  if (iterationCounter >= interval) {
    iterationCounter = 0;
    digitalWrite(LED_PIN, !digitalRead(LED_PIN)); // Toggle LED state
  }
  
  iterationCounter++;
}

int readTemperature() {
  int sensorValue = analogRead(SENSOR_PIN);
  float millivolts = (sensorValue / 1024.0) * 5000; // Convert sensor reading to millivolts
  float celsius = millivolts / 10; // Convert millivolts to Celsius
  return (int)celsius; // Return temperature in Celsius
}
