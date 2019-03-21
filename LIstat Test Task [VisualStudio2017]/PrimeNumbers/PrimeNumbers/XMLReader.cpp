#include "XMLReader.h"

XMLReader::XMLReader(std::string filename) :
	XMLFile(filename)
{
}

XMLReader::~XMLReader()
{
}

bool XMLReader::Open()
{
	file.open(filename, std::ios::in);
	return file.is_open();
}

void XMLReader::Parse()
{
	char symb = '\0';
	std::string tagName;
	std::string val;

	bool tag = false;
	bool endTag = false;

	XMLNode *cur_node = root;

	while (file >> symb)
	{
		if (symb == '<')
		{
			if (!tag && val != "")
			{
				cur_node->setValue(val);
			}
			val = "";
			tag = true;
		}
		else if (symb == '/')
		{
			endTag = true;
		}
		else if (symb == '>')
		{
			if (endTag)
			{
				cur_node = cur_node->getParentNode();
			}
			else
			{
				XMLNode *node = new XMLNode(tagName);
				if (!this->root)
				{
					this->root = node;
					cur_node = this->root;
				}
				else
				{
					cur_node->addChildNode(node);
					node->setParentNode(cur_node);
					cur_node = node;
				}
			}
			tagName = "";
			tag = false;
			endTag = false;
		}
		else
		{
			if (tag)
			{
				tagName += symb;
			}
			else
			{
				val += symb;
			}
		}
	}
}

void XMLReader::GetIntervals(std::list<Interval *> *interval_list)
{
	XMLNode *node = this->root;			// root
	node = node->getChildNodes()[0];	// intervals

	std::vector<XMLNode *> interval = node->getChildNodes();	// interval 1,2,3...

	for (std::vector<XMLNode *>::iterator iter = interval.begin(); iter != interval.end(); iter++)
	{
		std::string begin_str = (*iter)->getChildNodes()[0]->getValue();
		std::string end_str = (*iter)->getChildNodes()[1]->getValue();
		int begin = atoi(begin_str.c_str());
		int end = atoi(end_str.c_str());
		Interval *inter = new Interval(begin, end);
		(*interval_list).push_back(inter);
	}
}