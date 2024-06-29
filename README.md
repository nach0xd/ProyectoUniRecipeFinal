*Nota:* Para correr el programa en el shell: gcc tdas/*.c main.c -Wno-unused-result -o prueba, y luego ./prueba

## UniRecipe, recetario para estudiantes universitarios

Esta aplicación esta creada con el fin de apoyar a los estudiantes de educación superior a mantener una dieta sana, ofreciendoles diversas recetas que se destacan por su sencillez y rapidez en su preparación. El archivo "recetas.csv" que se sube a este programa contiene X recetas con su respectiva información, como nombre, ingredientes, complejidad, preparación paso a paso, etc.

## Funcionalidades de la aplicación
**1) Cargar recetas:** El programa carga los datos de cada recetas que contiene el archivo  

**2) Buscar recetas por ingredientes:** El programa permite al usuario buscar recetas dependiendo de el ingrediente que posea, buscando en la lista de ingredientes de cada receta dentro del mapa, si encuentra alguna receta o recetas que contengan el ingrediente que posea el usuario entonces el programa muestra el nombre de dicha receta o recetas

**3) Buscar recetas por nombre:** El programa permite al usuario buscar una receta por el nombre de esta misma, si la receta se encuentra dentro del mapa el programa muestra todo el contenido del struct de esa receta

**4) Buscar recetas por complejidad:** El programa permite al usuario buscar recetas dependiendo de la complejidad que tengan, permitiendole elegir entre tres opciones, 1 para "Fácil", 2 para "Media" y 3 para "Difícil". El usuario al elegir una opcion hace que el programa recorra el mapa para buscar todas las recetas con la complejidad deseada para luego mostrar los nombres de cada receta con la complejidad deseada

**5) Añadir receta a 'Recetas favoritas':** El programa permite al usuario añadir recetas a una lista de recetas favoritas mediante escribiendo el nombre de la receta, el programa logra esto cambiando el estado de favoritos de la receta buscada de 0 a 1, de esta manera considerando esa receta como una receta favorita 

**6) Mostrar 'Recetas favoritas':** El programa permite al usuario ver las recetas que marcó previamente como favoritas, mostrando una lista de todas las recetas favoritas, el programa realiza esto buscando en el mapa cada receta con el estado de favorito igual a 1 para luego añadirlas a la lista de favoritos que finalmente se mostrará 

## ¿Cómo se interactúa con la app?
PASO 1: CARGAR LAS RECETAS

Apretas "Run" y en "console" te debería aparecer el siguiente menú:
````
========================================
         Bienvenido a UniRecipe
========================================
Bienvenido a esta app de recetario para universitarios en la cual tu podrás 
descubrir una variedad de recetas que se destacan por su sencillez y su 
sabor. Podrás encontrar recetas según los ingredientes que desees, el nombre 
de la receta o su complejidad. Para continuar al menú principal, por favor 
ingrese '1' para cargar las recetas del archivo:

1) Cargar Recetas
2) Salir
Ingrese su opción: 1
````
En "Ingrese su opción:" colocas 1 para que se carguen las recetas.


PASO 2: BUSCAR RECETAS POR INGREDIENTES

Al ingresar 1 anteriormente te debería mostrar otro menú:
````
========================================
             Menú Principal
========================================
1) Buscar Recetas por Ingredientes
2) Buscar Recetas por Nombre
3) Buscar Recetas por Complejidad
4) Añadir Recetas a 'Recetas favoritas'
5) Mostrar 'Recetas favoritas'
6) Salir
Ingrese su opción: 1
````
En "Ingrese su opción:" colocas 1 para que puedas buscar por ingredientes. Te debería mostrar lo siguiente:
````
========================================
             Menú Principal
========================================
1) Buscar Recetas por Ingredientes
2) Buscar Recetas por Nombre
3) Buscar Recetas por Complejidad
4) Añadir Recetas a 'Recetas favoritas'
5) Mostrar 'Recetas favoritas'
6) Salir
Ingrese su opción: 1
Ingrese el nombre de los ingredientes a buscar:
````
En "Ingrese el nombre de los ingredientes a buscar:" escribes los ingredientes que deseas buscar, tienes que escribirlos en minúscula, se buscan por tres ingredientes, solamente tienes que separarlos con una coma.
El programa te arrojará todas las recetas que tenga al menos un ingrediente que deseas buscar. Así deberías de hacerlo:
````
=======================================
             Menú Principal
========================================
1) Buscar Recetas por Ingredientes
2) Buscar Recetas por Nombre
3) Buscar Recetas por Complejidad
4) Añadir Recetas a 'Recetas favoritas'
5) Mostrar 'Recetas favoritas'
6) Salir
Ingrese su opción: 1
Ingrese el nombre de los ingredientes a buscar: cebolla, tomate, pollo
````
La app te debería mostrar el nombre de las recetas, si deseas ver todo el contenido de la receta tienes que buscar por nombre, más adelante lo explicaremos.
````
========================================
             Menú Principal
========================================
1) Buscar Recetas por Ingredientes
2) Buscar Recetas por Nombre
3) Buscar Recetas por Complejidad
4) Añadir Recetas a 'Recetas favoritas'
5) Mostrar 'Recetas favoritas'
6) Salir
Ingrese su opción: 1
Ingrese el nombre de los ingredientes a buscar
(se puede buscar hasta por tres ingredientes, sepárelos con una coma): cebolla, tomate, pollo

Recetas encontradas:
-> Ensalada de Atún
-> Wrap de Pollo y Verduras
-> Arroz con Pollo
````


PASO 4: BUSCAR RECETAS POR NOMBRE

Tras haber buscado por ingredientes, te debería haber arrojado en este menú:
````
========================================
             Menú Principal
========================================
1) Buscar Recetas por Ingredientes
2) Buscar Recetas por Nombre
3) Buscar Recetas por Complejidad
4) Añadir Recetas a 'Recetas favoritas'
5) Mostrar 'Recetas favoritas'
6) Salir
Ingrese su opción: 2
````
En "Ingrese su opción:" colocas 2 para que puedas buscar por nombre. Aquí podrás buscar las recetas y te arrojará todo su contenido. Te debería mostrar lo siguiente:
````
========================================
             Menú Principal
========================================
1) Buscar Recetas por Ingredientes
2) Buscar Recetas por Nombre
3) Buscar Recetas por Complejidad
4) Añadir Recetas a 'Recetas favoritas'
5) Mostrar 'Recetas favoritas'
6) Salir
Ingrese su opción: 2
Ingrese el nombre de la receta que desea buscar: 
````
En "Ingrese el nombre de la receta que desea buscar:" colocas el nombre de la recetas, tiene que estar escrito idéntico de como está en la app.
````
========================================
             Menú Principal
========================================
1) Buscar Recetas por Ingredientes
2) Buscar Recetas por Nombre
3) Buscar Recetas por Complejidad
4) Añadir Recetas a 'Recetas favoritas'
5) Mostrar 'Recetas favoritas'
6) Salir
Ingrese su opción: 2
Ingrese el nombre de la receta que desea buscar: 
Arroz con Pollo
````
Te debiése arrojar todo su contenido.
````
========================================
             Menú Principal
========================================
1) Buscar Recetas por Ingredientes
2) Buscar Recetas por Nombre
3) Buscar Recetas por Complejidad
4) Añadir Recetas a 'Recetas favoritas'
5) Mostrar 'Recetas favoritas'
6) Salir
Ingrese su opción: 2
Ingrese el nombre de la receta que desea buscar: Arroz con Pollo

Receta:
-> Arroz con Pollo

Ingredientes: 
-> arroz  pollo  cebolla  pimentón  ajo  aceite  sal  agua 

Procedimiento: 
-> En una olla grande, calienta 2 cucharadas de aceite a fuego medio. Sofríe 1 cebolla picada y 1 pimentón picado hasta que la cebolla esté transparente. Añade 500 g de pollo trozado y cocina hasta que esté dorado por todos lados. Incorpora 1 diente de ajo picado y 1 taza de arroz; mezcla bien. Vierte 2 tazas de agua hirviendo, sazona con sal al gusto, y reduce el fuego a bajo. Cocina tapado durante 15-20 minutos o hasta que el arroz esté tierno y el líquido se haya absorbido.

Complejidad: Media
````


PASO 4: BUSCAR RECETAS POR COMPLEJIDAD

Aquí es básicamente hacer lo mismo que en los otros paso, tienes que colocar 3 en "Ingrese su opción:".
````
========================================
             Menú Principal
========================================
1) Buscar Recetas por Ingredientes
2) Buscar Recetas por Nombre
3) Buscar Recetas por Complejidad
4) Añadir Recetas a 'Recetas favoritas'
5) Mostrar 'Recetas favoritas'
6) Salir
Ingrese su opción: 3
````
Te debería mostrar esto:
````
========================================
             Menú Principal
========================================
1) Buscar Recetas por Ingredientes
2) Buscar Recetas por Nombre
3) Buscar Recetas por Complejidad
4) Añadir Recetas a 'Recetas favoritas'
5) Mostrar 'Recetas favoritas'
6) Salir
Ingrese su opción: 3
Ingrese el número de complejidad (1: Fácil, 2: Media, 3: Difícil): 
````
En "Ingrese el número de complejidad (1: Fácil, 2: Media, 3: Difícil):", deberás colocar 1, si deseas buscar una receta de complejidad fácil, 2 , si deseas buscar una receta de complejidad media y 3, si deseas buscar una receta de complejidad difícil.
````
========================================
             Menú Principal
========================================
1) Buscar Recetas por Ingredientes
2) Buscar Recetas por Nombre
3) Buscar Recetas por Complejidad
4) Añadir Recetas a 'Recetas favoritas'
5) Mostrar 'Recetas favoritas'
6) Salir
Ingrese su opción: 3
Ingrese el número de complejidad (1: Fácil, 2: Media, 3: Difícil): 1
````
Te debería arrojar todos los nombres de las recetas que tengan una complejidad fácil.
````
========================================
             Menú Principal
========================================
1) Buscar Recetas por Ingredientes
2) Buscar Recetas por Nombre
3) Buscar Recetas por Complejidad
4) Añadir Recetas a 'Recetas favoritas'
5) Mostrar 'Recetas favoritas'
6) Salir
Ingrese su opción: 3
Ingrese el número de complejidad (1: Fácil, 2: Media, 3: Difícil): 1

Recetas de complejidad Fácil:
-> Ensalada de Pollo y Fideos de Arroz
-> Wrap de Hummus y Vegetales
-> Sopa de Pollo y Vegetales
-> Wrap de Pollo y Verduras
-> Ensalada de Atún
````

Después puede utilizar la opción de buscar por nombre, si deseas saber todo el contenido de una receta.

PASO 5: AÑADIR RECETAS A "RECETAS FAVORITAS"
En "Ingrese su opción:" debes colocar 4 y te debería mostrar esto:
````
========================================
             Menú Principal
========================================
1) Buscar Recetas por Ingredientes
2) Buscar Recetas por Nombre
3) Buscar Recetas por Complejidad
4) Añadir Recetas a 'Recetas favoritas'
5) Mostrar 'Recetas favoritas'
6) Salir
Ingrese su opción: 4
Ingrese el nombre de la receta que desea agregar a favoritos: 
````
En "Ingrese el nombre de la receta que desea agregar a favoritos:" tienes que ingresar el nombre de la receta, al ingresarlo te deberia mostrar un mensaje diciendo que "ha sido agregada la lista de favoritos".
````
========================================
             Menú Principal
========================================
1) Buscar Recetas por Ingredientes
2) Buscar Recetas por Nombre
3) Buscar Recetas por Complejidad
4) Añadir Recetas a 'Recetas favoritas'
5) Mostrar 'Recetas favoritas'
6) Salir
Ingrese su opción: 4
Ingrese el nombre de la receta que desea agregar a favoritos: Arroz con Pollo
La receta 'Arroz con Pollo' ha sido agregada a la lista de favoritos.
````
Para añadir otras recetas, tienes que hacer el mismo procedimiento.

PASO 6: MOSTRAR "RECETAS FAVORITAS"
En "Ingrese su opción:" debes colocar 5 y te debería mostrar todas las recetas que hayas añadido como favorita.
````
========================================
             Menú Principal
========================================
1) Buscar Recetas por Ingredientes
2) Buscar Recetas por Nombre
3) Buscar Recetas por Complejidad
4) Añadir Recetas a 'Recetas favoritas'
5) Mostrar 'Recetas favoritas'
6) Salir
Ingrese su opción: 5

Recetas favoritas:
-> Arroz con Pollo
````
PASO 7: SALIR DEL PROGRAMA
En "Ingrese su opción:" debes colocar 6 para salir del Menú principal.
````
========================================
             Menú Principal
========================================
1) Buscar Recetas por Ingredientes
2) Buscar Recetas por Nombre
3) Buscar Recetas por Complejidad
4) Añadir Recetas a 'Recetas favoritas'
5) Mostrar 'Recetas favoritas'
6) Salir
Ingrese su opción: 6
````
Te arrojará al Menú inicial, y en "Ingrese su opción:" debes colocar 2.
````
========================================
         Bienvenido a UniRecipe
========================================
Bienvenido a esta app de recetario para universitarios en la cual tu podrás 
descubrir una variedad de recetas que se destacan por su sencillez y su 
sabor. Podrás encontrar recetas según los ingredientes que desees, el nombre 
de la receta o su complejidad. Para continuar al menú principal, por favor 
ingrese '1' para cargar las recetas del archivo:

1) Cargar Recetas
2) Salir
Ingrese su opción: 2
````
De esta manera la app va a dejar de funcionar.