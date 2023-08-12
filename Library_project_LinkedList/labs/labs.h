#ifndef LABS_H
#define LABS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../std_type/STD_TYPES.h"

typedef struct node{
	u8 book_name [50];
	u8 author[50];
	u16 price;
	struct node *next;
}node;

void interfacing(void);
void Addbook_Last(void);
void print_list(void);
void get_book(void);
node* search(void);
void DeleteBook(void);
void search_author(void);
void book_price(void);

#endif