Arduino-projects
================

Arduino Projects
 /*Name:Jobanpreet Singh
  Final Project COMP 1045
  project- Thermometer with display of temperature in 3 units- celsius, kelvin and fahrenheit
*/

#include <LiquidCrystal.h>
/*
  The circuit:
 * LCD RS pin to digital pin 8
 * LCD Enable pin to digital pin 9
 * LCD D4 pin to digital pin 4
 * LCD D5 pin to digital pin 5
 * LCD D6 pin to digital pin 6
 * LCD D7 pin to digital pin 7
 * LCD R/W pin to ground
*/



LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int temp;
int celsius;
int kelvin;
int fahrenheit;

int temp_sensor = 1;              
                    
// The setup() method runs once, when the sketch starts
void setup ()
{
  lcd.begin(16, 2);                   // set the lcd dimension
  lcd.clear();                        // LCD screen clear
  lcd.print(" Final Project");        // display the text
  lcd.setCursor(0,1);                 // set lcd.setCursor (column,row) 
  lcd.print(" Thermometer  "); 
  delay(3000); 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("By-           ");            // C:Celsius  K:kelvin
  lcd.setCursor(0,1);        
  lcd.print("Jobanpreet S. ");            // F:Fahrenheit
  delay(3000);                        // delay for 3000ms
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("C:      K:");            // C:Celsius  K:kelvin
  lcd.setCursor(0,1);        
  lcd.print("F:       ");            // F:Fahrenheit 
}



void loop()
{
  temp = analogRead(temp_sensor);    //get analog value
  
  celsius = temp/2;                    //refer to LM35 datasheet, celsius can get by devide by 2.
  lcd.setCursor(2, 0);                 // set cursor position
  lcd.print(celsius,DEC);              // print the tempreture value in DECIMAL
  
  kelvin = celsius + 273;              // kelvin = celsius + 273.15
  lcd.setCursor(10, 0);
  lcd.print(kelvin,DEC);
  
  fahrenheit = (celsius*18)+320;      // fehrenheit = (celsius*1.8)+32
  fahrenheit = fahrenheit/10;
  lcd.setCursor(2, 1);
  lcd.print(fahrenheit,DEC);


  
  delay(1000);               // the purpose of delay is to delay the update tempreture value for not too fast
  temp_value_clear();        // clear the tempreture value
}
  

void temp_value_clear(void)
{
  unsigned char i;
  for(i=0 ; i<2 ; i++)              
    {
    lcd.setCursor(2,i);            // set cursor position
    lcd.print("      ");           
    }
    
  for(i=0 ; i<2 ; i++)
    {
    lcd.setCursor(10,i);          // set cursor position
    lcd.print("      ");
    }
}
