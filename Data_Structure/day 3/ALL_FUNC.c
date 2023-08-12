#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;
node *head = NULL;

void enqueue_last(int data);
int dequeue(void);
node* search(int data); 
void AddAt(int data , int index); 
void deleteAt(int index);
void EditData(int oldData,int NewData);
void print_linked();

int main(){
	int n;
	enqueue_last(5);
	//enqueue_last(6);
	//enqueue_last(7);
	print_linked();
	printf("\n");
	
	deleteAt(4);   // worning
	deleteAt(0);	//delete 5
	print_linked();

	//dequeue();
	//dequeue();
	//dequeue();
	//dequeue();
	//dequeue();
	return 0;
 }
 
void enqueue_last(int data){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = NULL;
	node *current = head;

	if(head == NULL){
		head = newnode;
	}else{
		while(current -> next != NULL){
			current = current->next;
		}
		current ->next = newnode;
	}
}

int dequeue(void){
	if(head != NULL){
		node *current = head;
		int data = current->data;
		if(head -> next == NULL){
			head = NULL;
		}else{
			head = head->next;
		}
		free(current);
		return data;
	}else print_linked(); //go to print with the head = NULL to print EMPTY '-'
	return -1;
}

void print_linked(){
	if(head != NULL){
		node *current = head;
		while(current!=NULL){
			printf("%d	",current->data);
			current = current->next;
		}
	}else{
		printf("\n linked is EMPTY\n");
	}
}



void AddAt(int data , int index){
	int flag = 0;
	node *current = head;
	
	while(current != NULL){ // to know num of node
		current = current->next;
		flag++;
	}
	
	current = head;
	if(head!=NULL){
		if(index <= flag){ 		// to cheack index valid in the zone 
			node *newnode = (node*)malloc(sizeof(node));
			newnode->data = data;
			if(index != 0){ 
				for(int i=0; i<index-1; i++){
					current = current->next;
				}
				newnode->next = current->next;
				current->next = newnode;
				if(flag == 5){
					newnode->next = NULL;
					current->next = newnode;
				}
			}else{ 
				newnode->next = current;
				head = newnode;
			}
		}else 					//if index out of zone
			printf("NOT AVELABLE\n");
	}
}

void deleteAt(int index){
	int flag = 0;
	node *current = head;
	while(current != NULL){ // to know num of nodes
		current = current->next;
		flag++;
		
	}
	current = head;
	if(head!=NULL){
		if(index < flag){ 		// to cheack index valid in the zone
			if(index != 0){
				for(int i=0; i<index-1; i++){
					current = current->next;
				}
				node *temp = current->next;
				current->next = current->next->next;
				free(temp);
			}else{
				head = current->next;
				free(current);
			}
		}else{
			printf("\nNOT AVELABLE\n");
		}
	}else printf("NOT AVELABLE\n");
}

void EditData(int oldData,int NewData){
	node *current = search(oldData);
	if(current != NULL){
		current->data = NewData;
		print_linked();
	}else print_linked();
}
node* search(int data){
	node *current = head;
	//int position = 0;
	while(current->data != data && current->next != NULL){
		current = current->next;
		//position++;
	}
	if(current ->data != data){
		//return -1;
		return NULL;
	}
	if(current != NULL){
		return current;
		//return position;
	}	
}