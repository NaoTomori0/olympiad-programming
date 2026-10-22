#include <bits/stdc++.h>
using namespace std;

#define int long long

void Verity()
{
    int n, m;
    cin >> n >> m;

    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }

    int k = (n + 1) / 2;
    int len = n / 2;

    cout << k << '\n';

    for (int i = 1; i <= k; i++)
    {
        cout << i + 1 << ' ' << i + len << '\n';
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        Verity();
    }

    return 0;
}