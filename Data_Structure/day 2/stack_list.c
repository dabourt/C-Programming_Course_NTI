// PUSH 												prev | data | next
// creat new node 
// put data in data 
// prev point to NULL
// next hold contant of head -- newnode->next=head

// head->prev = newnode //if head != NULL
// head = newnode

// head = newnode , tail = newnode
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}node;

node *head = NULL;
node *tail = NULL;
void push(int data);
void print_linked();
int pop();

int main(){
	push(8);
	push(9);
	print_linked();
	for(int i = 0; i<2;i++){
		printf("\n%d is poped",pop());
	}
	pop();
	push(7);
	printf("\n%d is poped",pop());
	return 0;
}
void push(int d){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = d;
	newnode->prev = NULL;
	
	if(head != NULL){
		newnode->next = head;
		head->prev    = newnode;
		head          = newnode;
	}else{
		newnode->next = NULL;
		head          = newnode;
		tail          = newnode;
	}
}
int pop(){
	node *current = head;
	if(current != NULL){
		int d = current->data;
		if(current->next!=NULL){
			current->next->prev = NULL;
			head = head->next;
		}else{
			head = NULL;
			tail = NULL;
		}
		free(current);
		return d;
	}printf("\nSTACK IS EMPTY");
}

void print_linked(){
	node *current = head;
	
	while(current!=NULL){
		printf("%d	",current->data);
		current = current->next;
	}
}
