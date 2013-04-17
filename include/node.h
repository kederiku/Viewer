#ifndef __NODE_H__
#define __NODE_H__

#include <fbxsdk.h>
#include <list>

class Node
{
private:
	std::list<Node*>	__list_node;
	KFbxNode*		__node;
public:
				Node(void);
	virtual			~Node();
	bool			AddChild(Node* node);
	virtual bool		InitNode(KFbxNode* node);
	virtual	void		Draw();
};
#endif
