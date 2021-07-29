// Problem - WAP to input name, roll number and marks in 5 subjects for a student, and display it
// Author - mrsayan
// Date - 29/07/2021

#include <iostream>
using namespace std;

struct student
{
  char name[100];
  int roll;
  float marks[5];
};

int main() 
{
  student s;
  cout << "Store Student Info -->\t," << endl;
  cout << "\nName: ";
  cin >> s.name;
  cout << "\nRoll Number: \n";
  cin >> s.roll;
  for(int i=0;i<5;i++){
     cout << "Marks: ";
     cin >> s.marks[i];
  }
  cout << "\nStudent Details ->" << endl;
  cout << "Name: " << s.name << endl;
  cout << "Roll: " << s.roll << endl;
  for(int j=0;j<5;j++){
     cout << "Marks: " << s.marks[j] << endl;
  }
  return 0;
}