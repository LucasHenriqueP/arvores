#ifndef BST_H
#define BST_H
#include "BSTNode.h"

class BST
{
    public:
        BST();
        virtual ~BST();

    BSTNode* getRoot();
    bool isEmpty();
    int qtNodes();
    void inserir (int valor);
    void preOrder();
    void posOrder();
    void inOrder();
    BSTNode* remover(int);
    BSTNode* busca(int);
    protected:

    private:
    BSTNode *root;

    int height(BSTNode*);
    int qtNodes(BSTNode*);
    void preOrder(BSTNode *no);
    void posOrder(BSTNode *no);
    void inOrder(BSTNode *no);
    int max(int lhs, int rhs);
    BSTNode* remover(BSTNode *, int);
    BSTNode* busca(BSTNode *, int);
    BSTNode* rotateLR(BSTNode* node);
    BSTNode* rotateLL(BSTNode* node);
    BSTNode* inserir(BSTNode* t, int x);
    BSTNode* rotateRL(BSTNode* node);
    BSTNode* rotateRR(BSTNode* node);

};

#endif // BST_H
