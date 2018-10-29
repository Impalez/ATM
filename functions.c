#include "atm.h"

cont bc[] = {
	{"Popescu",		 "Ion",				1111, 0, 1500},
	{"Tupac",		"Shakur",			2592, 1, 2973},
	{"Cristea",	"Alexandru",		0123, 2, 999999},
	{"Dancila",	"Vasilica Viorica",	    9999, 3, 60},
	{"Codreanu",	"Ionel - Daniel",	7218, 4, 5000}
};

void ATM() {
	printf("The card has been introduced, what is your account id?\n");
	int acID;
	scanf("%d", &acID);

	int index = searchID(bc, 0, sizeof(bc) / sizeof(bc[0]), acID);

	if (index == -1) {
		printf("\nAccount ID is invalid, the card will now be ejected");
		return;
	}
	else {

		do {
			printf("\nAccount ID found, please enter your PIN: ");

			// acID will now be used as a pin, in order to free up some memory
			scanf("%d", &acID);

			if (acID != bc[index].pin) printf("Invalid PIN, please try again\n");

		} while (acID != bc[index].pin);


		ATM_Options(index);


	} // end else

}

void showBalance(int index) {
	int option = -1;

	do {
		system("cls");
		printf("Your current balance is: %.2f", bc[index].SumaDeBani);

		printf("\nWould you like to return?\n1 - Yes\n0 - No\n\n");
		scanf("%d", &option);
	} while (option < 0 || option > 1);

	if (!option) {
		printf("\nYour card will be removed shortly. Goodbye!\n");
		return;

	}
	else ATM_Options(index);

}

void extract(int index) {
	float ammount = -1;
	int option = -1;

	do {
		system("cls");

		do {
			printf("Enter the ammount you want to be extracted: ");
			scanf("%f", &ammount);

			if (ammount > bc[index].SumaDeBani) printf("\nInsufficient funds. Try again!\n");

		} while (ammount < 1 || ammount > bc[index].SumaDeBani);

		bc[index].SumaDeBani -= ammount;

		printf("\nWould you like to return?\n1 - Yes\n0 - No\n\n");
		scanf("%d", &option);

	} while (option < 0 || option > 1);

	if (!option) {
		printf("\nYour card will be removed shortly. Goodbye!\n");
		return;

	}
	else ATM_Options(index);

}

void transferBalance(int index) {
	int acID, option = -1, inde = -1, ok = 0;
	float ammount = -1;
	do {
		do {
			printf("\nEnter the other account id: ");
			scanf("%d", &acID);

			inde = searchID(bc, 0, sizeof(bc) / sizeof(bc[0]), acID);

			if (inde == -1) printf("Invalid account. Please try again with another id\n");

		} while (inde == -1);

		do {
			printf("\nEnter the ammount you want to be transfered: ");
			scanf("%f", &ammount);

			if (ammount > bc[index].SumaDeBani) printf("Insufficient funds. Try again!\n");

		} while (ammount < 1 || ammount > bc[index].SumaDeBani);

		do {
			printf("\nAre you sure you want to transfer %.2f to %s %s?\n1 - Yes\n0 - No\n\n", ammount, bc[inde].Prenume, bc[inde].Nume);
			scanf("%d", &ok);
		} while (ok < 0 || ok > 1);

		if (ok) bc[index].SumaDeBani -= ammount, bc[inde].SumaDeBani += ammount;
	
		printf("\nWould you like to return?\n1 - Yes\n0 - No\n\n");
		scanf("%d", &option);

	} while (option < 0 || option > 1);

	if (!option) {
		printf("\nYour card will be removed shortly. Goodbye!\n");
		return;

	}
	else ATM_Options(index);

}

void ATM_Options(int index) {
	int option = -1;

	do {
		system("cls");
		printf("Welcome, %s\n", bc[index].Prenume);
		printf("\nPlease select an option\n1 - Show balance on your current account\n2 - Extract an ammount of money\n3 - Transfer to another account\n0 - Exit\n\n");

		scanf("%d", &option);

		if (option < 0 || option > 3) {
			printf("Invalid input\n");
			system("pause");
		}
	} while (option < 0 || option > 3);

	switch (option) {
	case 1:
		showBalance(index);
		break;
	case 2:
		extract(index);
		break;
	case 3:
		transferBalance(index);
		break;

	case 0:
		printf("\nYour card will be removed shortly. Goodbye!\n");
		return;

	default: break;
	}
}
