#ifndef DS18B20_H
#define DS18B20_H

#include <stm32f103xb.h>
#include <stdbool.h>
#include <stdint.h>

void ds18b20_init();//si
//Inicializar el GPIO y dejar la línea 1-Wire preparada para funcionar.
uint8_t ds18b20_reset();//si
//Generar la secuencia de inicialización del protocolo y detectar si el DS18B20 respondió mediante un presence pulse
void ds18b20_write_bit(uint8_t bit);
//Transmitir un único bit mediante un time slot de escritura.
uint8_t ds18b20_read_bit();
//Generar un time slot de lectura y devolver el bit entregado por el DS18B20.
void ds18b20_write_byte(uint8_t data);
//Transmitir un byte completo utilizando el protocolo 1-Wire.
uint8_t ds18b20_read_byte();
//Recibir un byte completo utilizando los bits obtenidos desde el bus.
void ds18b20_start_conversion();
//Enviar la secuencia de comandos necesaria para indicarle al sensor que realice una nueva medición de temperatura.
float ds18b20_get_temperature();
//Leer los bytes correspondientes a la temperatura desde el Scratchpad, interpretarlos correctamente y devolver temp en celcius.

uint8_t dq_read();

#endif