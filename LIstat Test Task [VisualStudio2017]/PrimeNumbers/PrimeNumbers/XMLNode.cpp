#include "XMLNode.h"

XMLNode::XMLNode(std::string tagName) :
	tagName(tagName)
{
}

XMLNode::~XMLNode()
{
	for (std::vector<XMLNode *>::iterator iter = childNodes.begin(); iter != childNodes.end(); iter++)
	{
		if (*iter)
		{
			delete(*iter);
		}
	}
}

std::string XMLNode::getTagName()
{
	return this->tagName;
}

void XMLNode::setParentNode(XMLNode *node)
{
	this->parent = node;
}

XMLNode* XMLNode::getParentNode()
{
	return this->parent;
}

void XMLNode::addChildNode(XMLNode *node)
{
	this->childNodes.push_back(node);
}

std::vector<XMLNode *> XMLNode::getChildNodes()
{
	return this->childNodes;
}

void XMLNode::setValue(std::string value)
{
	this->value = value;
}

std::string XMLNode::getValue()
{
	return this->value;
}