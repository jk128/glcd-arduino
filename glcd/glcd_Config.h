/*
 * glcd_Config.h - User specific configuration for Arduino GLCD library
 *
 * This file is shipped to automatically configure the library for a 
 * 128x64 ks0108 panel using the wiring described in the documentation.
 *
 * Use this file to select the active glcd configuration file
 * Then edit the selected panel file to configure parameters for that panel.
 *
 * This wiring is identical to the wiring used in the previous ks0108 library.
 * For Teensy devices the wiring selected matches the wiring documented on the Teensy website.
 *
 */

#ifndef glcd_CONFIG_H
#define glcd_CONFIG_H

 /*
  * You can select a configuration file by uncommenting one line to include the
  * the desired configuration file.
  *
  * Select 1 and only 1 configuration file.
  *
  * The "AutoConfig" configuration files will configure the library based on a set of
  * pre-customized configurations for the supported Arduino board type. 
  *
  * These configurations match the the panel configurations and wiring diagrams
  * in the library documentation based on the type of board selected in the Arduino IDE
  * and are compatible with wiring used in earlier versions of the ks0108 library
  *
  * NOTE: if you have a panel that has different dimensions than the distributed configuration, you can either
  * edit the supplied configuration file for that board type or create a fully custom configuration file.
  *
  * The auto configuration file (default is named  "config/ks0108_panel.h") selects the appropriate board
  * configuration file based on the current board selection in the Arduino IDE.
  *   
  * The configuration files for each board type can be found in the "config" directory, the naming is:
  *  "{PANEL}_{BOARDNAME}_Config.h"
  * Where:
  *   {PANEL} is the glcd panel type. (for example, ks0108)
  *   {BOARDNAME} is the name of the board (as selected in the Arduino IDE).
  *
  * So for example, the auto configuration file name for a ks0108 config file for the 
  * standard Arduino board would be: "ks0108_Arduino_Config.h"
  * and for a "Mega" board it would be: "ks0108_Mega_Config.h"
  * 
  */

/***********************************************************************************************************
 *
 * ALPHA TEST NOTE:
 * The configuration mechanism used here is not finalized and feedback is welcome.
 *  - Does the autoconfig work correctly in your environment with your boards and displays?
 *  - Is the mechanism to make a custom configuration easy to use?
 *  - We want your comments and suggestions for making configuration easer, particularly for novices
 *
 * Additional "autoconfig" files can be created, there is an example for 192x64 panels in this distribution.
 * In the future there will be more for different panel types, like sed1520, ks0713, etc..
 * Not all custom configuration files that may be supplied in the release are included in the alpha distribution
 *
 ***********************************************************************************************************/


 /*
  * autoconfig includes - (comment this out if using manual configurations, see below)
  */
#include "config/ks0108_panel.h"          // automatically configure library for a ks0108 panel
//#include "config/ks0108-192x64_panel.h"   // automatically configure library for a ks0108 192x64 panel

/*
 * If you want to explicitly select a manual configuration, you can edit the desired manual configuration
 * to fill in or modify the configuration information to meet your needs.
 * You can also use these files as a template to make customized copies to hold specific configurations.
 *
 * Remember that to activate your manual configuration you uncomment the #include for the desired file
 * and make sure that all the other config  #includes are commented (including the autoconfig above) 
 */

//#include "config/ks0108_Manual_Config.h"       // generic ks0108 configuration

//#include "config/Modadm12864f_Manual_Config.h" // configuration for BGMicro 128x64 display with pinout diagram
//#include "config/Modvk5121_Manual_Config.h"    // configuration for vk5121 122x32 display with pinout diagram


/*========================== Optional User Defines ==================================*/

//#define GLCD_NO_SCROLLDOWN    // disable reverse scrolling (saves ~600 bytes of code)
                // This will allow those tight on FLASH space to save a bit of code space

/*
 * ALPHA TEST NOTE:
 * Should the default be "atomic" even though it will be a bit slower on standard Arduino boards?
 */

//#define GLCD_ATOMIC_IO    // Generate code that ensures all pin i/o operations are atomic
                // including any potential nibble operations.
                // Without this option enabled, nibble operations will be slightly faster but
                // might have issues if a pin used shares a processor i/o port with an
                // interrupt routine that updates pins/bits on the same port.


//#define GLCD_NODEFER_SCROLL    // uncomment to disable deferred newline processing

/*
 * ALPHA TEST NOTE:
 * These defines will probably disappear
 */

//#define GLCD_OLD_FONTDRAW    // uncomment this define to get old font rendering (not recommended)
//#define GLCD_READDATA_XFAST    // uncomment to enable experimental code that speeds up LCD read operations.

#endif
