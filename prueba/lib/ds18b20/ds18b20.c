#include <ds18b20.h>
int presence;

int RROM = 0x33;
int convert_t = 0x44;
int W_scratch = 0x4E;
int R_scratch = 0xBE;


uint8_t dq_read(presence){
    presence = GPIOB->IDR & (1<<10); 
    return presence;
}

void ds18b20_init(){
    RCC->APB2ENR|= RCC_APB2ENR_IOPBEN;

    GPIOB->CRL&=~(0xF<<(9%8)*4);
    GPIOB->CRL|= (0x4<<(9%8)*4);//floating input

    GPIOB->CRL&=~(0x5<<(10%8)*4);
    GPIOB->CRL|= (0x5<<(10%8)*4);//open drain
}

uint8_t ds18b20_reset(){

    GPIOB-> BSRR|=(1<<(10+16));//bajo
    delay_us(470);//tiempo reinicio

    GPIOB-> BSRR|=(1<<10);//espero presencia

    delay_us(69);//tiemppo espero presensia
    dq_read();
    if(presence) return;//cancel

    GPIOB-> BSRR|=(1<<(10+16));//todo ok, dqlow

    for(int i=0; i <16; i++){ //read rom cmd porque 1 solo sensor
        if(RROM[i]) GPIOB->BSRR |= (1<<10);
        else GPIOB->BSRR |= (1<<10+16); //envio cmd
    }
}

void ds18b20_write_bit(uint8_t bit){
    ds18b20_reset();

}

uint8_t ds18b20_read_bit(){
    ds18b20_reset();

}

void ds18b20_write_byte(uint8_t data){
    ds18b20_reset();

}

uint8_t ds18b20_read_byte(){
    ds18b20_reset();

}

void ds18b20_start_conversion(){
    ds18b20_reset();
    for(int i=0; i <16; i++){ //read rom cmd porque 1 solo sensor
        if(convert_t[i]) GPIOB->BSRR |= (1<<10);
        else GPIOB->BSRR |= (1<<10+16); //envio cmd
    }
}

float ds18b20_get_temperature(){
    ds18b20_reset();

}



