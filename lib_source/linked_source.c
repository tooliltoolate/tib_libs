#include "../../tib_includes/liblinked_l.h"
#include <stdio.h>
//how do i do this

linked_l_error linked_l_print(linked_list *input){
	linked_list *result = input;
	while(result){
		printf("%i ", result->key);
		result = result->next;
	}
	return true;
}

linked_l_error linked_l_search(linked_list *input, int key){
	if(input) return (input->key == key) || linked_l_search(input->next, key);	
	return false;
}

linked_l_error linked_l_insert(linked_list **input, linked_list *insertee){
	if(*input == NULL) {*input = insertee;
	return RECEIVED_NULL_POINTER;}
	else{
		(**input).next = insertee;
	}
	return EXECUTED_SUCCESSFULLY;
}
//so i have an array
//for insert, it would be best to have a pointer
//i guess i would 
//lets think of just pointers. so were passed a pointer. we deference it, change its value so it now points to a linked_list node.
//why can't we do this?
//because we can't dereference null pointers
//now what
//we can: not use nulls
//con: what sentinel do we use then?
//we have search. it would still work.
//okay so the hash_table isnt an array of nulls anymore
//its now an array of random linked_l arrays
//i dereference 
//and then what
//set the keys as sentinels
//what int man 
//fuck no
//how about we keep nulls anyway
//idk
//so we can't dereference nulls
