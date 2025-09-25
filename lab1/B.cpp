#include <iostream>
using namespace std;
#include <vector>
int main() {
    vector<int> queue;
    vector<int> queue_new;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        queue.push_back(a);
    }
    queue_new.push_back(-1);
    for(int i = 1; i < N; i++){
        bool check = false;
        for(int j = i-1; j >= 0; j--){
            if(queue[i] >= queue[j]){
                queue_new.push_back(queue[j]);
                check = true;
                break;
            }
        }
        if(!check){
            queue_new.push_back(-1);
        }
    }
    for(int i : queue_new){
        cout << i << " ";
    }
    return 0;
}