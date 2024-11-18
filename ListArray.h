#ifndef LISTARRAY_H
#define LISTARRAY_H


#include <string>
#include <exception>
#include <ostream>
#include "List.h"

#define TRUE 1
#define FALSE 0

template <typename T>

class ListArray : public List<T> {

	private:

		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;	
		
		void resize(int new_size)
		{
			max = new_size;
			n = new_size;
		}

	public:

		/*-------------------- INSERT ---------------------*/
		void insert(int pos, T e) override
		{
			if( !(pos < 0 || pos > size()) ) //comprobamos si esta dentro del rango 
			{
				if(pos == 0) //si esta vacia añadimos un elementeo al inicio de la lista
					prepend(e);
				else if(pos == size()) // si está al final añadimos un elemento despues 
					append(e);
				else // si esta en cluaquier lado 
				{
					int i, j, new_size = n + 1;

					T *aux = new T[new_size]; // creamos un nuevo array que tendrá un hueco mas qe el orginal en el que vamso a air copiando los elementoas

					for(i = 0, j = 0; i < new_size; i++)
					{
						if(pos == i) // si coinciden asignamos el nuevo valor 
							aux[i] = e;
						else
						{
							aux[i] = arr[j]; //si i no coincide con pos entrondes copiamos el elemento a arr y avanza j 
							j++;
						}
					}

					delete[] arr; // borramos el array orginal y asignamos a arr el nuevo array actualizado 
					arr = aux;
					resize(new_size);// actualizamos el tamaño 
				}
			}
			else
				throw std::out_of_range("Posicion no valida");
		}

		// seguimos la misma estrategia que arriba pero cada uno en us posicion 

		/*-------------------- APPEND ---------------------*/
		void append(T e) override
		{
			int new_size = size() + 1;
			T *aux = new T[new_size];

			for(int i = 0; i < size(); i++)
				aux[i] = arr[i];

			aux[size()] = e;

			delete[] arr;
			arr = aux;
			resize(new_size);
		}



		/*------------------- PREPEND ---------------------*/
		void prepend(T e) override
		{
			int new_size;

			(n == 0) ? (new_size = 1) : (new_size = size() + 1);

			T *aux = new T[new_size];

			aux[0] = e;

			if(n != 0)
			{
				for(int i = 0; i < size(); i++)
					aux[i+1] = arr[i];
			}

            delete[] arr;
            arr = aux;
            resize(new_size);

		}



		/*-------------------- REMOVE ---------------------*/
		T remove(int pos) override
		{
			T elemento;

			if( pos >= 0 && pos < size() )
			{
				int i, j, new_size = size() - 1;

				T *aux = new T[new_size];

				for(i = 0, j = 0; i < size(); i++)// bucle para copiar los elementos del array a un array nuevo actualizado 
				{
					if(pos == i) // si pos coincide con ele eleemento i que queremos eliminar, guardamos en elemento para devolverlo  y no lo guardamos en aux
						elemento = arr[i];
					else
					{
						aux[j] = arr[i];
						j++;
					}
				}

				delete[] arr; //borramos array viejo 
				arr = aux; //actualizamos array
				resize(new_size);
			}
			else
				throw std::out_of_range("Posicion no valida");

			return elemento; // devolvemos elemento eliminado 
		}



		/*--------------------- GET -----------------------*/
		T get(int pos) override
		{
			if(pos < 0 || pos >= size() )
				throw std::out_of_range("Posicion no valida");
			else
				return arr[pos];
		}



		/*-------------------- SEARCH ---------------------*/
		int search(T e) override
		{
			int i = 0, pos_aux;

			while( arr[i] != e && i < size() ) // recorremos array hasta que eencontremos elemento e
				i++;

			(i == size()) ? (pos_aux = -1) : (pos_aux = i); // si hemos recorrido todo el array y no hemso eontrado nada (i=size) devolvemos -1. 
			//si i<que size significa qeu hemos encontrado un eleelmtneo y lo devolvemos 

			return pos_aux;
		}



		/*-------------------- EMPTY ----------------------*/
		bool empty() override
		{
			bool aux;

			(n = 0) ? (aux = TRUE) : (aux = FALSE);// si n =0 entonces esta vacio de lo contrario está llema

			return aux;
		}

		/*--------------------- SIZE ----------------------*/
		int size() override
		{
			return max;
		}

//-----------------------------------------------------------------------------------------------------
		/*------------------ LISTARRAY----------------------*/
		ListArray()
		{
			arr = new T[MINSIZE];
			max = MINSIZE;	
			n = 0;
			
		}

		/*------------------ ~LISTARRAY----------------------*/
		~ListArray()
		{
			delete[] arr;			
		}

		/*--------------------OPERATOR-----------------------*/


		T operator[](int pos){
			
			if( pos >= 0 && pos < size() )
			{
				throw std::out_of_range("Posicion no valida");
			}
				return get(pos);
		}

		/*--------------------OPERATOR<<------------------------*/


		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list)
		{
		    out << "[";
   			 for (int i = 0; i < list.size(); i++) {
       				 out << list[i];
        			if (i < list.size() - 1) {
           				 out << ", ";  // Separador entre elementos
      				}
    			}
    		out << "]";
    		return out;

		};
		

#endif
