#include <iostream>
#include <vector>

using namespace std;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve()
{
    int n;
    long long l, r, ql, qr;
    if (!(cin >> n >> l >> r >> ql >> qr))
        return;

    vector<long long> w(n);
    vector<long long> pref(n + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> w[i];
        pref[i + 1] = pref[i] + w[i];
    }

    long long total_sum = pref[n];
    long long ans = -1;

    for (int k = 0; k <= n; ++k)
    {
        long long left_cnt = k;
        long long right_cnt = n - k;

        long long left_w = pref[k];
        long long right_w = total_sum - left_w;

        long long cost = left_w * l + right_w * r;

        if (left_cnt > right_cnt)
        {
            cost += (left_cnt - right_cnt - 1) * ql;
        }
        else if (right_cnt > left_cnt)
        {
            cost += (right_cnt - left_cnt - 1) * qr;
        }

        if (ans == -1 || cost < ans)
        {
            ans = cost;
        }
    }

    cout << ans << "\n";
}

int main()
{
    fast_io();
    solve();
    return 0;
}
