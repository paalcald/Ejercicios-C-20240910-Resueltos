#include <stdio.h>

/************** TAREAS********
 * Compila y ejecuta el código. Contesta a las cuestiones
 * 1. ¿Por qué no es necesario escribir "&list" para obtener la dirección del array list?
 * - Cuando declaras algo como un array es encubiertamente un puntero al comienzo de dicho array.
 * 2. ¿Qué hay almacenado en la dirección de "list"?
 * - El primer elemento del array.
 * 3. ¿Por qué es necesario pasar como argumento el tamaño del array en la función init_array? 
 * - al pasarle un array a una función estas pasando la dirección de memoria del primer miembro y el tamaño de cada miembro por medio del tipo, pero la longitud de dicho array es desconocida para la función.
 * 4. ¿Por qué el tamaño (sizeof())  del array de la función "init_array" no coincide con el declarado en main()?
 * - La función sólo está recibiendo el puntero en sí.
 * 5. ¿Por qué NO es necesario para omo argumento el tamaño del array en la función init_array2?
 * - Realmente se está definiendo init_array[5], no un init_array para un tamaño arbitrario.
 * 6. ¿Coincide el  tamaño (sizeof())  del array de la función "init_array2" con el declarado en main()?
 * - No, sigue siendo un puntero dentro de la función
 *+**************/

#define N 5

void init_array(int array[], int size) ;
void init_array2(int array[N]);

int main(void) {
	int i,list[N];
	printf("Dir de list %p Dir de list[0]: %p  Dir de list[1]: %p. Sizeof list %lu \n",list,&list[0],&list[1],sizeof(list));
	
	init_array(list, N);
	for (i = 0; i < N; i++)
		printf("next: %d ", list[i]);
	printf("\n-------------------------\n");

	init_array2(list);
	for (i = 0; i < N; i++)
		printf("next: %d ", list[i]);
	printf("\n-------------------------\n");
}

void init_array(int array[], int size) { 
	int i;
	printf("Direccion de array: %p Sizeof array %lu \n", array, sizeof(array));
	for (i = 0; i < size; i++)
		array[i] = i;
	printf("Array initialized\n\n");
}

void init_array2(int array[N]) { 
	int i;
	printf("Direccion de array: %p Sizeof array %lu \n", array, sizeof(array));
	for (i = 0; i < N; i++)
		array[i] = i*2;
	printf("Array initialized\n\n");
}


