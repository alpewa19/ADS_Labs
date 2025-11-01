#include <iostream>
#include <vector>
using namespace std;
void merge(vector <int> a, vector <int> b, int len1, int len2){
    int i=0;
    int j=0;
    while(i<len1 && j<len2){
        if(a[i]<=b[j]){
            cout<<a[i]<<" ";
            i++;
        }
        else{
            cout<<b[j]<<" ";
            j++;
        }
    }
    while(i<len1){
        cout<<a[i]<<" ";
        i++;
    }
    while(j<len2){
        cout<<b[j]<<" ";
        j++;
    }
}
int main(){
    int n1,n2;
    cin>>n1;
    vector <int> a(n1);
    for(int i=0;i<n1;i++){
        cin>>a[i]; 
    }
    cin>>n2;
    vector <int> b(n2); 
    for(int i=0;i<n2;i++){
        cin>>b[i]; 
    }
    merge(a,b,n1,n2);
    return 0;
}