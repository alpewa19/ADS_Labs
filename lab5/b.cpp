#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    multiset<long long> s;
    for (int i = 0; i < n; ++i)
    {
        long long x;
        cin >> x;
        s.insert(x);
    }
    while (s.size() >= 2)
    {
        multiset<long long>::iterator it = s.end();
        --it;
        long long y = *it;
        s.erase(it);

        it = s.end();
        --it;
        long long x = *it;
        s.erase(it);

        if (y != x)
            s.insert(y - x);
    }

    cout << (s.empty() ? 0 : *s.begin()) << '\n';
    return 0;
}
