#include<iostream>

#include "BST.cpp"
#include "BSTNode.cpp"

int main(){
  BST novo;
  novo.inserir(95);
  novo.inserir(5);
  novo.inserir(100);
  novo.preOrder();
  return 0;
}
