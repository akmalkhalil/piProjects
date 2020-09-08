# https://dronebotworkshop.com

# WARNING: be careful connecting together 5v (arduino) and 3.3V (pi) devices!!
# I2C pronounced I squared C, sometimes 2 written as superscript
# I2C = Inter-Intergrated Circuit Bus
"""
For I2C need 3 pins
SDA on pin 03 (GPIO 02)
SCL on pin 04 (GPIO 04)
Ground
"""


from smbus import SMBus
#System Management Bus library is the library used for I2C

ardAddr = 0x8 # The address of target arduino
bus = SMBus(1) # indicates /dev/i2c-1. NOTE: must be activated in raspi-config

print("Enter 1 for on or 0 for OFF")

while True:
  ledstate = input(">>   ")
  if ledstate == "1":
    bus.write_byte(ardAddr, 0x1) # Send byte 0x1 to arduino
    print("sending 1 to arudino\n")
  elif ledstate == "0":
    bus.write_byte(ardAddr, 0x0) # Send byte 0x0 to arduino
    print("sending 0 to arudino\n")
  elif ledstate == "q":
    quit()
