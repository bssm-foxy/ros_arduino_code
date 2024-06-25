/***************************************************************
   Motor driver function definitions - by James Nugen
   *************************************************************/

#ifdef L298_MOTOR_DRIVER
  //
 
  #define RIGHT_MOTOR_BACKWARD 5
  #define LEFT_MOTOR_BACKWARD  6
  #define RIGHT_MOTOR_FORWARD  9
  #define LEFT_MOTOR_FORWARD   10
  #define RIGHT_MOTOR_ENABLE 12
  #define LEFT_MOTOR_ENABLE 13
   /*
  #define RIGHT_MOTOR_DIR  9
  #define LEFT_MOTOR_DIR   10
  #define RIGHT_MOTOR_BREAK 12
  #define LEFT_MOTOR_BREAK 13
  #define RIGHT_MOTOR_PWM 5
  #define LEFT_MOTOR_PWM  6
  */
#endif
#ifdef DCMD_200_A
  //
  #define RIGHT_MOTOR_DIR  9
  #define LEFT_MOTOR_DIR   10
  #define RIGHT_MOTOR_BREAK 12
  #define LEFT_MOTOR_BREAK 13
  #define RIGHT_MOTOR_PWM 5
  #define LEFT_MOTOR_PWM  6
#endif
void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);
