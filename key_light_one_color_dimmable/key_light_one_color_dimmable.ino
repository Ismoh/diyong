/**
 * This was tested and working on Arduino Uno R3.
 */

/**
 * Everything related to Input:
 * Input pin (A0-A5) on UnoR3 for reading potentiometer value.
 * Input value of the potentiometer (5V) is between 0 - 1023.
 * https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/
 */
const int potiAnalogInputPin = A0; // A0 - A5
int potiAnalogInputValue = 0; // 0 - 1023

/** 
 * Everything related to LEDs.
 * 980Hz PWM Output on Pin 5 and 6.
 * 490Hz PWM Output on Pin 9, 10, 11.
 * https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/
 */
const int ledPin1_980 = 5;
const int ledPin2_980 = 6;
const int ledPin1_490 = 9;
const int ledPin2_490 = 10;
const int ledPin3_490 = 11;
int ledValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  potiAnalogInputValue = analogRead(potiAnalogInputPin);
  
  Serial.print(potiAnalogInputValue);
  Serial.print(" "); // a space ' ' or  tab '\t' character is printed between the two values.
  ledValue = convertAnalogInputToPwm(potiAnalogInputValue);
  
  analogWrite(ledPin1_980, ledValue);
  analogWrite(ledPin2_980, ledValue);
  analogWrite(ledPin1_490, ledValue);
  analogWrite(ledPin2_490, ledValue);
  analogWrite(ledPin3_490, ledValue);
}

/**
 * This method converts the analog input (0 - 1023) into
 * the appropriate PWM value (0 - 255).
 * In addition it converts PWM to Voltage, because
 * PWM = 255 -> LED off 0V.
 * PWM = 0 -> LED on 5V.
 */
int convertAnalogInputToPwm(float analogInput) {
  //float pwmValue = (255.0 / 1023.0) * analogInput; // 0,249266862170088
  float pwmValue = analogInput / 4;
  Serial.println(pwmValue);
  return 255.0 - pwmValue;
}
