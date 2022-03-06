#include <LCD_1602_RUS.h>

#define RED 4
#define GREEN 2
#define YELLOW 3
#define BUTTON A0
#define LED_BRIGHT_PIN A0

byte blinkAmount = 2; // 1 is turn and off light
unsigned int blinkTime = 1000;
unsigned int timeWait = 10000;
unsigned int timeWaitYellow = 3000;
unsigned int remainingTime = 15000;
unsigned long globalTimeBuffer = millis();
unsigned long localeTimeBuffer = millis();

String goPermission = "Можно ехать";
String ready = "Приготовиться";
String remainingTimeString = "Осталось времени:";
String stopMessage = "Стоп!";

LCD_1602_RUS LCD (0x27, 20, 4);

void setup() {

  Serial.begin(9600);

  pinMode(BUTTON, INPUT);

  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);

  digitalWrite(RED, 0);
  digitalWrite(GREEN, 0);
  digitalWrite(YELLOW, 0);

  LCD.init();
  LCD.backlight();
  
  pinMode(LED_BRIGHT_PIN, OUTPUT);
  analogWrite(LED_BRIGHT_PIN, 250);

  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);

  LCD.clear();

}


void writeTimeOnSecondAndThirdRows(String message, int time) {
  int buffer = time/1000;
  writeLCD((message));
  LCD.setCursor(0, 1);
  LCD.print(remainingTimeString);
  LCD.setCursor(0, 2);
  LCD.print(buffer);
  LCD.print(" с.");
  // LCD.println();
}

void writeLCD(String string) {
  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print((string));
}

void greenBlinking() {
  globalTimeBuffer = millis();
  int blinkCounter = 0;
  writeLCD(goPermission);
  boolean exiteState_1 = true;
  boolean exiteState_2 = true;
  while (exiteState_1) {
    digitalWrite(GREEN, 1);
    globalTimeBuffer = millis();  
    while (exiteState_2) {
      if (millis() - globalTimeBuffer > blinkTime) {
        exiteState_2 = false;
        globalTimeBuffer = millis();
      } 
    }
    exiteState_2 = true;

    digitalWrite(GREEN, 0);
    blinkCounter++;
    globalTimeBuffer = millis();
    while (exiteState_2) {
      if (millis() - globalTimeBuffer > blinkTime) {
        exiteState_2 = false;
        globalTimeBuffer = millis();
      } 
    }
    exiteState_2 = true;

    if (blinkCounter == blinkAmount) exiteState_1 = false;
  }
}

void greenToRed() {
  boolean exitState = true;
  byte redCounter = 0;
  digitalWrite(GREEN, 0);
  writeLCD(stopMessage);
  digitalWrite(RED, 1);
  globalTimeBuffer = millis();
  localeTimeBuffer = millis();
  while (exitState) {
    if (millis() - localeTimeBuffer > 1000) {
      writeTimeOnSecondAndThirdRows(stopMessage, timeWait - 1000*redCounter);
      localeTimeBuffer = millis();
      redCounter++;
    } 
    if (millis() - globalTimeBuffer > timeWait+2000) {
      exitState = false;
      localeTimeBuffer = millis();
    } 
  }

}

void waitYellow() {
  boolean exitState = true;
  digitalWrite(RED, 0);
  digitalWrite(YELLOW, 1);
  writeLCD(ready);
  globalTimeBuffer = millis();
  while (exitState) {
    if (millis() - globalTimeBuffer > timeWaitYellow) {
      exitState = false;
    } 
  }
  digitalWrite(YELLOW, 0);
}

void greenLightTime() {
  boolean exitState = true;
  digitalWrite(GREEN, 1);
  writeLCD(goPermission);
  globalTimeBuffer = millis();
  byte greenCounter = 0;
  localeTimeBuffer = millis();
  globalTimeBuffer = millis();
  while (exitState) {
    if (millis() - localeTimeBuffer > 1000) {
      writeTimeOnSecondAndThirdRows(goPermission, remainingTime - 1000*greenCounter);
      localeTimeBuffer = millis();
      greenCounter++;
    } 
    if (millis() - globalTimeBuffer > remainingTime+2800) {
      exitState = false;
      localeTimeBuffer = millis();
    } 
  }
}

void loop() {

  boolean button = true;

  if (button) {

    greenLightTime();
    
    greenBlinking();

    greenToRed();

    waitYellow();

  }

}
