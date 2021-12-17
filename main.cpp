#include "libs/LCD.h"
#include "libs/DHT.h"

int main(void) {

    LCD lcd(2, 3, 4, 5, 6, 7);
    DHT dht(8, DHT11);

    double temp, hum;

    while (1) {

        DHT_Status_t status = dht.read(&temp ,&hum);

        if(status == DHT_Ok){
         
         lcd.clear();
         lcd.print("hum: ");
         lcd.print(hum);
         lcd.print(" %");

         lcd.setXY(1, 2);
         lcd.print("T: ");
         lcd.print(temp);
         lcd.print(" C");

        }
        else if(status == DHT_Error_Humidity){

         lcd.clear();
         lcd.print("Error_Hum ");

        }
        else if(status == DHT_Error_Temperature){

         lcd.clear();
         lcd.print("Error_Temp ");

        }
        else if(status == DHT_Error_Checksum){

         lcd.clear();
         lcd.print("Error_sum ");

        }
        else{

         lcd.clear();
         lcd.print("Error_Time ");

        }

    }

    return 0;
}