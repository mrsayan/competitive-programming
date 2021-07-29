/* Problem - 
WAP to enter id, name, age and basic salary of n number of employees. Calculate the
gross salary of all the employees and display it along with all other details in a tabular
form, using pointer to structure.
[ Gross salary= Basic salary + DA + HRA,
DA = 80% of Basic salary
HRA=10% of Basic salary ]
*/
// Author  - mrsayan
// Date - 29/07/2021

#include <iostream>
using namespace std;

struct Employee
{ char name[50];
  int id;
  int age;
  float basic;
  float gross;
} s[10];

void display(Employee* emp, int size) {
  cout << "\n\nEmployee Details:- " << "\n\n";
  cout << "Emp_ID" <<"\t"<<"Name" <<"\t"<<"Age" <<"\t"<<"Salary" << "\n";
  cout << "------" <<"\t"<<"----" <<"\t"<<"---" <<"\t"<<"------";

  for(int i=0;i<size;i++)
  {
    cout << "\n" << emp->id <<"\t\t"<< emp->name <<"\t"<< emp->age <<"\t" << emp->gross;
    emp++;
  }
}

int main()
{
  int size,i;
  cout << "Employee Size : -> "; cin >> size;

  Employee* emp= s;
  cout << "\n\nStudents's Details:\n";
  for (i = 0; i < size; i++) {
    cout << "Enter ID -> " << endl;
    cin >> emp->id;
    cout << "Enter Name -> " << endl;
    cin >> emp->name;
    cout << "Enter Age -> " << endl;
    cin >> emp->age;
    cout << "Enter Basic Salary -> " << endl;
    cin >> emp->basic;

    //Gross salary= Basic salary + DA + HRA, DA = 80% of Basic salary, HRA=10% of Basic salary
    emp->gross = 1.9*(emp->basic); 
    emp++;
  }
  emp=s;
  display(emp,size);
}
