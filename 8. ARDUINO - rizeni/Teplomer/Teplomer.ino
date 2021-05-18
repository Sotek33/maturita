
#include <LiquidCrystal_I2C.h>
#include <DallasTemperature.h>
#include <OneWire.h>

LiquidCrystal_I2C lcd(0x27,16,2);
#define tep 2
OneWire oneWire(tep);
DallasTemperature sensors(&oneWire);
int b=13,g=12,r=11;
float t,mn=100,mx=0;

void setup() {
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  
  pinMode(2,INPUT);
  pinMode(10,INPUT);

  pinMode(b,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(r,OUTPUT);

}

void loop() {
 sensors.requestTemperatures();
 t=sensors.getTempCByIndex(0);

if(digitalRead(9) == LOW)
{
  if(digitalRead(10) == HIGH)
  {
  minmax(); 
  teplota();
  rgb();
  }

  else if(digitalRead(10) == LOW)
  {
    minmax(); 
    lcdminmax();
  }

  
}
else if(digitalRead(9) == HIGH)
{
nulovani();  
}

}

void teplota()
{
  if (t < 26.5)
  {
    lcd.setCursor(0,0);
    lcd.print("TOP=ZAP//KLI=VYP");
    lcd.setCursor(0,1);
    lcd.print(t,4);
    lcd.print(" C");
    lcd.setCursor(9,1);
    lcd.print("  ");
  }

  else if (t > 26.5 && t < 28.5)
  {
    lcd.setCursor(0,0);
    lcd.print("TOP=VYP//KLI=VYP");
    lcd.setCursor(0,1);
    lcd.print(t,4);
    lcd.print(" C");
    lcd.setCursor(9,1);
    lcd.print("  ");
  }

  else if (t > 28.5)
  {
    lcd.setCursor(0,0);
    lcd.print("TOP=VYP//KLI=ZAP");
    lcd.setCursor(0,1);
    lcd.print(t,4);
    lcd.print(" C");
    lcd.setCursor(9,1);
    lcd.print("  ");
  }
}

void rgb()
{
  if (t < 26.5)
  {
  digitalWrite(r,255);
  digitalWrite(g,0);
  digitalWrite(b,0); 
  }

  if (t > 26.5 && t < 28.5)
  {
  digitalWrite(r,0);
  digitalWrite(g,255);
  digitalWrite(b,0); 
  }

  if (t > 28.5)
  {
  digitalWrite(r,0);
  digitalWrite(g,0);
  digitalWrite(b,255); 
  }
}

void minmax()
{
  if (t > mx)
  {
    mx=t;
  }

  if (t < mn)
  {
    mn=t;
  }
}  
void lcdminmax()
{
  //  lcd.begin();
    lcd.setCursor(0,0);
    lcd.print("Max=");
    lcd.print(mx,4);
    lcd.setCursor(0,1);
    lcd.print("Min=");
    lcd.print(mn,4);
}

void nulovani()
{
  mn= 100;
  mx=0;
  
   // lcd.begin();
    lcd.setCursor(0,0);
    lcd.print("vynulovano");
    lcd.setCursor(0,1);
    lcd.print("Sw1 dejte 0");
}  
  
