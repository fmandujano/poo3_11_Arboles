// 11_Arboles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ListaLigada.h"
#include "Arbol.h"
#include <iostream>
#include "Pila.h"

void testListaligada()
{
	//Prueba de lista ligada
	ListaLigada<std::string> *lista = new ListaLigada<std::string>();
	std::string a = "hola";
	std::string b = "mundo";
	std::string c = "cruel";
	std::string d = "adios";
	lista->Insert(&a);
	lista->Insert(&b);
	lista->Insert(&c);
	lista->Insert(&d);
	//printf(" %s\n", lista->Begin().c_str());
	lista->Begin(); //rebobinar la lista
	while (lista->header != NULL)
	{
		printf(" %s \n", lista->header->data->c_str());
		lista->Next();
	}

	d = "bye";
	lista->Begin(); //rebobinar la lista

	while (lista->header != NULL)
	{
		printf(" %s \n", lista->header->data->c_str());
		lista->Next();
	}
}

//Prueba unitaria de pilas
void testPila()
{
	Pila<int> *pila = new Pila<int>();
	pila->push(new int(7));
	pila->push(new int(13));
	pila->push(new int(42));
	pila->push(new int(666));

	printf("popeado: %i\n", *(pila->pop()));
	printf("popeado: %i\n", *(pila->pop()));
	printf("popeado: %i\n", *(pila->pop()));

	printf("inicio: %i, fin : %i \n", *(pila->start->data), *(pila->last->data));
}

int main()
{
	//testListaligada();
	

	Arbol<int> *arbol = new Arbol<int>(  new int(18564 ),NULL, 0);
	arbol->insertar(  new int(20000));
	arbol->insertar(new int(18134));
	Arbol<int> * rama = arbol->insertar(new int(19588));
	printf("raiz de la rama: %i \n", *(rama->getRaiz()->data));

	rama->insertar(new int(10256));
	rama->insertar(new int(12560));

	Arbol<int> *subrama = rama->insertar(new int(12560));
	rama->insertar(new int(19999));
	rama->insertar(new int(25874));

	printf(" num de hijos del arbol : %i\n", arbol->Count());

	system("PAUSE");
    return 0;
}

