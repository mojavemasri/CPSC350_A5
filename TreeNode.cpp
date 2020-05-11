#include <iostream>
using namespace std;

template <class T>
class TreeNode{//BST Nodes
public:
  TreeNode(){//default constructor
    key = -1;
    left = NULL;
    right = NULL;
    val =  NULL;
  }
  TreeNode(int k){//overloaded1
    key = k;
    left = NULL;
    right = NULL;
    val = NULL;
  }
  TreeNode(T v){//overloaded2
    key = -1;
    left = NULL;
    right = NULL;
    val = v;
  }
  TreeNode(int k, T value){//overloaded3
    key = k;
    val = value;
    left = NULL;
    right = NULL;
  }
  ~TreeNode(){
    delete left;
    delete right;
  }
  int key;//key, in this assignment the ID
  TreeNode<T> *left;//left node
  TreeNode<T> *right;//right node
  T val;//value
};
