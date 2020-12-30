# https://www.ti.com/lit/ds/symlink/cd4051b.pdf?ts=1607878226758
# CD4051B

from gpiozero import PWMLED, LED
from time import sleep
controls = {"A":LED(4), "B":LED(17), "C":LED(22)}
leds = ["","A","B","AB","C","AC","BC","ABC"]
signal = PWMLED(18)

def setLED(i, on):# this should be encapsulated into a class with that leds array
    global leds
    for c in leds[i]:
        if on: # if in class we could have a var to track which are on, then turn them off every time this method was called
            controls[c].on()
        else: 
            controls[c].off()
#TODO: can I overload this with first param being int or str

def setAll(n=1000):
    global leds
    for k in range(n):
        for i in range(len(leds)):
            setLED((i-1)%len(leds),False)
            setLED(i, True)
    setLED(7, False)

# @params: time the LED is on/off for
def blinkRun(tOn=1, tOff=0):
    for i in range(len(leds)):
        setLED(i, True)
        sleep(tOn)
        setLED(i,False)
        sleep(tOff)
# TODO: "off" state is 0th LED on because that's what ABC=000 translates to, we need to turn the signal line off but I was avoiding doing that in these functions and letting that be independant. guess can't do that any more


