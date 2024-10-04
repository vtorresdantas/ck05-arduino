# CHECKPOINT 5

- O objetivo do checkpoint é avaliar a compreensão dos estudantes em relação ao conteúdo ministrado pela disciplina.
- Obrigatório utilizar como base o código de exemplo do jogo da memória disponível:

https://arnaldojr.github.io/cognitivecomputing/checkpoint/jogomemoria/jogomemoria.ino

https://wokwi.com/projects/409559148540388353

## Integrantes

- Vitor Torres Dantas RM: 88415
- Matheus de Oliveira RM: 88430

## Materiais Necessários:

▶️ Arduino UNO
▶️ LEDs
▶️ Botões
▶️ Buzzer
▶️ Resistores, jumpers e protoboard

## Ideia Geral

![image](https://github.com/user-attachments/assets/a0a7eb6e-d036-41f9-b33a-d9d0ddc3afe7)

### Neste checkpoint, o desafio é desenvolver o protótipo do jogo da memória "Genius" com Arduino, com as seguintes características:

- 4 (ou mais) LEDs de cores diferentes
- 4 (ou mais) Botões
- 1 Buzzer
- Possuir Interface de comunicação serial
- 
Vamos explorar mais detalhadamente o funcionamento do protótipo e os critérios de avaliação.

## Genius Arduino

O jogo tem a dinâmica padrão de qualquer outro jogo da memória: Inicia-se o game, os LEDs piscam em sequência aleatória, e o jogador precisa reproduzir essa sequência pressionando os botões correspondentes. Acertando, avança para o próximo nível; errando, é o fim do jogo.

## Atenção aos requisitos funcionais

# Requisitos Funcionais Básicos:

- LEDs: O jogo deve possuir 4 LEDs de cores diferentes.
- Botões: O jogo deve possuir 4 botões, cada botão corresponde a um LED.
- Buzzer: O jogo deve possuir 1 Buzzer que deve emitir uma frequência específica (nota musical) para cada cor de LED, tanto na sequência aleatória quanto ao pressionar das teclas.
- FASES DO JOGO: O jogo deve possuir 4 niveis de dificuldade.
- Monitor Serial: O jogo deve possuir permitir ao usuário jogar tanto pelos botões físicos quanto pelo monitor serial do Arduino.

# Requisitos Funcionais Avançados:

- FASES DO JOGO: O jogo deve possuir uma quantidade "infinita" de niveis de dificuldade.
- Nivel de dificuldade Crie a função nivelDificuldade que implementa a seleção de dificuldade do jogo em iniciante, médio e hard. Essa função altera a velocidade com que os leds piscam.
- Salvar Pontuações Usar uma memória EEPROM no Arduino para salvar as pontuações mais altas, permitindo que os jogadores vejam e tentem superar seus recordes anteriores.
- Comunicação Bluetooth: Faça a comunicação via bluetooth com o notebook ou celular para jogar o jogo.
- Comando de Voz: Através de um script em Python, ao receber a informação da cor, o computador anuncia em voz alta a cor acionada.
- OUTRAS FEATURES: O grupo pode propor outras features avançadas, mas deve ser aprovado pelo professor.

# Rubrica:

![image](https://github.com/user-attachments/assets/82827850-f909-4871-988b-405e5a03c40c)
