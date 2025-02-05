/* Programa de capacitação EMBARCATECH
 * Unidade 4 - Microcontroladores / Capítulo 5 - Clock e os temporizadores do sistema
 * Tarefa 2 - Aula Síncrona 29/01/2025
 *
 * Programa desenvolvido por:
 *      - Lucas Meira de Souza Leite
 * 
 * Objetivos: 
 *      - Simular o funcionamento de um semáforo
 *      - Fazer uso da função 'add_alarm_in_ms()' do Pico SDK
 *      - Fazer uso da função 'turn_off_callback()' do Pico SDK
 */

#include <stdio.h>
#include "pico/stdlib.h" 
#include "pico/time.h"   

#define LED_VERMELHO 13 // Definição do GPIO do LED vermelho
#define LED_AMARELO 12 // Definição do GPIO do LED azul
#define LED_VERDE 11 // Definição do GPIO do LED verde
#define BOTAO 5 // Definição do GPIO do botão

bool flag = false;       

// Todos ligados e seta a flag como true
int64_t turn_on_callback_all(alarm_id_t id, void *user_data) {
    gpio_put(LED_VERMELHO, 1); 
    gpio_put(LED_VERDE, 1); 
    gpio_put(LED_AMARELO, 1); 
    flag = true; 
    return 0;
}

// Desliga o verde
int64_t turn_off_callback_verde(alarm_id_t id, void *user_data) {
    gpio_put(LED_VERDE, 0);
    return 0;
}

// Desliga o amarelo
int64_t turn_off_callback_amarelo(alarm_id_t id, void *user_data) {
    gpio_put(LED_AMARELO, 0);
    return 0;
}

// Desliga ao vermelho e seta a flag como false
int64_t turn_off_callback_vermelho(alarm_id_t id, void *user_data) {
    gpio_put(LED_VERMELHO, 0); 
    flag = false;
    return 0;
}

void main() {
    stdio_init_all();

    //Inicialização das GPIOs 
    //Todos os LEDs apagados.
    gpio_init(LED_VERMELHO);              
    gpio_set_dir(LED_VERMELHO, GPIO_OUT); 
    gpio_put(LED_VERMELHO, 0);       

    gpio_init(LED_AMARELO);              
    gpio_set_dir(LED_AMARELO, GPIO_OUT); 
    gpio_put(LED_AMARELO, 0); 

    gpio_init(LED_VERDE);              
    gpio_set_dir(LED_VERDE, GPIO_OUT); 
    gpio_put(LED_VERDE, 0); 

    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);

    while (true) {
        if ((!flag) && (gpio_get(BOTAO) == 0)) {
            sleep_ms(100); 

            add_alarm_in_ms(100, turn_on_callback_all, NULL, false);  // Atraso para ligar todos os LEDs
            add_alarm_in_ms(3000, turn_off_callback_verde, NULL, false); // Atraso de 3 segundos
            add_alarm_in_ms(6000, turn_off_callback_amarelo, NULL, false); // Atraso de 6 segundos
            add_alarm_in_ms(9000, turn_off_callback_vermelho, NULL, false); // Atraso de 9 segundos                
        }
        sleep_ms(100);
    }   
}
