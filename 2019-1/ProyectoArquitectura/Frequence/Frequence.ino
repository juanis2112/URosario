#include <NewPing.h>
#include <toneAC.h>
#define DEBUG         false // Set to true to enable Serial debug
#define TONE_PIN      8
#define TONE_VOLUME   10   // 1-20
#define TRIGGER_PIN   12   // Board pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN      11   // Board pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE  200  // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
void setup() {
if (DEBUG) {
    Serial.begin(115200);
    Serial.println("Theremino starting");
  }
}
void loop() {
delay(30); // Wait 30ms between pings (about 33 pings/sec). 29ms should be the shortest delay between pings.
unsigned long uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
if (DEBUG) Serial.println(uS);
if (uS > 2000) { // Range is about 0-30 cm from sensor
toneAC(0); // Turn sound off when not in range
if (DEBUG) Serial.println("No tone");
  } else {
int freq = 2000 - uS / 1.5; // Get sound frequency
toneAC(freq, TONE_VOLUME); // Play it!
if (DEBUG) Serial.println(freq);
  }
}
