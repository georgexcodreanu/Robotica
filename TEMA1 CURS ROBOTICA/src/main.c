#include <Arduino.h>

int ledL1 = 10;// LED 25%
int ledL2 = 9; // LED 50%
int ledL3 = 8; // LED 75%
int ledL4 = 7; // LED 100%

int ledRed = 6;
int ledGreen = 5;
int ledBlue = 4;

int buttonStart = 3;
int buttonStop = 2;

bool isCharging = false;
bool isFree = true;
bool startButtonPressed = false;
bool stopButtonPressed = false;

unsigned long lastDebounceTimeStart = 0;
unsigned long lastDebounceTimeStop = 0;
unsigned long debounceDelay = 25;

void setup() {

  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledL1, OUTPUT);
  pinMode(ledL2, OUTPUT);
  pinMode(ledL3, OUTPUT);
  pinMode(ledL4, OUTPUT);

  pinMode(buttonStart, INPUT);
  pinMode(buttonStop, INPUT);
  
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledBlue, LOW);
}

void loop() {
  // Citim starea butonului de start cu debouncing
  int buttonStartState = digitalRead(buttonStart);
  if (buttonStartState == LOW && (millis() - lastDebounceTimeStart > debounceDelay)) {
    lastDebounceTimeStart = millis();
    startButtonPressed = true;
  }
  
  // Citim starea butonului de stop cu debouncing
  int buttonStopState = digitalRead(buttonStop);
  if (buttonStopState == LOW && (millis() - lastDebounceTimeStop > debounceDelay)) {
    lastDebounceTimeStop = millis();
    stopButtonPressed = true;
  }

  if (startButtonPressed && isFree) {
    startButtonPressed = false;
    isCharging = true;
    isFree = false;
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, LOW);
    startCharging();
  }

  if (stopButtonPressed && isCharging) {
    stopButtonPressed = false;
    stopCharging();
  }
}

void startCharging() {

  if (isCharging) {
    blinkLED(ledL1);

    if (!isCharging) return;
    blinkLED(ledL2);
    
    if (!isCharging) return;
    blinkLED(ledL3);
    
    if (!isCharging) return;
    blinkLED(ledL4);

    stopCharging();
    
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, HIGH);
    isCharging = false;
    isFree = true;
    
  }
}

void stopCharging() {

  blinkAllLeds();

  digitalWrite(ledL1, LOW);
  digitalWrite(ledL2, LOW);
  digitalWrite(ledL3, LOW);
  digitalWrite(ledL4, LOW);
  
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, HIGH);
  
  isCharging = false;
  isFree = true;
}

void blinkLED(int led){

  for (int i = 0; i < 3; i++) {

    digitalWrite(led, HIGH);
    delayWithStopCheck(500);
    if (!isCharging) return;
    
    digitalWrite(led, LOW);
    delayWithStopCheck(500);
    if (!isCharging) return;
  }
  digitalWrite(led, HIGH);
}


void blinkAllLeds() {

  for (int i = 0; i < 3; i++) {
    digitalWrite(ledL1, LOW);
    digitalWrite(ledL2, LOW);
    digitalWrite(ledL3, LOW);
    digitalWrite(ledL4, LOW);
    delay(500);
    digitalWrite(ledL1, HIGH);
    digitalWrite(ledL2, HIGH);
    digitalWrite(ledL3, HIGH);
    digitalWrite(ledL4, HIGH);
    delay(500);
  }
}

void delayWithStopCheck(int ms) {
  unsigned long startTime = millis();
  while (millis() - startTime < ms) {
    int buttonStopState = digitalRead(buttonStop);
    if (buttonStopState == LOW) {
      unsigned long pressStartTime = millis();
      while (digitalRead(buttonStop) == LOW) {
        if (millis() - pressStartTime >= 1000) {
          stopCharging();
          return;
        }
        delay(10);
      }
    }
    delay(10);
  }
}