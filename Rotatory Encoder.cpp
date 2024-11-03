// Tested and compiled with no errors
// Rotary encoder with Arduino to print position and direction of rotation
// source - www.circuitschools.com
#include <LiquidCrystal_I2C.h>
#define outputA 6
#define outputB 7

// Initialize the LCD library with I2C address and LCD size
LiquidCrystal_I2C lcd (0x27, 16,2);

int counter = 0;
int currentStateA;
int lastStateA;
String currentDir ="";

void setup() {
  
  // Set encoder pins as inputs
  pinMode(outputA,INPUT);
  pinMode(outputB,INPUT);


  // Setup Serial Monitor
  Serial.begin(9600);
  lcd. init ();
// Turn on the backlight on LCD. 
  lcd. backlight ();
  lcd.print ("CIRCUITSCHOOLS..");
  lcd. setCursor (0, 1);
  lcd.print ("ROTARY ENCODER");
  
delay(2000);
lcd.clear();
     lcd.setCursor(0, 0);
lcd.print("Rotate the knob");
  // Read the initial state of outputA
  lastStateA = digitalRead(outputA);
}

void loop() {
  
  // Read the current state of outputA
  currentStateA = digitalRead(outputA);


  // If last and current state of outputA are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateA != lastStateA  && currentStateA == 1){

    // If the outputB state is different than the outputA state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(outputB) != currentStateA) {
      counter ++;
      currentDir ="CW";
    } else {
      // Encoder is rotating CW so increment
      counter --;
      currentDir ="ACW";
    }

    Serial.print("Direction: ");
    Serial.print(currentDir);
    Serial.print(" | Counter: ");
    Serial.println(counter);
lcd.clear();
    lcd.setCursor(0, 0);
lcd.print("Position: ");
lcd.setCursor(10, 0);
lcd.print(counter);
lcd.setCursor(0, 1);
lcd.print("Dir: ");
lcd.setCursor(5, 1);
lcd.print(currentDir);
  }

  // Remember last outputA state
  lastStateA = currentStateA;

  // Put in a slight delay to help debounce the reading
  delay(1);
}