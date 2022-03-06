#include <LiquidCrystal_I2C.h>

#define LED_BRIGHT_PIN A0
#define POTENTIOMETR_PIN A3
#define BUTTON_PIN A4

const int count = 100;

LiquidCrystal_I2C LCD (0x27, 20, 4);

void setup() {

    Serial.begin(9600);
    
    LCD.init();
    LCD.backlight();
    
    pinMode(LED_BRIGHT_PIN, OUTPUT);
    analogWrite(LED_BRIGHT_PIN, 250);

    pinMode(A3, INPUT_PULLUP);
    pinMode(A4, INPUT_PULLUP);

    LCD.clear();
    
}

void loop() {
    
    unsigned int potentiometr = analogRead(POTENTIOMETR_PIN);
    boolean button = digitalRead(BUTTON_PIN);
    double buffer = (double) map(potentiometr, 0, 1023, 0, 500)/100; 
  
    LCD.clear();

    LCD.setCursor(0, 0);
    LCD.print("Potentiometr: ");
    LCD.print(buffer);
    LCD.print("V");

    LCD.setCursor(0, 1);
    LCD.print("Button: ");
    if (button) {
      LCD.print("pressed");
    } else LCD.print("not pressed");
    
    delay(100);
}