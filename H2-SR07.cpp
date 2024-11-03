// Compiled and tested with no errors
// Measure distance using HC-SR04 ultrasonic sensor with Arduino
// source - www.circuitschools.com
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int trigPin = 8;      //declare pin for trigger pin of UltraSonic sensor; 
int echoPin = 7;      //declare pin for echo pin of UltraSonic sensor;
float speed = 0.0347; //declare speed of sound in air @ room temp;
int dist;           //declare variable for containing distance sensed;
float pingTime;       //declare variable for containing echo time;
float distinch;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin,OUTPUT);    //set trigger pin as outpin;
  pinMode(echoPin,INPUT);     //set echo pin as input;
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.print ("CIRCUITSCHOOLS..");
  lcd. setCursor (0, 1);
  lcd.print ("Distance sensor");
  
delay(2000);
lcd.clear();
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(20);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);          //creating a pulse for sensing distance;
  pingTime = pulseIn(echoPin,HIGH);   //read the echoTime, &hence the distance;
  dist = (speed*pingTime*0.5);  
  distinch = dist/2.54;  
  Serial.print("Distance: ");
  Serial.print(dist); 
  Serial.print("cms --- ");
  Serial.print(distinch); 
  Serial.println("inches"); 
  lcd.setCursor(0, 0);
  lcd.print(dist);
  lcd.print("cms");
  lcd.setCursor(0, 1);
  lcd.print(distinch);
  lcd.print("inch");

delay(250);
  }