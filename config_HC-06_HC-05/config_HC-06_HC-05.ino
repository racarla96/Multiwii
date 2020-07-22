#include <SoftwareSerial.h>   // Include SoftwareSerial Library 
SoftwareSerial BTSerial(10,11);    // Define pins RX and TX of arduino to connect with the serial bluetooth pins

#define BAUDRATE_0 9600
#define BAUDRATE_1 115200
#define BAUDRATE_2 38400
#define BAUDRATE BAUDRATE_1

// Remind to cross the RX with TX pins
// HC-05/06 TX --- Arduino Pin 10 (soft RX)
// HC-05/06 RX --- Arduino Pin 11 (soft TX) 
// HC-05 Key   --- Arduino Pin 9 

// Useful commands for HC-05
//    To return HC-05 to mfg. default settings: "AT+ORGL"
//    To get version of your HC-05 enter: "AT+VERSION?"
//    To change device name from the default HC-05 to let's say MYBLUE enter: "AT+NAME=MYBLUE"
//    To change default security code from 1234 to 2987 enter: "AT+PSWD=2987"
//    To change HC-05 baud rate from default 9600 to 115200, 1 stop bit, 0 parity enter: "AT+UART=115200,1,0" 

// Useful commands for HC-06
// AT+NAMEXXXXX to change the name of the board
// AT+BAUD8 to change the baud rate to 115,200 for the MWC
// AT+PIN2134 to change the pin number for pairing
 
void setup()
{
  BTSerial.begin(BAUDRATE);       // Initialize serial bluetooth
  Serial.begin(BAUDRATE);   // Initialize serial usb
  pinMode(9, OUTPUT);       // this pin will pull the HC-05 en or key pin HIGH to switch module to AT mode
  digitalWrite(9, HIGH);
}
 
void loop()
{
  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());
}
