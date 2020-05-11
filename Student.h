#include <iostream>
#include <string>
using namespace std;

class Student{
public:
  unsigned int ID;
  string name;
  string year;
  string major;
  double gpa;
  unsigned int advisor;
  Student();//default constructor
  Student(int id, string n, string y, string m, double g, int ad);//overloaded constructor
  ~Student();
  void printInfo();//prints student info
  int compareYear(string opp);//compares the grade
};
