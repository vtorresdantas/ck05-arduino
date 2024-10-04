/*

JOGO DA MEMORIA - COM ARDUINO, SERIAL E BOTÕES

Arnaldo Viana @2021
Adaptação para botões físicos @2024

*/

// Variáveis Globais
String recebido;
String sequenciaNumerica = "";

const int LED_PINS[] = {8, 9, 10};   // Array de LEDs
const int BUTTON_PINS[] = {2, 3, 4}; // Array de Botões

const long SERIAL_TIMEOUT = 10000;   // Timeout de 10 segundos para leitura do Serial
const int NUM_LEDS = sizeof(LED_PINS) / sizeof(LED_PINS[0]);

long numeroGerado;

int sequencia;
bool usandoBotao = false;  // Indica se o jogador está usando botões

// Definindo o enum para os estados do jogo
enum GameState {
  START_GAME,
  LEVEL_1,
  LEVEL_2,
  GAME_OVER,
  PLAY_AGAIN
};
GameState stateGame = START_GAME;

void setup() {
  // Iniciar comunicação serial
  Serial.begin(9600);

  // Definir LEDs como OUTPUTs e botões como INPUTs
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    pinMode(BUTTON_PINS[i], INPUT_PULLUP);  // Configura botões como INPUT com resistor pull-up
  }

  // Definir a seed do gerador de números aleatórios
  randomSeed(analogRead(0));
}

void loop() {
  switch (stateGame) {
    case START_GAME:
      Serial.println("* INICIO *");
      Serial.println("Modo de jogo: (s) Serial ou (b) Botão?");
      leserial();
      if (recebido.equalsIgnoreCase("b")) {
        usandoBotao = true;
        Serial.println("Modo de jogo: Botão");
      } else {
        usandoBotao = false;
        Serial.println("Modo de jogo: Serial");
      }

      Serial.println("Começar? (s/n)");
      leserial();
      if (recebido.equalsIgnoreCase("s")) {
        stateGame = LEVEL_1;
        Serial.println("Jogo começando...");
        piscaled(1000, 3);
      } else {
        stateGame = GAME_OVER;
        Serial.println("Jogo não iniciado");
        piscaled(300, 5);
      }
      break;

    case LEVEL_1:
      Serial.println("* Nível 1 *");
      geraSequencia(1000, 3);
      if (usandoBotao) {
        leBotao(3); // Leitura via botões
      } else {
        leserial(); // Leitura via serial
      }
      if (recebido.equals(sequenciaNumerica)) {
        stateGame = LEVEL_2;
        Serial.println("Parabéns! Próximo nível.");
        piscaled(1000, 3);
      } else {
        stateGame = GAME_OVER;
        Serial.println("Errooooo!!!");
        piscaled(300, 5);
      }
      break;

    case LEVEL_2:
      Serial.println("* Nível 2 *");
      geraSequencia(1000, 5);
      if (usandoBotao) {
        leBotao(5); // Leitura via botões
      } else {
        leserial(); // Leitura via serial
      }
      if (recebido.equals(sequenciaNumerica)) {
        stateGame = GAME_OVER;
        Serial.println("Parabéns! Você venceu!");
        piscaled(1000, 3);
      } else {
        stateGame = GAME_OVER;
        Serial.println("Errooooo!!!");
        piscaled(300, 5);
      }
      break;

    case GAME_OVER:
      Serial.println("Game Over");
      piscaled(100, 5);
      stateGame = PLAY_AGAIN;
      break;

    case PLAY_AGAIN:
      Serial.println("Jogar novamente? (s/n)");
      leserial();
      if (recebido.equalsIgnoreCase("s")) {
        stateGame = LEVEL_1;
        Serial.println("Jogo começando...");
        piscaled(1000, 3);
      } else {
        stateGame = GAME_OVER;
        Serial.println("Jogo não iniciado");
        piscaled(300, 5);
      }
      break;
  }
}

void leserial() {
  Serial.println("* Insira sua resposta *");

  long startTime = millis();
  while (Serial.available() == 0 && millis() - startTime < SERIAL_TIMEOUT) {}

  if (Serial.available()) {
    recebido = Serial.readString();
    recebido.trim();
    Serial.println(recebido);
  } else {
    Serial.println("Timeout! Resposta não recebida.");
  }
}

void leBotao(int sequencia) {
  recebido = "";
  Serial.println("Pressione os botões na sequência.");
  
  for (int i = 0; i < sequencia; i++) {
    bool botaoPressionado = false;
    while (!botaoPressionado) {
      for (int j = 0; j < NUM_LEDS; j++) {
        if (digitalRead(BUTTON_PINS[j]) == LOW) { // Botão pressionado
          recebido += String(j + 1);
          Serial.print("Botão: ");
          Serial.println(j + 1);
          botaoPressionado = true;
          delay(500);  // Debounce simples
        }
      }
    }
  }
  Serial.print("Sequência recebida via botões: ");
  Serial.println(recebido);
}

void piscaled(int tempo, int vezes) {
  for (int i = 0; i < vezes; i++) {
    for (int j = 0; j < NUM_LEDS; j++) {
      digitalWrite(LED_PINS[j], HIGH);
    }
    delay(tempo);
    for (int j = 0; j < NUM_LEDS; j++) {
      digitalWrite(LED_PINS[j], LOW);
    }
    delay(tempo);
  }
}

void geraSequencia(int tempo, int sequencia) {
  int ordemLeds[sequencia];
  sequenciaNumerica = "";

  for (int i = 0; i < sequencia; i++) {
    ordemLeds[i] = random(1, NUM_LEDS + 1);
  }

  for (int j = 0; j < sequencia; j++) {
    int ledIndex = ordemLeds[j] - 1;
    digitalWrite(LED_PINS[ledIndex], HIGH);
    delay(tempo);
    digitalWrite(LED_PINS[ledIndex], LOW);
    delay(tempo);
    sequenciaNumerica += String(ordemLeds[j]);
  }
}
