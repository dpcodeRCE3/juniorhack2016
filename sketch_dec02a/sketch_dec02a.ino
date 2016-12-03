int ledPin = 13;
int fotoPin = A0;
float pct = 0; //num from 0 to 1
float light = 0; //light sensor 0 (light) to 500 (dark)
boolean inc = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  //light = analogRead(fotoPin);
  Serial.println(analogRead(A1)); //nefunkční kabílky?
  //if(light>550){light=550;}
  //pct = light/550;
  //ledOn(pct);
  //Serial.print(F(" | "));
  //Serial.println(pct);
}

void ledOn(float pwd){
  digitalWrite(13, HIGH);
  delayMicroseconds(pwd*1500); // Approximately 10% duty cycle @ 1KHz
  digitalWrite(13, LOW);
  delayMicroseconds(1500-pwd*1500);
}
