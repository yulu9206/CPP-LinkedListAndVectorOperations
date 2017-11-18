#include <iostream>
#include <iterator>
#include "SortedList.h"
#include <algorithm>
using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

int SortedList::size() const { return data.size(); }

bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedList::prepend(const long value)
{
	Node new_node(value);
	data.push_front(new_node);
}

void SortedList::append(const long value)
{
	Node new_node(value);
	data.push_back(new_node);
}

void SortedList::remove(const int index)
{
	list<Node>::iterator it = data.begin();
	advance (it, index);
	data.erase(it);
}

void SortedList::insert(const long value)
{
	list<Node>::iterator begin = data.begin();
	list<Node>::iterator end = data.end();
	list<Node>::iterator it;
	Node new_node(value);
	if(data.size() == 0)
	{
		data.insert(begin, new_node);
		return;
	}
	it = upper_bound(begin, end, new_node);
	data.insert(it, new_node);
}

Node SortedList::at(const int index)
{
	list<Node>::iterator it = data.begin();
	advance (it, index);
	return *it;
}





