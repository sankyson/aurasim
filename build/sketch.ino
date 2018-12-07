
// ===============================================
// SIMUINO_BEGIN
// ===============================================
// BOARD_TYPE:  MEGA
// SKETCH_NAME: HelloWorld_MEGA.ino
// SIM_LENGTH:  600
// WIN_LAYOUT:    2
// SO_DELAY:     40
//================================================
//  Scenario
//================================================
//
// SCENDIGPIN 10    1    0
// SCENDIGPIN 10   50    1
// SCENDIGPIN 10  100    0
// SCENDIGPIN 10  200    1
// SCENDIGPIN  9    1    0
// SCENDIGPIN  9   40    1
// SCENDIGPIN  9  130    0
//
// SCENANAPIN  4    1    5
// SCENANAPIN  5    1    8 
// SCENANAPIN  4   80   12
// SCENANAPIN  5  120   18 
//
//================================================
// Simuino log text customization
//================================================

// PINMODE_OUT: 11  "PIN: Led Urgent"
// PINMODE_OUT: 12  "PIN: Led Blink"

// DIGITALWRITE_LOW:  11  "Waiting"
// DIGITALWRITE_HIGH: 11  "Urgent"
// DIGITALWRITE_LOW:  12  "Led is off"
// DIGITALWRITE_HIGH: 12  "Led is on"

// DIGITALREAD:  9  "Read from nine"
// DIGITALREAD: 10  "Read from ten"


// ANALOGREAD: 4  "read analog four"
// ANALOGREAD: 5  "read analog five"


//-------- DIGITAL PIN settings ------------------

const int lowestPin = 2;
const int highestPin = 13;


void setup() {
  // set pins 2 through 13 as outputs:
  for (int thisPin = lowestPin; thisPin <= highestPin; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
  // iterate over the pins:
  for (int thisPin = lowestPin; thisPin <= highestPin; thisPin++) {
    // fade the LED on thisPin from off to brightest:
    for (int brightness = 0; brightness < 255; brightness++) {
      analogWrite(thisPin, brightness);
      delay(2);
    }
    // fade the LED on thisPin from brightest to off:
    for (int brightness = 255; brightness >= 0; brightness--) {
      analogWrite(thisPin, brightness);
      delay(2);
    }
    // pause between LEDs:
    delay(100);
  }
}
//================================================
// End of Sketch
//================================================
