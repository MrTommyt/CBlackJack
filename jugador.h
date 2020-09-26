#ifndef CBLACKJACK_JUGADOR_H
#define CBLACKJACK_JUGADOR_H

typedef struct {
    Baraja bar;
    char nombre[16];
    int acabar;
} Jugador;

Jugador getJugador();

const Jugador croupier = {{0}, "Croupier", 0};

void printBaraja(Jugador j, int isCrp, int mostrar);

void TurnarJugador(Jugador *jugador, Baraja *bar);

void TurnarCroupier(Jugador *jugador, Baraja *bar);

#endif //CBLACKJACK_JUGADOR_H
