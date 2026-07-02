#include <bits/stdc++.h> // Подключает сразу все библиотеки C++
using namespace std;

#define int long long // Защита от переполнения int (из-за этого часто горят баллы)

bool check(int mid, int k, vector<int> &a, int n)
{
    int count = 1, last_pos_inx = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[last_pos_inx] >= mid)
        {
            last_pos_inx = i;
            count++;
        }
    }

    return count >= k;
}

void solve()
{
    int n, k, l = 0, r = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > r)
            r = a[i] + 1;
    }

    sort(a.begin(), a.end());

    while (r > l + 1)
    {
        int mid = (l + r) / 2;
        if (check(mid, k, a, n))
            l = mid;
        else
            r = mid;
    }
    cout << l << "\n";
}

int32_t main()
{
    // Включаем супер-быстрый ввод-вывод для C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
