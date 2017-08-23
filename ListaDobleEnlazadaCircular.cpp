#include<stdlib.h>
#include<stdio.h>

typedef struct node node;

node* createInitialNode(int data);
node* insertInitialNode(node* addressInitialNode, node* newNode);
node* insetInOrder(node* addressInitialNode, int data);
void insertFinalNode(node* addressInitialNode, node* newNode);
node* searchNode(node* addressInitialNode);
node* deleteInitialNode(node* toDelete);
node* deleteNode(node* addressInitialNode, int data);
void printList(node* addressInitialNode);
int countList(node* addressInitialNode);

//Estructura de nodo
struct node{
	int data;
	node* next;
	node* back;
};

int main(){
	int menuInt, input;
	node* a;
	a = NULL;
	//Menu
	do{
		printf("\n --<>--MENU--<>-- \n"
				"1 - Agregar Nodo\n"
				"2 - Eliminar Nodo\n"
				"3 - Contar numer de Nodos \n"
				"4 - Imprimir Lista \n"
				"0 - Salir\n\n"
				);
		printf("Seleccion: ");
		scanf("%i",&menuInt);
		switch(menuInt){
			case 1: 
				system("CLS");
				printf("El nuevo Nodo contiene el numero: \n");
				scanf("%i",&input);
				a = insetInOrder(a,input);
				break;
			case 2: 
				int number;
				system("CLS");
				printf("Eliminar Nodo que contiene el numero: \n");
				scanf("%i",&input);
				a = deleteNode(a,input);
				break;
			case 3:
				system("CLS");
				printf("Hay %i Nodos en la lista: \n", countList(a));
				break;
			case 4:
				system("CLS");
				printf("Lista completa: \n");
				printList(a);
				break;
		}
	}while(menuInt!=0);
	
	return 0;
}

//Crea el primer nodo de una lista
node* createInitialNode(int data){
	node* temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->next = temp;
	temp->back = temp;
	return temp; 
}

//Crea un nodo en el final de la lista
void insertFinalNode(node* addressInitialNode, node* newNode){
	(*newNode).next = addressInitialNode;
	(*newNode).back = addressInitialNode->back;
	
	(addressInitialNode->back)->next = newNode;
	addressInitialNode->back = newNode;		
}

//Crea un nodo al inicio de la lista
node* insertInitialNode(node* addressInitialNode, node* newNode){
	(*newNode).next = addressInitialNode;
	(*newNode).back = addressInitialNode->back;
	
	(addressInitialNode->back)->next = newNode;
	addressInitialNode->back = newNode;
	
	return newNode;
}

//Imprime la lista
void printList(node* addressInitialNode){
	if(addressInitialNode != NULL){
		node* temp = addressInitialNode;
		int count = 0;
		while(temp->next  != addressInitialNode){
			printf("Dato en Nodo numero %i: %i \n",count,temp->data);
			temp = temp->next;
			count++;
		}
		printf("Dato en Nodo numero %i: %i \n",count,temp->data);
	}else{
		printf("No existen Nodos en la lista\n");
	}
}

//Gestiona la creacion de un nuevo nodo
node* insetInOrder(node* addressInitialNode, int data){
	//Nuevo Nodo
	node* temp = addressInitialNode;
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	
	if(temp == NULL){								//Si lista esta vacia
		return createInitialNode(data);
	}
	if(temp->data > data){							//Si va al incio de la lista el nuevo nodo
		return insertInitialNode(temp,newNode);
	}else if((temp->back)->data < data){			//Si va al final de la lista el nuevo nodo
		insertFinalNode(temp,newNode);
	}else{											//Si va en algun lugar central de la lista el nuevo nodo
		while((temp->next)->data < data){
			temp = temp->next;
		}
		newNode->next = temp->next;
		newNode->back = temp;
		(temp->next)->back = newNode;
		temp->next = newNode;
	
	}
	return addressInitialNode;
}

//Cuenta los elementos en la lista
int countList(node* addressInitialNode){
	int amount=0;
	if(addressInitialNode==NULL){
		printf("La lista no tiene elementos.\n");
		return 0;
	}
	node* temp = addressInitialNode;
	while(temp->next  != addressInitialNode){
		temp = temp->next;
		amount++;
	}
	amount++;
	printf("La lista tiene %i elementos.\n",amount);
	return amount;
}

//Busca la direccion de un Nodo
node* searchNode(node* addressInitialNode, int data){
	if(addressInitialNode==NULL){						//Si la lista esta vacia
		printf("La lista no tiene elementos.\n");
		return NULL;
	}
	
	node* temp = addressInitialNode;
	while(temp->next  != addressInitialNode){
			if(temp->data == data){
				return temp;
			}
			temp = temp->next;
		}
	if(temp->data == data){
		return temp;
	}
	printf("No se ha encontrado el elemento en la lista.\n");
	return NULL;
}

//Gestiona la eliminacion de un Nodo
node* deleteNode(node* addressInitialNode, int data){
	node* temp = addressInitialNode;
	node* toDelete = searchNode(temp,data);
	
	if(toDelete == NULL) return NULL;					//Si la lista esta vacia
	if(toDelete == temp){								//Si se tiene que eliminar el primer nodo de la lista
		if(countList(temp)==1){							//Si la solo tiene 1 nodo la lista
			free(addressInitialNode);
			return NULL;
		}else{											//Si tiene mas de 1 nodo la lista
			return deleteInitialNode(toDelete);
		}
	} else {											//Si se tiene que eliminar un nodo que no es el primero
		(toDelete->back)->next = toDelete->next;
		(toDelete->next)->back = toDelete->back;
		return addressInitialNode;
	} 
}

//Elimina el primer nodo
node* deleteInitialNode(node* toDelete){
	node* temp = toDelete->next;
	(toDelete->back)->next = toDelete->next;
	(toDelete->next)->back = toDelete->back;
	free(toDelete);
	toDelete = NULL;
	return temp;
}
