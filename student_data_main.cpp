#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

class Student {
public:
    Student(const std::string& name, int age, double grade) 
        : name_(name), age_(age), grade_(grade) {}

    std::string getName() const { return name_; }
    int getAge() const { return age_; }
    double getGrade() const { return grade_; }

    void setName(const std::string& name) { name_ = name; }
    void setAge(int age) { age_ = age; }
    void setGrade(double grade) { grade_ = grade; }

private:
    std::string name_;
    int age_;
    double grade_;
};

void loadDataFromFile(const std::string& filename, std::vector<Student>& students) {
    std::ifstream file(filename);
    std::string name;
    int age;
    double grade;

    while (file >> name >> age >> grade) {
        students.push_back(Student(name, age, grade));
    }

    file.close();
}

bool compareStudents(const Student& a, const Student& b) {
    return a.getGrade() > b.getGrade();
}

void sortStudentsByGrade(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), compareStudents);
}

void printStudents(const std::vector<Student>& students) {
    std::cout << "Name\tAge\tGrade" << std::endl;
    for (const auto& student : students) {
        std::cout << student.getName() << "\t" << student.getAge() << "\t" << student.getGrade() << std::endl;
    }
}

int main() {
    std::vector<Student> students;
    std::string filename = "students.txt";

    loadDataFromFile(filename, students);

    if (students.empty()) {
        std::cerr << "Error: No student data found." << std::endl;
        return 1;
    }

    sortStudentsByGrade(students);

    printStudents(students);

    return 0;
}