#include "atm.h"

void showBalance(int);
void extract(int);
void transferBalance(int);
void ATM();
void ATM_Options(int);

/**
*	Binary search in order to return the index for desired account
*	@params: accounts array, 0, sizeof(arr)/ sizeof(arr[0]), DESIRED ID
*	@returns: id found? index: -1;
*/

int searchID(cont arr[], int l, int r, int x) {
	while (l <= r)
	{
		int m = l + (r - l) / 2;

		if (arr[m].id == x)
			return m;

		if (arr[m].id < x)
			l = m + 1;

		else
			r = m - 1;
	}

	return -1;
}

int main()
{

	ATM();

	return 0;
}


