//Code for testing the CD74HC4067 MUX chip, using this library: https://github.com/waspinator/CD74HC4067

#include <CD74HC4067.h> 

//Creates a new CD74HC4067 object and specifies the control pins used to select the MUX channel to read/write with the common I/O. This is in the order of s0 s1, s2, s3 (from the chip)
CD74HC4067 muxIn(0, 1, 2, 3); 

//set the analog read pin from the common I/O of the MUX
const int commonIn = A0;

void setup() {
  // put your setup code here, to run once:
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);


} //end setup

void loop() {
  // put your main code here, to run repeatedly:


  muxIn.channel(0);
  int channelValue1 = analogRead(commonIn); //set the channelValue variable to the input value
    // print out the value you read:
    Serial.print("channel 1 is: ");
    Serial.println(channelValue1);
       
        delay(500);  // delay in between reads for stability
  muxIn.channel(1);
  int channelValue2 = analogRead(commonIn); //set the channelValue variable to the input value
    // print out the value you read:
    Serial.print("channel 2 is: ");
    Serial.println(channelValue2);


 delay(500);  // delay in between reads for stability

} //end main loop
