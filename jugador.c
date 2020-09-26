#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "cartas.h"
#include "jugador.h"

Jugador getJugador() {
    Baraja bar = {0};
    Jugador j = {
            bar,
            "Jugador",
            0
    };
    return j;
}

void printBaraja(Jugador j, int isCrp, int mostrar) {
    Baraja b = j.bar;
    char line[] = "---------------------------";

    printf(AMARILLO_T "-%s-" RESET_COLOR "\n" , line);
    printf(AMARILLO_T"| " NEGRO_T "[" VERDE_T "%i" NEGRO_T "]\t" CYAN_T "%s" RESET_COLOR "\n",
            !mostrar ? b.cartas[0].val.valor : getValorBaraja(j.bar, isCrp),
            j.nombre);
    printf(AMARILLO_T "-%s-" RESET_COLOR "\n", line);

    printf(AMARILLO_T "|| ");
    for (int i = 0; i < b.len; i++) {
        if (i > 0 && !mostrar) {
            printf(NEGRO_T "??");
        } else {
            printf("%s%c%c", b.cartas[i].Palo.color, b.cartas[i].val.simbolo, b.cartas[i].Palo.simbolo);
        }
        if (i < b.len - 1){
            printf(AMARILLO_T " | ");
        }
    }
    printf(AMARILLO_T " ||\n");
    printf(AMARILLO_T "-%s-" RESET_COLOR "\n\n", line);
}

void TurnarJugador(Jugador *jugador, Baraja *bar) {
    printf(AZUL_T "Por medio del siguiente puede seleccionar las acciones que desea realizar\n");
    printf(VERDE_T "1. Tomar\n");
    printf(ROJO_T "2. Parar" RESET_COLOR "\n");

    while (1) {
        long eleccion;
        char str[16];
        char *ptr;
        scanf("%s", str);
        eleccion = strtol(str, &ptr, 10);

        if (eleccion == 1) {
            addCartaToBaraja(&jugador->bar, getRandomCarta(bar));
            break;
        }
        if (eleccion == 2) {
            jugador->acabar = 1;
            break;
        }
        printf(ROJO_T "Lo ingresado no es válido\n" RESET_COLOR);
    }
}

void TurnarCroupier(Jugador *jugador, Baraja *bar) {
    if (getValorBaraja(jugador->bar, 1) < 17) {
        addCartaToBaraja(&jugador->bar, getRandomCarta(bar));
    } else {
        jugador->acabar = 1;
    }
}
