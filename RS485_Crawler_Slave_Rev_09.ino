// LARGE CRAWLER TEST RS485 MINI JOYSTICK ONLY SLAVE

// Import libraries
//#include <SoftwareSerial.h> allows the use of more than the standard serial pins 0 + 1 (Not required when using MEGA's
#include <RS485_protocol.h>

// Declare Constant Pin Numbers
const int ledPin =  13; // Pin Number for Built in Arduino LED to monitor tranmit and receive.
const int EnTxRxPin = 6; // Use this to pull pin 2 LOW reciever(RX) HIGH Transmit (TX) for Half Duplex.
// Joystick Input (MASTER CODE ONLY)
//int joyVert = A0; // Vertical  
//int joyHorz = A1; // Horizontal

// Declare Variables
// Motor A (Left Motor)
int GNDA = 7; // Motor controller GND (Black wire)
int SVA = 9; // Motor controller SV (white wire)
int FRA = 8; // Motor controller F/R (red wire)

// Motor B (Right Motor)
int GNDB = 5; // Motor controller GND (Black wire)
int SVB = 3; // Motor controller SV (white wire)
int FRB = 4; // Motor controller F/R (red wire)

int data;

// Motor Speed Value - Start at zero
int Motorspeed = 0;
int MotorspeedB;
int MotorspeedF;
int MotorspeedL;
int MotorspeedR;
int MotorspeedHigh;
int MotorspeedLow;
int MotorspeedBuzz;

// Joystick Values
int joyposVert = 512;
int joyposHorz = 512;

char (joyposVertB);
char (joyposVertF);
char (joyposHorzL);
char (joyposHorzR);

void setup()   
{
  Serial.begin(9600); Serial2.begin(19200);             //Serial on 0 + 1 Baud 9600, Serial2 on 19200, 17 (RX) 16 (TX)
  Serial.setTimeout(100); 
  pinMode(ledPin, OUTPUT);
  pinMode(EnTxRxPin, OUTPUT);
  digitalWrite(ledPin, HIGH);                          //Starts with LED off
  digitalWrite(EnTxRxPin, LOW);                        //Set low to receive RS485

  // Set all the motor control pins to outputs
  pinMode(GNDA, OUTPUT); // Motor controller A GND (Left Motor - Black wire)
  pinMode(GNDB, OUTPUT); // Motor controller B GND (Right Motor - Black wire)
  pinMode(SVA, OUTPUT); // Motor controller A SV (Left Motor - white wire)
  pinMode(SVB, OUTPUT); // Motor controller B SV (Right Motor - white wire)
  pinMode(FRA, OUTPUT); // Motor controller A F/R (Left Motor - red wire)
  pinMode(FRB, OUTPUT); // Motor controller B F/R (Right Motor - red wire)
 
 // Start with motors enabled and direction forward 
 // Switch on both motor controllers
  digitalWrite(GNDA, LOW);
  digitalWrite(GNDB, LOW);
  // Motor A (Left Motor)
  digitalWrite(FRA, LOW);
  // Motor B (Right Motor)
  digitalWrite(FRB, LOW);
}
void loop() 
{ 
  while(Serial.available())                     // If serial data is available then enter into while loop
  {
    if(Serial.read() == 'joyposVertB')           // This is backwards
    {
      digitalWrite(ledPin, LOW);     // Switch onboard SLAVE LED on
      MotorspeedB = Serial.parseInt();
      Serial.print("joyposVertB: "); // Print to serial monitor port on SLAVE
      Serial.println(MotorspeedB);     // Print to serial monitor port on SLAVE
      Serial.flush ();               // Wait for all data to be recieved
    } 
    else if (Serial.read() == 'joyposVertF')    //This is forwards
    {
      digitalWrite(ledPin, LOW);     // Switch onboard SLAVE LED on
      MotorspeedF = Serial.parseInt();
      Serial.print("joyposVertF: "); // Print to serial monitor port on SLAVE
      Serial.print(MotorspeedF);     // Print to serial monitor port on SLAVE
      Serial.flush ();               // Wait for all data to be recieved
    }
    else if (Serial.read() == 'joyposHorzL') //This is left
    {
      digitalWrite(ledPin, LOW);     // Switch onboard SLAVE LED on
      MotorspeedL = Serial.parseInt();
      Serial.print("joyposHorzL: "); // Print to serial monitor port on SLAVE
      Serial.print(MotorspeedL);     // Print to serial monitor port on SLAVE
      Serial.flush ();               // Wait for all data to be recieved
    }
    else if (Serial.read() == 'joyposHorzR') // This is right
    {
      digitalWrite(ledPin, LOW);     // Switch onboard SLAVE LED on
      MotorspeedR = Serial.parseInt();
      Serial.print("joyposHorzR: "); // Print to serial monitor port on SLAVE
      Serial.print(MotorspeedR);     // Print to serial monitor port on SLAVE
      Serial.flush ();               // Wait for all data to be recieved
    }
//    else
//        {
//          Motorspeed = 0;               //This is Stopped
//          Serial.println("MotorspeedS"); // Print to serial monitor port on SLAVE
//          Serial.flush ();               // Wait for all data to be recieved
//         }   
//    delay (1);     
//  } 
void function (int data); //Purge Data
      {
      if (data>500)
      digitalWrite(ledPin, HIGH); 
      else 
      digitalWrite(ledPin, LOW); 
      }
 }
}
//      digitalWrite(GNDA, LOW); // Switch on both Motor Controllers
//      digitalWrite(GNDB, LOW);
//      // Set Motor A (Left Motor) backward
//      digitalWrite(FRA, HIGH); // Motor controller A F/R (red wire)
// Set Motor B (Right Motor) backward
//     digitalWrite(FRB, HIGH); // Motor controller B F/R (red wire)
      //Determine Motor Speeds
//      MotorSpeed = map(joyposVert, 477, 0, 0, 255);
      // Send the motor speed to both motor controllers. 
//      analogWrite(SVA, MotorSpeed);
//      analogWrite(SVB, MotorSpeed);
//      }
//      else if (joyposVert > 547) // This is Forward
//         {
            // Switch on both Motor Controllers
//            digitalWrite(GNDA, LOW);
//            digitalWrite(GNDB, LOW);
            // Set Motor A (Left Motor) forward
//            digitalWrite(FRA, LOW);
            // Set Motor B (Right Motor) forward
//            digitalWrite(FRB, LOW);

            //Determine Motor Speed
//            MotorSpeed = map(joyposVert, 547, 1023, 0, 255);
            // Send the motor speed to both motor controllers.  
//            analogWrite(SVA, MotorSpeed);
//            analogWrite(SVB, MotorSpeed);
//          }

  // Now do the steering - Read The Horizontal Axis
//  joyposHorz = analogRead(joyHorz);

//      if (joyposHorz < 477) // Move Left
//          {   
            // Switch on both Motor Controllers
//            digitalWrite(GNDA, LOW);
//            digitalWrite(GNDB, LOW);
            // Set Motor A (Left Motor) BACKWARD
//            digitalWrite(FRA, HIGH);  
            // Set Motor B (Right Motor) FORWARD
//            digitalWrite(FRB, LOW);

            //Determine Motorspeed  
//            MotorSpeed = map(joyposHorz, 477, 0, 0, 255);

            // Send the motor speed to both motor controllers.  
//            analogWrite(SVA, MotorSpeed);
//            analogWrite(SVB, MotorSpeed);
//           }
//      else if (joyposHorz > 547)
//           {
            // Move Right
            // Switch on both Motor Controllers
//            digitalWrite(GNDA, LOW);
//            digitalWrite(GNDB, LOW);
            // Set Motor A (Left Motor) forward
//            digitalWrite(FRA, LOW);
            // Set Motor B (Right Motor) forward
//            digitalWrite(FRB, HIGH);
            // Determine Motor speed
//             MotorSpeed = map(joyposHorz, 547, 1023, 0, 255);

            // Send the motor speed to both motor controllers.  
//            analogWrite(SVA, MotorSpeed);
//            analogWrite(SVB, MotorSpeed);
//            }
//      else
//          {
//          (MotorSpeed) = 0; // This is Stopped
//          } 
//      if (MotorSpeed < 10)  
//          {
//            MotorSpeed = 0; // Adjust to prevent "buzzing" at very low speeds
//          }
//       if (MotorSpeed > 255) 
//          {
//        MotorSpeed = 255; // Don't exceed range of 0-255 for motor speeds
//          }
//       if (MotorSpeed < 0)   
//          {
//            MotorSpeed = 0;     // Don't exceed range of 0-255 for motor speeds
//          }
