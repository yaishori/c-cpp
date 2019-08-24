#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node* next;
};



struct node* middle(struct node* linkedList){
	struct node* node1= linkedList;
	struct node* node2= linkedList;
	while (node2->next != NULL && node2->next->next!= NULL){
		node1=node1->next;
		node2=node2->next->next;
	}
	printf("middle:%d\n",node1->value);
	return node1;
}


struct node* comminNode(struct node* node1,struct node* node2){
	int count1=0;
	int count2=0;
	int dif;
	int bigger=0;
	int i=0;
	struct node* myNode1=node1;
	struct node* myNode2=node2;
	while (myNode2->next!= NULL){
		count2++;
		myNode2=myNode2->next;
	}
	while (myNode1->next!= NULL){
		count1++;
		myNode1=myNode1->next;
	}
	if(count2>count1){
		dif=count2-count1;
		bigger=1;
	}
	else{
		dif=count1-count2;
	}
	printf("%d\n",dif);
	if(bigger){
		while(i<dif){
			node2=node2->next;
			i++	;
		}
	}
	else{
		while(i<dif){
			node1=node1->next;
			i++;
		}
	}
	while(node1->next!=node2->next){
		node1=node1->next;
		node2=node2->next;
	}
	printf("%d\n",node1->next->value);
	return node1->next;
}
int ifLoop(struct node* linkedList){
	struct node* node1= linkedList;
	struct node* node2= linkedList;
	while(node2->next != NULL){
		if(node2->next->next != NULL){
			node1=node1->next;
			node2=node2->next->next;
			if(node1==node2){
				return 1;
			}
		}
		else return 0;
	}

	return 0;

}

void push(struct node** head, int newData)  
{  
    struct node* newNode = (struct node*) malloc(sizeof(struct node));  
    newNode->value = newData;  
  
    newNode->next = (*head);  
  	(*head) = newNode;  
}  

void flipList(struct node** linkedList){
 
    struct node* node = *linkedList; 
    struct node* prev = NULL;
    struct node* next = NULL; 
  
        while (node != NULL) {  
            next = node->next;  
            node->next = prev; 
            prev = node; 
            node = next; 
        } 
        *linkedList = prev;   
    return;
}

void printList(struct node* linkedList) 
{ 
    struct node* temp = linkedList; 
    while (temp != NULL) { 
        printf("%d  ", temp->value); 
        temp = temp->next; 
    } 
     printf("\n");
} 


int main(){
	struct node* head = NULL;  
	struct node* node1=malloc(sizeof(struct node));
	struct node* node2=malloc(sizeof(struct node));
	struct node* node3=malloc(sizeof(struct node));
	struct node* node4=malloc(sizeof(struct node));
	struct node* node5=malloc(sizeof(struct node));
	struct node* node6=malloc(sizeof(struct node));

	struct node* head2 = NULL;

    int i;  
  
    for (i=5; i>0; i--)  
    {  
        push(&head, i);  
   
    }

    for (i=1; i<5; i++)  
    {  
        push(&head2, i);  
   
    }

	middle(head);  

	node1->value=1;
	node1->next=node3;
	node3->value=1;
	node3->next=node4;
	node4->value=5; /*commin*/
	node4->next=node6;
	node5->value=1;
	node5->next=node4;
	node6->value=1;
	node6->next=NULL;

	comminNode(node1,node5);

	printf("ifLoop\n");
	i = ifLoop(head);
	if(i){
		printf("yes\n");
	}
	else{
		printf("no\n");
	}

	node6->next=node3;
	i = ifLoop(node1);
	if(i){
		printf("yes\n");
	}
	else{
		printf("no\n");
	}


	printList(head2);
	flipList(&head2);
	printList(head2);


	return 0;
}