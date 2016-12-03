//modes
int MODE_OFF = 0;
int MODE_ON = 1;
int MODE_RAND = 2;
int mode = 2;
//photoresistor input pins
int FotoR1pin = A1;
int FotoR2pin = A2;
//led output pins
int LED1pin = 7;
int LED2pin = 13;
//photoresistor input value
float light1 = 0;
float light2 = 0;
//led output value
float pwd1 = 0;
float pwd2 = 0;
//RAND_MODE values
int tmp1 = 2000;
int tmp2 = 5000;
//button values
int previous = 0;

void setup() {
  pinMode(FotoR1pin,INPUT);
  pinMode(FotoR2pin,INPUT);
  pinMode(8,INPUT);
  pinMode(LED1pin,OUTPUT);
  pinMode(LED2pin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(8)==1){
    if(previous==0){
      if(mode==2){
        mode=0;
      }
      else mode++;
    }
    previous=1;
  }
  else
  {
    previous=0;
  }
  
  if(mode==1){
    on();
  }else if(mode==2){
    ran();
  }
}

void on(){
  light1 = analogRead(FotoR1pin);
  light2 = analogRead(FotoR2pin);
  pwd1 = (light1-0)/1000;
  pwd2 = (light2-0)/1000;
  led(LED2pin, pwd2);
  led(LED1pin, pwd1);
}

void ran(){
    int a1=millis()-tmp1;
    int a2=millis()-tmp2;
    
    if(a1<0){
      if(pwd1==0.9)pwd1=0;
      else pwd1=0.9;
      tmp1+=random(1000,7000);
    }
    if(a2<0){
      if(pwd2==0.9)pwd2=0;
      else pwd2=0.9;
      tmp2+=random(1000,7000);
    }
    
    led(LED2pin, pwd2);
    led(LED1pin, pwd1);
}
void led(int ledPin, float pwd){
  if(pwd!=0)digitalWrite(ledPin, HIGH);
  delayMicroseconds(1000-pwd*1000);
  digitalWrite(ledPin, LOW);
  delayMicroseconds(pwd*1000);
}

void setMode(int varMode){
  mode = varMode;
}
