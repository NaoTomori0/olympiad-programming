#include <bits/stdc++.h>
using namespace std;

#define int long long

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        queue<pair<vector<int>, int>> q;

        q.push({{}, 0});
        while (!q.empty())
        {
            pair<vector<int>, int> cur = q.front();
            q.pop();

            if (cur.first.size() == n)
            {
                res.push_back(cur.first);
                continue;
            }
            for (int i = 0; i < n; i++)
            {
                if (!((cur.second >> i) & 1))
                {
                    vector<int> next_perm = cur.first;
                    next_perm.push_back(nums[i]);

                    int next_m = cur.second | (1 << i);
                    q.push({next_perm, next_m});
                }
            }
        }
        return res;
    }
};

void solve()
{
    Solution s;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : s.permute(a))
    {
        for (auto &j : i)
            cout << j << ' ';
        cout << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
