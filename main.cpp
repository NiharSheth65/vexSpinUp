
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Robotic2                                         */
/*    Created:      Tue Sep 27 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// rFront               motor         1
// rBack                motor         2
// lBack                motor         3
// lFront               motor         4
// Controller1          controller
// launcherFront        motor         11
// launcherBack         motor         12
// intake               motor         13
// expansion            motor         14
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h"
using namespace vex;
float wheelCircumfrence = 2.75 * 3.14;
float oneRotationTravelled = sqrt(2 * pow(wheelCircumfrence, 2));
float turnRatio = 570 / 90;
int motorSpeed = 90;
// CODE TO MOVE ROBOT FORWARD
void moveForward(float distance, int speed, int motorLaunchSpeed) {
  float motorDegrees = (distance / oneRotationTravelled) * 360;
  launcherFront.spin(directionType::fwd, motorLaunchSpeed, velocityUnits::pct);
  launcherBack.spin(directionType::fwd, motorLaunchSpeed, velocityUnits::pct);
  rFront.startRotateFor(directionType::fwd, motorDegrees, rotationUnits::deg,
                        speed, velocityUnits::pct);
  rBack.startRotateFor(directionType::rev, motorDegrees, rotationUnits::deg,
                       speed, velocityUnits::pct);
  lFront.startRotateFor(directionType::rev, motorDegrees, rotationUnits::deg,
                        speed, velocityUnits::pct);
  lBack.rotateFor(directionType::fwd, motorDegrees, rotationUnits::deg, speed,
                  velocityUnits::pct);
}
// CODE TO MOVE ROBOT BACKWARD
void moveBackward(float distance, int speed, int motorLaunchSpeed) {
  float motorDegrees = (distance / oneRotationTravelled) * 360;
  launcherFront.spin(directionType::fwd, motorLaunchSpeed, velocityUnits::pct);
  launcherBack.spin(directionType::fwd, motorLaunchSpeed, velocityUnits::pct);
  rFront.startRotateFor(directionType::rev, motorDegrees, rotationUnits::deg,
                        speed, velocityUnits::pct);
  rBack.startRotateFor(directionType::fwd, motorDegrees, rotationUnits::deg,
                       speed, velocityUnits::pct);
  lFront.startRotateFor(directionType::fwd, motorDegrees, rotationUnits::deg,
                        speed, velocityUnits::pct);
  lBack.rotateFor(directionType::rev, motorDegrees, rotationUnits::deg, speed,
                  velocityUnits::pct);
}
// CODE TO DRIFT ROBOT HORIZONTALLY RIGHT
void driftRight(float distance, int speed, int motorLaunchSpeed) {
  float motorDegrees = (distance / oneRotationTravelled) * 360;
  launcherFront.spin(directionType::fwd, motorLaunchSpeed, velocityUnits::pct);
  launcherBack.spin(directionType::fwd, motorLaunchSpeed, velocityUnits::pct);
  rFront.startRotateFor(directionType::fwd, motorDegrees, rotationUnits::deg,
                        speed, velocityUnits::pct);
  rBack.startRotateFor(directionType::fwd, motorDegrees, rotationUnits::deg,
                       speed, velocityUnits::pct);
  lFront.startRotateFor(directionType::fwd, motorDegrees, rotationUnits::deg,
                        speed, velocityUnits::pct);
  lBack.rotateFor(directionType::fwd, motorDegrees, rotationUnits::deg, speed,
                  velocityUnits::pct);
}
// CODE TO DRIFT ROBOT HORIZONTALLY LEFT
void driftLeft(float distance, int speed, int motorLaunchSpeed) {
  float motorDegrees = (distance / oneRotationTravelled) * 360;
  launcherFront.spin(directionType::fwd, motorLaunchSpeed, velocityUnits::pct);
  launcherBack.spin(directionType::fwd, motorLaunchSpeed, velocityUnits::pct);
  rFront.startRotateFor(directionType::rev, motorDegrees, rotationUnits::deg,
                        speed, velocityUnits::pct);
  rBack.startRotateFor(directionType::rev, motorDegrees, rotationUnits::deg,
                       speed, velocityUnits::pct);
  lFront.startRotateFor(directionType::rev, motorDegrees, rotationUnits::deg,
                        speed, velocityUnits::pct);
  lBack.rotateFor(directionType::rev, motorDegrees, rotationUnits::deg, speed,
                  velocityUnits::pct);
}
// CODE TO turn right
void turnRight(float turningAngle, int speed, int motorLaunchSpeed) {
  float turnAmount = turningAngle * (570 / 90);
  launcherFront.spin(directionType::fwd, motorLaunchSpeed, velocityUnits::pct);
  launcherBack.spin(directionType::fwd, motorLaunchSpeed, velocityUnits::pct);
  rFront.startRotateFor(directionType::rev, turnAmount, rotationUnits::deg,
                        speed, velocityUnits::pct);
  rBack.startRotateFor(directionType::fwd, turnAmount, rotationUnits::deg,
                       speed, velocityUnits::pct);
  lFront.startRotateFor(directionType::rev, turnAmount, rotationUnits::deg,
                        speed, velocityUnits::pct);
  lBack.rotateFor(directionType::fwd, turnAmount, rotationUnits::deg, speed,
                  velocityUnits::pct);
}
// Code to turn robot leftwards
void turnLeft(float turningAngle, int speed, int motorLaunchSpeed) {
  float turnAmount = turningAngle * (630 / 90);
  launcherFront.spin(directionType::fwd, motorLaunchSpeed, velocityUnits::pct);
  launcherBack.spin(directionType::fwd, motorLaunchSpeed, velocityUnits::pct);
  rFront.startRotateFor(directionType::fwd, turnAmount, rotationUnits::deg,
                        speed, velocityUnits::pct);
  rBack.startRotateFor(directionType::rev, turnAmount, rotationUnits::deg,
                       speed, velocityUnits::pct);
  lFront.startRotateFor(directionType::fwd, turnAmount, rotationUnits::deg,
                        speed, velocityUnits::pct);
  lBack.rotateFor(directionType::rev, turnAmount, rotationUnits::deg, speed,
                  velocityUnits::pct);
}
// roller turn forward - roller spins in direction of intake
void turnRollerForward(float motorTime, int speed, int motorLaunchSpeed) {
  launcherFront.spin(directionType::fwd, motorLaunchSpeed, velocityUnits::pct);
  launcherBack.spin(directionType::fwd, motorLaunchSpeed, velocityUnits::pct);
  intake.rotateFor(directionType::fwd, motorTime, timeUnits::sec, speed,
                   velocityUnits::pct);
}
// roller turn backwards - roller turn away from the direction of the intake
void turnRollerBackward(float motorTime, int speed, int motorLaunchSpeed) {
  launcherFront.spin(directionType::fwd, motorLaunchSpeed, velocityUnits::pct);
  launcherBack.spin(directionType::fwd, motorLaunchSpeed, velocityUnits::pct);
  intake.rotateFor(directionType::rev, motorTime, timeUnits::sec, speed,
                   velocityUnits::pct);
}
// run launcher and intake at the same time
void launchAndIntake(int motorLaunchTime, int motorIntakeTime,
                     int motorLaunchSpeed, int motorIntakeSpeed) {
  intake.spin(directionType::rev, motorIntakeSpeed, velocityUnits::pct);
  launcherFront.spin(directionType::fwd, motorLaunchSpeed, velocityUnits::pct);
  launcherBack.rotateFor(directionType::fwd, motorLaunchTime, timeUnits::sec,
                         motorLaunchSpeed, velocityUnits::pct);
}
// drive forward and intake at the same time
void forwardAndIntake(int driveSpeed, int driveDistance, int intakeSpeed,
                      int intakeTime, int motorLaunchSpeed) {
  launcherFront.spin(directionType::fwd, motorLaunchSpeed, velocityUnits::pct);
  launcherBack.spin(directionType::fwd, motorLaunchSpeed, velocityUnits::pct);
  moveForward(driveDistance, driveSpeed, 100);
  launchAndIntake(0, driveDistance, 0, 100);
}
void launcherWarmUp(int launcherTime, int launcherSpeed) {
  launcherFront.spin(directionType::fwd, launcherSpeed, velocityUnits::pct);
  launcherBack.rotateFor(directionType::fwd, launcherTime, timeUnits::sec,
                         launcherSpeed, velocityUnits::pct);
}

// this program should do the bare minumum flawlessly
// long side basic program 

void autonomousLongSideDefault() {
  // move 1.5 inches robot forward
  moveForward(1.5, 100, 0);
  // spin roller, away from intake
  turnRollerBackward(2, 100, 0);
  // start up launcher for like 2 seconds
  launcherWarmUp(3, 100);
  // move 1.5 inches backward
  moveBackward(10, 100, 100);
  // turn 8 degrees robot left
  turnLeft(8, 75, 100);
  // run intake
  launchAndIntake(10, 10, 100, 100);
  // score 2 disks
}

// would be preferable to run this program, first make sure default programs run well
void autonomousLongSideComplex(){
  // does everything that the default should do 
  autonomousLongSideDefault(); 
  // turn 180 
  turnRight(180, 100, 0); 
  // turn Right
  turnRight(56, 100 , 0); 
  // drive forward
  moveForward(37, 100, 0);
  // drive backward
  moveBackward(5, 100, 0);
  // move forward 5 inches 
  moveForward(5, 100, 0);
  //intake for 2 seconds
  launchAndIntake(0, 1, 0, 100);
  // move forward 5 inches 
  moveForward(5, 100, 0);
  //intake for 2 seconds
  launchAndIntake(0, 1, 0, 100);
  moveForward(5, 100, 0);
  //intake for 2 seconds
  launchAndIntake(0, 1, 0, 100);
}

// this program should do the bare minumum flawlessly 
// short side basic program 
void autonomousShortSideDefault() {
  // move 9 inches robot forward
  moveBackward(4, 100, 100);
  // turn 23 degrees robot right
  turnRight(31, 75, 100);
  // warm  up launcher
  launcherWarmUp(3, 100);
  // spin intake for 3 seconds
  launchAndIntake(3, 3, 100, 100);
  // run for 2 more seconds
  launchAndIntake(2, 2, 100, 100);
  // spin 180 - 23 degrees robot left
  turnLeft(25, 75, 0);
  // move forward 2 inches and intake
  forwardAndIntake(100, 2, 100, 3, 0);
// move forward 30 inches
  moveForward(10, 100, 0);
    // drift left 31 inches
  driftRight(30, 100, 0);
  // turn roller
  turnRollerBackward(3, 100, 100);
}

void autonomousShortSideComplex(){
   // move 9 inches robot forward
  moveBackward(4, 100, 100);
  // turn 23 degrees robot right
  turnRight(31, 75, 100);
  // warm  up launcher
  launcherWarmUp(2, 100);
  // spin intake for 3 seconds
  launchAndIntake(3, 3, 100, 100);
  // run for 2 more seconds
  launchAndIntake(2, 2, 100, 100);
  // spin 180 
  turnRight(180, 75, 0); 
  // moveForwardAndIntake
  forwardAndIntake(100, 5, 100, 3, 0);
  // spin 180 - 23 degrees robot left
  turnLeft(25, 75, 0);
  // move forward 2 inches and intake
  forwardAndIntake(100, 2, 100, 3, 0);
// move forward 30 inches
  moveForward(10, 100, 0);
    // drift left 31 inches
  driftRight(30, 100, 0);
  // turn roller
  turnRollerBackward(3, 100, 100);
}



void userControl(void) {
  while (1) {
    if (Controller1.ButtonUp.pressing()) {
      motorSpeed = 100;
    } else if (Controller1.ButtonDown.pressing()) {
      motorSpeed = 65;
    }
    // Important things to remember
    // m1 should be x + y
    // m2 should be x - y
    // m3 should be x  + y
    // m4 should be x - y
    // vexRT[Ch1] = left/right
    // vexRT[Ch2] = up down
    rFront.spin(vex::directionType::fwd,
                Controller1.Axis1.position() + Controller1.Axis2.position() +
                    Controller1.Axis4.position(),
                vex::velocityUnits::pct);
    rBack.spin(vex::directionType::fwd,
               Controller1.Axis1.position() - Controller1.Axis2.position() -
                   Controller1.Axis4.position(),
               vex::velocityUnits::pct);
    lFront.spin(vex::directionType::fwd,
                Controller1.Axis1.position() - Controller1.Axis2.position() +
                    Controller1.Axis4.position(),
                vex::velocityUnits::pct);
    lBack.spin(vex::directionType::fwd,
               Controller1.Axis1.position() + Controller1.Axis2.position() -
                   Controller1.Axis4.position(),
               vex::velocityUnits::pct);
    // motor speed setting
    // launcher control
    if (Controller1.ButtonL1.pressing()) {
      launcherFront.spin(vex::directionType::fwd, motorSpeed,
                         vex::velocityUnits::pct);
      launcherBack.spin(vex::directionType::fwd, motorSpeed,
                        vex::velocityUnits::pct);
    } else if (Controller1.ButtonL2.pressing()) {
      launcherFront.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
      launcherBack.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    } else {
      launcherFront.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
      launcherBack.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
    }
    // intake control
    if (Controller1.ButtonR1.pressing()) {
      intake.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    } else if (Controller1.ButtonR2.pressing()) {
      intake.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    } else {
      intake.spin(vex::directionType::rev, 0, vex::velocityUnits::pct);
    }
    // do expansion

    expansion.stop(brakeType::hold);
    if (Controller1.ButtonLeft.pressing() &&
        Controller1.ButtonRight.pressing()) {
      expansion.stop(brakeType::coast);
      expansion.startRotateFor(directionType::fwd, 240, rotationUnits::deg, 75,
                               velocityUnits::pct);
    }
    //  run autonomous through controller
    if (Controller1.ButtonA.pressing()) {
      autonomousLongSideDefault();
    } else if (Controller1.ButtonB.pressing()) {
      autonomousShortSideDefault();
    }
  }
}
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  userControl();
  vexcodeInit();
}
