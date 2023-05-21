
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
    // Se alterou o valor de CLK
    lastClk = newClk;
    int dtValue = digitalRead(pinoDT);
    if (newClk == LOW && dtValue == HIGH)
    {
      // Serial.println("Sentido horário ⏩");

      frequencia += 50;
    }
    if (newClk == LOW && dtValue == LOW)
    {
      // Serial.println("Sentido anti-horário ⏪");

      frequencia -= 50;
    }
  }

  if (digitalRead(pinoBotao) == LOW)
  {
    // Serial.println("Botão pressionado!");

    botaoPressionado = true;

    while (botaoPressionado == true)
    {

      noTone(pinoBuzzer);

      // Serial.println("Botão pressionado! 😮");

      if (digitalRead((pinoBotao)) == LOW)
      {
        break;
      }
    }
    // Serial.println("Saiu!");

    botaoPressionado = false;

    tone(pinoBuzzer, frequencia);
  }
}