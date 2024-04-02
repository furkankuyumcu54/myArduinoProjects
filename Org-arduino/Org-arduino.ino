#define do 262
#define re 294
#define mi 330
#define fa 349
#define sol 392
#define la 440
#define si 493

void setup() {

  int i;

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  for (i = 2; i < 8; i++) {
    pinMode(i, OUTPUT);
  }

}

void loop() {

  for (int pin = 0; pin < 6; pin++) {
    if (digitalRead(A0 + pin) == HIGH) {
      playNote(getNoteFrequency(pin));
    }
  }
}

float getNoteFrequency(int noteIndex) {
  switch (noteIndex) {
    case 0: return do;
    case 1: return re;
    case 2: return mi;
    case 3: return fa;
    case 4: return sol;
    case 5: return la;
    default: return 0;
  }
}

void playNote(float frequency) {
  float period = 1000.0 / frequency;
  int numSamples = SAMPLE_RATE * period / 1000;
  int t;

  for (t = 0; t < numSamples; t++) {
    float waveform = 0;
    int k;
    for (k = 1; k < 10; k++) { 
      waveform += sin(2 * PI * frequency * t * k / SAMPLE_RATE) / k;
    }
    analogWrite(2, 127.5 + 127.5 * waveform);
    delayMicroseconds(1000000 / SAMPLE_RATE);
  }
  
  analogWrite(2, 0);
}
