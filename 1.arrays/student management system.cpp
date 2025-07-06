#include <iostream>

using namespace std;

const int MAX_COURSES = 5; // Maximum courses a student can take
const int MAX_STUDENTS = 5; // Maximum students in the system

// Course class to store course details
class Course {
private:
    string courseName;

public:
    Course() {} // Default constructor

    Course(string name) {
        courseName = name;
    }

    string getCourseName() const {
        return courseName;
    }
};

// Student class to store student details
class Student {
private:
    string name;
    string regNumber;
    Course courses[MAX_COURSES]; // Fixed-size array for courses
    int courseCount; // Number of enrolled courses

public:
    Student() {
        courseCount = 0; // Initialize course count
    }

    Student(string studentName, string regNo) {
        name = studentName;
        regNumber = regNo;
        courseCount = 0; // Initialize course count
    }

    // Add a course to the student's list
    void addCourse(Course course) {
        if (courseCount < MAX_COURSES) {
            courses[courseCount] = course;
            courseCount++;
        } else {
            cout << "Cannot add more courses for " << name << ". Limit reached!" << endl;
        }
    }

    // Display student details along with enrolled courses
    void displayDetails() const {
        cout << "Student Name: " << name << endl;
        cout << "Registration Number: " << regNumber << endl;
        cout << "Enrolled Courses: " << endl;
        if (courseCount == 0) {
            cout << "No courses enrolled." << endl;
        } else {
            for (int i = 0; i < courseCount; i++) {
                cout << "- " << courses[i].getCourseName() << endl;
            }
        }
        cout << "---------------------------" << endl;
    }
};

int main() {
    Student students[MAX_STUDENTS]; // Fixed-size array for students
    int studentCount = 0; // Number of students added

    // Creating students
    students[studentCount++] = Student("Alice Johnson", "S12345");
    students[studentCount++] = Student("Bob Smith", "S67890");

    // Creating courses
    Course course1("Mathematics");
    Course course2("Physics");
    Course course3("Computer Science");

    // Assigning courses to students
    students[0].addCourse(course1);
    students[0].addCourse(course3);

    students[1].addCourse(course2);
    students[1].addCourse(course3);

    // Displaying student details
    cout << "Student Management System\n";
    cout << "===========================\n";
    for (int i = 0; i < studentCount; i++) {
        students[i].displayDetails();
    }

    return 0;
}

