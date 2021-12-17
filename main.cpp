#include <math.h>
#include "libs/analog.h"
#include "libs/LCD.h"
#include "avr/io.h"

uint32_t ad0 = 0;
float tension = 0;
float temp = 0;
float res = 0;
uint32_t r1 = 10000;
float vcc = 5;


LCD lcd(2, 3, 4, 5, 6, 7);

int main(void) {
    
    analogRef(AREF);     

    lcd.clear();

    const uint32_t B = 3900;   // El beta de la formula, en grados Kelvin
    const uint32_t T0 = 298;    // T0 que es 25 °C pero lo ponemos en Kelvin 298
    const uint32_t R = 10000;    // R(T0)
    
    while(1) {

        ad0 = analogRead(0);

        tension =  ad0 * (vcc / 1023);
        
        res = tension * r1 / (vcc - tension);

        temp = ((T0 * B) / ((T0 * log(res / R)) + B)) - 273.15;
        
        lcd.setXY(1, 1);
        lcd.print("R: ");
        lcd.print(res);
        lcd.print(" Ohm");

        lcd.setXY(1, 2);
        lcd.print("T: ");
        lcd.print(temp);
        lcd.print(" C");

        _delay_ms(1000);

        lcd.clear();
    }

    return 0;
}
