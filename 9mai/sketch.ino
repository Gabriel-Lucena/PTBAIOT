int pinoLed = 13;

void setup()
{
  pinMode(pinoLed, OUTPUT);
}

void loop()
{
  tone(pinoLed, 5000);
}