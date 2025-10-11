#include <iostream>
#include <vector>
using namespace std;

vector<long long> heap;

void siftUp(int i)
{
    while (i > 0)
    {
        int p = (i - 1) / 2;
        if (heap[p] >= heap[i])
            break;
        long long t = heap[p];
        heap[p] = heap[i];
        heap[i] = t;
        i = p;
    }
}

void siftDown(int i)
{
    int n = (int)heap.size();
    while (true)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int best = i;
        if (l < n && heap[l] > heap[best])
            best = l;
        if (r < n && heap[r] > heap[best])
            best = r;
        if (best == i)
            break;
        long long t = heap[i];
        heap[i] = heap[best];
        heap[best] = t;
        i = best;
    }
}

void push(long long x)
{
    heap.push_back(x);
    siftUp((int)heap.size() - 1);
}

long long popMax()
{
    long long ans = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    if (!heap.empty())
        siftDown(0);
    return ans;
}

int main()
{
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; ++i)
    {
        long long a;
        cin >> a;
        push(a);
    }

    long long revenue = 0;
    while (x > 0 && !heap.empty())
    {
        long long y = popMax();
        revenue += y;
        --x;
        if (y - 1 > 0)
            push(y - 1);
    }

    cout << revenue << '\n';
    return 0;
}
