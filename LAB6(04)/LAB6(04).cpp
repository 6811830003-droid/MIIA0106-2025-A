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
	int size;
	cout << "Enter number of students: ";
	cin >> size;
	cin.ignore(); // เคลียร์ newline ก่อน getline

	string* name = new string[size];
	string* id = new string[size];
	double* score = new double[size];
	char* grade = new char[size];

	// 1. วนรับข้อมูล size คน
	for (int i = 0; i < size; i++) {
		cout << "\n--- Student " << i + 1 << " ---\n";
		cout << "Enter Name: ";
		getline(cin, name[i]);
		cout << "Enter ID: ";
		getline(cin, id[i]);
		cout << "Enter Score: ";
		cin >> score[i];
		cin.ignore(); 

		// 2. เรียกใช้ calculateGrade เพื่อหาเกรด
		calculateGrade(score[i], grade[i]);
	}

	// 3. วนแสดงผล size คน ด้วย displayStudentInfo
	cout << "\n========== Student total ==========\n";
	for (int i = 0; i < size; i++) {
		displayStudentInfo(name[i], id[i], score[i], grade[i]);
		cout << "--------------------------------------\n";
	}

	// 4. delete[] ให้ครบทุกตัวแปร (สำคัญมากเพื่อป้องกัน Memory Leak)
	delete[] name;
	delete[] id;
	delete[] score;
	delete[] grade;

	return 0;
}