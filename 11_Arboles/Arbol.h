#pragma once
#include <iostream>
#include "ListaLigada.h"
#include "Pila.h"

template<class datatype>
class Arbol
{
private:
	int nextIndex;

public:
	typedef Arbol< datatype > Nodo;
	int index;
	datatype * data;
 	//padre es un arbol
	Nodo * padre;
	//jefe de jefes
	Nodo * raiz; 
	//hijos es una lista ligada de arboles
	ListaLigada<Nodo> *hijos;

	Arbol(datatype *_data , Nodo * _padre, int nextI)
	{
		//si padre es null, este es un nodo raiz
		padre = _padre;
		data = _data;
		hijos = new ListaLigada<Nodo>();
		index = nextI;
		nextIndex = index + 1;
		raiz = getRaiz();
	}
	Arbol()
	{
		puts("usando constructor default de Arbol");
	}
	~Arbol()
	{}

	Nodo * getRaiz()
	{
		if (padre != NULL)
		{
			//printf("Nodo %i tiene padre %i \n", *data, *(padre->data));
			return padre->getRaiz();
		}
		else
		{
			//printf("Nodo %i NO tiene padre, es el RAIZ \n", *data);
			return this;
		}
	}

	int getNextIndex()
	{
		int res = nextIndex;
		nextIndex++;
		return res;
	}

	Nodo * insertar(datatype *dato)
	{
		Nodo *nodo = new Arbol( dato, this, raiz->getNextIndex());
		hijos->Insert( nodo);
		printf("Nodo insertado con indice %i y dato: %i \n", nodo->index, *(nodo->data) );
		return nodo;
	}

	int Count()
	{
		/*
		Pila<Nodo*> pila;
		Nodo * actual;
		actual = this;
		actual->hijos->Begin();
		while (actual->hijos->header != NULL)
		{
			pila->push( actual->hijos->header->data );
			//printf("%i, ", *(actual->hijos->header->data->data));
			actual->hijos->Next();
		}

		actual = pila->pop();
		while (actual != NULL)
		{
			actual->hijos->Begin();
			while (actual->hijos->header != NULL)
			{
				pila->push(actual->hijos->header);
				actual->hijos->Next();
			}
		}
		*/
		return 0;
	}
};

