#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

int mainMenu(void); //prints opening screen

typedef struct duration
{
	int minutes;
	int seconds;

} Duration;

typedef struct record {
	char artist[30];
	char album[30];
	char songName[30];
	char genre[20];
	Duration songlen;
	int timesPlayed;
	int rating;
} Record;

typedef struct node {
	Record data;
	struct node *pNext;
	struct node *pPrev;
} Node;


void load(Node **pHead); //loads records from file to the doubly linked list

// tries to allocate space for a Node on the heap
// initializes the Node with the item passed in, sets the next pointer to NULL
// returns a pointer to the beginning of the allocated block
Node *makeNode(Record Data);

// inserts an item at the front of the list
// inspired from inclass code
void insertFront(Node **pHead, Record data);

//The “store” command writes the current records, in the dynamic doubly linked list, to the musicPlayList.csv file. The store will completely overwrite the previous contents in the file.
void store(Node *pHead);


//The “display” command prints records to the screen.
void display(Node *pHead);

//The “edit” command must allow the user to find a record in the list by artist.
//The user may modify all of the attributes in the record.
void edit(Node *pHead);

//allows the user to assign a value of 1 – 5 to a song; 1 is the lowest rating and 5 is the highest rating. The rating will replace the previous rating.
void rate(Node *pHead);

//allows the user to select a song, and must start “playing” each song in order from the current song.
void play(Node *pHead);

//The “insert” command must prompt the user for the details of a new record.
void insert(Node **pHead);

//The “delete” command must prompt the user for a song title, and remove the matching record from the list. If the song title does not exist, then the list remains unchanged.
void deletesong(Node **pHead);

//The “sort” command must prompt the user for 4 different methods to sort the records in the list.
void sort(Node *pHead);

//provides a random order in which the songs are played.
void shuffle(Node *pHead);








#endif