#include <LiquidCrystal_I2C.h>

#define LED_BRIGHT_PIN A0
const int count = 100;

LiquidCrystal_I2C LCD (0x27, 20, 4);

void setup() {

    Serial.begin(9600);
    
    LCD.init();
    LCD.backlight();
    
    pinMode(LED_BRIGHT_PIN, OUTPUT);
    analogWrite(LED_BRIGHT_PIN, 250);


    LCD.setCursor(0, 0);
    LCD.print("First connection");

    LCD.setCursor(0, 1);
    LCD.print("LCD to Arduino");
    
}

void loop() {
    for (int i = 0; i < count; i++) {
        
        LCD.clear();
        
        LCD.setCursor(0, 1);
        LCD.print("LCD to Arduino");

        LCD.setCursor(i, 0);
        LCD.print("First connection");

        delay(400);
        
    }
    
}