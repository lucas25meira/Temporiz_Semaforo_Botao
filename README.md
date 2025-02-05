# Temporiz_Semaforo_Botao
Embarcatech: Unidade 4 - Microcontroladores / Capítulo 5 - Clock e os temporizadores do sistema

## **Descrição**
Este projeto foi desenvolvido como tarefa na capacitação promovida para a EmbarcaTech e demonstra o acionamento de LEDs de forma temporizada e por disparo por botão através de funções do Pico SDK como 'add_alarm_in_ms()'.

## **Funcionalidades do projeto**
- Todos os leds iniciam apagados.
- Ao pressionar o botão, é disparada uma rotina que acende todos os LEDs imediatamente.
- A cada 3 segundos passados, um LED se apaga de forma sequencial (Verde -> Amarelo -> Vermelho).
- Só é possível iniciar um novo disparo pressionando o botão, após o último LED (vermelho) se apagar.

## **Requisitos pra instalação e execução**
- Ambiente de desenvolvimento VSCode configurado com Pico SDK.
- Plugin do Wokwi instalado no VSCode.
