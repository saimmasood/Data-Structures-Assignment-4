#include <iostream>
#include <unordered_map>
#include<string>
using namespace std;

// Structure for Student Data
struct Student
{
    string name;
    int semester;
    float cgpa;
};

int main()
{
    unordered_map<int, Student> students;

    int choice;

    do
    {
        cout << "\n===== Student Record Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Update CGPA\n";
        cout << "4. Delete Student\n";
        cout << "5. Display All Records\n";
        cout << "6. Display Size and Load Factor\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id;
            Student s;

            cout << "Enter Student ID: ";
            cin >> id;

            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, s.name);

            cout << "Enter Semester: ";
            cin >> s.semester;

            cout << "Enter CGPA: ";
            cin >> s.cgpa;

            students[id] = s;

            cout << "Student added successfully.\n";
            break;
        }

        case 2:
        {
            int id;

            cout << "Enter Student ID to search: ";
            cin >> id;

            auto it = students.find(id);

            if (it != students.end())
            {
                cout << "\nStudent Found:\n";
                cout << "ID: " << it->first << endl;
                cout << "Name: " << it->second.name << endl;
                cout << "Semester: " << it->second.semester << endl;
                cout << "CGPA: " << it->second.cgpa << endl;
            }
            else
            {
                cout << "Student not found.\n";
            }

            break;
        }

        case 3:
        {
            int id;
            float newCGPA;

            cout << "Enter Student ID: ";
            cin >> id;

            auto it = students.find(id);

            if (it != students.end())
            {
                cout << "Enter new CGPA: ";
                cin >> newCGPA;

                it->second.cgpa = newCGPA;

                cout << "CGPA updated successfully.\n";
            }
            else
            {
                cout << "Student not found.\n";
            }

            break;
        }

        case 4:
        {
            int id;

            cout << "Enter Student ID to delete: ";
            cin >> id;

            if (students.erase(id))
            {
                cout << "Student record deleted.\n";
            }
            else
            {
                cout << "Student not found.\n";
            }

            break;
        }

        case 5:
        {
            cout << "\n===== All Student Records =====\n";

            for (auto student : students)
            {
                cout << "ID: " << student.first << endl;
                cout << "Name: " << student.second.name << endl;
                cout << "Semester: " << student.second.semester << endl;
                cout << "CGPA: " << student.second.cgpa << endl;
                cout << "--------------------------\n";
            }

            break;
        }

        case 6:
        {
            cout << "Current Size: " << students.size() << endl;
            cout << "Load Factor: " << students.load_factor() << endl;

            break;
        }

        case 7:
        {
            cout << "Exiting Program...\n";
            break;
        }

        default:
        {
            cout << "Invalid choice.\n";
        }
        }

    } while (choice != 7);

    return 0;
}