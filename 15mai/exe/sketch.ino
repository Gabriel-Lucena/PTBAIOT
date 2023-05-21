
int pinoCLK = 2;
int pinoDT = 3;
int pinoBotao = 4;

int pinoBuzzer = 5;
int frequencia = 5000;
bool botaoPressionado = false;

void setup()
{
  Serial.begin(115200);

  pinMode(pinoCLK, INPUT);
  pinMode(pinoDT, INPUT);
  pinMode(pinoBotao, INPUT_PULLUP);

  pinMode(pinoBuzzer, OUTPUT);
}

int lastClk = HIGH;

void loop()
{

  tone(pinoBuzzer, frequencia);

  int newClk = digitalRead(pinoCLK);

  if (newClk != lastClk)
  {
    lastClk = newClk;

    int dtValue = digitalRead(pinoDT);

    if (newClk == LOW && dtValue == HIGH)
    {
      frequencia += 50;
    }

    if (newClk == LOW && dtValue == LOW)
    {
      frequencia -= 50;
    }
  }

  if (digitalRead(pinoBotao) == LOW)
  {
    botaoPressionado = true;

    noTone(pinoBuzzer);

    delay(100);

    while (botaoPressionado == true)
    {
      if (digitalRead(pinoBotao) == LOW)
      {
        break;
      }
    }

    botaoPressionado = false;

    delay(100);
  }
}