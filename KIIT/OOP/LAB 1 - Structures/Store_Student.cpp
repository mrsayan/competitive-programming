/* Problem - 
WAP to input name, roll number and marks in 5 subjects for n number of students. Write functions to:-
a. Find total marks and percentage of all n students.
b. Display details of a student with a given roll number.
c. Display the details for all the students having percentage in a given range.
d. Sort the array in ascending order of marks.
*/
// Author  - mrsayan
// Date - 29/07/2021

#include <bits/stdc++.h>
using namespace std;

struct Student {
	char name[50];
	int roll;
	float marks;
	float percent;
};

bool compare( Student a, Student b){
	if(a.percent < b.percent)
		return 1;
	else 
		return 0;
}

void display(Student s[], int size, int a, int b) {

    //Sort the array in ascending order of marks
	sort(s, s+size, compare);

	//Display Student Details
	cout << "\n\nDisplay Student's Information:\n";
	cout << "Roll" << "\t" << "Name" << "\t" <<  "Precentage" << "\n";
	cout << "----" << "\t" << "----" << "\t" <<  "----------" <<"\n";

	for (int i = 0; i < size; i++) {
		//students having percentage in a given range
		if(s[i].percent >=a && s[i].percent <=b)
			cout << s[i].roll << "\t\t" << s[i].name << "\t" << s[i].percent << "\n";
	}
}

int main() {
	int stu, total, i, sub, sum=0;

	cout << "No. of students -> "; cin >> stu;
	cout << "Total Marks -> "; cin >> total;
	struct Student s[stu + 1];
	cout << "\n\nEnter Range:\n";
	int a,b; cin >> a >> b;

  //Store Student Details
	cout << "\n\nStudents's Details:\n";
	for (i = 0; i < stu; i++) 
	{
		cout << "\nEnter Roll Number:";
		cin >> s[i].roll;

		cout << "\nEnter Name -> ";
		cin >> s[i].name;

		cout << "\nEnter Marks in 5 Subjects-> ";
		for (int j = 0; j < 5; j++) 
		{
			cin >> sub;
			sum= sum + sub;
		}
		s[i].marks= sum;
		sum = 0 ;
		s[i].percent = (s[i].marks*100)/(5*total);
	}
	
	display(s,stu,a,b);
}
