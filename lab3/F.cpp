#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N,P;
    cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    cin>>P;
    vector<int> B(P);
    for(int i=0;i<P;i++) cin>>B[i];
    for (int i=0;i<P;i++){
        int count=0;
        int powCount=0;
        for (int j=0;j<N;j++){
            if (A[j]<=B[i]){
                count++;
                powCount+=A[j];
            }
        }
        cout<<count<<" "<<powCount<<"\n";
    }
return 0;
}