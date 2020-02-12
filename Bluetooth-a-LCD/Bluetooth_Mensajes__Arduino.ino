#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6, 5, 4, 3, 2);
int ledPin = 13; //Asignamos la palabra ledPin como una variable tipo entera
String readString; //Asignamos la palabra readString a una variable tipo cadena


void setup()
{
  Serial.begin(9600); //inicializamos la comunicacion serial
  pinMode(ledPin, OUTPUT); //Se determina que el pin 13 va a ser usado como salida
  lcd.begin(16, 2);
  lcd.clear();
  lcd.noAutoscroll();
  lcd.print("Esperando SMS");
  delay( 200 );
}

void loop()
{
  while (Serial.available())
  { //Se verifica la disponibilidad del puero serial 
    delay(3);                  // a traves de un loop
    char c = Serial.read();  // Se leen los caracteres que ingresan por el puerto
    readString += c;         //se acumulan cada uno de los caracteres en readString
  }
  if (readString.length() >0)
  { //Se verifica que la variable contenga informacion
    lcd.clear();
    Serial.println(readString);  //se envia lo que tenga la variable
    lcd.print(readString);
    if (readString == "On")     //se compara si la palabra que llega es "on"
    {
      digitalWrite(ledPin, HIGH); //Si es "on" se enciende el led del pin 13
    }
    if (readString == "Off")  // Se compara si la palabra que llega es "off"
    {
      digitalWrite(ledPin, LOW); //si es "off" se apaga el led del pin 13
    }
    readString=""; // Se limpia la variable 
  } 
}
