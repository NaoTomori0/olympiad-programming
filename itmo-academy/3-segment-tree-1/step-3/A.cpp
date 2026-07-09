// A. Инверсии
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест1024 мегабайта

// Дана перестановка p_i из n элементов, найдите для каждого i число таких j, что j < i и p_j > p_i.

// Входные данные
// Первая строка содержит число n (1 ≤ n ≤ 10^5), вторая строка содержит n чисел p_i. Гарантируется, что p_i образуют перестановку чисел от 1 до n.

// Выходные данные
// Выведите n чисел, i-е число равно числу таких j, что j < i и p_j > p_i.

// ======================================================================
// Пример
// ======================================================================
// Входные данные
// ======================================================================
// 5
// 4 1 3 5 2
// ======================================================================
// Выходные данные
// ======================================================================
// 0 1 1 0 3
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct segtree
{
    vector<int> tree;
    int size = 1;

    void init(int x)
    {
        while (size < x)
            size *= 2;
        tree.assign(2 * size - 1, 0);
    }

    void plus(int i, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x]++;
            return;
        }
        int m = (rx + lx) / 2;
        if (i < m)
            plus(i, 2 * x + 1, lx, m);
        else
            plus(i, 2 * x + 2, m, rx);

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void plus(int i) { plus(i, 0, 0, size); }

    int sum(int l, int x, int lx, int rx)
    {
        if (l >= rx)
            return 0;
        if (lx >= l)
        {
            return tree[x];
        }

        int m = (lx + rx) / 2;
        int s1 = sum(l, 2 * x + 1, lx, m);
        int s2 = sum(l, 2 * x + 2, m, rx);
        return s1 + s2;
    }

    int sum(int l) { return sum(l, 0, 0, size); }
};

void solve()
{
    int n;
    cin >> n;
    segtree st;
    st.init(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cout << st.sum(x) << " ";
        st.plus(x);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
