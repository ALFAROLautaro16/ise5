from machine import Pin
import time
from machine import ADC, Pin
from math import log
p2 = Pin(2, Pin.OUT)
p8 = Pin(8, Pin.OUT)
adc1 = ADC(Pin(28))
adc2 = ADC(Pin(27))

while(1):
 print("el valor de adc1 leido es:{}".format(adc1.read_u16()))
 print("el valor de adc2 leido es:{}".format(adc2.read_u16()))
 Vrt1 = (adc1.read_u16()*3.3)/65535
 print("el valor de tension 1 calculado es:{:.2f} V".format(Vrt1))
 Rt1 = (Vrt1*10000)/(3.3-Vrt1)
 print("el valor de resistencia 1 calculado es:{:.2E} Ω".format(Rt1))
 TrK1 = (298*3950)/(298*log(Rt1/10000)+3950)
 TrC1 = TrK1-273.15
 TrC2 = (adc2.read_u16()*35)/65535
 print("el valor de temperatura 1 calculado es:{:.2f} C°".format(TrC1))
 print("el valor de temperatura 2 calculado es:{:.2f} C°".format(TrC2))
 if(TrC1>TrC2):
  p8.value(1)
  time.sleep(10)
  p8.value(0)
 else:
  p2.value(1)
  time.sleep(10)
  p2.value(0)
 p2.value(0)
 p8.value(0)