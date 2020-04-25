// This code contains data structures implemented in C.

#include "data_structures.h"
#include <stdlib.h> // malloc, free, ...
#include <stdio.h> // printf

// The line below defines the type of "t_elem". The list structure is generic
// for numerical types in its elements, therefore, use the type that you need.
// e.g.: int, double, float, char, unsigned int
// typedef int t_elem; // Present in data_structures.h. Should be modified there.

// ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~
// Lists

// Simple lists:
// typedef struct _node *pt_node; // present in data_structures.h
struct _node {
	t_elem *elem; // Element of the node
	pt_node next; // Pointer to the next node.
};

// Create a node with a node. Returns the created node.
// Parameters:
// 		t_elem elem: the element of type t_elem that will be in the created node.
pt_node node_create(t_elem elem) { // Create a simple list node.
	pt_node node;
	if( ( node = (pt_node)malloc(sizeof(struct _node)) ) == NULL) return NULL;
	if( ( node->elem = (t_elem *)malloc(sizeof(t_elem)) ) == NULL) {
		free(node);
		return NULL;
	}
	*node->elem = elem;
	node->next = NULL;
	return node;
}
// Destroys a node.
// Parameters:
// 		pt_node *dnode: node to be destroyed
void node_destroy(pt_node *dnode) {
	free((*dnode)->elem);
	free(*dnode);
	*dnode = NULL;
}

// Search in a list, by element. Returns the node that contains the f_elem
// Parameters:
// 		pt_node head: head node of a list
// 		t_elem f_elem: element of the node to be found
pt_node list_search(pt_node head, t_elem f_elem) {
	pt_node node;
	for(node = head; node != NULL; node = node->next)
		if(*node->elem == f_elem) break;
	return node;
}

// Print the list.
// Parameters:
// 		pt_node head: head of the list
void list_print(pt_node head) {
	if(head == NULL) return;
	pt_node node;
	printf("[");
	for(node = head; node != NULL; node = node->next)
		if(node->next != NULL) print("%d, ", *node->elem)
		else printf("%d]\n", *node->elem);
}

// Inserd a node in a ordered way
// Parameters:
// 		pt_node *head: pointer to the head of the list
// 		t_elem elem: element of the node to be inserted.
void list_insert(pt_node *head, t_elem elem) {
	pt_node ins, prev = NULL, actual = *head;
	if( (ins = node_create(elem)) == NULL ) return;
	// While isn't in the end of the list or the elem to be inserted is bigger than the current element in list
	// move forward.
	while (actual != NULL && elem > *actual->elem ) { 
		prev = actual; 
		actual = actual->next;
	}
	// this "if" happends when elem < *head->elem (first element), or when there is no elements in the list.
	if(prev == NULL) {
		ins->next = *head; // new node starts pointing to the old head VALUE (this VALUE isn't a reference)
		*head = ins; // and the new node become the new head. (Value of the node head, that has been passed by reference)
	}
	else { // if it's after the first element (even if it is the last).
		ins->next = actual;
		prev->next = ins;
	}
}



// ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~ X ~~~~~~~~~~~~~~~~~~