#include "node.h"

Node::Node(int data):
    data(data)
{
}

Node::~Node()
{
}

int Node::GetData()
{
    return data;
}

void Node::SetNext(Node *node)
{
    next = node;
}

Node* Node::GetNext()
{
    return next;
}
