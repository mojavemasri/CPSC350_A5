#include "Faculty.h"
#include "Student.h"
#include "BST.cpp"
#include <fstream>
//main class
class Menu{
public:
  BST<Student> *studTree;//tree of students
  BST<Faculty> *facTree;//tree of faculty
  DoublyLinkedList<int> *factList;//list of faculty
  DoublyLinkedList<int> *init;//faculty with no advisors
  Menu();//default construct
  ~Menu();//destructor
  void printStud();//prints all student information
  void printFact();//prints all faculty info
  void printStudTree(TreeNode<Student> *node);//recursively prints all students info
  void printFactTree(TreeNode<Faculty> *node);//recursively prints all faculty members info
  void getStudent(int id);//prints student info given id
  void getFact(int id);//prints faculty info given id
  void getAdvisor(int studID);//prints advisor info given student id
  void getAdvisees(int factID);//prints advisees' info given faculty id
  void addStudent(int id, string n, string y, string m, double g, int ad);//adds a student given variables
  void addStudent(Student s);//adds student given student
  void deleteStudent(int id);//deletes student given id
  void addFact(Faculty f);//adds faculty given faculty member
  void deleteFact(int id);//deletes faculty member
  void changeAdvisor(int studID, int factID);//changes advisor given student ids
  void removeAdvisee(int factID, int studID);//removes advisee given student ids
  void initFacTree();//initializes faculty tree given facultyTable file
  void initStudTree();//initializes student tree given studentTable file
  void breakdownStudTree(TreeNode<Student> *node);//dissolves studTree into studTable file
  void breakdownFacTree(TreeNode<Faculty> *node);//disolves facTree into facTable file
  bool containsDuplicates(int t, DoublyLinkedList<int> *L);//returns if there are duplicates
  bool isGood(string fname);//returns if files exist
};
