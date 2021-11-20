#include <Arduino.h>
#include <ota.h>

void setup() {
    Serial.begin( 9600 );
    while(!Serial);

    ota_init("device-one");
}

void loop() {
    ota_loop();
}
