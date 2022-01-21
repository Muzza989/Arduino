// LARGE CRAWLER TEST MINI JOYSTICK ONLY

// Motor A
int SVA = 9; // Motor controller SV (white wire)
int FRA = 8; // Motor controller F/R (red wire)

// Motor B
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
  // Motor A 
  digitalWrite(FRA, LOW);
  
  // Motor B
  digitalWrite(FRB, LOW);
}

void loop() {

  // Read the Joystick Vert
  joyposVert = analogRead(joyVert);
  // Determine if this is a forward or backward motion & Apply results to MotorSpeed

  if (joyposVert < 477) // This is Backward
  {
    
    // Set Motor A backward
    digitalWrite(FRA, HIGH); // Motor controller A F/R (red wire)

    // Set Motor B backward
    digitalWrite(FRB, HIGH); // Motor controller B F/R (red wire)

    //Determine Motor Speeds
    MotorSpeed = map(joyposVert, 460, 0, 0, 255);
    // Send the motor speed to both motor controllers.  
    analogWrite(SVA, MotorSpeed);
    analogWrite(SVB, MotorSpeed);
  }
  else if (joyposVert > 560)
  {
    // This is Forward
    // Set Motor A forward
    digitalWrite(FRA, LOW);

    // Set Motor B forward
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
  
  if (joyposHorz < 477)
  {
    // Move Left
    // Set Motor A BACKWARD (LEFT MOTOR)
    digitalWrite(FRA, HIGH);  

    // Set Motor B FORWARD (RIGHT MOTOR)
    digitalWrite(FRB, LOW);
    
    //Determine Motorspeed  
    MotorSpeed = map(joyposHorz, 460, 0, 0, 255);

    // Send the motor speed to both motor controllers.  
    analogWrite(SVA, MotorSpeed);
    analogWrite(SVB, MotorSpeed);

  }
  else if (joyposHorz > 560)
  {
    // Move Right

     // Set Motor A forward
    digitalWrite(FRA, LOW);

    // Set Motor B forward
    digitalWrite(FRB, HIGH);
  
    // Determine Motor speed
    MotorSpeed = map(joyposHorz, 550, 1023, 0, 255);

    // Send the motor speed to both motor controllers.  
    analogWrite(SVA, MotorSpeed);
    analogWrite(SVB, MotorSpeed);
  }
    // Adjust to prevent "buzzing" at very low speed
  if (MotorSpeed < 10)MotorSpeed = 0;
    // Don't exceed range of 0-255 for motor speeds
  if (MotorSpeed > 255)MotorSpeed = 255;
  if (MotorSpeed < 0)MotorSpeed = 0; 

 delay (1);
}
