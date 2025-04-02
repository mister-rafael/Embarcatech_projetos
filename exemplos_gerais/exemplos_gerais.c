#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define LED_PIN 25  // Pino do LED embutido na Raspberry Pi Pico

int main() {
    stdio_init_all();  // Inicializa a saída padrão (necessário para printf)
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    absolute_time_t next_blink_time = make_timeout_time_ms(2000); // Define o tempo inicial para 2 segundos no futuro

    while (true) {
        if (absolute_time_diff_us(get_absolute_time(), next_blink_time) < 0) {
            // Já passou do tempo definido, então podemos piscar o LED
            gpio_put(LED_PIN, !gpio_get(LED_PIN)); // Inverte o estado do LED
            printf("LED alternado!\n");

            // Atualiza o tempo para piscar novamente daqui a 2 segundos
            next_blink_time = make_timeout_time_ms(2000);
        }

        // Outras tarefas podem rodar aqui sem bloqueio
        sleep_ms(100); // Pequeno delay para evitar uso excessivo da CPU
    }

    return 0;
}

