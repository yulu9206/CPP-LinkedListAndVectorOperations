#include <iostream>
#include "Node.h"

using namespace std;

long Node::constructor_count;
long Node::destructor_count;
long Node::copy_count;
    /**
     * Constructor.
     * @param the_value the initial value.
     */
Node::Node(const long the_value):value(the_value){constructor_count++;}

    /**
     * Copy constructor.
     * @param other the other node object to copy.
     */
Node::Node(const Node& other)
{
	long the_value = other.get_value();
	value = the_value;
	Node::copy_count++;
}

    /**
     * Destructor.
     */
Node::~Node(){destructor_count++;}

    /**
     * Getter.
     * @return the value.
     */
long Node::get_value() const{return value;}

    /**
     * Getter.
     * @return the value of the global constructor_count.
     */
long Node::get_constructor_count(){return constructor_count;}

    /**
     * Getter.
     * @return the value of the global copy_count.
     */
long Node::get_copy_count(){return copy_count;}

    /**
     * Getter.
     * @return the value of the global destructor_count.
     */
long Node::get_destructor_count(){return destructor_count;}

    /**
     * Reset the values of the global counters.
     */
void Node::reset()
{
	constructor_count = 0;
	copy_count = 0;
	destructor_count = 0;
}

    /**
     * Overloaded == operator.
     * @return true if the values of two nodes are equal, else false.
     */
bool Node::operator ==(const Node& other) const
{
	return value == other.get_value();
}

    /**
     * Overloaded > operator.
     * @return true if the value of this node is greater than
     *              the value of the other node, else false.
     */
bool Node::operator  >(const Node& other) const
{
	return value > other.get_value();
}
bool Node::operator  <(const Node& other) const
{
	return value < other.get_value();
}




