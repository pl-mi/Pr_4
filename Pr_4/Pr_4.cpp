#include "student.h"
#include <windows.h>

int main() {
    //  Підтримка української мови
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    StudentExtended group;

    // Додавання студентів
    group.addStudent(Student(1, "Іваненко", "МБФ", "MB-21", 2, "стаціонар"));
    group.addStudent(Student(2, "Петренко", "ТФ", "TF-11", 1, "заочна"));
    group.addStudent(Student(3, "Сидоренко", "МБФ", "MB-21", 2, "заочна"));

    cout << "Усі студенти:\n";
    group.printAll();

    cout << "\nСортування за прізвищем:\n";
    group.sortStudents();
    group.printAll();

    cout << "\nСтуденти факультету МБФ:\n";
    group.filterByFaculty("МБФ");

    return 0;
}
