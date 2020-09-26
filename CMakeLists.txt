cmake_minimum_required(VERSION 3.17)
project(CBlackJack C)

set(CMAKE_C_STANDARD 99)

add_executable(CBlackJack main.c cartas.h colors.h jugador.h jugador.c cartas.c)