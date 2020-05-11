#include <iostream>
#include "DoublyLinkedList.cpp"
#include <string>
using namespace std;

class Faculty{
public:
  unsigned int ID;
  string name;
  string level;
  string department;
  int *advisees;//array of advisees
  int size;//size of array
  Faculty();//default constructor
  Faculty(int id, string n, string l, string d);//overloaded constructor
  ~Faculty();//destructor
  void printInfo();//prints info for faculty
  void Mem();//reallocates memory
};
