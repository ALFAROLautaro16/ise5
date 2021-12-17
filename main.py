from machine import I2C
from machine import Pin
import time
import MPU6050
import math

i2c = I2C(1, scl=Pin(27), sda=Pin(26))
mpu = MPU6050.Accel(i2c)

blueA = Pin(2, Pin.OUT)
greenA = Pin(3, Pin.OUT)
redA = Pin(4, Pin.OUT)

blueG = Pin(6, Pin.OUT)
greenG = Pin(7, Pin.OUT)
redG = Pin(8, Pin.OUT)

while 1:
  msmnt = mpu.get_values()
  aux = msmnt["AcX"]*2/32768
  auy = msmnt["AcY"]*2/32768
  auz = msmnt["AcZ"]*2/32768

  gux = msmnt["GyX"]*250/32768
  guy = msmnt["GyY"]*250/32768
  guz = msmnt["GyZ"]*250/32768

  print("aceleración X: {:.2f}g".format(aux))
  print("aceleración Y: {:.2f}g".format(auy))
  print("aceleración Z: {:.2f}g".format(auz))
  print("Variación Angular X: {:.2f} grado/s".format(gux))
  print("Variación Angular Y: {:.2f} grado/s".format(guy))
  print("Variación Angular Z: {:.2f} grado/s".format(guz))    
  
  if msmnt["AcX"] > 0:
    redA.off()
  else:
    redA.on()
  
  if msmnt["AcY"] > 0:
    greenA.off()
  else:
    greenA.on()
  
  if msmnt["AcZ"] > 0:
    blueA.off()
  else:
    blueA.on()

  if msmnt["GyX"] > 0:
    redG.off()
  else:
    redG.on()
  
  if msmnt["GyY"] > 0:
    greenG.off()
  else:
    greenG.on()
  
  if msmnt["GyZ"] > 0:
    blueG.off()
  else:
    blueG.on()
