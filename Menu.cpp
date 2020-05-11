#include "Menu.h"

//see h file for comments
Menu::Menu(){
  factList = new DoublyLinkedList<int>();
  studTree = new BST<Student>();
  facTree = new BST<Faculty>();
  if(isGood("studentTable.txt") && isGood("facultyTable.txt")){
    initFacTree();
    initStudTree();
  }
  init = new DoublyLinkedList<int>();
}
Menu::~Menu(){
  if(studTree != NULL)
    delete studTree;
  if(facTree != NULL)
    delete facTree;
}

void Menu::initStudTree(){
  ifstream inFS;
  inFS.open("studentTable.txt");
  if(!inFS.eof()){
  int size;
  inFS >> size;
  for(int i = 0; i < size; ++i){
    int id = 0;
    string name = "";
    string year = "";
    string major = "";
    double gpa = 0;
    int advisor;
    inFS >> id;
    inFS.ignore();
    getline(inFS, name);
    getline(inFS, year);
    getline(inFS, major);
    inFS >> gpa;
    inFS >> advisor;
    Student *s = new Student(id, name, year, major, gpa, advisor);
    addStudent(*s);
  }
}
}
void Menu::initFacTree(){
ifstream inFS;
inFS.open("facultyTable.txt");
if(!inFS.eof()){
int size = 0;
inFS >> size;
for(int i = 0; i < size; ++i){
  int id = 0;
  string name = "";
  string level = "";
  string department = "";
  int numofAdvisors = 0;
  int curr = 0;
  int sizeOf = 0;
  int *adv = NULL;
  inFS >> id;
  inFS.ignore();
  getline(inFS, name);
  getline(inFS, level);
  getline(inFS, department);
  inFS >> numofAdvisors;
  if(numofAdvisors == 0){
    numofAdvisors = 5;
    adv = new int[10];
    for(int i = 0; i < 10; ++i){
      adv[i] = 0;
    }
  }
  else{
  adv = new int[numofAdvisors*2];
  for(int j = 0; j < numofAdvisors; ++j){
    inFS >> curr;
    adv[j] = curr;
    adv[(numofAdvisors*2) - j - 1] = 0;
  }
}
  Faculty *f = new Faculty(id, name, level, department);
  f->advisees = adv;
  f->size = numofAdvisors*2;
  addFact(*f);
}
}
}
void Menu::breakdownStudTree(TreeNode<Student> *node){
  ofstream outFS;
  outFS.open("studentTable.txt", ios_base::app);
  Student s = node->val;
  outFS << s.ID << endl;
  outFS << s.name << endl;
  outFS << s.year << endl;
  outFS << s.major << endl;
  outFS << s.gpa << endl;
  outFS << s.advisor << endl;
  if(node->left != NULL)
  {
    breakdownStudTree(node->left);
  }
  if(node->right != NULL){
  breakdownStudTree(node->right);
  }
}
void Menu::breakdownFacTree(TreeNode<Faculty> *node){
  ofstream outFS;
  outFS.open("facultyTable.txt", ios_base::app);
  Faculty f = node->val;
  outFS << f.ID << endl;
  outFS << f.name << endl;
  outFS << f.level << endl;
  outFS << f.department << endl;
  int k = 0;
  for(int i = 0; i < f.size; ++i){
    if(f.advisees[i] == 0){
      k = i;
      break;
    }
  }
  outFS << k << endl;
  for(int j = 0; j < k; ++j){
    outFS << f.advisees[j] << endl;
  }
  if(node->left != NULL)
  {
    breakdownFacTree(node->left);
  }
  if(node->right != NULL){
  breakdownFacTree(node->right);
  }
}

void Menu::printStud(){
  if(studTree->isEmpty()){
    cout << "No students have been inputed into the system" << endl;
    return;
  }
  printStudTree(studTree->root);
}
void Menu::printFact(){
  if(facTree->isEmpty()){
    cout << "No faculty members have been inputed into the system" << endl;
    return;
  }
  printFactTree(facTree->root);
}
void Menu::getStudent(int id){
  Student s = studTree->retrieve(id)->val;
  cout << endl;
  s.printInfo();
}
void Menu::getFact(int id){
  Faculty f = facTree->retrieve(id)->val;
  cout << endl;
  f.printInfo();
}
void Menu::getAdvisor(int studID){
  Student stud = (studTree->retrieve(studID))->val;
  if(facTree->searchNode(stud.advisor))
    getFact(stud.advisor);
}
void Menu::getAdvisees(int factID){
  Faculty *f = &(facTree->retrieve(factID)->val);
  int *list = f->advisees;
  if(list[0] == 0){
    cout << "Advisor currently has no advisees" << endl;
    return;
  }
  else{
    for(int i = 0; i < f->size; ++i){
      if(list[i] == 0)
        break;
      else{
        getStudent(list[i]);
      }
    }
  }


}

void Menu::addStudent(Student s){
  if(!facTree->searchNode(s.advisor) && s.advisor != 0){
    cout << "MENU :: Invalid Advisor ID, please try again: " << endl;
    return;
  }
studTree->insert(s.ID, s);
if(s.advisor == 0){
  return;
}
Faculty *f = NULL;
f = &(facTree->retrieve(s.advisor)->val);
f->Mem();
  for(int i = 0; i < f->size; ++i){
    if(f->advisees[i] == s.ID){
      break;
    }
    if(f->advisees[i] == 0){
      f->advisees[i] = s.ID;
      break;
    }
  }
}

void Menu::deleteStudent(int id){
  int ad = studTree->retrieve(id)->val.advisor;
  removeAdvisee(ad, id);
  studTree->deleteNode(id);
}

void Menu::addFact(Faculty f){
  facTree->insert(f.ID, f);
  factList->insertBack(f.ID);
}

void Menu::deleteFact(int id){
  Faculty *f = &(facTree->retrieve(id)->val);
  int *ad = f->advisees;
  for(int i = 0; i < f->size; ++i){
    if(ad[i] == 0){
      break;
    }
  changeAdvisor(ad[i], 0);
}
  facTree->deleteNode(id);
  factList->removeAtPos(factList->search(id));
}
void Menu::changeAdvisor(int studID, int factID){
  if(factID == 0){
    studTree->retrieve(studID)->val.advisor = 0;
    return;
  }
  else{
    for(int j = 0; j < facTree->retrieve(studTree->retrieve(studID)->val.advisor)->val.size; ++j){
      if(facTree->retrieve(studTree->retrieve(studID)->val.advisor)->val.advisees[j] == studID){
        facTree->retrieve(studTree->retrieve(studID)->val.advisor)->val.advisees[j] = 0;
        break;
      }
    }
    studTree->retrieve(studID)->val.advisor = factID;
    for(int i = 0; i < facTree->retrieve(factID)->val.size; ++i){
      if(facTree->retrieve(factID)->val.advisees[i] == 0){
        facTree->retrieve(factID)->val.advisees[i] = studID;
        return;
      }
    }
    return;
  }
  bool found = 0;
  int num = 0;
  Faculty *f = NULL;
  int *list;
  for(int i = 0; i < factList->size; ++i){
      if(facTree->retrieve((factList->get(i)))->val.department == facTree->retrieve(factID)->val.department){
        if(facTree->retrieve((factList->get(i)))->val.ID != factID){
          num = i;
        Student *s = &(studTree->retrieve(studID)->val);
        s->advisor = facTree->retrieve(i)->val.ID;
        f = &(facTree->retrieve(i)->val);
        f->Mem();
        list = f->advisees;
        int j = 0;
        while(list[j] != 0 && j != f->size){
          ++j;
        }
        if(j != f->size){
          list[j] = studID;
        }
        found = 1;
      }
      break;
      }
  }
  if(!found){
    cout << "MENU :: New advisor could not be found! Advisor will be set to 0!" << endl;
    studTree->retrieve(studID)->val.advisor = 0;
    return;
  }
  int j = 0;
  while(list[j] != studID && j != f->size){
    ++j;
  }
  if(j != f->size)
    list[j] = 0;
  for(int i = j; i < f->size; ++i){
    if(list[i] == 0){
      list[j] = list[i-1];
      list[i - 1] = 0;
      break;
    }
  }
}
void Menu::removeAdvisee(int factID, int studID){
  Faculty *f  = &(facTree->retrieve(factID)->val);
  int j = 0;
  int *list = NULL;
  list = f->advisees;
  while(list[j] != studID && j != f->size){
    ++j;
  }
  if(j != f->size)
    list[j] = 0;
  for(int i = j; i < f->size; ++i){
    if(list[i] == 0){
      list[j] = list[i-1];
      list[i - 1] = 0;
      break;
    }
  }
}

void Menu::printStudTree(TreeNode<Student> *node){
  if(node == NULL){
    return;
  }
    printStudTree(node->left);
    (node->val).printInfo();
    printStudTree(node->right);
}
void Menu::printFactTree(TreeNode<Faculty> *node){
  if(node == NULL){
    return;
  }
    printFactTree(node->left);
    (node->val).printInfo();
    printFactTree(node->right);
}
bool Menu::containsDuplicates(int t, DoublyLinkedList<int> *L){
  if(L->isEmpty()){
    return false;
  }
  else if(L->front == NULL){
    return false;
  }
  ListNode<int> *node = L->front;
  if(node->data == t){
    return true;
  }
  while(node != L->back){
    node = node->next;
    if(t == node->data){
      return true;
    }
  }
  return false;
}
bool Menu::isGood(string fname){
  ifstream infile(fname);
  return infile.good();
}
