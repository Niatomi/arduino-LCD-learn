#include <LiquidCrystal_I2C.h>

#define LED_BRIGHT_PIN A0
#define POTENTIOMETR_PIN A3
#define BUTTON_PIN A4

const int count = 100;

LiquidCrystal_I2C LCD (0x27, 20, 4);

byte squareSymbol[8] =
    {
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B00000,
};

void setup() {

    Serial.begin(9600);
    
    LCD.init();
    LCD.backlight();
    
    pinMode(LED_BRIGHT_PIN, OUTPUT);
    analogWrite(LED_BRIGHT_PIN, 250);

    pinMode(A3, INPUT_PULLUP);
    pinMode(A4, INPUT_PULLUP);

    LCD.createChar(0, squareSymbol);

    LCD.clear();

}

double buffer = (double) map(analogRead(POTENTIOMETR_PIN), 0, 1023, 0, 500)/100; 

void loop() {
    
    unsigned int potentiometr = analogRead(POTENTIOMETR_PIN);
    boolean button = digitalRead(BUTTON_PIN);
    double voltage = (double) map(potentiometr, 150, 1023, 0, 500)/100;

    Serial.println(round(map(round(voltage), 0, 5, 0, 2000)/100)); 
    // Serial.print(" ");
    // Serial.println(voltage);
    // Serial.println();
    

    if (voltage != buffer) {

      LCD.clear();

      LCD.setCursor(0, 0);
      LCD.print("Potentiometr: ");
      LCD.print(voltage);
      LCD.print("V");

      
      Serial.println(buffer);

      for (int i = 0; i < map(round(voltage), 0, 5, 0, 2000)/100; i++) {
        
        LCD.setCursor(i, 1);
        LCD.write(byte(0));

        LCD.setCursor(i, 2);
        LCD.write(byte(0));

        LCD.setCursor(i, 3);
        LCD.write(byte(0));
      } 

      buffer = voltage;

    }
    
  
    delay(50);
}