#ifndef _EASY_PDLC
#define _EASY_PDLC
#include "Arduino.h"
#include "Ticker.h"

/*! \mainpage Intro
 * The module uses a pretty high voltage(60V) to power up the PDLCs, so be sure to keep it unplugged from the PC when you turn the high-voltage on.
 * (Disconnect VPOWER pin->Flash the code->unplug from the pc->connect external source->connect VPOWER pin)
 */ 

/** @brief The main EasyPDLC class**/
class EasyPDLC{
    public:
    /** @brief The microcontroller pin connected to 50_Hz_PWM pin of the EasyPDLC**/
    uint8_t outputEnable;
    /** @brief The microcontroller pin connected to SHCP pin of the EasyPDLC**/
    uint8_t shcp;
    /** @brief The microcontroller pin connected to STCP pin of the EasyPDLC**/
    uint8_t stcp;
    /** @brief The microcontroller pin connected to DSIN pin of the EasyPDLC**/
    uint8_t dsin;
    /** @brief The instance of Ticker class that keeps 5OHz on outputEnable pin**/
    Ticker tickerInstance;
    /** @brief The variable that prevents multiple calls of Tricker.attatch() function within the instance**/
    bool enableState;

    /** @brief This constructor takes 4 pin names as arguments, they are labeled 50_Hz_PWM, SHCP, STCP and DSIN on your EasyPDLC module
     * @param outputEnable The microcontroller pin connected to 50_Hz_PWM pin of the EasyPDLC
     * @param shcp The microcontroller pin connected to SHCP pin of the EasyPDLC.
     * @param stcp The microcontroller pin connected to STCP pin of the EasyPDLC.
     * @param dsin The microcontroller pin connected to DSIN pin of the EasyPDLC.
      **/
    EasyPDLC(uint8_t outputEnable,uint8_t shcp, uint8_t stcp, uint8_t dsin);

    /** @brief Sets active output pins on your EasyPDLC. If you have multiple modules connected 'in series' (EasyPDLC DSOUT->EasyPDLC2 DSIN)
    * the value is set to the first module in series(The one which has DSIN connected to the Arduino/ESP32).
    * To display the value set with this method use the @ref Latch method!
    * @param number The binary representation of pins of a EasyPDLC (for example: 3 turns on pin 0 and 1 as in binary it would be represented as ...0011)**/
    void SetPDLC(uint16_t number);
  
    /** @brief This method outsputs the pins state that you have set using @ref SetPDLC, be sure to call it after @ref SetPDLC**/
    void Latch(void);

    /** @brief function passed to Ticker instance that keeps the 50Hz pulse on outputEnable pin**/
    void OutputEnableFunction();
};

#endif

