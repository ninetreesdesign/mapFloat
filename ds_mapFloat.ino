/*
 * Arduino map() function only works for integers;
 * By changing variable types, a floating point version is made.
 *
 */

/// setup function
void setup() {
    // Set up serial port
    Serial.begin(57600);
    // the while loop is needed for devices with USB port for programming
    while (!Serial && (millis() < 5000)) {} // program continues after time interval even if a monitor window is never opened
    Serial.println("\nPort initialized.\n");

    // test new mapping function
    String str = "";
    float x;
    float y;
    for ( int i = 0; i < 10; i++) {
        x = (float)i * .5 - 0.2;
        y = mapFloat(x, -1.0, 1.0, -100, 100);
        str =  String(x) + ", " + String(y);
        Serial.println(str);
    }
}


void loop() {
    ;    // nothing
}


/// map one numerical span to another with floating point values
double mapFloat (double x, double in_min, double in_max, double out_min, double out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
