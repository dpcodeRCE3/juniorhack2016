#include <SPI.h>
#include <Ethernet.h>
 
// zde si upravte podle sebe
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
 
// IP adresa
IPAddress ip(192,168,0, 150);
// port
EthernetServer server(80);

int led = 13;

void setup() {
 // inicalizace sítě
  Ethernet.begin(mac, ip);
  // inicializace serveru
  server.begin();
  
  pinMode(led, OUTPUT);
}

void loop() {
  
  digitalWrite(led, HIGH); 
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);  
  
  /*
  EthernetClient client = server.available();
  String buffer = "";
  while (client.connected()) {
    if (client.available()) {
         char c = client.read();
         buffer = buffer + c;
         if (c == '\n') {
          if(buffer.indexOf("params")>=0){
          
          }
          // TO DO SEND RESPONSE
          client.stop();
         }
    }
  }
  */
}
