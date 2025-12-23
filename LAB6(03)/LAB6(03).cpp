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
	const int N = 3; // นักเรียน 3 คน
	const int M = 4; // วิชา 4 วิชา

	string name[N], id[N];
	double score[N][M];
	double total[N];
	char grade[N];

		// TODO: วนรับ name/idf
	for (int i = 0; i < N; i++) {

		cout << "Enter Student Name: ";
		getline(cin >> ws, name[i]);
		cout << "Enter Student ID  : ";
		cin >> id[i];

		total[i] = 0.0;
		// TODO: nested loop รับคะแนน M วิชา
		for (int j = 0; j < M; j++) {
			cout << "  Enter Score for Subject  " << (j + 1) << " : ";
			cin >> score[i][j];
			total[i] += score[i][j];
		}

		// TODO: calculateGrade โดยใช้ค่าเฉลี่ย (คะแนนรวม / จำนวนวิชา)
		calculateGrade( total[i], grade[i]);
	}

	cout << "\n========== STUDENT RESULTS ==========\n";
			
		// TODO: แสดงผลโดยใช้ displayStudentInfo
		for(int i=0;i<N;i++){
		displayStudentInfo(name[i], id[i],total[i], grade[i]);
	}

	return 0;
}