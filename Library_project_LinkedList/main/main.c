#include "main.h"

u8 option = 1;
extern node *head;
u32 main(){
	while(option != 0){
		interfacing();

		switch (option){
			case 1 :
				Addbook_Last();
				break;
			
			case 2 :
				print_list();
				break;
				
			case 3 :
				get_book();
				break;
				
			case 4 :
				DeleteBook();
				break;
			
			case 5 :
				search_author();
				break;
				
			case 6 :
				book_price();
				break;
			}
	}	
	free(head);
	printf("\n   Thanks, good bye");
	return 0;
}