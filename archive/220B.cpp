#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

const int BLOCK_SIZE = 320;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
        if (i > n)
            i = 0;
    }

    vector<int> result(q);
    vector<pair<int, pair<int, int>>> rl(q);
    for (int i = 0; i < q; i++)
    {
        cin >> rl[i].second.first >> rl[i].first;
        rl[i].first--, rl[i].second.first--;
        rl[i].second.second = i;
    }

    sort(all(rl), [](const auto &a, const auto &b)
         {
        int block_a = a.second.first / BLOCK_SIZE;
        int block_b = b.second.first / BLOCK_SIZE;
        if (block_a != block_b)
            return block_a < block_b;
        return a.first < b.first; });

    int res = 0;
    vector<int> cnt(n + 5, 0);
    int l = 0, r = -1;

    for (auto &i : rl)
    {
        while (r < i.first)
        {
            r++;
            if (a[r] != 0)
            {
                if (cnt[a[r]] == a[r])
                    res--;
                cnt[a[r]]++;
                if (cnt[a[r]] == a[r])
                    res++;
            }
        }
        while (r > i.first)
        {
            if (a[r] != 0)
            {
                if (cnt[a[r]] == a[r])
                    res--;
                cnt[a[r]]--;
                if (cnt[a[r]] == a[r])
                    res++;
            }
            r--;
        }
        while (l < i.second.first)
        {
            if (a[l] != 0)
            {
                if (cnt[a[l]] == a[l])
                    res--;
                cnt[a[l]]--;
                if (cnt[a[l]] == a[l])
                    res++;
            }
            l++;
        }
        while (l > i.second.first)
        {
            l--;
            if (a[l] != 0)
            {
                if (cnt[a[l]] == a[l])
                    res--;
                cnt[a[l]]++;
                if (cnt[a[l]] == a[l])
                    res++;
            }
        }

        result[i.second.second] = res;
    }

    for (auto &i : result)
        cout << i << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
