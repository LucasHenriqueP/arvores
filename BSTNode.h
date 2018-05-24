#ifndef BSTNODE_H
#define BSTNODE_H
#include <iostream>



class BSTNode
{
    public:
        BSTNode();
        BSTNode(int);
        virtual ~BSTNode();

        int getData();
        void setData(int);
        BSTNode* getLeft();
        BSTNode* getRight();
        void setRight(BSTNode*);
        void setLeft(BSTNode*);
	void setHeight(int);
	int getHeight();


    protected:

    private:
        BSTNode *left, *right;
        int data;
	int height;
};

#endif // BSTNODE_H
