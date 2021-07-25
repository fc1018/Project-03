#include <Arduino.h>

const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
  Serial.begin(9600);

  for ( int pinNumber = 2; pinNumber < 5; pinNumber++ ) {
    pinMode (pinNumber, OUTPUT);
    digitalWrite (pinNumber, LOW);
  }
}

void loop() {
  void printVolts ();
  void printSensorVal ();
  void printTemp ();
  void checkTemp ();

  printVolts ();

  printSensorVal ();

  printTemp ();

  checkTemp ();

  delay (1);

}

void printVolts () {
  int sensorVal = analogRead (sensorPin);
  float voltage = (sensorVal/1024.0) * 5.0;

  Serial.print ("Volts: ");
  Serial.print (voltage);
  Serial.print ("\n");

  return;
}

void printSensorVal () {
  int sensorVal = analogRead (sensorPin);

  Serial.print ("Sensor value: ");
  Serial.print (sensorVal);
  Serial.print ("\n");  

  return;
}

void printTemp () {
  int sensorVal = analogRead (sensorPin);
  float voltage = (sensorVal/1024.0) * 5.0;
  float temperature = (voltage - .5) * 100;

  Serial.print ("degree C: ");
  Serial.println (temperature);
  Serial.print ("\n");

  return;
}

void checkTemp () {
  int sensorVal = analogRead (sensorPin);
  float voltage = (sensorVal/1024.0) * 5.0;
  float temperature = (voltage - .5) * 100;

  if (temperature < baselineTemp) {
    for ( int i = 2; i <= 4; i++ ) {
      //sets all lamps to low 
      digitalWrite(i, LOW);
    }
  }
  else if ( temperature >= baselineTemp + 2 &&
    temperature < baselineTemp + 4) {
    digitalWrite (2, HIGH);
    digitalWrite (3, LOW);
    digitalWrite (4, LOW);
  }
  else if (temperature >= baselineTemp + 4 &&
    temperature < baselineTemp + 6) {
      digitalWrite (2, HIGH);
      digitalWrite (3, HIGH);
      digitalWrite (4, LOW);
    }
  else if (temperature >= baselineTemp + 6) {
    for ( int i = 2; i <= 4; i++ ) {
      //sets all lamps to high
      digitalWrite(i, HIGH);
    }
  }
}