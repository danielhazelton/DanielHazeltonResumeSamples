#include "Header.h"

int mainMenu(void) {//prints opening screen
	printf("Welcome to DMM. Please enter one of the options\n");
	printf("(1) load\n(2) store\n(3) display\n(4) insert\n(5) delete\n(6) edit\n(7) sort\n(8) rate\n(9) play\n(10) shuffle\n(11) exit\n");
	int select = 0;
	scanf("%d", &select);
	
	return select;
}

void load(Node **pHead) {
	FILE *infile = NULL;
	infile = fopen("musicPlayList.csv", "r");//opens file for reading
	Node *pMem = NULL;
	
	
	char songinfo[100]="";
	
	Record Data;




	while (!feof(infile)) {
		fgets(songinfo, 100, infile);
		
		
		
		const char split[2] = ",";
		char *token;
		token = strtok(songinfo, split);
		strcpy(Data.artist, token);
		if (Data.artist[0] == '"') {
			token = strtok(NULL, split);
			strcat(Data.artist, ",");
			strcat(Data.artist, token);
		}

		token = strtok(NULL, split);
		strcpy(Data.album, token);
		token = strtok(NULL, split);
		strcpy(Data.songName, token);
		token = strtok(NULL, split);
		strcpy(Data.genre, token);
		token = strtok(NULL, ":");
		Data.songlen.minutes = atoi(token);
		token = strtok(NULL, split);
		Data.songlen.seconds = atoi(token);
		token = strtok(NULL, split);
		Data.timesPlayed = atoi(token);
		token = strtok(NULL, split);
		Data.rating = atoi(token);

		insertFront(pHead, Data);
		
		}


	fclose(infile);
	
	
}


Node *makeNode(Record Data) {
	
	Node *pMem = NULL;
	
	pMem = (Node *)malloc(sizeof(Node));// allocate space on heap
	
	
	
	
	if (pMem != NULL) // malloc succeeded
	{
		// init memory
		pMem->pNext = NULL;
		pMem->pPrev = NULL;
		strcpy(pMem->data.artist, Data.artist);
		strcpy(pMem->data.album, Data.album);
		strcpy(pMem->data.songName, Data.songName);
		strcpy(pMem->data.genre, Data.genre);
		pMem->data.songlen.minutes = Data.songlen.minutes;
		pMem->data.songlen.seconds = Data.songlen.seconds;
		pMem->data.timesPlayed = Data.timesPlayed;
		pMem->data.rating = Data.rating;

		
		


		}

	



	return pMem;
}


// inserts an item at the front of the list
// inspired from inclass code
void insertFront(Node **pHead, Record Data)
{
	

	Node *pcurrent = NULL;
	

	
	pcurrent = makeNode(Data);
	
	if (*pHead == NULL)// dealing with an empty list!
	{
		*pHead = pcurrent;
	}

	else // // not dealing with empty list
	{
		pcurrent->pNext = *pHead;// pMem points to the beginning of the list
		pcurrent->pNext->pPrev = pcurrent;// node in front is set to point its pPrev pointer to new pcurrent
		*pHead = pcurrent; // p_head now points to the new node
		}
	}

void store(Node *pHead) {
	FILE *outfile = NULL;
	outfile = fopen("musicPlayList.csv", "w");//opens file for writing
	

	Node *testtemp = pHead;


	while (testtemp != NULL) {
		fprintf(outfile,"%s", testtemp->data.artist);
		fprintf(outfile, ",%s", testtemp->data.album);
		fprintf(outfile, ",%s", testtemp->data.songName);
		fprintf(outfile, ",%s", testtemp->data.genre);
		fprintf(outfile, ",%d", testtemp->data.songlen.minutes);
		fprintf(outfile, ":%d", testtemp->data.songlen.seconds);
		fprintf(outfile, ",%d", testtemp->data.timesPlayed);
		fprintf(outfile, ",%d", testtemp->data.rating);
		if (testtemp->pNext != NULL) {
			fprintf(outfile, "\n");
		}
		testtemp = testtemp->pNext;
	}//while (testtemp != NULL)



	fclose(outfile);
}


void display(Node *pHead) {

	Node *pTemp = pHead;
	int choice = 0;
	while (choice != 1 && choice != 2){
	printf("What would you like to do?\n");
	printf("1) Print all records.\n");
	printf("2) Print all records that match an artist.\n");

	scanf("%d", &choice);

	


	if (choice == 1) {
		while (pTemp != NULL) {
			printf("%s", pTemp->data.artist);
			printf(",%s", pTemp->data.album);
			printf(",%s", pTemp->data.songName);
			printf(",%s", pTemp->data.genre);
			printf(",%d", pTemp->data.songlen.minutes);
			printf(":%d", pTemp->data.songlen.seconds);
			printf(",%d", pTemp->data.timesPlayed);
			printf(",%d\n", pTemp->data.rating);
			pTemp = pTemp->pNext;
		}//while (pTemp != NULL)
	}//if select=1
	if (choice == 2) {
		char name[50] = "";

		printf("What artist would you like to look for?\n");
		getchar();
		gets(name);
		while (pTemp != NULL) {
			if (strcmp(pTemp->data.artist, name) == 0) {
				printf("%s", pTemp->data.artist);
				printf(",%s", pTemp->data.album);
				printf(",%s", pTemp->data.songName);
				printf(",%s", pTemp->data.genre);
				printf(",%d", pTemp->data.songlen.minutes);
				printf(":%d", pTemp->data.songlen.seconds);
				printf(",%d", pTemp->data.timesPlayed);
				printf(",%d\n", pTemp->data.rating);
			}//if (strcmp(pTemp->data.artist, name) == 0)
				pTemp = pTemp->pNext;
			
		}//while (pTemp != NULL)

		}//(select == 2)
	}//(select != 1 && select != 2)
}

void edit(Node *pHead) {
	Node *pTemp = pHead;
	
	char name[50] = "";

	printf("What artist would you like to look for?\n");
	getchar();
	gets(name);
	int check = 0;
	
	while (pTemp != NULL) {
		if (strcmp(pTemp->data.artist, name) == 0) {
			printf("%s", pTemp->data.artist);
			printf(",%s", pTemp->data.album);
			printf(",%s", pTemp->data.songName);
			printf(",%s", pTemp->data.genre);
			printf(",%d", pTemp->data.songlen.minutes);
			printf(":%d", pTemp->data.songlen.seconds);
			printf(",%d", pTemp->data.timesPlayed);
			printf(",%d\n", pTemp->data.rating);
		
			check = 0;
		printf("Is this the correct song?(1=yes 2=no)\n");
		scanf("%d",&check);
		
		if (check == 1) {
			int change = 0;
			printf("What would you like to change?\n");
			printf("1) Artist\n2) Album Title\n3) Song Title\n4) Genre\n5) Song length\n6) Times Played\n7) Rating\n");
			scanf("%d", &change);
			if (change == 1) {
				printf("What do you want to change it to?\n");
				getchar();
				gets(pTemp->data.artist);
			}
			if (change == 2) {
				printf("What do you want to change it to?\n");
				getchar();
				gets(pTemp->data.album);
			}
			if (change == 3) {
				printf("What do you want to change it to?\n");
				getchar();
				gets(pTemp->data.songName);
			}
			if (change == 4) {
				printf("What do you want to change it to?\n");
				getchar();
				gets(pTemp->data.genre);
			}
			
			if (change == 5) {
				printf("What do you want to change the minutes to?\n");
				scanf("%d", &pTemp->data.songlen.minutes);
				printf("Seconds?\n");
				scanf("%d", &pTemp->data.songlen.seconds);
			}
			if (change == 6) {
				printf("What do you want to change it to?\n");
				scanf("%d", &pTemp->data.timesPlayed);
			}
			if (change == 7) {
				printf("What do you want to change it to?\n");
				scanf("%d", &pTemp->data.rating);
			}

			return;
		}
		}//if (strcmp(pTemp->data.artist, name) == 0)
		pTemp = pTemp->pNext;
		
	}//while (pTemp != NULL)
	if (check == 2) {
		printf("That was the last song by this artist. Please try again.\n");
	}





}


void rate(Node *pHead) {
	Node *pTemp = pHead;

	char name[50] = "";

	printf("What song would you like to rate?\n");
	getchar();
	gets(name);
	int rating = 0;
	int go = 1;
	while (pTemp != NULL) {
		if (strcmp(pTemp->data.songName, name) == 0) {
			printf("%s", pTemp->data.artist);
			printf(",%s", pTemp->data.album);
			printf(",%s", pTemp->data.songName);
			printf(",%s", pTemp->data.genre);
			printf(",%d", pTemp->data.songlen.minutes);
			printf(":%d", pTemp->data.songlen.seconds);
			printf(",%d", pTemp->data.timesPlayed);
			printf(",%d\n", pTemp->data.rating);
			go = 1;
			while (go == 1) {
				printf("What would you like to rate it (1-5)?\n");
				scanf("%d", &rating);
				if (rating > 5 || rating < 1) { printf("Choose a valid number\n"); }

				else {
					pTemp->data.rating = rating;
					go = 0;
				}

			}
		}
		pTemp = pTemp->pNext;
	}

}


void play(Node *pHead) {
	Node *pTemp = pHead;

	char name[50] = "";

	printf("What song would you like to start with?\n");
	getchar();
	gets(name);
	int start = 0;

	while (pTemp != NULL) {
		if (strcmp(pTemp->data.songName, name) == 0) {
			start = 1;
		}
		if (start == 1) {
			system("cls");
			printf("%s", pTemp->data.artist);
			printf(",%s", pTemp->data.album);
			printf(",%s", pTemp->data.songName);
			printf(",%s", pTemp->data.genre);
			printf(",%d", pTemp->data.songlen.minutes);
			printf(":%d", pTemp->data.songlen.seconds);
			printf(",%d", pTemp->data.timesPlayed);
			printf(",%d\n", pTemp->data.rating);
			Sleep(5000);
			system("cls");

		}

		pTemp = pTemp->pNext;
	}


}


void insert(Node **pHead) {
	Record NewIns;


	printf("What is the song's Artist?\n");
	getchar();
	gets(NewIns.artist);
	printf("What is the song's Album title?\n");
	gets(NewIns.album);
	printf("What is the song's Title?\n");
	gets(NewIns.songName);
	printf("What is the song's Album Genre?\n");
	gets(NewIns.genre);
	printf("What is the song's length (minutes only)?\n");
	scanf("%d", &NewIns.songlen.minutes);
	printf("What is the song's remaining seconds?\n");
	scanf("%d", &NewIns.songlen.seconds);
	printf("What is the song's number of times played?\n");
	scanf("%d", &NewIns.timesPlayed);
	printf("What is the song's rating?\n");
	scanf("%d", &NewIns.rating);

	insertFront(pHead, NewIns);


}

void deletesong(Node **pHead) {
	
	char name[50] = "";
	printf("What song would you like to delete?\n");
	getchar();
	gets(name);
	Node *del = *pHead;
	Node *Prev = NULL;
	Node *Next = del->pNext;
	
	
	while (del != NULL) {
		
		if (strcmp(del->data.songName, name) == 0) {
			if (del->pPrev==NULL) {
				*pHead = del->pNext;
				free(del);
				return;
			}
			if (del->pNext == NULL) {
				Prev->pNext = NULL;
				free(del);
				return;
			}
			
			else {
				Next->pPrev = del->pPrev;
				Prev->pNext = del->pNext;
				free(del);
				return;
			}
		}
		else {
			Prev = del;
			del = del->pNext;
			if (del != NULL) {
				Next = del->pNext;
			}
		}
	}
	

}

void sort(Node *pHead) {
	int choice = 0;
	printf("How would you like to sort the list?\n");
	printf("1) Sort based on artist (A-Z)\n2) Sort based on album title(A-Z)\n3) Sort based on rating(1 - 5)\n4) Sort based on times played(largest - smallest)\n");
	scanf("%d", &choice);

	if (choice == 1) {
		int swapped = 0;
		
		Node *ptr1 = NULL;
		Node *lptr = NULL;



		do
		{
			swapped = 0;
			ptr1 = pHead;

			while (ptr1->pNext != lptr)
			{
				char string[100] = "";
				char string2[100] = "";
				strcpy(string, ptr1->data.artist);
				strcpy(string2, ptr1->pNext->data.artist);
				if (string[0] == '\"') {
					memmove(string, string + 1, strlen(string));
				}
				if (string2[0] == '\"') {
					memmove(string2, string2 + 1, strlen(string2));
				}
				
				
				if (strcmp(string, string2)>0)
				{
					Record temp;
					temp = ptr1->data;
					ptr1->data = ptr1->pNext->data;
					ptr1->pNext->data = temp;
					swapped = 1;
				}
				ptr1 = ptr1->pNext;
			}
			lptr = ptr1;
		} while (swapped);
	}
	
	if (choice == 2) {
		int swapped = 0;

		Node *ptr1 = NULL;
		Node *lptr = NULL;



		do
		{
			swapped = 0;
			ptr1 = pHead;

			while (ptr1->pNext != lptr)
			{
				char string[100] = "";
				char string2[100] = "";
				strcpy(string, ptr1->data.album);
				strcpy(string2, ptr1->pNext->data.album);
				if (string[0] == '\"') {
					memmove(string, string + 1, strlen(string));
				}
				if (string2[0] == '\"') {
					memmove(string2, string2 + 1, strlen(string2));
				}


				if (strcmp(string, string2)>0)
				{
					Record temp;
					temp = ptr1->data;
					ptr1->data = ptr1->pNext->data;
					ptr1->pNext->data = temp;
					swapped = 1;
				}
				ptr1 = ptr1->pNext;
			}
			lptr = ptr1;
		} while (swapped);
	}
	
	if (choice == 3) {
		int swapped = 0;
		int i = 0;
		Node *ptr1= NULL;
		Node *lptr = NULL;



		do
		{
			swapped = 0;
			ptr1 = pHead;

			while (ptr1->pNext != lptr)
			{
				if (ptr1->data.rating > ptr1->pNext->data.rating)
				{
					Record temp;
					temp = ptr1->data;
					ptr1->data = ptr1->pNext->data;
					ptr1->pNext->data = temp;
					swapped = 1;
				}
				ptr1 = ptr1->pNext;
			}
			lptr = ptr1;
		}
		while (swapped);
	}
	
if (choice == 4) {
	int swapped = 0;
	int i = 0;
	Node *ptr1 = NULL;
	Node *lptr = NULL;



	do
	{
		swapped = 0;
		ptr1 = pHead;

		while (ptr1->pNext != lptr)
		{
			if (ptr1->data.timesPlayed < ptr1->pNext->data.timesPlayed)
			{
				Record temp;
				temp = ptr1->data;
				ptr1->data = ptr1->pNext->data;
				ptr1->pNext->data = temp;
				swapped = 1;
			}
			ptr1 = ptr1->pNext;
		}
		lptr = ptr1;
	} while (swapped);
	}


}


void shuffle(Node *pHead) {
	int listlen = 0;
	Node *pTemp = pHead;
	Node *pPlay = pHead;
	int array[100];

	while (pTemp != NULL) {
		listlen += 1;
		pTemp = pTemp->pNext;
		array[listlen - 1] = listlen;
	}
	if (listlen > 1)
	{
		int i=0;
		for (i = 0; i < listlen - 1; i++)
		{
			int j = i + rand() / (RAND_MAX / (listlen - i) + 1);
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
		}
	}
	int k=0;
	int r = 1;
	for (k = 0; k < listlen - 1; k++) {
		while (array[k]!=r) {
			if (r < array[k]) {
				pPlay = pPlay->pNext;
				r += 1;
			}
			if (r > array[k]) {
				pPlay = pPlay->pPrev;
				r -= 1;
			}
							}
		system("cls");
		printf("%s", pPlay->data.artist);
		printf(",%s", pPlay->data.album);
		printf(",%s", pPlay->data.songName);
		printf(",%s", pPlay->data.genre);
		printf(",%d", pPlay->data.songlen.minutes);
		printf(":%d", pPlay->data.songlen.seconds);
		printf(",%d", pPlay->data.timesPlayed);
		printf(",%d\n", pPlay->data.rating);
		Sleep(5000);
		system("cls");
	}
	
	
	
	

}



















