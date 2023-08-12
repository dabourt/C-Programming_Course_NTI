#include <stdio.h>
#define STACK_SIZE 5

void push(int data);
int pop(void);
int top;
int stack[STACK_SIZE];

int main(){
  	int x=0;
	for(int i=0; i<8;i++){
		push(i);
	}
	printf("\n");
	for(int i = 0; i<5; i++){
		printf("%d\n",stack[i]);

	}
	printf("\n");
	for(int i=0; i<8;i++){
		x = pop();
		printf("%d\n",x);
	}
	return 0;
}
void push(int data){
	if(top<STACK_SIZE){         //if top = STACK_SIZE means top 
								//point to void and means top exit the stack
		stack[top] = data;
		top++;
	}else printf("ISFULL\n");
}
int pop(void){
	if(top!=0){		//top = 0 means stack is empty
		top--;
		return stack[top];
	}else printf("ISEMPTY\n");
}