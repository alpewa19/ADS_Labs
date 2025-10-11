#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<long long> b;
    long long cost = 0;
    int i = 0;
    int j = 0;
    for (int st = 1; st < n; ++st)
    {
        long long x;
        if (i >= a.size())
        {
            x = b[j];
            j++;
        }
        else if (j >= b.size())
        {
            x = a[i];
            i++;
        }
        else if (a[i] <= b[j])
        {
            x = a[i];
            i++;
        }
        else
        {
            x = b[j];
            j++;
        }
        long long y;
        if (i >= a.size())
        {
            y = b[j];
            j++;
        }
        else if (j >= b.size())
        {
            y = a[i];
            i++;
        }
        else if (a[i] <= b[j])
        {
            y = a[i];
            i++;
        }
        else
        {
            y = b[j];
            j++;
        }
        long long s = x + y;
        cost += s;
        b.push_back(s);
    }
    cout << cost;
    return 0;
}
