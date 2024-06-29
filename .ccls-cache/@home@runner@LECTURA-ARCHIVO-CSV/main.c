#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tdas/list.h"
#include "tdas/map.h"
#include "tdas/extra.h"

typedef struct {
  char id[100];
  char nombre_receta[50];
  List *ingredientes;
  char procedimiento[800];
  int complejidad;
  int estado_fav;
} cont_receta;


void cargar_recetas(Map *recetas_byid) {
  FILE *archivo = fopen("data/recetas.csv", "r");
  if (archivo == NULL) {
      printf("No se pudo abrir el archivo.\n");
      return;
  }

  char **campos;
  while ((campos = leer_linea_csv(archivo, ',')) != NULL) {

      cont_receta *receta = malloc(sizeof(cont_receta));
      if (receta == NULL) {
          printf("Error de memoria.\n");
          break;
      }

      eliminar_Comillas(campos[0]);
      strncpy(receta->id, campos[0], sizeof(receta->id) - 1);
      receta->id[sizeof(receta->id) - 1] = '\0';

      eliminar_Comillas(campos[1]);
      strncpy(receta->nombre_receta, campos[1], sizeof(receta->nombre_receta) - 1);
      receta->nombre_receta[sizeof(receta->nombre_receta) - 1] = '\0';

      receta->ingredientes = list_create();
      eliminar_Comillas(campos[2]);
      char *token = strtok(campos[2], ",");
      while (token != NULL) {
          char *ingrediente = strdup(token);
          list_pushBack(receta->ingredientes, ingrediente);
          token = strtok(NULL, ",");
      }

      eliminar_Comillas(campos[3]);
      strncpy(receta->procedimiento, campos[3], sizeof(receta->procedimiento) - 1);
      receta->procedimiento[sizeof(receta->procedimiento) - 1] = '\0';

      eliminar_Comillas(campos[4]);
      receta->complejidad = atoi(campos[4]);
      receta->estado_fav = 0;

      map_insert(recetas_byid, receta->id, receta);

  }

  fclose(archivo);
  printf("Recetas cargadas correctamente\n");
}

void rellenar_mapa_ingredientes(Map *recetas_byingredients, Map *recetas_byid){
  MapPair *iter = map_first(recetas_byid); 

  while (iter != NULL){ 
    cont_receta *recetas = iter->value; 
    char *node = list_first(recetas->ingredientes); 
    while (node != NULL) { 
      MapPair *pair = map_search(recetas_byingredients, node); 
      if (pair == NULL){ 
        List * lista = list_create(); 
        map_insert(recetas_byingredients, strdup(node), lista); 
        list_pushBack(lista, recetas);                            
      } else {
        List *lista = pair->value; 

        if (lista == NULL){ 
          lista = list_create(); 
          pair->value = lista; 
        }
        list_pushBack(lista, recetas);       
      }
      node = list_next(recetas->ingredientes); 
    }
    iter = map_next(recetas_byid); 
  }
}

void buscar_por_ingredientes(Map *recetas_byingredients) {
    char entrada[60];
    char ingrediente1[20] = "";
    char ingrediente2[20] = "";
    char ingrediente3[20] = "";

    printf("Ingrese el nombre de los ingredientes a buscar\n(se puede buscar hasta por tres ingredientes, sepárelos con una coma): ");
    scanf(" %[^\n]s", entrada);

    char *token = strtok(entrada, ",");
    if (token != NULL) {
        eliminar_Comillas(token);
        strncpy(ingrediente1, token, sizeof(ingrediente1) - 1);
        ingrediente1[sizeof(ingrediente1) - 1] = '\0';
    }
    token = strtok(NULL, ",");
    if (token != NULL) {
        eliminar_Comillas(token);
        strncpy(ingrediente2, token, sizeof(ingrediente2) - 1);
        ingrediente2[sizeof(ingrediente2) - 1] = '\0';
    }
    token = strtok(NULL, ",");
    if (token != NULL) {
        eliminar_Comillas(token);
        strncpy(ingrediente3, token, sizeof(ingrediente3) - 1);
        ingrediente3[sizeof(ingrediente3) - 1] = '\0';
    }

    List *result = list_create();

    if (strlen(ingrediente1) > 0) {
        MapPair *pair = map_search(recetas_byingredients, ingrediente1);
        if (pair != NULL) {
            List *recetas = pair->value;
            void *receta = list_first(recetas);
            while (receta != NULL) {
                if (!list_contains(result, receta)) {
                    list_pushBack(result, receta);
                }
                receta = list_next(recetas);
            }
        }
    }

    if (strlen(ingrediente2) > 0) {
        MapPair *pair = map_search(recetas_byingredients, ingrediente2);
        if (pair != NULL) {
            List *recetas = pair->value;
            void *receta = list_first(recetas);
            while (receta != NULL) {
                if (!list_contains(result, receta)) {
                    list_pushBack(result, receta);
                }
                receta = list_next(recetas);
            }
        }
    }

    if (strlen(ingrediente3) > 0) {
        MapPair *pair = map_search(recetas_byingredients, ingrediente3);
        if (pair != NULL) {
            List *recetas = pair->value;
            void *receta = list_first(recetas);
            while (receta != NULL) {
                if (!list_contains(result, receta)) {
                    list_pushBack(result, receta);
                }
                receta = list_next(recetas);
            }
        }
    }
    printf("\nRecetas encontradas:\n");
    if (list_first(result) != NULL) {
        void *receta = list_first(result);
        while (receta != NULL) {
            cont_receta *rec = (cont_receta *)receta;
            printf("-> %s\n", rec->nombre_receta);
            /*printf("ID: %s\n", rec->id);
            printf("Procedimiento: %s\n", rec->procedimiento);
            printf("Complejidad: %d\n", rec->complejidad);
            printf("Estado favorito: %d\n", rec->estado_fav);*/
            receta = list_next(result);
        }
    } else {
        printf("No se encontraron recetas con los ingredientes especificados.\n");
    }

    list_clean(result);
}

void rellenar_mapa_nombre(Map *recetas_bynombre, Map *recetas_byid) {
  MapPair *iter = map_first(recetas_byid); 

  while (iter != NULL) {
      cont_receta *receta = iter->value; 
      map_insert(recetas_bynombre, strdup(receta->nombre_receta), receta); 
      iter = map_next(recetas_byid); 
  }
}

void buscar_por_nombre(Map *recetas_bynombre) {
  char nombre_receta[100];

  printf("Ingrese el nombre de la receta que desea buscar: ");
  scanf(" %[^\n]s", nombre_receta);

  MapPair *par = map_search(recetas_bynombre, nombre_receta);
  if (par != NULL) {
      cont_receta *receta = (cont_receta *)par->value;
      printf("\nReceta:\n-> %s\n", receta->nombre_receta);
      printf("\nIngredientes: \n-> ");
      void *ingrediente = list_first(receta->ingredientes);
      while (ingrediente != NULL) {
          printf("%s ", (char *)ingrediente);
          ingrediente = list_next(receta->ingredientes);
      }
      printf("\n\nProcedimiento: \n-> %s\n", receta->procedimiento);
      if (receta->complejidad == 1) printf("\nComplejidad: Fácil\n");
      else if (receta->complejidad == 2) printf("\nComplejidad: Media\n");
    else printf("\nComplejidad: Difícil\n");
      //printf("Estado favorito: %d\n", receta->estado_fav);
  } else {
      printf("No se encontró la receta con el nombre especificado.\n");
  }
}

void rellenar_mapa_complejidad(Map *recetas_bycomplejidad, Map *recetas_byid){
    MapPair *pair = map_first(recetas_byid); 

    while(pair != NULL)
    {
    cont_receta *receta = pair->value; 
    MapPair *aux = map_search(recetas_bycomplejidad, &receta->complejidad);

    if(aux == NULL) 
    {
      List *recetaComplejidad = list_create(); 
      list_pushFront(recetaComplejidad, receta);
      map_insert(recetas_bycomplejidad, &receta->complejidad, recetaComplejidad); 
    } else {
      List *auxList = aux->value; 
      list_pushFront(auxList, receta); 
    }
    pair = map_next(recetas_byid); 
    }
}

void buscar_por_complejidad(Map *recetas_bycomplejidad) {
    int complejidad;
    printf("Ingrese el número de complejidad (1: Fácil, 2: Media, 3: Difícil): ");
    scanf("%d", &complejidad);

    if (complejidad < 1 || complejidad > 3) {
        printf("Complejidad no válida. Ingrese un número del 1 al 3.\n");
        return;
    }

    printf("\nRecetas de complejidad ");
    if (complejidad == 1) printf(" Fácil:\n");
    else if (complejidad == 2) printf(" Media:\n");
    else printf(" Difícil:\n");
  
    MapPair *pair = map_search(recetas_bycomplejidad, &complejidad);
    if (pair != NULL) {
        List *recetas = (List *)pair->value;
        void *receta = list_first(recetas);

        while (receta != NULL) {
            cont_receta *rec = (cont_receta *)receta;
            printf("\nReceta:\n-> %s\n", rec->nombre_receta);
            //printf("ID: %s\n", rec->id);
            printf("\nIngredientes: \n-> ");
            void *ingrediente = list_first(rec->ingredientes);
            while (ingrediente != NULL) {
                printf("%s ", (char *)ingrediente);
                ingrediente = list_next(rec->ingredientes);
            }
            printf("\n\nProcedimiento: \n-> %s\n", rec->procedimiento);
            //printf("Complejidad: %d\n", rec->complejidad);
            //printf("Estado favorito: %d\n", rec->estado_fav);
            receta = list_next(recetas);
        }
    } else {
        printf("No se encontraron recetas con la complejidad especificada.\n");
    }
}

// revisar
void rellenar_mapa_favoritos(Map *recetas_byfavoritos, Map *recetas_byid){
    MapPair *pair = map_first(recetas_byid);
    
    while(pair != NULL){
        cont_receta *receta = pair->value;
        MapPair *aux = map_search(recetas_byfavoritos, &receta->estado_fav);
        if(aux == NULL){
            List *recetaFavoritos = list_create();
            list_pushFront(recetaFavoritos, receta);
            map_insert(recetas_byfavoritos, &receta->estado_fav, recetaFavoritos);
        } else {
            List *auxList = aux->value;
            list_pushFront(auxList, receta);
        }
        pair = map_next(recetas_byid);
    }
}

void agregar_a_favoritos(Map *recetas_byfavoritos, Map *recetas_bynombre) {
    char nombre_receta[100];

    printf("Ingrese el nombre de la receta que desea agregar a favoritos:\n");
    scanf(" %[^\n]s", nombre_receta);

    MapPair *par = map_search(recetas_bynombre, nombre_receta);
    if (par != NULL) {
        cont_receta *receta = (cont_receta *)par->value;

        if (receta->estado_fav == 1) {
            printf("La receta '%s' ya se encuentra en la lista de favoritos.\n", receta->nombre_receta);
            return;
        }
      
        receta->estado_fav = 1;

        MapPair *aux = map_search(recetas_byfavoritos, &receta->estado_fav);
        if (aux == NULL) {
            List *recetaFavoritos = list_create();
            list_pushFront(recetaFavoritos, receta);
            map_insert(recetas_byfavoritos, &receta->estado_fav, recetaFavoritos);
        } else {
            List *auxList = aux->value;
            list_pushFront(auxList, receta);
        }

        printf("La receta '%s' ha sido agregada a la lista de favoritos.\n", receta->nombre_receta);
    } else {
        printf("No se encontró la receta con el nombre especificado.\n");
    }
}

void mostrar_favoritos(Map *recetas_byfavoritos){
    int estado_favorito = 1; 

    MapPair *pair = map_search(recetas_byfavoritos, &estado_favorito);
    if (pair != NULL) {
        List *recetas_favoritas = (List *)pair->value;
        void *receta = list_first(recetas_favoritas);

        while (receta != NULL) {
            cont_receta *rec = (cont_receta *)receta;
            printf("-> %s\n", rec->nombre_receta);
            receta = list_next(recetas_favoritas);
        }
    } else {
        printf("No hay recetas marcadas como favoritas.\n");
    }
}

int main() {
  char opcion, opcion2;

  Map *recetas_byid = map_create(is_equal_int);
  Map *recetas_byingredientes = map_create(is_equal_str);
  Map *recetas_bynombre = map_create(is_equal_str);
  Map *recetas_bycomplejidad = map_create(is_equal_int);
  Map *recetas_byfavoritos = map_create(is_equal_int);
  
  do {
    mostrarMenuInicial();
    printf("Ingrese su opción: ");
    scanf(" %c", &opcion);
    
    switch (opcion){
      case '1':
      cargar_recetas(recetas_byid);
      rellenar_mapa_ingredientes(recetas_byingredientes, recetas_byid);
      rellenar_mapa_nombre(recetas_bynombre, recetas_byid);
      rellenar_mapa_complejidad(recetas_bycomplejidad, recetas_byid);
      rellenar_mapa_favoritos(recetas_byfavoritos, recetas_byid);
      presioneTeclaParaContinuar();
        
      do {
        mostrarMenuPrincipal();
        printf("Ingrese su opción: ");
        scanf(" %c", &opcion2);

        switch (opcion2) {
        case '1':
          buscar_por_ingredientes(recetas_byingredientes);
          break;
        case '2':
          buscar_por_nombre(recetas_bynombre);
          break;
        case '3':
          buscar_por_complejidad(recetas_bycomplejidad);
          break;
        case '4':
          agregar_a_favoritos(recetas_byfavoritos, recetas_bynombre);
          break;
        case '5':
          printf("\nRecetas favoritas:\n");
          mostrar_favoritos(recetas_byfavoritos);
          break;
        case '6':
          printf("Salir a Menú de inicio\n");
          break;
        default:;
        }
        presioneTeclaParaContinuar();
        
      } while (opcion2 != '6');

    }
  } while (opcion != '2');

  return 0;
}