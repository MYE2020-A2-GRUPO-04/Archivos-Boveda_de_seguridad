#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//puertos seriales para la cominicacion con FPM10A
SoftwareSerial mySerial(18, 19);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

//puertos seriales para la comunicacion con HC06
SoftwareSerial hc06(16,17);
String btData;

//puertos seriales para la comunicacion con ELECHOUSEVR
VR myVR(15,14);
uint8_t records[3]; // save record
uint8_t buf[64];
#define Usuario1 (0)
#define Usuario2 (1)
#define Usuario3 (2)

//configuración para comunicacion I2C con lcd
LiquidCrystal_I2C lcd(0x3F,16,2);

//Configuracion KeyPad
char* pass1="5896";
char* pass2="3652";
char* pass3="4298";
int pos1=0;
int pos2=0;
int pos3=0;
const byte ROWS=4;
const byte COLS=3;

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
//Cambiar la configuracion de los pines
byte rowPins[ROWS] = {31, 33, 35, 37};
byte colPins[COLS] = {39, 41, 43};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//pin de salida para el TRIAC-Cerradura
int pinCerradura = 8;
bool var2fa= false;

void setup() {
  // Inicio de la comunicacion con FPM10A
  finger.begin(57600);
  //Inicio de la comunicacion con HC06
  hc06.begin(14400);
  //Inicio de la comunicacion con ELECHOUSEVR
  myVR.begin(19200);
  //Inicio de la comunicacion con LCD
  lcd.init();

  //FPM10A settings
  delay(5);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  //ELECHOUSE settings
  if (myVR.load((uint8_t)Usuario1) >= 0) {
    Serial.println("Usuario1 loaded");
  }

  if (myVR.load((uint8_t)Usuario2) >= 0) {
    Serial.println("Usuario2 loaded");
  }

  if (myVR.load((uint8_t)Usuario3) >= 0) {
    Serial.println("Usuario3 loaded");
  }

  //LCD settings
  lcd.backlight();
  
  Serial.begin(9600);
  pinMode(pinCerradura, OUTPUT);
  digitalWrite(pinCerradura, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Asegurado");
}

void loop() {
  char key = keypad.getKey();
  if (key){
    if (key == '*' || key == '#')
    {
      pos1 = 0;
      pos2 = 0;
      pos3 = 0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Asegurado");
    }
    if (key == pass1[pos1])
    {
      pos1 ++;
    }
    else
    {
      pos1 = 0;
    }
    if (key == pass2[pos2])
    {
      pos2 ++;
    }
    else
    {
      pos2 = 0;
    }
    if (key == pass3[pos3])
    {
      pos3 ++;
    }
    else
    {
      pos3 = 0;
    }
    if(pos1==0 && pos2==0 && pos3==0){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Asegurado");
    }
    if(pos1==1 || pos2==1 || pos3==1){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(key);
    }
    if(pos1==2 || pos2==2 || pos3==2){
      lcd.setCursor(1,0);
      lcd.print(key);
    }
    if(pos1==3 || pos2==3 || pos3==3){
      lcd.setCursor(2,0);
      lcd.print(key);
    }
    if (pos1 == 4 || pos2 == 4 || pos3 == 4)
    {
      lcd.setCursor(0,0);
      lcd.print("Esperando");
      lcd.setCursor(0,1);
      lcd.print("2FA...");
      digitalWrite(pinCerradura,LOW);
      var2fa = true;
    }
    else
    {
      digitalWrite(pinCerradura,LOW);
    }
  }
  
  if(var2fa){
    if(celular() || huella() || voz()){
      lcd.setCursor(0,0);
      lcd.print("Correcto    ");
      lcd.setCursor(0,1);
      lcd.print("Abierto    ");
      digitalWrite(pinCerradura,HIGH);
      delay(5000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Asegurado");
      digitalWrite(pinCerradura,LOW);
      pos1 = 0;
      pos2 = 0;
      pos3 = 0;
      var2fa = false;
    }
  }
}

boolean celular(){
  if (hc06.available()){
    btData=hc06.readString();
    if(btData.equals("OK")){
      return true;
    }else{
      return false;
    }
  }else{
    return false;
  }
}

boolean huella(){
  uint8_t p = finger.getImage();

  if(p == FINGERPRINT_OK) return true;
  return false;
}

boolean voz(){
  int ret;
  ret = myVR.recognize(buf, 50);
  if(ret > 0){
    switch(buf[1]){
      case Usuario1:
        return true;
      case Usuario2:
        return true;
      case Usuario3:
        return true;
      default:
        return false;
    }
    printVR(buf);
  }else{
    return false;
  }
}

void printSignature(uint8_t *buf, int len)
{
  int i;
  for(i=0; i<len; i++){
    if(buf[i]>0x19 && buf[i]<0x7F){
      Serial.write(buf[i]);
    }
    else{
      Serial.print("[");
      Serial.print(buf[i], HEX);
      Serial.print("]");
    }
  }
}

void printVR(uint8_t *buf)
{
  Serial.println("VR Index\tGroup\tRecordNum\tSignature");

  Serial.print(buf[2], DEC);
  Serial.print("\t\t");

  if(buf[0] == 0xFF){
    Serial.print("NONE");
  }
  else if(buf[0]&0x80){
    Serial.print("UG ");
    Serial.print(buf[0]&(~0x80), DEC);
  }
  else{
    Serial.print("SG ");
    Serial.print(buf[0], DEC);
  }
  Serial.print("\t");

  Serial.print(buf[1], DEC);
  Serial.print("\t\t");
  if(buf[3]>0){
    printSignature(buf+4, buf[3]);
  }
  else{
    Serial.print("NONE");
  }
  Serial.println("\r\n");
}
