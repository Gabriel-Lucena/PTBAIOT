int ThermistorPin = A0;
int LedPin = 13;
float R1 = 10000; // valor de R1 na placa
float logR2, R2, T;
float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741; // coeficientes de Steinhart-Hart para o termistor
const float BETA = 3950;                                        // Deve corresponder ao coeficiente beta do termistor

void setup()
{
    Serial.begin(9600);
    pinMode(LedPin, OUTPUT); // define o pino do LED como saída
}

void loop()
{
    int Vo = analogRead(ThermistorPin);
    float celsius = 1 / (log(1 / (1023. / Vo - 1)) / BETA + 1.0 / 298.15) - 273.15;

    Serial.print("Temperatura: ");
    Serial.print(celsius);
    Serial.println(" C");

    if (celsius < 24)
    {
        digitalWrite(LedPin, HIGH);
    }

    else
    {
        digitalWrite(LedPin, LOW);
    }
}