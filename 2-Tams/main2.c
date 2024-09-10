#include <stdio.h>


/******** TAREAS *****
 * Compila el código y trata de ejecutarlo. Contesta a las cuestiones
 * 1. ¿Tenemos un problema de compilación o de ejecución?
 * - Si, estamos intentando crear un array en el stack, pero a la hora de la compilación no sabemos aún el tamaño que tenemos que dejar en nuestro stack frame, creo.
 * 2. ¿Por qué se da el problema?. Soluciónalo, compila y ejecuta de nuevo.
 *
 * 3. a,b,c, y x están declaradas de forma consecutiva. ¿Sus direcciones son concesutivas?
 * - No, el standard de C no especifica el padding de cada elemento en memoría, es cosa del compilador y el target.
 * 4. ¿Qué significa el modificar "%lu" en printf()?
 * - long unsigned, es decir 8 bytes, lo que corresponde con una dirección de memoría en una arquitectura de 64 bits.
 * 5. ¿A qué dirección apunta "pc"? ¿Coincide con la de alguna variable anteriormente declarada? Si es así,
 * ¿Coinciden los tamaños de ambas?
 * - pc apunta a la dirección de memoría que contiene a 'x'.
 * - Tienen diferentes tamaños, ya que pc guarda la dirección de memoría, es decir 8bytes en una arquitectura de 64 bits, mientras que &x es un short  de 2 bytes.
 * 6. ¿Coincide el valor del tamaño de "array1" con el número de elementos del array? ¿Por qué?
 * - No, sizeof(array1) es 40 por que alberga 40 bytes. El número de elementos es 10, pero cada uno de ellos ocupa 4 bytes (en mi sistema operativo).
 * - Para conseguir el número de elementos necesitaríamos 'sizeof(array1)/sizeof(int)
 * 7. ¿Coinciden las direcciones a la que apunta cadena1 con la de cadena2?
 * No, aún que CREO que podría ser el caso dependiendo del nivel de optimización
 * 8. ¿Por qué los tamaños (según sizeof()) de cadena1 y cadena2 son diferentes?
 * - sizeof(cadena1) nos dá el tamaño de un puntero, mientras que sizeof(cadena2) nos da su tamaño en bytes, 20 caracteres y el carácter de terminación '\0' que nos indica cuando un null-terminated string (char[]) acaba en C.
***************/

#define ARRAY_SIZE  10

int a = 7;
unsigned long b = 8;
short c;
char x;
char* pc;

int array1[ARRAY_SIZE];
int* array2[]; //Realmente esto no nos dá un tamaño para array2, pero como es una variable que luego no se usa pues nos vale xD

char* cadena1 = "CADENA DE CARACTERES";
char cadena2[] = "CADENA DE CARACTERES";
int main() {
	pc =&x;
	a = 16;
	printf("Direccion de a: %p Tam: %lu \n",&a,sizeof(a));
	printf("Direccion de b: %p Tam: %lu \n",&b,sizeof(b));
	printf("Direccion de c: %p Tam: %lu \n",&c,sizeof(c));
	printf("Direccion de x: %p Tam: %lu \n",&x,sizeof(x));
	printf("Direccion de pc: %p Direccion a la que apunta pc: %p Tam: %lu \n",&pc,pc,sizeof(pc));
	printf("Direccion de array: %p Direccion del elem 0: %p Tam de array: %lu \n",array1, &array1[0], sizeof(array1));
	printf("Direccion de cadena1: %p Direccion a la que apunta: %p Tam: %lu \n",&cadena1,cadena1,sizeof(cadena1));
	printf("Direccion de cadena2: %p Direccion a la que apunta: %p Tam: %lu \n",&cadena2,cadena2,sizeof(cadena2));	
return 0;
}
