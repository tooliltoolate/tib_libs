#include "../../tib_includes/liblinked_l.h"
#include <stdio.h>

//printing all
//searching
//inserting
//can i change it
bool linked_l_print(linked_list *input){
	linked_list *result = input;
	while(result){
		printf("%i ", result->key);
		result = result->next;
	}
	return true;
}

bool linked_l_search(linked_list *input, int key){
	if(input) return (input->key == key) || linked_l_search(input->next, key);	
	return false;
}

bool linked_l_insert(linked_list *input, linked_list *insertee){
	if(input){
		input->next = insertee;
	}
	input = insertee;
	return true;
}
