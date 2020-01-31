#include "Header.h"

/*Function for problem 1*/
void my_str_n_cat(char *dest, char *source) {
	int n, x = 0, y = 0;
	printf("How many characters of the source string would you like to copy?\n");
	scanf("%d", &n);
	while (dest[x] != '\0') {
		x += 1;
	}
	while (source[y] != '\0'&&n != 0) {
		dest[x] = source[y];
		x += 1;
		y += 1;
		n -= 1;
	}
}

/*Function for problem 2*/
void binary_search(int target, int list[]) {
	int n = 5;

	int left = 1, right = n;
	int mid;
	char found = 'F';
	int targetindex = -1;

	while (found == 'F' && left <= right) {
		mid = (right + left) / 2;
		if (target == list[mid]) {
			found = 'T';
			targetindex = mid;
		}
		if (target < list[mid]) {
			right = mid - 1;
		}
		if (target > list[mid]) {
			left = mid + 1;
		}
	}

	if (found == 'F') {
		printf("FALSE");
	}
	if (found == 'T') {
		printf("TRUE: Location= %d", targetindex);
	}
}


/*Function for problem 3*/
void bubble_sort(char *array[],int num){
    int U,C,N;
    U = num-1;
    char *pholder;
    while (U > 0){
        C = 1;
        while (C<=U){
            
            N = strcmp(array[C], array[C-1]);
            if (N<0){
                pholder = array[C];
                array[C]=array[C-1];
                array[C-1] = pholder;
                
                
            }
            C+=1;
        }
        U-=1;
    }
}

/*Function for problem 4*/
int is_palindrome(char *string, int num, int count, int valid) {
	int n=0;



	if (count<num) {
		if (string[count] == ' ') {
			n = 1;
			count += 1;
		}
		if (string[num - 1] == ' ') {
			n = 1;
			num -= 1;
		}


		if (string[count] != string[num - 1]) {
			valid = 0;
		}
		is_palindrome(string, num - (1+n), count + (1+n), valid);
	}
	else { return valid; }
}

/*Function for problem 5*/
int sum_primes(int n, int sum) {

	if (n == 2) {
		sum += n;
		return sum;
	}
	if (n == 3) {
		sum += n;
	}
	if (n % 3 != 0 && n % 2 != 0 && n != 2) {
		sum += n;
		sum_primes(n - 1, sum);
	}
	else {
		sum_primes(n - 1, sum);
	}
}
