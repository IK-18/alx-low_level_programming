#!/bin/bash
#include <stdio.h>

int main (void) {
	char string[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19";
	fwrite(string, sizeof(string) - 1, 1, stdout);
	return(1);
};
