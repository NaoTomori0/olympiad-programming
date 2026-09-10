#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mvX[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int mvY[] = {1, -1, -2, 2, -2, 2, -1, 1};

struct Node
{
    int step, x, y, dir;
};

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<Node> st(n * n + 1);
    int cur_st_inx = 1;
    st[0] = {1, x, y, 0};
    m[y][x] = 1;

    while (cur_st_inx > 0)
    {
        Node &cur = st[cur_st_inx - 1];
        if (cur.step == n * n)
            break;

        bool moved = 0;
        for (int k = cur.dir; k < 8; k++)
        {
            int newPosX = cur.x + mvX[k];
            int newPosY = cur.y + mvY[k];
            cur.dir = k + 1;
            if (newPosX >= 0 && newPosY >= 0 && newPosY < n && newPosX < n && m[newPosY][newPosX] == 0)
            {
                m[newPosY][newPosX] = cur.step + 1;
                st[cur_st_inx++] = {cur.step + 1, newPosX, newPosY, 0};
                moved = 1;
                break;
            }
        }
        if (!moved)
        {
            m[cur.y][cur.x] = 0;
            cur_st_inx--;
        }
    }

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
