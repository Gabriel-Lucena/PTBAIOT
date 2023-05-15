const int pinoCLK = 3; //PINO DIGITAL (CLK)
const int pinoDT = 4;  //PINO DIGITAL (DT)
const int pinoSW = 5;  //PINO DIGITAL (SW)

int contadorPos = 0; //CONTADOR DE POSIÇÕES DO ENCODER
int ultPosicao;      //REGISTRA A ÚLTIMA POSIÇÃO DO ENCODER
int leituraCLK;      //VARIÁVEL PARA ARMAZENAR LEITURA DO PINO CLK
boolean bCW;         //VARIÁVEL DE CONTROLE DO SENTIDO (HORÁRIO / ANTI-HORÁRIO)

void setup()
{
    Serial.begin(9600);                //INICIALIZA A SERIAL
    pinMode(pinoCLK, INPUT);           //DEFINE O PINO COMO ENTRADA
    pinMode(pinoDT, INPUT);            //DEFINE O PINO COMO ENTRADA
    pinMode(pinoSW, INPUT_PULLUP);     //DEFINE O PINO COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
                                       //DO ARDUINO PARA GARANTIR QUE NÃO EXISTA FLUTUAÇÃO ENTRE 0 (LOW) E 1 (HIGH)
    ultPosicao = digitalRead(pinoCLK); //VARIÁVEL RECEBE A LEITURA DO PINO CLK
}

void loop()
{
    leituraCLK = digitalRead(pinoCLK); //VARIÁVEL RECEBE A LEITURA DO PINO CLK
    if (leituraCLK != ultPosicao)
    { //SE VALOR DA VARIÁVEL FOR DIFERENTE DO VALOR DE "ultPosicao", FAZ
        if (digitalRead(pinoDT) != leituraCLK)
        {                  //SE LEITURA DO PINO FOR DIFERENTE DA LEITURA DE "leituraCLK",
                           //SIGNIFICA QUE O EIXO ESTÁ SENDO GIRADO NO SENTIDO HORÁRIO E FAZ
            contadorPos++; //INCREMENTA CONTAGEM DA VARIÁVEL EM +1
            bCW = true;    //VARIÁVEL BOOLEANA RECEBE VERDADEIRO (SENTIDO HORÁRIO)
        }
        else
        {                  //SENÃO, SIGNIFICA QUE O EIXO ESTÁ SENDO GIRADO NO SENTIDO ANTI-HORÁRIO E FAZ
            bCW = false;   //VARIÁVEL BOOLEANA RECEBE FALSO (SENTIDO ANTI-HORÁRIO)
            contadorPos--; //DECREMENTA CONTAGEM DA VARIÁVEL EM -1
        }
        Serial.print("Giro no "); //IMPRIME O TEXTO NA SERIAL
        if (bCW)
        {                                    //SE VARIÁVEL FOR IGUAL A VERDADEIRO, FAZ
            Serial.print("sentido horário"); //IMPRIME O TEXTO NA SERIAL
        }
        else
        {                                         //SENÃO, FAZ
            Serial.print("sentido anti-horário"); //IMPRIME O TEXTO NA SERIAL
        }
        Serial.print(" / Posição do encoder: "); //IMPRIME O TEXTO NA SERIAL
        Serial.println(contadorPos);             //IMPRIME NO MONITOR SERIAL A POSIÇÃO ATUAL DO ENCODER
    }
    if (digitalRead(pinoSW) == LOW)
    {                                        //SE LEITURA DO PINO FOR IGUAL A LOW, FAZ
        Serial.println("Botão pressionado"); //IMPRIME O TEXTO NA SERIAL
        delay(200);                          //INTERVALO DE 200 MILISSEGUNDOS
    }
    ultPosicao = leituraCLK; //VARIÁVEL RECEBE O VALOR DE "leituraCLK"
}