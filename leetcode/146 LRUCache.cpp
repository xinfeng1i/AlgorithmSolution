/**
 * LRU Cache Implementation using DoubleLinkList & hashtable
 * Copyright 2015 python27
 * 2015/06/26
 */
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <deque>
#include <cassert>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct CacheNode
{
	int key;
	int value;
	CacheNode* prev;
	CacheNode* next;
	
	CacheNode(int k, int v) : key(k), value(v), prev(NULL), next(NULL)
	{}
	
	CacheNode():key(0), value(0), prev(NULL), next(NULL)
	{}		
};

class LRUCache
{
public:
	LRUCache(int capacity);
	
	int Get(int key);
	void Put(int key, int value);
	
public:
	void PrintList() const;
private:
	void InsertNodeFront(CacheNode* p);
	void DeleteNode(CacheNode* p);
	
private:
	map<int, CacheNode*> m_hashtable;		// hash table
	CacheNode* m_head;						// double link list head
	CacheNode* m_tail;						// double link list tail
	int m_capacity;							// capacity of link list
	int m_size;								// current size of link list
};

void LRUCache::PrintList() const
{
	CacheNode* p = m_head;
	for (p = m_head; p != NULL; p = p->next)
	{
		printf("(%d, %d)->", p->key, p->value);
	}
	printf("\n");
	printf("size = %d\n", m_size);
	printf("capacity = %d\n", m_capacity);
}

LRUCache::LRUCache(int capacity)
{
	m_capacity = capacity;
	m_size = 0;
	m_head = NULL;
	m_tail = NULL;
}

//	insert node into head pointed by p
void LRUCache::InsertNodeFront(CacheNode* p)
{
	if (p == NULL) return;
	
	if (m_head == NULL)
	{
		m_head = p;
		m_tail = p;
	}
	else
	{		
		p->next = m_head;
		m_head->prev = p;
		m_head = p;
	}
}

// delete node in double linklist pointed by p
void LRUCache::DeleteNode(CacheNode* p)
{
	if (p == NULL) return;
	
	assert(m_head != NULL && m_tail != NULL);
	
	if (m_size == 1)
	{
		if (p == m_head && p == m_tail)
		{
			delete p;
			m_head = NULL;
			m_tail = NULL;
		}
		else
		{
			fprintf(stderr, "Delete Wrong! No such Node");
			return;
		}
	}
	else if (p == m_head)
	{
		m_head = m_head->next;
		m_head->prev = NULL;
		delete p;
	}
	else if (p == m_tail)
	{
		m_tail = m_tail->prev;
		m_tail->next = NULL;
		delete p;
	}
	else
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
	}
	
}

int LRUCache::Get(int key)
{
	// if key not in return -1
	if (m_hashtable.find(key) == m_hashtable.end())
	{
		return -1;
	}
		
	CacheNode* p = m_hashtable[key];
	int k = p->key;
	int v = p->value;
	
	// delete this node
	DeleteNode(p);
		
	// insert this node to the head
	p = new CacheNode(k, v);
	InsertNodeFront(p);
	// update hash table
	m_hashtable[k] = p;
	return p->value;
}

void LRUCache::Put(int key, int value)
{
	// if key alread in, update
	if (m_hashtable.find(key) != m_hashtable.end())
	{
		CacheNode* p = m_hashtable[key];
		
		// delete node
		DeleteNode(p);
		// insert node
		p = new CacheNode(key, value);
		InsertNodeFront(p);
		// update hash table
		m_hashtable[key] = p;
		return;
	}
	// if list is full, delete the tail node
	else if (m_size >= m_capacity)
	{
		// delete the tail node
		CacheNode* p = m_tail;
		m_hashtable.erase(p->key);
		DeleteNode(p);
		m_size--;
	}
	
	// create node and insert into head
	assert(m_size < m_capacity);
	CacheNode* p = new CacheNode(key, value);
	InsertNodeFront(p);
	m_hashtable[key] = p;
	m_size++;
    
}

int main()
{
	LRUCache lru(3);
	lru.Put(1, 11);
	lru.PrintList();
	lru.Put(2, 22);
	lru.PrintList();
	lru.Put(3, 33);
	lru.PrintList();
	lru.Put(4, 44);
	lru.PrintList();
	int value = lru.Get(3);
	printf("Get(3) = %d\n", value);
	lru.PrintList();
	value = lru.Get(2);
	printf("Get(2) = %d\n", value);
	lru.PrintList();
	value = lru.Get(4);
	printf("Get(4) = %d\n", value);
	lru.PrintList();
	value = lru.Get(1);
	printf("Get(1) = %d\n", value);
	lru.PrintList();
	
	return 0;
}
