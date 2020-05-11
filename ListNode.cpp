#include <iostream>

using namespace std;

template<class T>
class ListNode{
public:
  T data;//holds the data
  ListNode *next;//points to next node
  ListNode *prev;//points to prev node
ListNode(){
  data = NULL;
  next = NULL;
  prev = NULL;
}

ListNode(T d){
  data = d;
  next = NULL;//if issues, change NULL to nullptr
  prev = NULL;
}

~ListNode(){
  delete next;
  delete prev;
}
};
