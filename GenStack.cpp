#include <iostream>

using namespace std;
//T stack, can change data type

template <class T>
class GenStack
{
  public:
  GenStack()//default constructor
    {
      //initialization of default values
      myArray = new T[5];
      size = 5;
      top = -1;
    }
  GenStack(int maxSize)
  {
    myArray = new T[maxSize];
    size = maxSize;
    top = -1;
  }//overloaded constructor 1

  ~GenStack()
  {
    delete myArray;
  }//destructor

//core functions
  void push(T d)
  {
    if(isFull()){
      allocateMem();
    }
    myArray[++top] = d;
  }
  T pop(){

    if(isEmpty()){
      return myArray[0];
    }
    else{
    return myArray[top--];//pop returns and removes
  }
}
  T peek()
  {
    if(isEmpty()){
      cout << "Empty Stack" << endl;
      return NULL;
    }
    else{
    return myArray[top];
}//aka top()
}
  void allocateMem(){//when stack becomes full, a new array is created that is twice the size, and all the values are copied over
    myArray[0] = myArray[1];
    myArray[1] = myArray[2];
    myArray[2] = myArray[3];
    myArray[3] = myArray[4];
    myArray[4] = myArray[5];
    top--;
  }
//helper functions
bool isFull()
{
  return (top == size-1);;
}

bool isEmpty()
{
  return(top == -1);
}

  int getSize(){
  return size;
}


  int size;//max size of my stack
  int top;//variable to keep track of indices representing the top of our stack
//pointer *myArray to chars
  T *myArray;
};
