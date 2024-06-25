/* *************************************************************
   Encoder definitions
   
   Add an "#ifdef" block to this file to include support for
   a particular encoder board or library. Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   ************************************************************ */
   
#ifdef USE_BASE

volatile bool leftEncoderFlagA = false;
volatile bool leftEncoderFlagB = false;
volatile bool rightEncoderFlagA = false;
volatile bool rightEncoderFlagB = false;

#if defined(TOSPO_ENCODER)
  #include "Globals.h"
  volatile long left_enc_pos = 0L;
  volatile long right_enc_pos = 0L;
  
  /* Interrupt routine for LEFT encoder, taking care of actual counting */
  /*
  ISR (PCINT2_vect){
    if (leftMotorDirection == FORWARD) { left_enc_pos++; } 
    
    else if (leftMotorDirection == BACKWARD) { left_enc_pos--; }

    //Serial.print("leftA:");
    //Serial.print(digitalRead(LEFT_ENC_PIN_A));
    //Serial.print(",leftB:");
    //Serial.println(digitalRead(LEFT_ENC_PIN_B));
  }
  */

  /* Interrupt routine for RIGHT encoder, taking care of actual counting */
  /*
  ISR (PCINT1_vect){
    if (rightMotorDirection == FORWARD) { right_enc_pos++; } 
    else if (rightMotorDirection == BACKWARD) { right_enc_pos--; }
  } 
  */   
  void leftEncoderISR_A() {
    if(leftMotorDirection==FORWARD){
      left_enc_pos++;
    }
    else if(leftMotorDirection==BACKWARD){
      left_enc_pos--;
    }
  }

  void rightEncoderISR_A() {
    if(rightMotorDirection==FORWARD){
      right_enc_pos++;
    }
    else if(rightMotorDirection==BACKWARD){
      right_enc_pos--;
    }
  }

  /* Wrap the encoder reading function */
  long readEncoder(int i) {
    if (i == LEFT) return left_enc_pos;
    else return right_enc_pos;
  }

  /* Wrap the encoder reset function */
  void resetEncoder(int i) {
    if (i == LEFT){
      left_enc_pos=0L;
      return;
    } else { 
      right_enc_pos=0L;
      return;
    }
  }
#else
  #error A encoder driver must be selected!
#endif

/* Wrap the encoder reset function */
void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
}

#endif

