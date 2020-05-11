#include "Func.h"
//essentially stores information such that if undo is called it can recreate previous scenarios
Func::Func(){//default constructor
  opt = -1;
  factID = -1;
  studID = -1;
  name = "";
  year = "";
  major = " ";
  gpa = -1;
  level = "";
  department = "";
  advisees = NULL;
  size = -1;
}

Func::Func(int o, int f, int s){//overloaded constructor
  opt = o;
  factID = f;
  studID = s;
  name = "";
  year = "";
  major = " ";
  gpa = -1;
  level = "";
  department = "";
  advisees = NULL;
  size = -1;
}
