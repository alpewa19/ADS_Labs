#include <iostream>
using namespace std;
#include <vector>
#include <queue>
int main() {
    int N;
    cin >> N;
    vector<vector<int>> deck;
    for(int i = 0; i < N; i++){
        int numberOfCards;
        cin >> numberOfCards;
        queue<int> cards;
        for(int j = 1; j < numberOfCards+1; j++){
            cards.push(j);
        }
        vector<int> container(numberOfCards);
        for(int j = 0; j < numberOfCards; j++){
            int i = j + 1;
            while(i > 0){
                cards.push(cards.front());
                cards.pop();
                i -= 1;
            }
            container[cards.front()-1] = j+1;
            cards.pop();
        }
        deck.push_back(container);
    }
    for (int i = 0; i < N; i++) {
        for (int j : deck[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}