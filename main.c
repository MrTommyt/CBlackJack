#include <stdio.h>
#include "cartas.h"
#include "jugador.h"
#include "colors.h"

//char ss[] = "♥♦♠♣";
int salir = 1;

int main() {
    while (salir) {
        int inPartida = 1;
        Baraja mazo = generarStack();
        Jugador jugador = getJugador();
        Jugador crp = croupier;

        addCartaToBaraja(&jugador.bar, getRandomCarta(&mazo));
        addCartaToBaraja(&crp.bar, getRandomCarta(&mazo));
        addCartaToBaraja(&jugador.bar, getRandomCarta(&mazo));
        while (inPartida) {
            printBaraja(jugador, 0, 1);
            printBaraja(crp, 1, 0);

            TurnarJugador(&jugador, &mazo);
            TurnarCroupier(&crp, &mazo);

            int valJ = getValorBaraja(jugador.bar, 0);
            int valC = getValorBaraja(crp.bar, 0);
            if (valJ > 21 || valC > 21 || (jugador.acabar && crp.acabar)) {
                int diffJ = valJ - 21;
                int diffC = valC - 21;

                if (diffJ == diffC) {
                    printf(AMARILLO_T "¡Uy! Es un empate\n");
                    printf("Esto no se queda así, esto se resolverá en otra ocasión\n" RESET_COLOR);

                } else if ((valC > 21 && valJ < 21) ||
                (((21 < valJ && valJ < valC) || (21 > valJ && valJ > valC)) && (valC > 21 || diffJ < diffC))) {
                    printf(VERDE_T "¡%s ha ganado con %i puntos!\n", jugador.nombre, valJ);
                    printf("Los %i puntos del Crupier no han sido suficientes para detenerte\n", valC);
                    printf("¡Felicidades!\n" RESET_COLOR);

                } else {
                    printf(ROJO_T "Los %i no han sido suficientes, %s\n", valJ, jugador.nombre);
                    printf("¡El Crupier ha ganado magistralmente con %i puntos!\n", valC);
                    printf("La próxima será\n" RESET_COLOR);

                }

                inPartida--;
            }
        }

        if (!salir) {
            printf(VERDE_T "Gracias por jugar " ROJO_T "<3");
            break;
        }
    }
    return 0;
}
