# https://core-electronics.com.au/tutorials/using-usb-and-bluetooth-controllers-with-python.html

# Find the directory representing the games controller
controllerDir = "event0"


#import evdev
from evdev import InputDevice, categorize, ecodes

#creates object 'gamepad' to store the data
gamepad = InputDevice('/dev/input/'+controllerDir)


def printButtons():
    ### Printing the controller output
        
    #prints out device info at start
    print(gamepad)
    #evdev takes care of polling the controller in a loop
    for event in gamepad.read_loop():
        print(categorize(event))

def printEventKey():
    #prints out device info at start
    print(gamepad)

    #evdev takes care of polling the controller in a loop
    for event in gamepad.read_loop():
        #filters by event type
        if event.type == ecodes.EV_KEY:
            print(event)

def rockCandyQuickTestPrint():
    print(gamepad)
    ybtn = 304
    bbtn = 305
    abtn = 306
    xbtn = 307

    for event in gamepad.read_loop():
        if event.type == ecodes.EV_KEY: 
            if event.value == 1: # ie btn down
                if event.code == ybtn:
                    print("Y")
                elif event.code == bbtn:
                    print("B")
                elif event.code == abtn:
                    print("A")
                elif event.code == xbtn:
                    print("X")


from gpiozero import LED

def rockCandyLEDs():
    print(gamepad)
    ybtn = 304
    bbtn = 305
    abtn = 306
    xbtn = 307

    ledUp = LED(21)
    ledLeft = LED(6)
    ledDown = LED(16)
    ledRight = LED(26)

    for event in gamepad.read_loop():
        if event.code == ybtn:
            if event.value == 1:
                ledLeft.on()
            elif event.value == 0:
                ledLeft.off()
        if event.code == bbtn:
            if event.value == 1:
                ledDown.on()
            elif event.value == 0:
                ledDown.off()
        if event.code == abtn:
            if event.value == 1:
                ledRight.on()
            elif event.value == 0:
                ledRight.off()
        if event.code == xbtn:
            if event.value == 1:
                ledUp.on()
            elif event.value == 0:
                ledUp.off()


if __name__ == "__main__":
    print("0 for print all button presses")
    print("1 for print EV_KEY button presses")
    print("2 for ybax test for Rock Candy Controller")
    print("3 for rock candy controller and LEDs")
    choice = input()
    if choice == "0":
        printButtons()
    elif choice == "1": 
        printEventKey()
    elif choice == "2":
        rockCandyQuickTestPrint()