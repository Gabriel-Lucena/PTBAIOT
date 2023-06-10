int pinoSensor = 13;
int pinoLed = 9;
int pinoBuzzer = 6;

int frequencia = 20000;

void setup()
{
  pinMode(pinoSensor, INPUT);
  pinMode(pinoLed, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);
}

void loop()
{
  if (digitalRead(pinoSensor) == HIGH)
  {
    digitalWrite(pinoLed, HIGH);
    tone(pinoBuzzer, frequencia);

    frequencia += 400;

    delay(100);
  }

  else
  {
    noTone(pinoBuzzer);

    frequencia = 5000;
    digitalWrite(pinoLed, LOW);

    delay(100);
  }

  delay(100);
}