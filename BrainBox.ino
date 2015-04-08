/*
 8-ohm speaker on digital pin 0
 tone(pin, frequency, duration)
 25200000 ms = 7 hours
*/

#define ALPHA_LOW 8
#define THETA_HIGH 6
#define THETA_LOW 4
#define DELTA_HIGH 3
#define DELTA_MED 2
#define DELTA_LOW 1

int melody[] = {
  ALPHA_LOW, ALPHA_LOW, ALPHA_LOW, ALPHA_LOW, ALPHA_LOW, THETA_HIGH, THETA_HIGH, THETA_HIGH, THETA_HIGH, THETA_HIGH, THETA_LOW, THETA_LOW, THETA_LOW, THETA_LOW, THETA_LOW, DELTA_HIGH, DELTA_MED, DELTA_LOW};

int noteDurations[] = {
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

void setup() {
  digitalWrite(0, LOW);
}

void loop() {
  for (int thisNote = 0; thisNote < 18; thisNote++) {
    int noteDuration = 100000/noteDurations[thisNote];
    tone(0, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 0.1;
    delay(pauseBetweenNotes);
    noTone(0);
  }
}
