// Include library for LCD and define pins
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int green_led = 10;
const int red_led = 13;
const int buzzer = 6;
int PIR = 8;  // Define PIR pin
int val = 0;

// Set threshold for AQI
#include "DHT.h"

#define DHTPIN 7 

#define DHTTYPE DHT11  // DHT 11


DHT dht(DHTPIN, DHTTYPE);
void setup() {
  // Set direction of input-output pins
  
  pinMode(green_led, OUTPUT);
  pinMode(red_led, OUTPUT);
 

  pinMode(PIR, INPUT);
  pinMode(buzzer, OUTPUT);

  /*digitalWrite(green_led, LOW);
  digitalWrite(buzzer, LOW);
  // Initiate serial and lcd communication
  Serial.begin (9600);*/
  lcd.clear();
  lcd.begin(16, 2);
  lcd.print("Security Alarm!");


  delay(5000);
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  val = digitalRead(PIR);  // The value read from PIR pin 3 will be assigned to 'val'
                           /*if(val == HIGH){
  digitalWrite(green_led, HIGH); // Turn LED ON
  digitalWrite(buzzer, HIGH); // Turn Buzzer ON
  Serial.println("Movement Detected"); // Print this text in Serial Monitor
}
else 
{
  digitalWrite(green_led, LOW);
  digitalWrite(buzzer, LOW);
  Serial.println("Movement not Detected");
}*/

  Serial.print("Temperature : ");
  Serial.println(t);
  Serial.print("Humidity : ");
  Serial.println(h);
  Serial.print("Human Detection : ");
  Serial.println(val);
  Serial.println(" ");
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.println("Temperature: ");
  lcd.setCursor(12, 0);
  lcd.print(t);
  // lcd.setCursor(14, 0);
  // lcd.println(" C ");
  // lcd.setCursor(9, 0);
  // lcd.print(int(h));
  lcd.setCursor(0, 1);
  lcd.print("Motion: ");
  lcd.setCursor(8, 1);
  lcd.print(val);


  if ((val == HIGH)) {
    digitalWrite(green_led, HIGH);
    digitalWrite(buzzer, HIGH);    
  
    // tone(buzzer, 1000, 1000);
    delay(2000);
    digitalWrite(buzzer, LOW);
    digitalWrite(green_led, LOW);
    Serial.println("Movement Detected");
    Serial.println(" ");
    // lcd.print("D: ");
    lcd.setCursor(8, 1);
    lcd.print(val);
    // lcd.setCursor(15, 0);
    // lcd.print(val);


  }
  if (t > 30) {
    digitalWrite(red_led, HIGH);
    
    digitalWrite(buzzer, HIGH);
    delay(2000);
    digitalWrite(red_led, LOW);
    digitalWrite(buzzer, LOW);
    
  } 
  
  delay(1000);
}