#include "Header.h"

/***********************************
Name: Daniel Hazelton
ID: 011513177
Class: CptS 122
PA#:2
Date Due: 9/13/17
***********************************/





int main(void)
{
	srand(time(NULL));
	int choice = 0;

	Node *pHead = NULL;

	while (choice != 11) {
	
		choice = mainMenu();

		if (choice == 1) {
			load(&pHead);
		}

		if (choice == 2) {
			store(pHead);
		}

		if (choice == 3) {
			display(pHead);
		}

		if (choice == 4) {
			insert(&pHead);
		}
		
		if (choice == 5) {
			deletesong(&pHead);
		}

		if (choice == 6) {
			edit(pHead);
		}
		
		if (choice == 7) {
			sort(pHead);
		}

		if (choice == 8) {
			rate(pHead);
		}

		if (choice == 9) {
			play(pHead);
		}

		if (choice == 10) {
			shuffle(pHead);
		}

		



	}

	if (choice == 11) {
		store(pHead);
		return 0;
	}







	
}