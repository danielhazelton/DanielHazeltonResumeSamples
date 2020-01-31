#include "Header.h"

int main(void) {

	char destl[20] = "fire";
	char source[20] = "water";
	/*Stuff for problem 1*/
	printf("Problem 1 destination string: %s\n", destl);
	my_str_n_cat(destl, source);
	printf("Problem 1 source string: %s\n", source);
	printf("Problem 1 new destination string: %s\n", destl);
	/*-----------*/

	/*Stuff for problem 2*/
	int list[20] = { 1,2,6,8,9 };
	int target = 6;
	binary_search(target, list);
	/*-----------*/

	/*Stuff for problem 3*/
	char *arr[20] = { "water","fire","earth","air" };
	int numstr = 4;
	printf("\n");
	printf("%s ", arr[0]);
	printf("%s ", arr[1]);
	printf("%s ", arr[2]);
	printf("%s ", arr[3]);
	printf("\n");
	bubble_sort(arr, numstr);
	printf("%s ", arr[0]);
	printf("%s ", arr[1]);
	printf("%s ", arr[2]);
	printf("%s ", arr[3]);
	printf("\n");
	/*-----------*/


	/*Stuff for problem 4*/
	char palin[100] = "rac ecar";
	int palnum = 8;
	int countpal = 0;
	int valid = 1;
	int pal = is_palindrome(palin, palnum, countpal, valid);
	printf("%d\n", pal);
	/*-----------*/

	/*Stuff for problem 5*/
	int sum = 0;
	int sump, n = 7;
	sump = sum_primes(n, sum);
	printf("%d\n", sump);

	/*-----------*/

	
/*Stuff for problem 6*/
char maxstr[20] = "test string";

typedef struct occurrences
{
	int num_occurrences;
	double frequency;
} Occurrences;


Occurrences array[127];



int i = 0, j = 0;
while (maxstr[j] != '\0') {
	i = maxstr[j];
	if (array[i].num_occurrences < 0) {
		array[i].num_occurrences = 0;
	}
	array[i].num_occurrences += 1;
	j += 1;
}
int k, max = 0;
double fre;
char let;
int len = strlen(maxstr);

for (k = 0;k <= 127;k++) {
	double db = array[k].num_occurrences;
	array[k].frequency = db / len;
	if (array[k].num_occurrences > max || max == 0) {
		max = array[k].num_occurrences;
		let = k;
		fre = array[k].frequency;
	}
}






printf("The letter \"%c\" occured %d times with a frequency of %.2lf\n", let, max, fre);

/*-----------*/
	
	
	
return 0;

}


