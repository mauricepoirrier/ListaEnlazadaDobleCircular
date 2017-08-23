#include<stdlib.h>
#include<stdio.h>
typedef struct node node;
node* createInitialNode(int data);
void insertFinalNode(node* addressInitialNode, int data);
node* insertInitialNode(node* addressInitialNode, int data);
void printList(node* addressInitialNode);

struct node{
	int data;
	node* link;
};

int main(){
	int menuInt;
	node* a;
	a = NULL;
	/*
	do{
		printf("\n MENU \n"
				"1 - Agregar Nodo\n"
				"2 - Eliminar Nodo\n"
				"3 - Imprimir Lista \n"
				"0 - Salir"
				);
		//Getting number
		printf("Seleccion: ");
		scanf("%i",&c);
		switch(c){
			case 1: printlist(a);
			case 2: printlist(a);
			case 3: printlist(a);
		}
	}while(menuInt!=0);
	*/
	
	a = createInitialNode(2);
	insertFinalNode(a, 3); 
	insertFinalNode(a, 4);
	insertFinalNode(a, 5);
	a = insertInitialNode(a, 1);
	printList(a);
	return 0;
}

node* createInitialNode(int data){
	node* temp = (node*)malloc(sizeof(node));
	(*temp).data = data;
	//temp->data = data;
	(*temp).link = NULL;
	//temp->link = NULL;
	return temp; 
}

void insertFinalNode(node* addressInitialNode, int data){
	node* newNode = (node*)malloc(sizeof(node));
	(*newNode).data = data;
	(*newNode).link = NULL;
	
	node* temp = addressInitialNode;
	while((*temp).link != NULL){
		temp = (*temp).link;
	}
	(*temp).link = newNode;
}

node* insertInitialNode(node* addressInitialNode, int data){
	node* newNode = (node*)malloc(sizeof(node));
	(*newNode).data = data;
	(*newNode).link = addressInitialNode;
	return newNode;
}

void printList(node* addressInitialNode){
	node* temp = addressInitialNode;
	
	while((*temp).link != NULL){
		printf("%i\n",(*temp).data);
		temp = (*temp).link;
	}
	printf("%i\n",(*temp).data);	
}
