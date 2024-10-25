#ifndef _EASY_PDLC
#define _EASY_PDLC
#include "Arduino.h"
#include "Ticker.h"

/*! \mainpage Intro
 * The module uses a pretty high voltage(60V) to power up the nixies, so be sure to keep it unplugged from the PC when you turn the high-voltage on.
 * (Disconnect VPOWER pin->Flash the code->unplug from the pc->connect external source->connect VPOWER pin)
 */ 

/** @brief The main EasyNixie class**/
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

    Ticker tickerInstance;

    bool enableState;

    /** @brief This constructor takes 4 pin names as arguments, they are labeled 50_Hz_PWM, SHCP, STCP and DSIN on your EasyPDLC module
     * @param outputEnable The microcontroller pin connected to 50_Hz_PWM pin of the EasyPDLC
     * @param shcp The microcontroller pin connected to SHCP pin of the EasyPDLC.
     * @param stcp The microcontroller pin connected to STCP pin of the EasyPDLC.
     * @param dsin The microcontroller pin connected to DSIN pin of the EasyPDLC.
      **/
    EasyPDLC(uint8_t outputEnable,uint8_t shcp, uint8_t stcp, uint8_t dsin);

    /** @brief Set nixie digit/symbol on your EasyPDLC. If you have multiple modules connected 'in series' (EasyPDLC DSOUT->EasyNixie2 DSIN)
    * the value is set to the first module in series(The one which has DSIN connected to the Arduino).
    * To display the value set with this method use the @ref Latch method!
    * @param number The digit/symbol you want to display. The digits can be swapped if you are using non-standard nixies(not In-12/In-17).
    * @param color Led color, checkout the \ref Colors, I should have probably used enum to avoid illegal arguments, 
    * but I am too lazy to rewrite and retest all the examples...
    * @param voltage This argument enables the high-voltage convertor, be sure to disconnect the EasyPDLC from PC,
    *  when you are calling the function with this argument set to true. You can flash the code with VPOWER pin disconneted,
    *  then disconnect the board from PC, connect to some external power source, then connect the VPOWER pin.
    * @param comma Or the 'decimal point'. This argument controls the decimal point of In-12B.
    * @param dimming Basically, just PWM on the @ref outputEnable pin. 0 means max brightness, 255 means min brightness.
    **/
    void SetPDLC(uint16_t number);
  
    /** @brief This method 'displays' the digit that you have set using @ref SetPDLC, be sure to call it after @ref SetPDLC**/
    void Latch(void);

    void OutputEnableFunction();
};

#endif

