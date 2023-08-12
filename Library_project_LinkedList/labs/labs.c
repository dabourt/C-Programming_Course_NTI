#include "labs.h"

node *head = NULL;
extern u8 option;
node *prev;

void interfacing(void){
	printf("\n---------------------------------------");
	printf("\nChoose one of the following option :\n");
	printf("To add a new book      ENTER '1'\n");
	printf("To view ALL            ENTER '2'\n");
	printf("To search for a book   ENTER '3'\n");
	printf("To Delete any book     ENTER '4'\n");
	printf("To all author's books  ENTER '5'\n");
	printf("To get book's price    ENTER '6'\n");
	printf("To Exit                ENTER '0'\n");
	printf("---------------------------------------");
	printf("\n\n----> You Choice is : "); 
	scanf("%d",&option);	
}

void Addbook_Last(void)
{
	u8 mask [50];
	printf("\n---------------------------------------\n");
	node*current=head;
	node* newnode=(node*)malloc(sizeof(node));
	printf("Enter the name of the book : ");
	scanf("%s",mask);
	fflush(stdin);
	for(u8 i = 0; i<50; i++){
		newnode->book_name[i] = mask[i];
	}
	printf("Enter the name of author   : ");
	scanf("%s",mask);
	fflush(stdin);

	for(u8 i = 0; i<50; i++){
		newnode->author[i] = mask[i];
	}
	printf("price                      : ");
	scanf("%d",&newnode->price);
	fflush(stdin);

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

void print_list(){
	if(head != NULL){
		node *current = head;
		while(current!=NULL){
			printf("\nBook Name     : %s	",current->book_name);
			printf("\nAuthor        : %s	",current->author);
			printf("\nPrice         : %d $\n",current->price);

			current = current->next;
		}
	}else
		printf("\nLibrary is Empty");
}

node* search(){
	u8 input[50]={0};
	u8 flag = 0;
	u8 char_num = 0;
	node *current = head;
	
	printf("\nEnter wanted book : ");
	scanf("%s",input);
	fflush(stdin);

	for(u8 i = 0; i<50 ;i++){  // to get number of character 
		if( input[i]!= '\0'){
			char_num++;
		}
	}
	
	while(current != NULL){
		for(u8 i=0; i<50; i++){
			if(current->book_name[i] != '\0'){
				if(current->book_name[i] == input[i]){
					flag++;
					if(flag == char_num)
						break;
				}
			}
		}
		if(flag == char_num)
			break;
		flag = 0;
		prev = current;
		current = current->next;
	}
	if(current != NULL){
			return current;
	}else 
		return NULL;	
}

void get_book(){
	node *current = (node*)search();
	
	if(current != NULL){
		printf("\nBOOK EXIST\n");
		printf("\nBook Name     : %s	",current->book_name);
		printf("\nAuthor        : %s	",current->author);
		printf("\nPrice         : %d $\n",current->price);
		
	}else 
		printf("\nBook not exit before\n");
}
void DeleteBook()
{	
	node *current = search();
	if(head != NULL){
		if(current != NULL){
			if(current == head){
				head = current->next;
				free(current);
			}else{
				prev->next = current->next;
				free(current);
				prev = NULL;
			}
			printf("\nThe book is deleted");
		}else
			printf("\nThis book not exist");			
	}else
		printf("\nList is empty");
}
void search_author(){
	u8 input[50]={0};
	u8 flag = 0;
	u8 char_num = 0;
	u8 exist = 0;
	node *current = head;
	
	printf("\nEnter the author's name  : ");
	scanf("%s",input);
	fflush(stdin);

	for(u8 i = 0; i<50 ;i++){  // to get number of character 
		if( input[i]!= '\0'){
			char_num++;
		}
	}
	
	while(current != NULL){
		for(u8 i=0; i<50; i++){
			if(current->author[i] != '\0'){
				if(current->author[i] == input[i]){
					flag++;
					if(flag == char_num)
						break;
				}
			}
		}
		if(flag == char_num){
			printf("\nHas a book : %s",current->book_name);
			exist++;
		}
		current = current->next;
		flag = 0;
	}
	if(exist == 0)
		printf("\nThis author has no posts here right now");
}

void book_price(){
	node *current = search();
	if(current != NULL){
		printf("\nbook's price    : %d $",current->price);
	}else
		printf("\nThe book not exist");
}