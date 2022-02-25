#include <LiquidCrystal_I2C.h>

#define LED_BRIGHT_PIN A0
byte ruSymbolP[8] =
    {
        B11111,
        B10001,
        B10001,
        B10001,
        B10001,
        B10001,
        B10001,
        B00000,
    };

LiquidCrystal_I2C LCD (0x27, 20, 4);

void setup() {

    Serial.begin(9600);
    
    LCD.init();
    LCD.backlight();
    LCD.createChar(0, ruSymbolP);
    
    pinMode(LED_BRIGHT_PIN, OUTPUT);
    analogWrite(LED_BRIGHT_PIN, 250);
    
}

void loop() {
    LCD.setCursor(0, 0);
    LCD.write(byte(0));
}