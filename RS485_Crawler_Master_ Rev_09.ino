// LARGE CRAWLER TEST RS485 MINI JOYSTICK ONLY MASTER

//Import needed libraries
// #include <PS2.h> (NOT REQUIRED YET)
#include <SoftwareSerial.h> //Allows the use of more than the standard serial pins 0 + 1 (Not required when using MEGA's)
#include <RS485_protocol.h>
//MEGA Hardware Serial = 9600, 0 (RX) 1 (TX), Serial1 = 38400, 19 (RX) 18 (TX), Serial2 = 19200, 17 (RX) 16 (TX), Serial3 = 4800, 15 (RX) 14 (TX)

// Declare Constant Pin Numbers
Serial (2, 3); // setup pins (Required UNO)
//RX is digital pin 2 (connect to TX of other device)
//TX is digital pin 3 (connect to RX of other device)

const int ledPin =  13; // Pin Number for Built in Arduino LED to monitor tranmit and receive.
const int EnTxRxPin = 6; // Use this to pull pin 2 LOW reciever(RX) HIGH Transmit (TX) for Half Duplex.
int joyVert = A0; //Declare Joystick Input Vertical  
int joyHorz = A1; //Declare Joystick Input Horizontal

// Motor Speed Value - Start at zero
int Motorspeed = 0;
int MotorspeedB = 0;
int MotorspeedF = 0;
int MotorspeedL = 0;
int MotorspeedR = 0;

int data;

// Joystick Values - Start at 512 (middle position)
int joyposVert = 512;
int joyposHorz = 512;

char (joyposVertB);
char (joyposVertF);
char (joyposHorzL);
char (joyposHorzR);
char (MotorspeedHigh);
char (MotorspeedLow);
char (MotorspeedBuzz);

void setup()
  {
    Serial.begin(9600);              //Serial on 0 + 1 Baud 9600, 
    Serial2.begin(19200);            //Serial2 on 19200, (17 (RX) + 16 (TX) MEGA)
    Serial.setTimeout(100); 
    pinMode(ledPin, OUTPUT);
    pinMode(EnTxRxPin, OUTPUT);
    RS485Serial.begin(4800);// Start the software serial port, to another device & set the data rate 
    digitalWrite(ledPin, HIGH);      //Starts with LED off
    digitalWrite(EnTxRxPin, LOW);   //Set low to receive RS485
  }

void loop()
  {
   joyposVert= analogRead(joyVert);     // Read the Joystick Vert
     
     if  (joyposVert < 477 )            //This is Backward
      {
      digitalWrite(ledPin, HIGH);       //Switch L LED on
      digitalWrite(EnTxRxPin, HIGH);    //Transmit Begin
      delay (5);
      Serial.print("joyposVertB: ");    //Send joy position Backwards
      Serial2.print("joyposVertB: ");    //Send joy position Backwards to SLAVE
      MotorspeedB = map(joyposVert, 477, 0, 0, 255);
      Serial.println(MotorspeedB);      //Send joy analogue reading
      Serial2.println(MotorspeedB);     //Send joy motorspeed to SLAVE
      Serial.flush ();                  //wait for all data to be sent
      digitalWrite(EnTxRxPin, LOW);     //Transmit End
      }
     else if (joyposVert > 577)         //This is Forward
      {
        digitalWrite(ledPin, HIGH);     //Switch L LED on
        digitalWrite(EnTxRxPin, HIGH);  //Transmit Begin
        delay (5);
        Serial.print("joyposVertF: ");  //Send joy position Forward
        Serial2.print("joyposVertF: ");  //Send joy position Forward to SLAVE
        MotorspeedF = map(joyposVert, 577, 1023, 0, 255);
        Serial.println(MotorspeedF);        //Send joy analogue reading
        Serial2.println(MotorspeedF);       //Send joy motorspeed to SLAVE
        Serial.flush ();                //wait for all data to be sent
        digitalWrite(EnTxRxPin, LOW);   //Transmit End
      } 
//    else
//        {
//          Motorspeed = 0;               //This is Stopped
//          Serial.println("MotorspeedS"); // Print to serial monitor port on SLAVE
//          Serial.flush ();               // Wait for all data to be recieved
//         }   
    joyposHorz = analogRead(joyHorz);    // Now do the steering - Read The Horizontal Axis
      
      if (joyposHorz < 477)             //This is Move Left
       {
         digitalWrite(ledPin, HIGH);     //Switch L LED on
         digitalWrite(EnTxRxPin, HIGH);  //Transmit Begins
         delay (5);
         Serial.print("joyposHorzL: ");  //Send joy Left
         Serial2.print("joyposHorzL: ");  //Send joy Left to SLAVE
         MotorspeedL = map(joyposHorz, 477, 0, 0, 255);
         Serial.println(MotorspeedL);        //Send joy analogue reading
         Serial2.println(MotorspeedL);       //Send joy motorspeed to SLAVE
         Serial.flush ();                //wait for all data to be sent
         digitalWrite(EnTxRxPin, LOW);   //Transmit End
        }
       else if (joyposHorz > 547)           //This is Move Right
        {
          digitalWrite(ledPin, HIGH);     //Switch L LED on
          digitalWrite(EnTxRxPin, HIGH);  //Transmit Begins
          delay (5);
          Serial.print("joyposHorzR: ");  //Sends joy Right
          Serial2.print("joyposHorzR: ");  //Sends joy Right to SLAVE
          MotorspeedR = map(joyposHorz, 547, 1023, 0, 255);
          Serial.println(MotorspeedR);    //Send Motorspeed reading
          Serial2.println(MotorspeedR);    //Send Motorspeed reading to SLAVE
          Serial.flush ();                //wait for all data to be sent
          digitalWrite(EnTxRxPin, LOW);
        }
//    else
//        {
//          Motorspeed = 0;               //This is Stopped
//          Serial.println("MotorspeedS"); // Print to serial monitor port on SLAVE
//          Serial.flush ();               // Wait for all data to be recieved
//         }     

//if (Motorspeed < 10)  // Adjust to prevent "buzzing" at very low speed
//       {
//         Motorspeed = 0;
//           Serial.println("MotorspeedBuzz");
//        }
    
//     if (Motorspeed > 255)  // Don't exceed range of 0-255 for motor speeds
//        {
//          Motorspeed = 255;
//          Serial.println("MotorspeedHigh");
//        }
//     if (Motorspeed < 0)
//        {
//          Motorspeed = 0;
//          Serial.print("MotorspeedLow"); 
//        }

void function (int data); //Purge Data
      { 
      if (data>500)
      digitalWrite(ledPin, HIGH); 
      else 
      digitalWrite(ledPin, LOW); 
      }
 }
  
