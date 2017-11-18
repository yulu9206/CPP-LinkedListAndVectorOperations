#include <iostream>
#include <iterator>
#include <vector>
#include "SortedVector.h"
#include <algorithm>

using namespace std;

SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
}

int SortedVector::size() const { return data.size(); }

bool SortedVector::check() const
{
    if (data.size() == 0) return true;

    vector<Node>::const_iterator it = data.begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

void SortedVector::prepend(const long value)
{
    Node new_node(value);
    vector<Node>::iterator it = data.begin();
    it = data.insert(it, new_node);
}

void SortedVector::append(const long value)
{
	Node new_node(value);
	data.push_back(new_node);
}

void SortedVector::remove(const int index)
{
	vector<Node>::iterator it = data.begin() + index;
	it = data.erase(it);
}

void SortedVector::insert(const long value)
{
	vector<Node>::iterator begin = data.begin();
	vector<Node>::iterator end = data.end();
	vector<Node>::iterator it;
	Node new_node(value);
	if(data.size() == 0)
	{
		data.insert(begin, new_node);
		return;
	}
	it = upper_bound(begin, end, new_node);
	data.insert(it, new_node);
}

Node SortedVector::at(const int index) const
{
	return data.at(index);
}




