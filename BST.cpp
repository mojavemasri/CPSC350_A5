#include "TreeNode.cpp"

template <class T>
class BST{
 public:
   TreeNode<T> *root;//root
   BST(){
     root = NULL;
   }//default constructor
   ~BST(){
     delete root;
   }//destructor
     TreeNode<T>* retrieve(int k){
       if(searchNode(k)){
         TreeNode<T> *curr = root;

         while(curr->key != k){
           if(k < curr->key){
             curr = curr->left;
           }
           else if(k > curr->key){
             curr = curr->right;
           }
           if(curr == NULL){
             TreeNode<T> *blank = NULL;
             return blank;
           }
       }
       return curr;
     }
       else{
         TreeNode<T> *blank = NULL;
         return blank;
       }
     }//returns a tree node given the key

     bool searchNode(int k){

       if(isEmpty()){
         return false;
       }
       else{
         //tree is not empty
         TreeNode<T> *curr = root;

         while(curr->key != k){
           if(k < curr->key){
             curr = curr->left;
           }
           else if(k > curr->key){
             curr = curr->right;
           }

           if(curr == NULL){
             return false;
           }
           else{
           }
         }
         return true;
       }
     }//returns whether or not a key exists

   void insert(int k, T v){
     TreeNode<T> *newNode = new TreeNode<T>(k, v);
     if(root == NULL){
       //we have an empty tree
       root = newNode;
     }
     else{
     TreeNode<T> *node = NULL;
     node = new TreeNode<T>(k, v);
     node->key = k;
    node->val = v;
       //tree is not empty, we need to find a location
       TreeNode<T> *curr = root;
       TreeNode<T> *parent = root;
       while(true){
         parent = curr;
         if(k < curr->key){
           curr = curr->left;
           if(curr == NULL){
             parent->left = node;
             break;
           }
         }
         else{
            curr = curr->right;
           if(curr == NULL){
             parent->right = node;
             break;
           }
         }
       }
       node = NULL;
       delete node;
     }
   }//inserts a new node

   int numNodes(TreeNode<T> *node){
     if(node->right != NULL && node->left != NULL){
       return numNodes(node->left) + numNodes(node->right) + 1;
     }
     else if(node->right == NULL && node->left == NULL){
       return 1;
     }
     else if(node->right == NULL){
       return 1 + numNodes(node->left);
     }
     else if(node->left == NULL){
       return 1 + numNodes(node->right);
     }
   }//coutns the number of nodes in the tree

   int numNodes(){
     return numNodes(root);
   }//numNodes(root), essentially starts it off
   bool deleteNode(int k){
     if(!searchNode(k))
      return false;

      //tree is not empty and value exist
    TreeNode<T> *curr = root;
    TreeNode<T> *parent = root;
    bool isLeft;

    while(curr->key != k){
      parent = curr;
      if(k < curr->key){
        isLeft = true;
        curr = curr->left;
      }
      else if(k > curr->key){
        isLeft = false;
        curr = curr->right;
      }

      if(curr == NULL){
        return false;
      }
    }
    //node found, let's delete
    if(curr->left == NULL && curr->right == NULL){//no children
      if(curr == root){
        root = NULL;
      }
      else if(isLeft){
        parent->left = NULL;
      }
      else if(!isLeft){
        parent->right = NULL;
      }
    }
    else if(curr->left == NULL){
      if(curr == root){
        root = curr->right;
      }
      else if(isLeft){
        parent->left = curr->right;
      }
      else if(!isLeft){
        parent->right = curr->right;
      }
    }

    else if(curr->right == NULL){
      if(curr == root){
        root = curr->left;
      }
      else if(isLeft){
        parent->left = curr->left;
      }
      else if(!isLeft){
        parent->right = curr->left;
      }
    }
    else{
      //the node has 2 Children
      TreeNode<T> *succ = getSuccessor(curr);
      if(curr == root){
        root = succ;
      }
      else if(isLeft){
        parent->left = succ;
      }
      else if(!isLeft){
        parent->right = succ;
      }
      succ->left = curr->left;

      return true;
    }
 }//deletes a node given the key

   bool isEmpty(){
     return(root == NULL);
   }//returns whether or not its empty
   TreeNode<T>* getMax(){
     TreeNode<T>* curr = root;
     while(curr->right != NULL){
       curr = curr->right;
     }
     return curr;
   }//returns the smallest key's treenode
   TreeNode<T>* getMin(){
     TreeNode<T> *curr = root;
     if(root == NULL){
       return NULL;//tree is empty
     }
     while(curr->left != NULL){
       curr = curr->left;
     }
     return curr;
   }//returns the biggest key's treenode

   TreeNode<T>* getSuccessor(TreeNode<T> *d){
     TreeNode<T> *curr = d->right;
     TreeNode<T> *sp = d;
     TreeNode<T> *successor = d;

     while (curr != NULL){
       sp = successor;
       successor = curr;
       curr = curr->left;
     }
     if(successor != d->right){
       sp->left = successor->right;
       successor->right = d->right;
     }
     return successor;
   }//returns successor to arguement

   void printTree(TreeNode<T> *node){
     if(node == NULL){
       return;
     }
       printTree(node->left);
       printTree(node->right);
   }//prints tree

   void printTree(){
     printTree(root);
   }//printTree(root)

   };
