#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

void solve()
{
    int n;
    cin >> n;

    int N = 1;
    while (N <= n)
        N <<= 1;

    vector<int> B(1, 1);
    int cur = 2;
    while (cur < N)
    {
        vector<int> newB = B;
        newB.push_back(cur);
        newB.insert(newB.end(), B.begin(), B.end());
        B = newB;
        cur <<= 1;
    }

    vector<int> a = B;
    a.push_back(0);
    a.insert(a.end(), B.begin(), B.end());

    cout << a.size() << '\n';
    for (int i = 0; i < (int)a.size(); ++i)
        cout << a[i] << ' ';

    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
