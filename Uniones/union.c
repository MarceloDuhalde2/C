// Encabezado del programa
// Programa: Detector de Endianness
// Descripción: Este programa determina si el sistema utiliza formato big-endian 
// o little-endian para almacenar enteros en memoria
// Autor: Marcelo Duhalde
// Fecha: 2011

#include<stdio.h>

// Definición de la unión para analizar bytes individuales de un entero
union {
    int i;              // Variable entera de 4 bytes
    unsigned char c[4]; // Arreglo de 4 bytes para acceder a bytes individuales
} u;

int main()
{
    // Asignamos un valor hexadecimal específico para analizar su orden de bytes
    u.i = 0x12345678;
    
    // Imprimimos si el sistema es big-endian o little-endian
    // Si el primer byte (c[0]) es 0x12, es big-endian
    // Si no, es little-endian
    printf("es %s endian \n", u.c[0] == 0x12 ? "big" : "little");
    
    return 0;  // Indicamos que el programa terminó exitosamente
}