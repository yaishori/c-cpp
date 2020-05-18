// IMPLEMENT YOUR FUNCTIONS HERE

#include "average_buffer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//double linked list
struct node{
	int value;
	struct node* next;
	struct node* prev;
};

struct AverageBuffer{
	int capacity;
	int quarter;
	int numOfSampelsEver;
	int sumCurrent;
	int sumForever;
	int sumUpper;
	int sumLower;
	node* old;
	node* new;
	node* upperQuerter;//pointer to the node that end the upper quarter
	node* lowerQuerter;	//pointer to the node that start the lower quarter
};

void* allocAverageBuffer(int size){
	AverageBuffer* ab;
	
	if(size <= 0)
		return NULL;
	
	ab = malloc(sizeof(AverageBuffer));
	if(ab == NULL)
		return NULL;
	
	ab->capacity = size;
	ab->quarter = 0;
	ab->numOfSampelsEver = 0;;
	ab->sumCurrent = 0;
	ab->sumForever = 0;
	ab->sumUpper = 0;
	ab->sumLower = 0;
	ab->old = NULL;
	ab->new = NULL;
	ab->upperQuerter = NULL;
	ab->lowerQuerter = NULL;
	
	return ab;
}

void clearAverageBuffer(AverageBuffer* ab){
	node* node = ab->new;
	while (node != NULL){
		free(ab->new);
		node = node->next;
		ab->new = node;
	}

	ab->quarter = 0;
	ab->numOfSampelsEver = 0;;
	ab->sumCurrent = 0;
	ab->sumForever = 0;
	ab->sumUpper = 0;
	ab->sumLower = 0;
	ab->old = NULL;
	ab->new = NULL;
	ab->upperQuerter = NULL;
	ab->lowerQuerter = NULL;
	
	return;
}

void freeAverageBuffer(AverageBuffer* ab){
	clearAverageBuffer(ab);
	free(ab);
	
	return;
}

void addSample(AverageBuffer* ab, int randNum){
	
	node* node = malloc(sizeof(node));
	node->value = randNum;
	node->prev = NULL;
	
	ab->numOfSampelsEver++;
	ab->sumForever += randNum;
	ab->sumCurrent += randNum;
	

	if (ab->new == NULL){
		ab->old = node;
		ab->new = ab->old;
	}
	
	else{
		node->next = ab->new;
		ab->new->prev = node;
		ab->new = node;
		
		if ((ab->capacity >= 4) && (ab->numOfSampelsEver >= 4)){
			checkQuarter(ab);
		}
		
		if (ab->numOfSampelsEver > ab->capacity){
			ab->sumCurrent -= ab->old->value;
			ab->old = ab->old->prev;
			free(ab->old->next);
			ab->old->next = NULL;
		}
	}
	
	return;
}

void checkQuarter(AverageBuffer* ab){
	
	ab->sumUpper += ab->new->value;
	
	if (ab->numOfSampelsEver == 4){
		ab->quarter = 1;
		ab->lowerQuerter = ab->old;
		ab->upperQuerter = ab->new;
		ab->sumLower += ab->lowerQuerter->value;
	}


	else{
		int changeUpper;
		int changeLower;
		int full = 0;
		int changeQuarter = 0;
		if(ab->numOfSampelsEver > ab->capacity){ 
			full = 1;
		}
		
		changeUpper = full;
		changeLower = full;
		if(!full && ((ab->numOfSampelsEver % 4) == 0)){
			changeQuarter = 1;
		}
		
		if (full)
			ab->sumLower -= ab->old->value;
		
		if (!full){
			
			if (changeQuarter){
				changeLower = 1;
				ab->quarter = ab->numOfSampelsEver / 4;
			}
			
			else{
				changeUpper = 1;
			}
		}
		
		if (changeLower){
			ab->lowerQuerter = ab->lowerQuerter->prev;
			ab->sumLower += ab->lowerQuerter->value;
		}
		
		if (changeUpper){
			ab->sumUpper -= ab->upperQuerter->value;
			ab->upperQuerter = ab->upperQuerter->prev;
		}
		
	}
	
	return;
}

double getAverage(AverageBuffer* ab){
	if(ab == NULL || ab->numOfSampelsEver == 0){
		return 0;
	}
	
	if(ab->numOfSampelsEver >= ab->capacity){
		return (double)ab->sumCurrent / (double)ab->capacity;
	}
	
	return (double)ab->sumCurrent / (double)ab->numOfSampelsEver;
}

double getAverageForever(AverageBuffer* ab){
	if(ab == NULL  || ab->numOfSampelsEver == 0){
		return 0;
	}
	
	return (double)ab->sumForever / (double)ab->numOfSampelsEver;
}

double getUpperQuarterAverage(AverageBuffer* ab){
	if(ab == NULL  || ab->quarter == 0){
		return 0;
	}
	
	return (double)ab->sumUpper / (double)ab->quarter;
}

double getLowerQuarterAverage(AverageBuffer* ab){
	if(ab == NULL  || ab->quarter == 0){
		return 0;
	}
	
	return (double)ab->sumLower / (double)ab->quarter;
}

	
	
	
	
