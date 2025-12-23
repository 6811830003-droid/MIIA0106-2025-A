#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void displayStudentInfo(string name, string id, double score, char grade)
{
	cout << "Student Name: " << name << "\n";
	cout << "Student ID : " << id << "\n";
	cout << "Score : " << fixed << setprecision(2) << score << "\n";
	cout << "Grade : " << grade << "\n";
}

void calculateGrade(double score, char& grade)
{
	if (score >= 90) grade = 'A';
	else if (score >= 80) grade = 'B';
	else if (score >= 70) grade = 'C';
	else if (score >= 60) grade = 'D';
	else grade = 'F';
}
int main()
{
	string name, id;
	double score;
	char grade;
	// TODO: รับชื่อ (getline)
	cout << "Enter student name: ";
	getline(cin, name);
	// TODO: รับรหัสและคะแนน (cin)
	cout << "Enter student id: ";
	cin >> id;
	// TODO: calculateGrade(score, grade);
	cout << "Enter student score: ";
	cin >> score;
	calculateGrade(score, grade);
	// TODO: displayStudentInfo(name, id, score, grade);
	displayStudentInfo(name, id, score, grade);

	return 0;
}