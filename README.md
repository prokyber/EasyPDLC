
# EasyPDLC Library

The EasyPDLC library is designed to control Polymer Dispersed Liquid Crystal sheets through EasyPDLC modules. These modules operate at a high voltage (60V), so safety precautions are necessary during setup and operation.

## **Safety Instructions**

- Ensure the module is unplugged from the PC before enabling high voltage:
  1. Disconnect the `VPOWER` pin.
  2. Flash the code to the microcontroller.
  3. Unplug the microcontroller from the PC.
  4. Connect an external power source.
  5. Reconnect the `VPOWER` pin.

## All User Methods

- EasyPDLC
- SetPDLC
- Latch

## EasyPDLC

A constructor method that sets all the necessary pins

### Parameters

- uint8_t outputEnable - number of pin that enables voltage on the desk. The Ticker instance is running on this pin keeping 50Hz pulse that is esential for correct function of the module
- uint8_t shcp - number of shcp pin
- uint8_t stcp - number of stcp pin
- uint8_t dsin - number of data input pin

## SetPDLC

A method used to set up shift registers of the VFDDs. Don't forget to call the the Latch method afterward to apply the changes.

### Parameters

- `uint16_t number` - 2-byte sized binary number that serves as a representation of output pin. If pin's voltage is `HIGH` the attatched PDLC sheet is transparent.

### Call example

("e" is an EasyVFDD instance)

```cpp
e.SetVFDD(0b0000000000000101); /* value = 5 */
```

Result of this call will be that after calling the Latch method PDLC sheets attatched to pins 0 and 2 will be transparent and rest will be still clouded.

## Latch

A method that latches all shift registers. Don't forget to use the SetPDLC method to set them up first.

### Call example

("e" is an EasyPDLC instance)

```cpp
e.SetVFDD(/*your values*/);
e.Latch();
```

## Notes

- The library uses the `Ticker` class to generate a 50 Hz pulse, which is essential for proper PDLC operation.
- Always follow the safety precautions mentioned above to avoid damage to components or injury.
