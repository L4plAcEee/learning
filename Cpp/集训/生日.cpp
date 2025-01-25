#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int year, month, day;

    bool operator<(const Student& other) const {
        if (year != other.year) {
            return year < other.year;
        }
        if (month != other.month) {
            return month < other.month;
        }
        return day < other.day;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Student> students(n);

    for (int i = 0; i < n; ++i) {
        cin >> students[i].name >> students[i].year >> students[i].month >> students[i].day;
    }

    sort(students.begin(), students.end());

    for (const auto& student : students) {
        cout << student.name << endl;
    }

    return 0;
}
