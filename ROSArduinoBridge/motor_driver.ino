/***************************************************************
   Motor driver definitions
   
   Add a "#elif defined" block to this file to include support
   for a particular motor driver.  Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   *************************************************************/

#ifdef USE_BASE
   
#if defined DCMD_200_A
  void initMotorController() {
    digitalWrite(RIGHT_MOTOR_BREAK, LOW);
    digitalWrite(LEFT_MOTOR_BREAK, LOW);
  }
  
  void setMotorSpeed(int i, int spd) {
    unsigned char reverse = 0;
  
    if (spd < 0)
    {
      spd = abs(spd);
      reverse = 1;
    }
    if (spd > 255)
      spd = 255;
    

    if (i == LEFT) {
      if(reverse == 0 && spd > 0) {
        analogWrite(LEFT_MOTOR_PWM, spd); 
        analogWrite(LEFT_MOTOR_DIR, 0); 
        leftMotorDirection = FORWARD;
      }
      else if (reverse == 1) { 
        analogWrite(LEFT_MOTOR_PWM, spd); 
        analogWrite(LEFT_MOTOR_DIR, 255); 
        leftMotorDirection = BACKWARD;
      }
      else { 
        analogWrite(LEFT_MOTOR_PWM, 0); 
        leftMotorDirection = STOPPED; 
      }
    }
    else /*if (i == RIGHT) //no need for condition*/ {
      if(reverse == 0 && spd > 0) { 
        analogWrite(RIGHT_MOTOR_PWM, spd); 
        analogWrite(RIGHT_MOTOR_DIR, 0);
        rightMotorDirection = FORWARD;
      }
      else if (reverse == 1 ) { 
        analogWrite(RIGHT_MOTOR_PWM, spd); 
        analogWrite(RIGHT_MOTOR_DIR, 255);
        rightMotorDirection = BACKWARD;
      }
      else { 
        analogWrite(RIGHT_MOTOR_PWM, 0); 
        rightMotorDirection = STOPPED; 
      }
    }
  }
  
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }

#elif defined L298_MOTOR_DRIVER
  void initMotorController() {
    digitalWrite(RIGHT_MOTOR_ENABLE, HIGH);
    digitalWrite(LEFT_MOTOR_ENABLE, HIGH);
  }
  
  void setMotorSpeed(int i, int spd) {
    unsigned char reverse = 0;
  
    if (spd < 0)
    {
      spd = -spd;
      reverse = 1;
    }
    if (spd > 255)
      spd = 255;
    
    if (i == LEFT) {
      if(reverse == 0 && spd > 0) { 
        analogWrite(LEFT_MOTOR_FORWARD, spd); 
        analogWrite(LEFT_MOTOR_BACKWARD, 0); 
        leftMotorDirection = FORWARD;
      }
      else if (reverse == 1) { 
        analogWrite(LEFT_MOTOR_BACKWARD, spd); 
        analogWrite(LEFT_MOTOR_FORWARD, 0); 
        leftMotorDirection = BACKWARD;
      }
      else { 
        analogWrite(LEFT_MOTOR_FORWARD, 0); 
        analogWrite(LEFT_MOTOR_BACKWARD, 0); 
        leftMotorDirection = STOPPED; 
      }
    }
    else /*if (i == RIGHT) //no need for condition*/ {
      if      (reverse == 0 && spd > 0) { 
        analogWrite(RIGHT_MOTOR_FORWARD, spd); 
        analogWrite(RIGHT_MOTOR_BACKWARD, 0); 
        rightMotorDirection = FORWARD;
      }
      else if (reverse == 1) { 
        analogWrite(RIGHT_MOTOR_BACKWARD, spd); 
        analogWrite(RIGHT_MOTOR_FORWARD, 0); 
        rightMotorDirection = BACKWARD;
      }
      else { 
        analogWrite(RIGHT_MOTOR_BACKWARD, 0); 
        analogWrite(RIGHT_MOTOR_FORWARD, 0); 
        rightMotorDirection = STOPPED; 
      }
    }
  }
  
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }
#else
  #error A motor driver must be selected!
#endif

#endif
