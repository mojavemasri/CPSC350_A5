#include "Menu.h"
#include "GenStack.cpp"
#include "Func.h"

int main(){
  cout << "MAIN:: start" << endl;
  Menu *m = new Menu();
  GenStack<Func> *stack = new GenStack<Func>();
  bool done = false;
  int options = 0;
  cout << "Welcome to The Student Directory: " << endl;
  while(!done){//this variable is only changed when the user hits 14
    cout << "Press enter to continue: ";
    char temp = 'x';//this just gives a delay so the user can hit enter
    while (temp != '\n'){
      cin.get(temp);
    }
    cout << endl << endl;
    cout << "Select one of the following options: " << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3. Find and display student information given the students id" << endl;
    cout << "4. Find and display faculty information given the faculty id" << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7. Add a new student" << endl;
    cout << "8. Delete a student given the id" << endl;
    cout << "9. Add a new faculty member" << endl;
    cout << "10. Delete a faculty member given the id." << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "12. Remove an advisee from a faculty member given the ids" << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;
    do{
      cout << "Select your option: ";
      cin >> options;
      if(cin.fail()){
        cout << "Invalid input: integer required: please restart program." << endl;//this ends the software and returns -1
        return -1;
      }
    }while(options <= 0 || options > 14);
    if(options == 1){
      temp = 'x';
      while (temp != '\n'){
        cin.get(temp);
      }
      m->printStud();
    }
    else if(options == 2){
      temp = 'x';
      while (temp != '\n'){
        cin.get(temp);
      }
      m->printFact();
    }
    else if(options == 3){
      int studID3 = 0;
      cout << "Enter student ID: ";
      cin >> studID3;
      if(cin.fail()){
        cout << "Invalid input: integer required: please restart program." << endl;
        return -1;
      }
      else if(m->studTree->searchNode(studID3)){

      m->getStudent(studID3);//error handling done inside class

      }
      else{
        cout << "Student ID Number " << studID3 << " does not exist. Please try again." << endl;
      }
      temp = 'x';
      while (temp != '\n'){
        cin.get(temp);
      }
    }
    else if(options == 4){
      int factID4 = 0;
      cout << "Enter faculty ID: ";
      cin >> factID4;
      if(cin.fail()){
        cout << "Invalid input: integer required: please restart program." << endl;
        return -1;
      }

      if(m->facTree->searchNode(factID4)){
      m->getFact(factID4);//error handling done inside class
    }
    else{
      cout << "That faculty member does not exist. Please try again" << endl;
    }
    temp = 'x';
    while (temp != '\n'){
      cin.get(temp);
    }
    }
    else if(options == 5){
      int studID5 = 0;
      cout << "Enter student ID: ";
      cin >> studID5;
      if(cin.fail()){
        cout << "Invalid input: integer required: please restart program." << endl;
        return -1;
      }
      if(m->studTree->searchNode(studID5)){
      m->getAdvisor(studID5);//error handling done inside class
    }
    else{
      cout << "That student does not exist. Please try again" << endl;
    }
    temp = 'x';
    while (temp != '\n'){
      cin.get(temp);
    }
  }
    else if(options == 6){
      int factID6 = 0;
      cout << "Enter faculty ID: ";
      cin >> factID6;
      if(cin.fail()){
        cout << "Invalid input: integer required: please restart program." << endl;
        return -1;
      }
      if(m->facTree->searchNode(factID6)){
      m->getAdvisees(factID6);//error handling done inside class
    }
    else{
      cout << "This faculty member does not exist. Please try again." << endl;
    }
    temp = 'x';
    while (temp != '\n'){
      cin.get(temp);
    }
  }
    else if(options == 7){//error handling throughout checks whether data types are inserted correctly
      int studID6 = 0;
      string name6 = "";
      string year6 = "";
      string major6 = "";
      double gpa6 = 0;
      int factID6 = 0;
      cout << "Enter student ID: ";
      cin >> studID6;
      if(cin.fail()){
        cout << "Invalid input: integer required: please restart program." << endl;
        return -1;
      }
      cout << "Enter student gpa(decimal): ";
      cin >> gpa6;
      if(cin.fail()){
        cout << "Invalid input: decimal required: please restart program." << endl;
        return -1;
      }
      cout << "Enter Faculty ID: ";
      cin >> factID6;
      if(cin.fail()){
        cout << "Invalid input: integer required: please restart program." << endl;
        return -1;
      }
      cin.ignore();
      cout << "Enter student name: ";
      getline(cin, name6);
      cout << "Enter student year(Freshman, Sophomore): ";
      cin >> year6;
      cin.ignore();
      cout << "Enter major: ";
      getline(cin, major6);
      if(!m->facTree->searchNode(factID6)){
        cout << "Faculty member does not exist. Please try again." << endl;
      }
      else if(m->facTree->retrieve(factID6)->val.department != major6){
        cout << "Student major(" << major6 << ") does not match major of the faculty member's department(" << m->facTree->retrieve(factID6)->val.department << "). Please try again." << endl;

      }
      else{
        Student *S6 = new Student(studID6, name6, year6, major6, gpa6, factID6);
        m->addStudent(*S6);
        Func *t6 = new Func(8, factID6, studID6);
        stack->push(*t6);
      }
    }
    else if(options == 8){
      //error handling
      int studID8 = 0;
      cout << "Enter student ID: ";
      cin >> studID8;
      if(cin.fail()){
        cout << "Invalid input: integer required: please restart program." << endl;
        return -1;
      }
        if(m->studTree->searchNode(studID8)){
      Func *t8 = new Func(7, m->studTree->retrieve(studID8)->val.advisor, studID8);
      t8->name = m->studTree->retrieve(studID8)->val.name;
      t8->major = m->studTree->retrieve(studID8)->val.major;
      t8->year = m->studTree->retrieve(studID8)->val.year;
      t8->gpa = m->studTree->retrieve(studID8)->val.gpa;
      stack->push(*t8);
      m->deleteStudent(studID8);//error handling done inside class
    }
    else{
      cout << "Student does not exist. Please try again." << endl;
    }
    temp = 'x';
    while (temp != '\n'){
      cin.get(temp);
    }
  }
    else if(options == 9){
      int factID9 = 0;
      string name9 = "";
      string level9 = "";
      string dep9 = "";
      cout << "Enter faculty ID: ";
      cin >> factID9;
      if(cin.fail()){//error handling
        cout << "Invalid input: integer required: please restart program." << endl;
        return -1;
      }
      cin.ignore();
      cout << "Enter faculty name: ";
      getline(cin, name9);
      cout << "Enter faculty level: ";
      getline(cin, level9);
      cout << "Enter department: ";
      getline(cin, dep9);
      //error handling

      Func *t9 = new Func(10, factID9, -1);
      stack->push(*t9);
      Faculty *f9 = new Faculty(factID9, name9, level9, dep9);
      m->addFact(*f9);
    }
    else if(options == 10){
    int factID10 = 0;
    cout << "Enter faculty ID: ";
    cin >> factID10;
    if(cin.fail()){
      cout << "Invalid input: integer required: please restart program." << endl;
      return -1;
    }

    if(m->facTree->searchNode(factID10)){
    Func *t10  = new Func(9, factID10, -1);
    t10->name = m->facTree->retrieve(factID10)->val.name;
    t10->level = m->facTree->retrieve(factID10)->val.level;
    t10->department = m->facTree->retrieve(factID10)->val.department;
    t10->advisees = m->facTree->retrieve(factID10)->val.advisees;
    t10->size = m->facTree->retrieve(factID10)->val.size;
    stack->push(*t10);
    m->deleteFact(factID10);//error handling done inside class
  }
  else{
    cout << "Faculty does not exist" << endl;
  }
  temp = 'x';
  while (temp != '\n'){
    cin.get(temp);
  }
}
    else if(options == 11){
      int factID11 = 0;
      int studID11 = 0;
      cout << "Enter faculty ID: ";
      cin >> factID11;
      if(cin.fail()){
        cout << "Invalid input: integer required: please restart program." << endl;
        return -1;
      }
      cout << "Enter student ID: ";
      cin >> studID11;
      if(cin.fail()){
        cout << "Invalid input: integer required: please restart program." << endl;
        return -1;
      }

      if(m->facTree->searchNode(factID11) && m->studTree->searchNode(studID11)){
      Func *t11 = new Func(11, m->studTree->retrieve(studID11)->val.advisor, studID11);
      stack->push(*t11);
      m->changeAdvisor(studID11, factID11);//error handling done here
    }
    else{
      cout << "Faculty member or student does not exist" << endl;
    }
    temp = 'x';
    while (temp != '\n'){
      cin.get(temp);
    }
  }
    else if(options == 12){
      int factID12 = 0;
      int studID12 = 0;
      cout << "Enter faculty ID: ";
      cin >> factID12;
      if(cin.fail()){
        cout << "Invalid input: integer required: please restart program." << endl;
        return -1;
      }
      cout << "Enter student ID: ";
      cin >> studID12;
      if(cin.fail()){
        cout << "Invalid input: integer required: please restart program." << endl;
        return -1;
      }
      if(m->facTree->searchNode(factID12) && m->studTree->searchNode(studID12)){
      Func *t12 = new Func(12, factID12, studID12);
      stack->push(*t12);
      m->removeAdvisee(factID12, studID12);//error handling done inside class
    }
    else{
      cout << "Faculty member or student does not exist. Please try again." << endl;
    }
    temp = 'x';
    while (temp != '\n'){
      cin.get(temp);
    }
  }
    else if(options == 13){//undo
      if(stack->isEmpty()){
        cout << "Undo not available" << endl;
      }
      else{
        Func temp = stack->pop();
        Func *t13 = &temp;
        if(t13->opt == 7){
          Student *s13 = new Student(t13->studID, t13->name, t13->year, t13->major, t13->gpa, t13->factID);
          m->addStudent(*s13);
        }
        else if(t13->opt == 8){
          m->deleteStudent(t13->studID);
        }
        else if(t13->opt == 9){
          Faculty *f13 = new Faculty(t13->factID, t13->name, t13->level, t13->department);
          f13->advisees = t13->advisees;
          m->addFact(*f13);
          for(int i = 0; i < f13->size; ++i){
            if(f13->advisees[i] == 0){
              break;
            }
            else{
              m->studTree->retrieve(f13->advisees[i])->val.advisor = t13->factID;
            }
          }
        }
        else if(t13->opt == 10){
          m->deleteFact(t13->factID);
        }
        else if(t13->opt == 11){
          m->changeAdvisor(t13->studID, t13->factID);
        }
        else if(t13->opt == 12){
          for(int i = 0; i < m->facTree->retrieve(t13->factID)->val.size; ++i){
            if(m->facTree->retrieve(t13->factID)->val.advisees[i] == 0){
              m->facTree->retrieve(t13->factID)->val.advisees[i] = t13->studID;
            }
          }
          m->studTree->retrieve(t13->studID)->val.advisor = t13->factID;
        }
      }
    }
    else if(options == 14){
      //insert size of each tree at the beginning here
      ofstream outFS1;
      ofstream outFS2;/
      outFS1.open("facultyTable.txt");
      outFS1 << m->facTree->numNodes() << endl;
      outFS2.open("studentTable.txt");
      outFS2 << m->studTree->numNodes() << endl;
      m->breakdownStudTree(m->studTree->root);//these zip up the functions into their respective stored files
      m->breakdownFacTree(m->facTree->root);
      done = true;
    }
  }
  delete m;
}
