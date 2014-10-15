#include <iostream>
#include <string>
using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int d = 0):data(d),next(NULL){}
};

void InsertBack(Node* &head, int key)
{
	Node* pnewnode = new Node(key);
	// change head pointer
	if (head == NULL)
	{
		head = pnewnode;	
		return;
	}
	Node* p = head; 
	// find the last node
	while (p->next != NULL) p = p->next;
	p->next = pnewnode;
	return;
}

void InsertFront(Node* &head, int key)
{
	Node* pnewnode = new Node(key);
	pnewnode->next = head;
	head = pnewnode;
	return;
}

void InsertAfter(Node* prevNode, int key)
{
	if (prevNode == NULL)
	{
		cerr << "The given previous node cannot be NULL !" << endl;
		return;
	}
	Node* pnewnode = new Node(key);
	pnewnode->next = prevNode->next;
	prevNode->next = pnewnode;
}

void Delete(Node* &head, int key)
{
	if (head == NULL)
	{
		cerr << "Link List is empty, cannot delete" << endl;
		return;
	}

	//find the key in the linklist 
	bool found = false;
	Node* q = NULL;
	Node* p = head;
	for (; p != NULL; q = p, p = p->next)
	{
		if (p->data == key)
		{
			found = true;
			break;
		}
	}
	
	// cannot find
	if (!found)
	{
		cerr << "Link list does not contain the key" << endl;
		return;
	}
	else // find it
	{
		// it is the first node in the list, update head
		if (q == NULL)
		{
			head = head->next;
		}
		else // update the prev pointer
		{
			q->next = p->next;	
		}
		delete p;
	}
	return;
}	

void PrintList(Node* head)
{
	for (Node* p = head; p != NULL; p = p->next)
	{
		cout << " " << p->data;
	}
	cout << endl;
}


int main()
{
	Node* head = NULL;
	InsertBack(head, 6);
	InsertFront(head, 7);
	InsertFront(head, 1);
	InsertBack(head, 4);
	InsertAfter(head->next, 8);
	cout << "The created list:" << endl;
	PrintList(head);
	cout << "delete 1" << endl;
	Delete(head, 1);
	PrintList(head);
	cout << "delete 8" << endl;
	Delete(head, 8);
	PrintList(head);
	cout << "delete 4" << endl;
	Delete(head, 4);
	PrintList(head);
	return 0;
}
