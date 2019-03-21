#pragma once

#include <string>
#include <vector>

class XMLNode
{
private:
	std::string				tagName;
	XMLNode					*parent = nullptr;
	std::vector<XMLNode*>	childNodes;
	std::string				value;
public:
	XMLNode(std::string tagName);
	~XMLNode();

	std::string getTagName();

	void setParentNode(XMLNode *node);
	XMLNode* getParentNode();

	void addChildNode(XMLNode *node);
	std::vector<XMLNode *> getChildNodes();

	void setValue(std::string value);
	std::string getValue();
};