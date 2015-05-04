#include "listbag.h"
#include <assert.h>
#include "type.h"
#include <stdlib.h>

/*Bag interface*/
/* Function to initialize bag:
	Pre: b is not null
	Post: list implementing the bag is initialized, size = 0
*/
void initBag(struct bag* b){
	assert( b != NULL);
	b->lst = (struct list*)malloc(sizeof(struct list));/*Allocate for the list implementing the bag*/
	initList(b->lst);/*Initialize list*/
}

/* Function to add an element to the bag:
	Pre: b is not null
	Post: val is added to the bag ie the list implementing the bag*/
void addToBag(struct bag* b, TYPE val){
 	assert(b != 0);
	addBackList(b->lst, val);
	assert(EQ(backList(b->lst),val));

}

/* Function to remove an element from the bag:
	Pre: b is not null
	Post: Element (if found) removed from bag/list
*/
void removeFromBag(struct bag* b, TYPE val){
	assert(b != 0);
	if(listContains(b->lst, val))
		listRemove(b->lst, val);
}

/*Function to test if an element exists in the bag
	Pre: b is not null
*/
int bagContains(struct bag* b, TYPE val){
	return listContains(b->lst, val);
}

/*Function to test if the bag is empty
	Pre: b is not null
*/

int isEmptyBag(struct bag* b){
	assert(b != 0);
	return isEmptyList(b->lst);
}
