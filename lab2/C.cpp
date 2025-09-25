#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector <int> array;
    int count=0;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        if (i%2==0){
            array.push_back(a);
             count++;
        }
        else{
            continue;
        }
       
    }
    for (int i=0;i<count;i++){
        cout<<array[i]<<" ";
    }
}