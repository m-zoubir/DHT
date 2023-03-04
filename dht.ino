#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DHT_U.h>

const int sensor = 10 ;
#define DHTTYPE DHT11


DHT dht(sensor, DHTTYPE);
LiquidCrystal_I2C lcd(0x27,16,2);  

void setup()
{
  lcd.init();                     
  Serial.begin(9600);
  lcd.backlight();
  dht.begin();
  
  
}


void loop()
{
   delay(2000);
   float h = dht.readHumidity();
   float t = dht.readTemperature();
   float f = dht.readTemperature(true); // isFahreheit == true
  if ( isnan(h) || isnan(t) || isnan(f) )
  {
    lcd.setCursor(0,0);
    lcd.print(" failure !");
    return ; 
  }
  float hif = dht.computeHeatIndex(f,h);
  float hit = dht.computeHeatIndex(t,h, false); // isFahreheit == false 
  lcd.setCursor(0,0);
  Serial.println("Humidity : ");
  lcd.print("HUM: ");
  lcd.print(h);
  Serial.print(h);
  lcd.setCursor(0,1);
  Serial.println("Temperature : ");
  lcd.print("TEM: ");
  lcd.print(t);
  Serial.print(c);
  Serial.println(" C ");
  lcd.print(" C ");
  lcd.print(f);
  lcd.print(" F ");
  Serial.print(f);
  Serial.println(" F ");
  
}
