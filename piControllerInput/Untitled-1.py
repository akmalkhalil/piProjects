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


if __name__ == "__main__":
    print("0 for print all button presses")
    print("1 for print EV_KEY button presses")
    print("2 for ybax test for Rock Candy Controller")
