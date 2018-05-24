#include "BST.h"
#include <iostream>

using namespace std;

BST::BST()
{
    //ctor
    root = NULL;
}

BST::~BST()
{
    //dtor
}

bool BST::isEmpty()
{
    return root==NULL;
}

int BST::height(BSTNode* t)
{
	return t == NULL ? -1 : t->getHeight();
}

int BST::max(int lhs, int rhs){
	return lhs > rhs ? lhs : rhs;
}

int BST::qtNodes()
{
    return qtNodes(root);
}

int BST::qtNodes(BSTNode* no)
{
    if (no == NULL)
		return 0;
	int qtleft = qtNodes (no->getLeft());
	int qtright = qtNodes (no->getRight());
	return qtleft + qtright + 1;
}

void BST::inserir (int valor)
{
    root = inserir(root,valor);
}



void BST::preOrder()
{
    preOrder(root);
}

void BST::inOrder()
{
    inOrder(root);
}

void BST::posOrder()
{
    posOrder(root);
}

void BST::preOrder(BSTNode *no)
{
    if (no!=NULL)
    {
        cout<<no->getData()<<endl;
        preOrder(no->getLeft());
        preOrder(no->getRight());
    }
}

void BST::posOrder(BSTNode *no)
{
    if (no!=NULL)
    {
        posOrder(no->getLeft());
        posOrder(no->getRight());
        cout<<no->getData()<<endl;
    }
}

void BST::inOrder(BSTNode *no)
{
    if (no!=NULL)
    {
        inOrder(no->getLeft());
        cout<<no->getData()<<endl;
        inOrder(no->getRight());

    }
}


BSTNode* BST::inserir(BSTNode* t, int x){

	if(t == NULL){

		t = new BSTNode(x);

	}else if (x < t->getData()){

		t->setLeft( inserir(t->getLeft(), x) );

    //cout << "RIGHT: " << height(NULL) << endl;

		if( height(t->getRight()) - height(t->getLeft()) == -2){

			if(x < t->getLeft()->getData()){
				t = rotateLL( t );
			}else{
				t = rotateLR( t );
			}
       if(x > t->getData()){

				t->setRight(inserir(t->getRight(), x));

				if(height(t->getRight()) - height(t->getLeft()) == 2){
					if( x > t->getRight()->getData()){
						t = rotateRR(t);
					}else{
						t = rotateRL(t);
					}
				}

			}else{
				t->setHeight(max(height(t->getLeft()), height(t->getRight())) + 1);
				return t;
			}
		}
	}

}

BSTNode* BST::rotateLL(BSTNode* node){

	BSTNode* leftSubTree = node->getLeft();
	node->setLeft(leftSubTree->getRight());
	leftSubTree->setRight(node);
	node->setHeight( max( height(node->getLeft()), height(node->getRight()) )+1); //implementar
	leftSubTree->setHeight( max(height(leftSubTree->getLeft()), node->getHeight()) + 1 );
	return leftSubTree;
}

BSTNode* BST::rotateLR(BSTNode* node){
	node->setLeft( rotateRR( node->getLeft() ) );
	return rotateLL(node);
}

BSTNode* BST::rotateRL(BSTNode* node){
	return node;
}


BSTNode* BST::rotateRR(BSTNode* node){
	return node;
}



BSTNode*  BST::remover(int valor){
    remover(root, valor);
}

BSTNode* BST::remover(BSTNode *no, int valor){

      // PRIMEIRO CASO DA REMOÇÃO

      if(no->getData() == valor){
        if((no->getRight() == NULL )&& (no->getLeft()== NULL)){
            delete(no);
            return NULL;
          }



      // SEGUNDO CASO DA REMOÇÃO
      else if((no->getRight() == NULL)){
         BSTNode* aux;
         aux = no->getLeft();
         delete(no);
         return aux;
      }
      else if(no->getLeft() == NULL){
        BSTNode* aux;
        aux = no->getRight();
        delete(no);
        return aux;
      }

      //TERCEIRO CASO DA REMOÇÃO

      BSTNode* esquerda = no->getLeft();
      while(esquerda->getRight() != NULL)
        esquerda = esquerda->getRight();

      no->setData(esquerda->getData());
      remover(esquerda, esquerda->getData());
    }

      // SE NÃO ACHOU O VALOR

      if(valor > no->getData()){
        no->setRight(remover(no->getRight(), valor));
      }
      else
      no->setLeft(remover(no->getLeft(), valor));
}

     BSTNode* BST::busca(int valor){
       busca(root, valor);
     }

     BSTNode* BST::busca(BSTNode *no, int valor){
       if(no == NULL){
         return NULL;
       }
       int d = no->getData();
       if(d == valor){
         return no;
       }
       if(valor < d){
         return busca(no->getLeft(), valor);
       }
       else if(valor > d){
         return busca(no->getRight(), valor);
       }
     }
