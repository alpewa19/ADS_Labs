#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    stack<string> students;
    string name;
    cin >> name;
    students.push(name);
    for(int i = 1; i < N; i++){
        cin >> name;
        if(students.top() != name) students.push(name);
    }
    cout << "All in all: " << students.size() << endl;
    cout << "Students: " << endl;
    int studentsSize = students.size();
    for(int i = 0; i < studentsSize; i++){
        cout << students.top() << endl;
        students.pop();
    }
    return 0;
}