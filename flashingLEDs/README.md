There wasn't really a point to this, I had some LEDs and a bit of time so had some fun

Releasing the button makes the lights flash in a new pattern (though only 2 are programmed).
Issue: button relies on cycle of the loop() function which can be long
can solve by either setting it as a hardware interrupt or by using FreeRTOS

Potentiometer controls speed of on/off cycles of LEDs. A greater analogRead value leads to longer cycle, lower value leads to shorter cycles.
