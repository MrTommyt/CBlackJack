#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cartas.h"

int getValorBaraja(Baraja b, int isCrp) {
    int sum = 0;
    int as = 0;

    do {
        if (as){
            if (sum + 11 > 21){
                sum += 1;
                break;
            }
            sum += 11;
        }

        for (int i = 0; i < b.len; i++) {
            Carta carta = b.cartas[i];
            int valor = carta.val.valor;

            if (isCrp && carta.val.simbolo == 'A') {
                as++;
            } else{
                sum += valor;
            }

        }
    } while (as);

    return sum;
}

Palo getRandomPalo(void) {
    srandom(time(NULL));
    int numero = rand() % 4;
    return PALOS[numero];
}

void addCartaToBaraja(Baraja *b, Carta c) {
    b->cartas[b->len] = c;
    b->len++;
}

Carta *getTodasCartas(void) {
    Carta *cartas[52];
    int len = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            Carta carta = {Valores[j], PALOS[i]};
            printf("%s%c%c\n", carta.Palo.color, carta.val.simbolo, carta.Palo.simbolo);
            cartas[len] = &carta;
            len++;
        }
    }
    return *cartas;
}

Baraja generarStack(void) {
    Baraja bar = {0};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            Carta carta = {Valores[j], PALOS[i]};
            bar.cartas[bar.len] = carta;
            bar.len++;
        }
    }
    return bar;
}

Carta getRandomCarta(Baraja *b) {
    srandom(time(NULL));
    int len = b->len;
    int num = rand() % len;
    Carta carta = b->cartas[num];

    for (int i = len; i < 51; i++) {
        b->cartas[i] = b->cartas[i + 1];
    }

    b->len--;
    return carta;
}