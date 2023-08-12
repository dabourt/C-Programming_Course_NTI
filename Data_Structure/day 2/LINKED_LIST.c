//// get the address to next node ,save it in current pointer
//// put data in variable(d)
//// delete the contant of head pointer
//// head = current
//// return d

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
}node;
node* head=NULL;

int delete_first();
void print_linked();
void AddFrist(int d);
void AddLast(int d);

int main(){
	AddFrist(5);
	AddFrist(7);
	AddLast(6);
	AddLast(1);
	AddLast(6);
	AddLast(3);

	print_linked();

	DeleteLast();
	delete_first();
	print_linked();
	delete_first();
	delete_first();
	delete_first();
	delete_first();
	delete_first();
	delete_first();
	delete_first();	
	return 0;
}
int delete_first(){
	if(head != NULL){
		node *current = head;
		int d;
		d = current->data;
		current = current->next;
		free(head);
		head = current;
		return d;
	}
}

void print_linked(){
	if(head != NULL){
		node *current = head;
		while(current!=NULL){
			printf("%d	",current->data);
			current = current->next;
		}
	}
}

void AddFrist(int d)
{
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=d;
	newnode->next=head;
	head=newnode;
}

void AddLast(int d)
{
	node*current=head;
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=d;
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;
	}
	else
	{
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=newnode;
	}
	

}
int DeleteLast(void)
{
	if(head!=NULL)
	{
		int d;
		node*current=head;
		while(current->next->next!=NULL)
		{
			current=current->next;
		}
		d=current->next->data;
		free(current->next);
		current->next=NULL;
		return d;
	}
	
}