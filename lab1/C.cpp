#include <iostream>
using namespace std;
#include <vector>
int main() {
    string first;
    string second;
    cin >> first >> second;
    string first_new;
    string second_new;
    for(int i = 0; i < first.size(); i++){
        if(first[i] != '#'){
            first_new += first[i];
        }else{
            first_new = first_new.substr(0, first_new.size()-1);
        }
    }
    for(int i = 0; i < second.size(); i++){
        if(second[i] != '#'){
            second_new += second[i];
        }else{
            second_new = second_new.substr(0, second_new.size()-1);
        }
    }
    if(second_new == first_new){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}