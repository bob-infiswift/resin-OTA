/*
 ============================================================================
 Name        : hello.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	while (1)
	{
		puts("Process 1"); /* prints !!!Hello World!!! */
		sleep (1);
	}
	return EXIT_SUCCESS;
}
