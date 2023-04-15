int pinoled1 = 11;
int pinoled2 = 12;
int pinoled3 = 13;

int tempo = 10000;
int tempo2 = 2000;

void setup()
{
  pinMode(pinoled1, OUTPUT);
  pinMode(pinoled2, OUTPUT);
  pinMode(pinoled3, OUTPUT);
}

void loop()
{
  digitalWrite(pinoled1, HIGH);
  delay(tempo);
  digitalWrite(pinoled1, LOW);
  digitalWrite(pinoled2, HIGH);
  delay(tempo2);
  digitalWrite(pinoled2, LOW);
  digitalWrite(pinoled3, HIGH);
  delay(tempo);
  digitalWrite(pinoled3, LOW);
}