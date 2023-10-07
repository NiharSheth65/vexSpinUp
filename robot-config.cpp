#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor rFront = motor(PORT1, ratio18_1, true);
motor rBack = motor(PORT2, ratio18_1, false);
motor lBack = motor(PORT3, ratio18_1, false);
motor lFront = motor(PORT4, ratio18_1, true);
controller Controller1 = controller(primary);
motor launcherFront = motor(PORT11, ratio6_1, false);
motor launcherBack = motor(PORT12, ratio6_1, true);
motor intake = motor(PORT13, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}