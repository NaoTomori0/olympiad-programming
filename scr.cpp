#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector<vector<pair<int, vector<pair<int, int>>>>> m(n, vector<pair<int, vector<pair<int, int>>>>(n, {1e9, vector<pair<int, int>>(0)}));
    m[y1][x1].first = 0;
    int mvX[] = {
        -2,
        -2,
        -1,
        -1,
        1,
        1,
        2,
        2,
    };
    int mvY[] = {
        1,
        -1,
        -2,
        2,
        -2,
        2,
        -1,
        1,
    };

    queue<pair<int, int>> q;
    q.push({x1, y1});
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur.first == x2 && cur.second == y2)
            break;

        for (int i = 0; i < 8; i++)
        {
            int newPosX = cur.first + mvX[i], newPosY = cur.second + mvY[i];
            if (newPosX >= 0 && newPosY >= 0 && newPosY < n && newPosX < n)
            {
                if (m[cur.second][cur.first].first + 1 < m[newPosY][newPosX].first)
                {
                    m[newPosY][newPosX].first = m[cur.second][cur.first].first + 1;
                    m[newPosY][newPosX].second = m[cur.second][cur.first].second;
                    m[newPosY][newPosX].second.push_back(cur);
                }
                q.push({newPosX, newPosY});
            }
        }
    }

    for (auto &i : m)
    {
        for (auto &j : i)
            cout << j.first << ' ';
        cout << '\n';
    }

    for (auto &i : m[y2][x2].second)
    {
        cout << i.first << ' ' << i.second << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
