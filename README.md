# Temperature-Band-Indicator

**ARDUINO** consists of both a physical programmable circuit board (often referred to as a microcontroller) and a piece of software, or IDE (Integrated Development Environment) that runs on your computer, used to write and upload computer code to the physical board.

The Major Thing we used for getting Input, that is knowing the temperature was **NTC(Negative Temperature Coefficient).**
The NTC thermistor is widely used in many applications for a variety of purposes where a negative temperature coefficient is required. Being an NTC thermistor the resistance falls as the temperature increases, making it particularly useful in a number of different areas.

**NTC THERMISTOR BASICS**

As the name indicates, the NTC thermistor provides a reduction in resistance for an increase in thermistor body temperature.
The change in body temperature of the NTC thermistor can be brought about in two main ways:

**Raising external temperature.** Raising the temperature of the external fluid, possibly air in which the NTC thermistor is placed will cause the body of the device to change its temperature and hence its resistance will change. To make thermistors responsive when used in this way, they must be in a position where the temperature of the surroundings can be detected as well as possible. Good thermal conduction to the thermistor is needed, either by placing it in a flow of the fluid, e.g. air, or by ensuring it is thermally bonded to the chassis or other mechanical item on which the temperature needs to be sensed.

**Passage of current through the device:**   Passing current through any resistor including an NTC thermistor will cause heat to be dissipated (Watts = Volts x Amps). This will cause the temperature to rise.Typically NTC thermistors exhibit a change in resistance of between about **-3%/°C to -6%°C at 25°C.** The actual relationship follows a curve that is approximately exponential, with much higher changes in resistance at lower temperatures, and lowering considerably at higher temperatures.

NTC thermistors are widely used within the electronics industry for many basic temperature sensing uses.
The best approximation known to date is the **Steinhart-Hart formula,** published in 1968:
![alt text](https://github.com/aditi-mishra/Temperature-Band-Indicator/blob/master/Steinhart.png)

Where ln R is the natural logarithm of the resistance at temperature T in Kelvin, and A, B and C are coefficients derived from experimental measurements.The Steinhart-Hart formula is typically accurate to around ±0.15°C over the range of -50°C to +150°C, which is plenty for most applications. 

**WORKING OF The Code And Project**
-NTC takes the temperature from the surrounding which is an analog value. On pressing the switch First time, first  DP will glow of seven segment. This DP indicates that we are showing the Analog value. After the indication Of DP, the resultant value will be displayed on the SSD. Now, Using Steinhart Equation, this analog value is converted into Degree, Celsius and fahreinheit.The degree, celsius and fahreinheit value are displayed on Seven Segment Display after being Indicated by First, Second and Third DP respectively.

The corresponding RGB LED is glown according to the Temperature value obtained. We set a particular range for each LED, and LED belonging to that range  will glow. 
