#include <math.h>
#include "avr/io.h"
#include "libs/analog.h"
#include "libs/LCD.h"
#include "libs/bmp180.h"

float P = 123;
uint8_t llave = 8;
int estadopin = 0;      // Estado de una entrada de los botones

#define pinPa      8
#define pinhPa     9
#define pinkPa     10
#define pinatm     11
#define pinmmHg    12
#define pinBar     13
#define pinPSI     14
#define pinTorr    15

int main(void) {

    BMP180 bmp;                 // Inicializacion del sensor
    LCD lcd(2, 3, 4, 5, 6, 7);  // Inicializacion del display
    analogRef(AREF);            // Tomo la referencia interna del ADC 

    lcd.clear();

    pinMode(pinTorr, INPUT);

    while(1) {

        uint8_t status = bmp.read();    // Hago una lectura completa y guardo el estado
        if (status == bmp.status_ok) {  // Si no hubo error en la lectura, prosigo

        if (digitalRead(pinPa) > 0){
        llave = 0;
        }
        else if (digitalRead(pinhPa) > 0){
        llave = 1;
        }
        else if (digitalRead(pinkPa) > 0){
        llave = 2;
        }
        else if (digitalRead(pinatm) > 0){
        llave = 3;
        }
        else if (digitalRead(pinmmHg) > 0){
        llave = 4;
        }
        else if (digitalRead(pinBar) > 0){
        llave = 5;
        }
        else if (digitalRead(pinPSI) > 0){
        llave = 6;
        }
        else if (digitalRead(pinTorr) > 0){
        llave = 7;
        }
        else{
        llave = 8;   
        }

        P = bmp.getPressure(llave);
        }
        
        lcd.clear();
        lcd.setXY(1, 1);
        lcd.print("P=");

        

        switch (llave) {
            case 0:
                lcd.print(P);
                lcd.print(" Pa");
                break;
            case 1:
                lcd.print(P);
                lcd.print(" hPa");
                break;
            case 2:
                lcd.print(P);
                lcd.print(" kPa");
                break;
            case 3:
                lcd.print(P);
                lcd.print(" atm");
                break;
            case 4:
                lcd.print(P);
                lcd.print(" mmHg");
                break;
            case 5:
                lcd.print(P);
                lcd.print(" Bar");
                break;
            case 6:
                lcd.print(P);
                lcd.print(" PSI");
                break;
            case 7:
                lcd.print(P);
                lcd.print(" Torr");
                break;
            case 8:
                lcd.clear();
                break;
        }

        _delay_ms(1000);

        lcd.clear();

        

    }

    return 0;
}

