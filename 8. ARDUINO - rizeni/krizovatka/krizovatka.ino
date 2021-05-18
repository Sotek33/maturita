int rh=13;  //červená hlavní
int oh=12;  //oranžová hlavní
int gh=11;  //zelená hlavní

int rv=10;  //červená vedlejší
int ov=9;   //oranžová vedlejší
int gv=8;   //zelená vedlejší

int sw=7,z=0,pocet=0;

volatile int x=0;
float d=1000;


void setup() {
  pinMode(rh, OUTPUT);
  pinMode(oh, OUTPUT);
  pinMode(gh, OUTPUT);
  pinMode(rv, OUTPUT);
  pinMode(ov, OUTPUT);
  pinMode(gv, OUTPUT);
  
  pinMode(sw,INPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(4,OUTPUT);
  pinMode(6,INPUT);
  
  attachInterrupt(0,button,RISING);

  Serial.begin(9600);
}

void loop() {

if(digitalRead(sw)==HIGH)
{
    if(z==2)
    {   
      prepnuti();
      z=1;
    } 

  den();
  
  }

else
{
  noc();
  z=2;
  }

}

void button()
{
  x=1;
  }


void noc()
{
  digitalWrite(rh, LOW);
  digitalWrite(oh, HIGH);
  digitalWrite(gh, LOW);
  
  digitalWrite(rv, LOW);
  digitalWrite(ov, HIGH);
  digitalWrite(gv, LOW);
  delay(500);

  digitalWrite(oh, LOW);
  digitalWrite(ov, LOW);
  delay(500);
  }

void prepnuti()
{
  digitalWrite(rh, HIGH);
  digitalWrite(rv, HIGH);
  delay (5000);
  digitalWrite(rh, LOW);
  digitalWrite(rv, LOW);
  delay (100);
}

void den()
{
  if(x==1)
    {
      x=0;
      pocet=pocet+1;
   
  
  if (pocet==0)
    {
    d=1000;
      
    }
   else if (pocet==1)
    {
    d=500;
      
    }

    else if (pocet==2)
    {
    d=250;
      
    }

    else if (pocet==3)
    {
    d=1000;
    pocet =0;
    }
 }
    Serial.println(pocet);
  
  digitalWrite(rh, HIGH);
  digitalWrite(oh, LOW);
  digitalWrite(gh, LOW);
  
  digitalWrite(rv, LOW);
  digitalWrite(ov, HIGH);
  digitalWrite(gv, LOW);
  delay(d); 
  //1s
  
  digitalWrite(rh, HIGH);
  digitalWrite(oh, HIGH);
  digitalWrite(gh, LOW);
  
  digitalWrite(rv, HIGH);
  digitalWrite(ov, LOW);
  digitalWrite(gv, LOW);
  delay(d);
  //2s

  digitalWrite(rh, LOW);
  digitalWrite(oh, LOW);
  digitalWrite(gh, HIGH);
  
  digitalWrite(rv, HIGH);
  digitalWrite(ov, LOW);
  digitalWrite(gv, LOW);
  delay(d);
  //3s

  digitalWrite(rh, LOW);
  digitalWrite(oh, LOW);
  digitalWrite(gh, HIGH);
  
  digitalWrite(rv, HIGH);
  digitalWrite(ov, LOW);
  digitalWrite(gv, LOW);
  delay(d);
  //4s

  digitalWrite(rh, LOW);
  digitalWrite(oh, HIGH);
  digitalWrite(gh, LOW);
  
  digitalWrite(rv, HIGH);
  digitalWrite(ov, LOW);
  digitalWrite(gv, LOW);
  delay(d);
  //5s

  digitalWrite(rh, HIGH);
  digitalWrite(oh, LOW);
  digitalWrite(gh, LOW);
  
  digitalWrite(rv, HIGH);
  digitalWrite(ov, HIGH);
  digitalWrite(gv, LOW);
  delay(d);
  //6s

  digitalWrite(rh, HIGH);
  digitalWrite(oh, LOW);
  digitalWrite(gh, LOW);
  
  digitalWrite(rv, LOW);
  digitalWrite(ov, LOW);
  digitalWrite(gv, HIGH);
  delay(d);
  //7s 
}
