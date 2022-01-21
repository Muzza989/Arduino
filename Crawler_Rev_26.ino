// LARGE CRAWLER TEST MINI JOYSTICK ONLY
// This one almost works correctly. 
// Black wire to motor driver GND hooked up to breadboard GND & looped to EN on motor driver.

// Motor A (Left Motor)
int SVA = 9; // Motor controller SV (white wire)
int FRA = 8; // Motor controller F/R (red wire)

// Motor B (Right Motor)
int SVB = 3; // Motor controller SV (white wire)
int FRB = 4; // Motor controller F/R (red wire)

// Joystick Input
int joyVert = A0; // Vertical  
int joyHorz = A1; // Horizontal

// Motor Speed Value - Start at zero
int MotorSpeed = 0;

// Joystick Values - Start at 512 (middle position)
int joyposVert = 512;
int joyposHorz = 512;

void setup()
{
  // Set all the motor control pins to outputs
  pinMode(SVA, OUTPUT); // Motor controller A SV (white wire)
  pinMode(SVB, OUTPUT); // Motor controller B SV (white wire)
  pinMode(FRA, OUTPUT); // Motor controller A F/R (red wire)
  pinMode(FRB, OUTPUT); // Motor controller B F/R (red wire) 
 
 // Start with motors enabled and direction forward 
  // Motor A (Left Motor)
  digitalWrite(FRA, LOW);
  // Motor B (Right Motor)
  digitalWrite(FRB, LOW);
}

void loop() {

  // Read the Joystick Vert
  joyposVert = analogRead(joyVert);
  // Determine if this is a forward or backward motion & Apply results to MotorSpeed

  if (joyposVert < 460) // This is Backward
  {
    // Set Motor A (Left Motor) backward
    digitalWrite(FRA, HIGH); // Motor controller A F/R (red wire)
    // Set Motor B (Right Motor) backward
    digitalWrite(FRB, HIGH); // Motor controller B F/R (red wire)

    //Determine Motor Speeds
    MotorSpeed = map(joyposVert, 460, 0, 0, 255);
    // Send the motor speed to both motor controllers. 
    analogWrite(SVA, MotorSpeed);
    analogWrite(SVB, MotorSpeed);
  }
  else if (joyposVert > 564)
  {
    // This is Forward
    // Set Motor A (Left Motor) forward
    digitalWrite(FRA, LOW);
    // Set Motor B (Right Motor) forward
    digitalWrite(FRB, LOW);

    //Determine Motor Speed
    MotorSpeed = map(joyposVert, 550, 1023, 0, 255);
    // Send the motor speed to both motor controllers.  
    analogWrite(SVA, MotorSpeed);
    analogWrite(SVB, MotorSpeed);
  }

  // Now do the steering - Read The Horizontal Axis
  joyposHorz = analogRead(joyHorz);
  // Determine if this is a forward or backward motion & Apply results to MotorSpeed

  if (joyposHorz < 460)
  {
    // Move Left
    // Set Motor A (Left Motor) BACKWARD
    digitalWrite(FRA, HIGH);  
    // Set Motor B (Right Motor) FORWARD
    digitalWrite(FRB, LOW);

    //Determine Motorspeed  
    MotorSpeed = map(joyposHorz, 460, 0, 0, 255);

    // Send the motor speed to both motor controllers.  
    analogWrite(SVA, MotorSpeed);
    analogWrite(SVB, MotorSpeed);
  }
  else if (joyposHorz > 564)
  {
    // Move Right
     // Set Motor A (Left Motor) forward
    digitalWrite(FRA, LOW);
    // Set Motor B (Right Motor) forward
    digitalWrite(FRB, HIGH);
    // Determine Motor speed
    MotorSpeed = map(joyposHorz, 550, 1023, 0, 255);

    // Send the motor speed to both motor controllers.  
    analogWrite(SVA, MotorSpeed);
    analogWrite(SVB, MotorSpeed);
  }
  else
  {
    // This is Stopped
    MotorSpeed = 0;
  }
    // Adjust to prevent "buzzing" at very low speed
  if (MotorSpeed < 10)MotorSpeed = 0;
    // Don't exceed range of 0-255 for motor speeds
  if (MotorSpeed > 255)MotorSpeed = 255;
  if (MotorSpeed < 0)MotorSpeed = 0;

  // Send the motor speed to both motor controllers.
  //analogWrite(SVA, MotorSpeed);
  //analogWrite(SVB, MotorSpeed);

 delay (1);
}
