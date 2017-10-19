/*
 ============================================================================
 Name        : hello2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	while (1)
	{
		puts("Process 2"); /* prints !!!Hello World!!! */
		sleep (1);
	}
	return EXIT_SUCCESS;
}
