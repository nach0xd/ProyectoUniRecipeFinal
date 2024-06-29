#ifndef EXTRA_H
#define EXTRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 6

char **leer_linea_csv(FILE *archivo, char separador);

void limpiarPantalla();

void presioneTeclaParaContinuar();

void mostrarMenuPrincipal();

void mostrarMenuInicial();

char *espacio_inicial(char *cadena);

void eliminar_Comillas(char *str);

int is_equal_str(void *key1, void *key2);

int is_equal_int(void *key1, void *key2);

#endif