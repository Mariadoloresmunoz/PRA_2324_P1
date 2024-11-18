#ifndef NODE_H
#define NODE_H

#include <ostream>

#define TRUE 1
#define FALSE 0

template <typename T>

class Node{

	public:

		T data;
		Node<T> *next;
		
		Node(T data, Node<T> *next = nullptr)
		{
			this->data = data;
			this->next = next;
		}

		friend std::ostream& operator<<(std::ostream &out, const Node<T> &node)
		{
			out << "Secuencia: ";

  			while(node != nullptr)
  			{
   				out << node.data << " ";
   				node = node.next;
 			}

			return out;
		}
		
};

#endif
