#include "colors.h"

#ifndef CBLACKJACK_CARTAS_H
#define CBLACKJACK_CARTAS_H

/**
 * Aquí se definen cada uno de los palos que pueden haber
 */
typedef struct {
    char simbolo;
    char color[5];
} Palo;


const Palo HEARTS = {'H', ROJO_T};

const Palo DIAMONDS = {'D', CYAN_T};
const Palo SPADES = {'S', AMARILLO_T};
const Palo CLUB = {'C', VERDE_T};
const Palo PALOS[] = {
        {'H', ROJO_T},
        {'D', CYAN_T},
        {'S', AMARILLO_T},
        {'C', VERDE_T}
};

/**
 * Estos son los valores, y representan, más que nada, el valor neto de la carta.
 * Es decir, sin importar el palo, priorizando mucho más el símbolo de la carta y
 * lo que esta pueda llegar a valer.
 */
typedef struct {
    char simbolo;
    int valor;
} Valor;

const Valor ACE = {'A', 11};

const Valor TWO = {'2', 2};
const Valor THREE = {'3', 3};
const Valor FOUR = {'4', 4};
const Valor FIVE = {'5', 5};
const Valor SIX = {'6', 6};
const Valor SEVEN = {'7', 7};
const Valor EIGHT = {'8', 8};
const Valor NINE = {'9', 9};
const Valor TEN = {'T', 10};
const Valor JACK = {'J', 10};
const Valor KING = {'K', 10};
const Valor QUEEN = {'Q', 10};
const Valor Valores[] = {
        {'A', 1},
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9},
        {'T', 10},
        {'J', 10},
        {'K', 10},
        {'Q', 10}
};

/**
 * Estas son estructuras de datos muy importantes, las barajas y las cartas en sí, las cartas contienen simplemente
 * una información básica del como está compuesta la carta, con su respectivo valor y el palo al que esta pertenece.
 * La baraja puede llegar a mantener un array de cartas y usarse para trabajar como con una interfaz mucho más
 * simple de trabajar
 */
typedef struct {
    Valor val;
    Palo Palo;
} Carta;

typedef struct {
    int len;
    Carta cartas[52];
} Baraja;

int getValorBaraja(Baraja b, int isCrp);

Palo getRandomPalo(void);

void addCartaToBaraja(Baraja *b, Carta c);

Carta *getTodasCartas(void);

Baraja generarStack(void);

Carta getRandomCarta(Baraja *b);

#endif //CBLACKJACK_CARTAS_H
