#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mvX[] = {
    -2,
    -2,
    -1,
    -1,
    1,
    1,
    2,
    2,
};
const int mvY[] = {
    1,
    -1,
    -2,
    2,
    -2,
    2,
    -1,
    1,
};

bool moveF(vector<vector<int>> &m, int i, int x, int y, int n)
{
    m[y][x] = i;

    if (i == n * n)
        return 1;

    for (int j = 0; j < 8; j++)
    {
        int newPosX = x + mvX[j];
        int newPosY = y + mvY[j];
        if (newPosX >= 0 && newPosY >= 0 && newPosY < n && newPosX < n && m[newPosY][newPosX] == 0)
        {
            if (!moveF(m, i + 1, newPosX, newPosY, n))
                m[newPosY][newPosX] = 0;
            else
                return 1;
        }
    }
    return 0;
}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<vector<int>> m(n, vector<int>(n, 0));

    moveF(m, 1, x, y, n);
    for (auto &i : m)
    {
        for (auto &j : i)
            cout << j << '\t';
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
