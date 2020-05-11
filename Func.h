#include <iostream>
using namespace std;
//essentially stores information such that if undo is called it can recreate previous scenarios
class Func{
public:
  int opt;//stores which function to call on undo
  int factID;
  int studID;
  string name;
  string year;
  string major;
  double gpa;
  string level;
  string department;
  int *advisees;
  int size;
  Func();//default constructor
  Func(int o, int f, int s);//overloaded constructor
};
