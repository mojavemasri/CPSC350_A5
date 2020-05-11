#include "ListNode.cpp"

template<class T>
class DoublyLinkedList{
public:
    ListNode<T> *front;//front of list
    ListNode<T> *back;//back of list
    unsigned int size;
  DoublyLinkedList(){//default constructor
  //empty list
  size = 0;
  front = NULL;
  back = NULL;
}

unsigned int getSize(){//returns size
  return size;
}
bool isEmpty(){//checks whether list is empty
  if(front == NULL || back == NULL){
    return true;
  }
  return(size == 0);
}
void printList(){//prints list
  ListNode<T> *curr = front;
  ListNode<T> *next = front;
  int idx = 0;
  while(curr != back){
    idx++;//instead of below
    curr = curr->next;
  if(curr == NULL){
    break;
  }
  }
}
T insertFront(T d){//inserts a node in front
  ListNode<T> *node = new ListNode<T>(d);
  if(isEmpty()){//case check
    back = node;
    front = node;
    size++;
    return d;
  }
  else{
  front->prev = node;
  node->next = front;
}
front = node;
  size++;
  printList();
  return d;
}
void insertBack(T d){//inserts back
  ListNode<T> *node = new ListNode<T>(d);
  if(isEmpty()){//case check
    back = node;
    front = node;
    size++;
    return;
  }
  else{
    //reassign pointers
  back->next = node;
  node->prev = back;
}
node->next = NULL;
  back = node;
  size++;
}
T removeFront(){
  ListNode<T> *ft = front;
  //case checking
  if(isEmpty()){
    return ft->data;
  }
  if(--size == 0){
    T thing = front->data;
    delete front;
    return thing;
  }
    //reassign pointers
  T temp = front->data;
  front = front->next;
  ft->next = NULL;
  ft = NULL;
  delete ft;
  return temp;
}
T peekFront(){
  return front->data;
}
int search(T val){
  //search but it's for the value
  if(isEmpty())//error checking
    return -1;
  int pos = 1;
  ListNode<T> *curr = front;
  while(curr->data != val){
    curr = curr->next;
    if(curr == NULL){
      return -1;
    }
    pos++;
  }
    return pos;
}
int search(ListNode<T> val){
  //search but its for a node
  if(isEmpty())
    return -1;
  int pos = 1;
  ListNode<T> *curr = front;
  while(curr != val){
    curr = curr->next;
    if(curr == NULL){
      return -1;
    }
    pos++;
  }
    return pos;
}
T removeAtPos(unsigned int pos){
  //error checking exceeding bounds
  if(pos >= size){
    return front->data;
  }
  int idx = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;
  ListNode<T> *next = front;
  if(pos == 0){
    return removeFront();
  }
//searching for position
  while(idx != pos){
    prev = curr;
    curr = curr->next;
    next = curr->next;
    idx++;
  }
  if(curr == back){
    back = curr->prev;
  }
  //updating pointers
  if(pos == size-1)
    prev->next = NULL;
  else
    prev->next = curr->next;
  if(pos != size -1)
    next->prev = curr->prev;
  curr->next = NULL;
  curr->prev = NULL;
  T ret = curr->data;
  size--;
  delete curr;
  return ret;
}
T removeBack(){
  return removeAtPos(size-1);
}
T get(int pos){
  if(pos == 0){
    if(!isEmpty()){/
      return (back->data);
    }
    else{
    }
  }
  //access
  ListNode<T> *temp = front;
  if(pos > size){
    T val = 0;
    return val;
  }
  else{
    for(int i = 0; i < pos; ++i){
      if(temp == back){
        return back->data;
      }
      temp = temp->next;
    }
    return (temp->data);
  }
}
};
