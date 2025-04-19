#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Структура Студент
struct Student {
    int number;
    string surname;
    string faculty;
    string group;
    int course;
    string form;

    Student() : number(0), surname(""), faculty(""), group(""), course(0), form("") {}

    Student(int n, string s, string f, string g, int c, string formType)
        : number(n), surname(s), faculty(f), group(g), course(c), form(formType) {
    }

    Student(const Student& other) {
        number = other.number;
        surname = other.surname;
        faculty = other.faculty;
        group = other.group;
        course = other.course;
        form = other.form;
    }

    explicit operator string() const {
        return to_string(number) + " " + surname + " " + faculty + " " + group + " " +
            to_string(course) + " " + form;
    }
};

//  Базовий клас
class StudentBase {
protected:
    vector<Student> students;

public:
    void addStudent(const Student& s) {
        students.push_back(s);
    }

    virtual void printAll() const {
        for (const auto& s : students) {
            cout << (string)s << endl;
        }
    }
};

//  Похідний клас
class StudentExtended : public StudentBase {
public:
    void sortStudents() {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.surname < b.surname;
            });
    }

    void filterByFaculty(const string& facultyName) const {
        for (const auto& s : students) {
            if (s.faculty == facultyName) {
                cout << (string)s << endl;
            }
        }
    }

    void filterByCourse(int courseNum) const {
        for (const auto& s : students) {
            if (s.course == courseNum) {
                cout << (string)s << endl;
            }
        }
    }
};

