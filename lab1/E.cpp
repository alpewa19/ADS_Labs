#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int main() {
    deque<int> boris;
    deque<int> nursik;
    for(int i = 0; i < 5; i++){
        int card;
        cin >> card;
        boris.push_back(card);
    }
    for(int i = 0; i < 5; i++){
        int card;
        cin >> card;
        nursik.push_back(card);
    }
    int countMoves = 0;
    int maxMoves = 1000000;
    while(!boris.empty() && !nursik.empty()){
        if(countMoves > maxMoves){
            cout << "blin nichya";
            return 0;
        }
        if((boris.front() == 0 && nursik.front() == 9) || (boris.front() > nursik.front() && !(boris.front() == 9 && nursik.front() == 0) )){
            boris.push_back(boris.front());
            boris.push_back(nursik.front());
            boris.pop_front();
            nursik.pop_front();
            countMoves += 1;
        }
        else {
            nursik.push_back(boris.front());
            nursik.push_back(nursik.front());
            boris.pop_front();
            nursik.pop_front();
            countMoves += 1;
        }
    }
    if(boris.empty()){
        cout << "Nursik " << countMoves;
    }else{
        cout << "Boris " << countMoves;
    }
    return 0;
}