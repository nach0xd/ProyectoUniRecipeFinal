#include "extra.h"

char **leer_linea_csv(FILE *archivo, char separador) {
    static char linea[MAX_LINE_LENGTH];
    static char *campos[MAX_FIELDS];
    char *ptr, *start;
    int idx = 0;

    if (fgets(linea, MAX_LINE_LENGTH, archivo) == NULL) {
        return NULL; 
    }

    linea[strcspn(linea, "\n")] = '\0';

    ptr = start = linea;
    while (*ptr) {
        if (idx >= MAX_FIELDS - 1)
            break;

        if (*ptr == '\"') { 
            start = ++ptr;    
            while (*ptr && !(*ptr == '\"' && *(ptr + 1) == separador))
                ptr++;
        } else { 
            start = ptr;
            while (*ptr && *ptr != separador)
                ptr++;
        }

        if (*ptr) {
            *ptr = '\0'; 
            ptr++;
            if (*ptr == separador)
                ptr++;
        }

        if (*(ptr - 2) == '\"') {
            *(ptr - 2) = '\0';
        }

        campos[idx++] = start;
    }

    campos[idx] = NULL; 
    return campos;
}

void limpiarPantalla() {
    system("clear");
}

void presioneTeclaParaContinuar() {
    puts("Presione una tecla para continuar...");
    getchar(); 
    getchar(); 
}

void mostrarMenuPrincipal() {
  limpiarPantalla();
  puts("========================================");
  puts("             Menú Principal");
  puts("========================================");

  puts("1) Buscar Recetas por Ingredientes");
  puts("2) Buscar Recetas por Nombre");
  puts("3) Buscar Recetas por Complejidad");
  puts("4) Añadir Recetas a 'Recetas favoritas'");
  puts("5) Mostrar 'Recetas favoritas'");
  puts("6) Salir");
}

void mostrarMenuInicial(){
  limpiarPantalla();
  puts("========================================");
  puts("         Bienvenido a UniRecipe");
  puts("========================================");

  puts("Bienvenido a esta app de recetario para universitarios en la cual tu podrás \ndescubrir una variedad de recetas que se destacan por su sencillez y su \nsabor. Podrás encontrar recetas según los ingredientes que desees, el nombre \nde la receta o su complejidad. Para continuar al menú principal, por favor \ningrese '1' para cargar las recetas del archivo:\n");
  puts("1) Cargar Recetas");
  puts("2) Salir");
}

char *espacio_inicial(char *cadena) {
    while (isspace(*cadena)) {
        cadena++;
    }
    return cadena;
}

void eliminar_Comillas(char *str) {
    char *src = str, *dst = str;
    while (*src) {
        if (*src != '"') {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
}

int is_equal_str(void *key1, void *key2) {
    return strcmp((char *)key1, (char *)key2) == 0;
}

int is_equal_int(void *key1, void *key2) {
    return *(int *)key1 == *(int *)key2;
}