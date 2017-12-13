#include "list.h"

Node::Node(DataType val, Node * n )
{
	data = val;
	next = n;
}

List::List(Node * h) 
{
	head = h;
}

List::List(const List& list2) 
{
	head = list2.head;
}

List::~List() 
{
	Node*tmp1 = head , *tmp2;
	if (head != NULL)
	{
		while (tmp1 != NULL)
		{
			tmp2 = tmp1->next;
			delete tmp1;
			tmp1 = tmp2;
		}
	}

}

List& List:: operator=(const List& list2)
{
	if (this != &list2)
	{
		head = list2.head;
	}
	return *this;
}

void List::InserToHead(const DataType& d) // вставить элемент d первым
{
	if (head == NULL)
		head = new Node(d, NULL);
	else {
		Node * tpm = new Node(d,head);
		head = tpm;
	}
} 

void List::InserToTail(const DataType& d) // вставить элемент d последним
{
	if (head == NULL)
		head = new Node(d, NULL);
	else 
	{
		Node*tmp = head;
		while (tmp->next != NULL)
			tmp = tmp->next;		
		tmp->next = new Node(d, NULL);
	}
}

void List::InsertAfter(Node* node, const DataType& d) // вставить элемент d после звена node
{
	Node * tmp = new Node(d,node->next);
	node->next = tmp;
}

void List::Inverse() // инвертировать список, т.е. звенья должны идти в обратном порядке
{
	
	Node*tmp1, *tmp2, *tmp3;

	tmp1 = head;
	tmp2 = head->next;
	while (tmp2 != NULL)
	{
		tmp3 = tmp2->next;
		tmp2->next = tmp1;
		tmp1 = tmp2;
		tmp2 = tmp3;
	}
	head = tmp1;
}

void List::Delete(const DataType& d) // удалить звено со значением data = d
{
	Node*tmp = head, *p;
	Node*tmp2;
	while (tmp->data != d)
		tmp = tmp->next;
	p = tmp->next;
	tmp = tmp->next->next;
	delete p;

}

int List::GetSize() // узнать число звеньев в списке
{
	if (head != NULL)
	{
		int k = 0;
		Node* tmp = head;
		while (tmp != NULL)
		{
			k += 1;
			tmp = tmp->next;
		}
		return k;
	}
else return 0;
}

Node* List:: GetHead() // получить указатель на первое звено списка
{
	return head;
}

Node* List:: Search(const DataType& d) // найти указатель на звено со значением data = d
{
	Node * tmp = head;
	while ((tmp->data != d)&&(tmp!=NULL))
	{
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return NULL;
	else return tmp;
}

void List::Clean() // удалить все звенья
{
	Node*tmp1 = head, *tmp2;
	if (head != NULL)
	{
		while (tmp1 != NULL)
		{
			tmp2 = tmp1->next;
			delete tmp1;
			tmp1 = tmp2;
		}
	}

}
