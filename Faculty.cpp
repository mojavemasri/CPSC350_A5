#include "Faculty.h"


Faculty::Faculty(){//default constructor
  ID = 0;
  level = "";
  department = "";
  name = "";
  advisees = new int[10];
  for(int i = 0; i < 10; ++i){
    advisees[i] = 0;
  }
  size = 10;
}

Faculty::Faculty(int id, string n, string l, string d){//overloaded
  ID = id;
  name = n;
  level = l;
  department = d;
  advisees = new int[10];
  for(int i = 0; i < 10; ++i){
    advisees[i] = 0;
  }
  size = 10;
}

Faculty::~Faculty(){//destructor
}

void Faculty::printInfo(){//print info
  cout << "ID: "  << ID << endl;
  cout << "Name: " << name << endl;
  cout << "Level: " << level << endl;
  cout << "Department: " << department << endl;
  cout << "Advisees: " << endl;
  int i = 0;
  while(advisees[i] != 0){
    cout << advisees[i] << endl;
    ++i;
  }
  cout << endl;
}

void Faculty::Mem(){//reallocates array memory
  for(int j = 0; j < sizeof(advisees); ++j){
    cout << advisees[j] << endl;
  }
  if(advisees[sizeof(advisees)-1] != 0){
    int temp[sizeof(advisees)*2];
    for(int i = 0; i < sizeof(advisees)*2; ++i){
      if(i < sizeof(advisees))
        temp[i] = advisees[i];
      else
        temp[i] = 0;
    }
    advisees = temp;
  }
}
