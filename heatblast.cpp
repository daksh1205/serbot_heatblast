#include <SoftwareSerial.h>
#include <Servo.h>

const int flameSensor1Pin = 2;
const int flameSensor2Pin = 3;
const int flameSensor3Pin = 4;
const int gasSensorPin = A0;
const int waterPumpPin = 5;
const int motorPin1 = 6;
const int motorPin2 = 7;
const int motorPin3 = 8;
const int motorPin4 = 9;
const int servoPin = 10;

SoftwareSerial gsmSerial(11, 12);
String smsMessage;
Servo waterServo;

void setup() {
    Serial.begin(9600);
    gsmSerial.begin(9600);

    pinMode(flameSensor1Pin, INPUT);
    pinMode(flameSensor2Pin, INPUT);
    pinMode(flameSensor3Pin, INPUT);
    pinMode(gasSensorPin, INPUT);
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(waterPumpPin, OUTPUT);

    waterServo.attach(servoPin);
    waterServo.write(0);
}

void loop() {
    int flame1 = digitalRead(flameSensor1Pin);
    int flame2 = digitalRead(flameSensor2Pin);
    int flame3 = digitalRead(flameSensor3Pin);
    int gasLevel = analogRead(gasSensorPin);

    if (flame1 == HIGH || flame2 == HIGH || flame3 == HIGH) {
        Serial.println("Fire Detected!");
        digitalWrite(waterPumpPin, HIGH);
        waterServo.write(90);
        sendAlert("Fire detected! Water pump activated.");
    }

    if (gasLevel > 300) {
        Serial.println("Gas Leak Detected!");
        sendAlert("Gas leak detected! Take necessary action.");
    }

    if (flame1 == LOW && flame2 == LOW && flame3 == LOW) {
        digitalWrite(waterPumpPin, LOW);
        waterServo.write(0);
    }

    moveRobot();
    delay(1000);
}

void sendAlert(String message) {
    smsMessage = message;
    gsmSerial.println("AT+CMGF=1");
    delay(100);
    gsmSerial.println("AT+CMGS=\"+1234567890\"");
    delay(100);
    gsmSerial.println(smsMessage);
    delay(100);
    gsmSerial.write(26);
    delay(1000);
}

void moveRobot() {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
}
