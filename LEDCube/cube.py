"""

WARNING:
I don't have a demultiplexer yet, so mutiple rows can be on simultaneously which means twice the number of LEDs per column than was planned

"""


from gpiozero import PWMLED, LED
from time import sleep


ledcols = {
    "one": PWMLED(19),
    "two": PWMLED(16),
    "three": PWMLED(26),
    "four": PWMLED(20),
}#TODO: some better keys would be nice

ledrows = {
    "top" : LED(4),
    "bottom": LED(22),
}

def testIndiv(n = 1)
    for i in range(n):
        for row in ledrows:
            ledrows[row].on()
            for col in ledcols:
                ledcols[col].value = 1
                sleep(0.7)
                ledcols[col].off()
                sleep(0.3)
            ledrows[row].off()

def allOn():
    for col in ledcols:
        ledcols[col].value = 1
    for i in range(200):
        for row in ledrows:
            ledrows[row].on()
            ledrows[row].off()


