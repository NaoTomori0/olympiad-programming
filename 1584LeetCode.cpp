#include <bits/stdc++.h>
using namespace std;

#define int long long

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {

        struct DSU
        {
            vector<int> p, r;
            DSU(int n)
            {
                p.resize(n);
                r.assign(n, 1);
                for (int i = 0; i < n; i++)
                    p[i] = i;
            };

            int get(int x) { return p[x] = (x == p[x] ? x : get(p[x])); }

            bool united(int a, int b)
            {
                a = get(a), b = get(b);
                if (a != b)
                {
                    if (r[a] > r[b])
                        swap(a, b);
                    p[a] = b;
                    if (r[a] == r[b])
                        r[b]++;
                    return 1;
                }
                return 0;
            }
        };
        int n = points.size();
        vector<pair<int, pair<int, int>>> e;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                e.push_back({(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])), {i, j}});

        sort(e.begin(), e.end());

        DSU d(n);
        int res = 0;
        for (auto &i : e)
        {
            // cout << i.first << ' ' << i.second.first << ' ' << i.second.second << '\n';
            res += d.united(i.second.first, i.second.second) * i.first;
            // for (auto &j : d.p)
            //     cout << j << ' ';
            // cout << '\n';
        }
        return res;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<vector<int>> a{{3, 12}, {-2, 5}, {-4, 1}};
    cout << sol.minCostConnectPoints(a);
    return 0;
}
