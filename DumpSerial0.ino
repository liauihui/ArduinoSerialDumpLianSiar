#ifndef SS_SOFTWARE_SERIAL
#define SS_SOFTWARE_SERIAL
#include <SoftwareSerial.h>
#endif

void setup() {
  Serial.begin(9600);
  Serial.println("baud:9600");
  Serial.println("CHR HEX BIN OCT DEC");
}

//--------------------------------------------------------
void loop() {
  
  String str = "";

  while ( Serial.available() > 0 ) {

    int iByte = Serial.read();

    if ( 0 == bitRead(iByte, 7) ) {
      Serial.print(" ");
    }

    Serial.print("[");
    Serial.print(char(iByte));
    Serial.print("]");

    Serial.print(" ");

    Serial.print(iByte, HEX);
    Serial.print(" ");

    str = String(iByte, BIN);
    while ( str.length() < 8 ) {
      str = String("0") + str;
    }
    Serial.print(str);

    Serial.print(" ");

    str = String(iByte, OCT);
    while ( str.length() < 3 ) {
      str = String(" ") + str;
    }
    Serial.print(str);
    Serial.print(" ");

    str = String(iByte, DEC);
    while ( str.length() < 3 ) {
      str = String(" ") + str;
    }
    Serial.print(str);
    Serial.print(" ");

    
    Serial.print("-----");
   
    Serial.println(""); // newLine

    
  }//WHILE

  delay(1000);

}//LOOP
