#include <stdio.h>

typedef struct contBancar {
	char Nume[50], Prenume[50];
	int pin, id;
	float SumaDeBani;
} cont;

void ATM_Options(int index);
void transferBalance(int index);
void extract(int index);
void showBalance(int index);
void ATM();
