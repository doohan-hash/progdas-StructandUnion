#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


union ScoreUnion {
    int score;
};


struct Student {
    string firstName;
    string lastName;
    ScoreUnion testScore; 
    char grade;
};


char getGrade(int score) {
    if (score >= 90)
        return 'A';
    else if (score >= 80)
        return 'B';
    else if (score >= 70)
        return 'C';
    else if (score >= 60)
        return 'D';
    else
        return 'F';
}

int main() {
    const int NUM_STUDENTS = 20;
    Student students[NUM_STUDENTS];

    cout << "Masukkan data 20 siswa (Nama Depan, Nama Belakang, Nilai):\n";

    
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "\nSiswa ke-" << i + 1 << ":\n";
        cout << "  Nama Depan   : ";
        cin >> students[i].firstName;
        cout << "  Nama Belakang: ";
        cin >> students[i].lastName;
        cout << "  Nilai Ujian  : ";
        cin >> students[i].testScore.score;

        students[i].grade = getGrade(students[i].testScore.score);
    }

    
    int highest = students[0].testScore.score;
    for (int i = 1; i < NUM_STUDENTS; i++) {
        if (students[i].testScore.score > highest)
            highest = students[i].testScore.score;
    }

    
    cout << "\n===== DATA SISWA =====\n";
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << students[i].firstName << "  " << students[i].lastName
             << setw(10) << "  Score: " << students[i].testScore.score
             << setw(10) << "  Grade: " << students[i].grade << endl;
    }

    
    cout << "\n===== NILAI TERTINGGI =====\n";
    cout << "Nilai tertinggi: " << highest << endl;
    cout << "Siswa yang mendapat nilai tertinggi:\n";
    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (students[i].testScore.score == highest) {
            cout << "  " << students[i].firstName << " " << students[i].lastName << endl;
        }
    }

    return 0;
}
