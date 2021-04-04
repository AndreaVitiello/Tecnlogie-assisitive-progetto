#define TRIG_PIN 10
#define ECHO_PIN 9
#define TEMPERATURA_PIN A0

void setup(){
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIG_PIN, LOW);
}

void loop(){
  int input = analogRead(TEMPERATURA_PIN);
  float temperatura = input / 2.046;
  
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long tempo = pulseIn(ECHO_PIN, HIGH);
  float velocita = 0.03314 + 0.000062 * temperatura;
  float distanza = velocita * tempo / 2;

  Serial.println("Distanza: " + String(distanza) + "cm"+ " ------ Mentre la temperatura  = " +String(temperatura));
  delay(1000);
}
