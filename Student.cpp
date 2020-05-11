#include "Student.h"


Student::Student(){//default constructor
  ID = 0;
  advisor = 0;
  gpa = 0;
  year = "";
  major = "";
  name = "";
}

Student::Student(int id, string n, string y, string m, double g, int ad){//overloaded constructor
  ID = id;
  name = n;
  year = y;
  major = m;
  gpa = g;
  advisor = ad;
}

Student::~Student(){//destructor

}

void Student::printInfo(){//prints student info
  cout << "ID: "  << ID << endl;
  cout << "Name: " << name << endl;
  cout << "Year: " << year << endl;
  cout << "Major: " << major << endl;
  cout << "GPA: " << gpa << endl;
  cout << "Advisor: " << advisor << endl << endl;;
}

int Student::compareYear(string opp){//returns 1 if the variable year is bigger, -1 if opp is bigger, and 0 if they're equal
  if(year == ""){
    return -2;
  }
  else if(opp == year){
    return 0;
  }
  else if(opp == "Freshman"){
      return 1;
  }
  else if(opp == "Senior"){
      return -1;
  }
  else if(opp == "Junior"){
    if(year == "Senior"){
      return 1;
    }
    else{
      return -1;
    }
  }
  else if(opp == "Sophomore"){
    if(year == "Freshman"){
      return -1;
    }
    else{
      return 1;
    }
  }
  else{
    cout << "ERROR: Invalid string" << endl;
    return -1;
  }
}
