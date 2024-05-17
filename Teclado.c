#include "Teclado.h"
#include "MKL25Z4.h"
#include "ctype.h"
int i, j;
int pinColumnas[4]={1, 2, 3, 4};
int pinFilas[4]={5,6,7,8};
char teclado [4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

void init(char port){
    char port= toupper(port);
    switch (port){
    case 'A':
    for(i=0; i<4; i++){
        PORTA->PCR[pinColumnas[i]]|=PORT_PCR_MUX(1);
        PORTA->PCR[pinFilas[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
        PORTA->PCR[pinFilas[i]]|=PORT_PCR_MUX(1);
    }
        break;
            case 'B':
    for(i=0; i<4; i++){
        PORTB->PCR[pinColumnas[i]]|=PORT_PCR_MUX(1);
        PORTB->PCR[pinFilas[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
        PORTB->PCR[pinFilas[i]]|=PORT_PCR_MUX(1);
    }
        break;
            case 'C':
    for(i=0; i<4; i++){
        PORTC->PCR[pinColumnas[i]]|=PORT_PCR_MUX(1);
        PORTC->PCR[pinFilas[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
        PORTC->PCR[pinFilas[i]]|=PORT_PCR_MUX(1);
    }
        break;
            case 'D':
    for(i=0; i<4; i++){
        PORTD->PCR[pinColumnas[i]]|=PORT_PCR_MUX(1);
        PORTD->PCR[pinFilas[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
        PORTD->PCR[pinFilas[i]]|=PORT_PCR_MUX(1);
    }
        break;
            case 'E':
    for(i=0; i<4; i++){
        PORTE->PCR[pinColumnas[i]]|=PORT_PCR_MUX(1);
        PORTE->PCR[pinFilas[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
        PORTE->PCR[pinFilas[i]]|=PORT_PCR_MUX(1);
    }
        break;
    

    }

}
char tecla (char port){
    char port= toupper(port);
    int Est_columnas;
    switch (port){
    case'A':
    for( i=0; i<4; i++){
        PTA->PSOR|=(0<<pinColumnas[i]);
        for (j = 0; j <4; j++){
            Est_columnas= PTA->PDIR&(0<<pinColumnas[j]);
           if((Est_columnas==0)){
            return teclado[i][j];
           }
        }
        PTA->PSOR|=(1u<<pinColumnas[i]);
    }
        break;
     case'B':
    for( i=0; i<4; i++){
        PTB->PSOR|=(0<<pinColumnas[i]);
        for (j = 0; j <4; j++){
            int Est_columnas= PTB->PDIR&(0<<pinColumnas[j]);
           if((Est_columnas==0)){
            return teclado[i][j];
           }
        }
        PTB->PSOR|=(1u<<pinColumnas[i]);
    }
        break;
         case'C':
    for( i=0; i<4; i++){
        PTC->PSOR|=(0<<pinColumnas[i]);
        for (j = 0; j <4; j++){
            Est_columnas= PTC->PDIR&(0<<pinColumnas[j]);
           if((Est_columnas==0)){
            return teclado[i][j];
           }
        }
        PTC->PSOR|=(1u<<pinColumnas[i]);
    }
        break;
        case'D':
    for( i=0; i<4; i++){
        PTD->PSOR|=(0<<pinColumnas[i]);
        for (j = 0; j <4; j++){
            Est_columnas= PTD->PDIR&(0<<pinColumnas[j]);
           if((Est_columnas==0)){
            return teclado[i][j];
           }
        }
        PTD->PSOR|=(1u<<pinColumnas[i]);
    }
        break;
        case'E':
    for( i=0; i<4; i++){
        PTE->PSOR|=(0<<pinColumnas[i]);
        for (j = 0; j <4; j++){
            Est_columnas= PTE->PDIR&(0<<pinColumnas[j]);
           if((Est_columnas==0)){
            return teclado[i][j];
           }
        }
        PTE->PSOR|=(1u<<pinColumnas[i]);
    }
        break;
    }

}
