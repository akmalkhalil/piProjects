# Linear LED Clock

Clock can be circular, but linear is easier to put onto a circuit board.

Clock will give the rough time, not the exact minute.


## Idea
Have 12 LEDs in a column to represent the hour.
At 12 the 0th LED turns on.
At 1 the 1st LED.
etc.

Parallel to this will be 12 more LEDs to represent the minutes.
There will be a 5 minute time gap between each LED.
On the hour, the 0th LED will be lit.
At 5 past, the 1st.
At 10 past, the 2nd.
etc.

LEDs will fade to represent the in between minutes.
At 5 past the 1st LED is lit at 100% all, other minute LEDs are off.
At 6 past the 1st LED is at 80%, the 2nd LED at 20%.
at 7 minutes past the LEDs are at 60% and 40%, respectively.
etc.


## Plan
 - I'll prototype in pygame first.
 - Test having 12 LEDs in a line with a common line with a resistor on that line if only one LED is active at a time.
 - Once happy purchase
   - Small solderboard
   - Set of LEDs
   - microcontroller (maybe just an ATMega chip and quartz crystal?)
 - Designate day for tinkering
 - Have fun!