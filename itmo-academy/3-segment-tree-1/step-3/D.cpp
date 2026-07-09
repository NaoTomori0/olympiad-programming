// D. Пересекающиеся отрезки
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест1024 мегабайта

// Дан массив из 2n чисел, каждое число от 1 до n в нём встречается ровно два раза.
// Будем говорить, что отрезок y пересекается с отрезком x, если ровно одно вхождение
// числа y находится между вхождениями числа x. Найдите для каждого отрезка i,
// сколько есть отрезков, которые с ним пересекаются.

// Входные данные
// Первая строка содержит число n (1 ≤ n ≤ 10^5), вторая строка содержит 2n чисел.
// Гарантируется, что каждое число от 1 до n встречается ровно два раза.

// Выходные данные
// Выведите n чисел, i-е число равно числу отрезков, которые пересекаются с отрезком i.

// ======================================================================
// Пример
// ======================================================================
// Входные данные
// ======================================================================
// 5
// 5 1 2 2 3 1 3 4 5 4
// ======================================================================
// Выходные данные
// ======================================================================
// 1 0 1 1 1
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct segtree
{
    vector<int> tree, memory, res;
    int size = 1;

    void init(int x, int n)
    {
        size = 1;
        while (size < x)
            size *= 2;
        tree.assign(2 * size, 0);
        memory.assign(n + 1, -1);
        res.assign(n + 1, 0);
    }

    void clear(int x, int n)
    {
        fill(tree.begin(), tree.end(), 0);
        fill(memory.begin(), memory.end(), -1);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    int sum(int l, int r, int x, int lx, int rx)
    {
        if (lx >= l && rx <= r)
            return tree[x];
        if (l >= rx || r <= lx)
            return 0;
        int m = (lx + rx) / 2;
        int s1 = sum(l, r, 2 * x + 1, lx, m), s2 = sum(l, r, 2 * x + 2, m, rx);
        return s1 + s2;
    }

    int sum(int l, int r)
    {
        return sum(l, r, 0, 0, size);
    }

    void set(int i, int v)
    {
        if (memory[v] == -1)
        {
            memory[v] = i;
            set(i, 1, 0, 0, size);
        }
        else
        {
            set(memory[v], 0, 0, 0, size);

            res[v] += sum(memory[v], i, 0, 0, size);
        }
    }

    void build(int x, int n)
    {
        init(x, n);
    }

    void solve(vector<int> &a, int n)
    {
        for (int i = 0; i < a.size(); i++)
            set(i, a[i]);

        clear(2 * n, n);
        reverse(a.begin(), a.end());

        for (int i = 0; i < a.size(); i++)
            set(i, a[i]);

        for (int i = 1; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
    }
};

void solve()
{
    int n;
    cin >> n;
    segtree st;
    st.build(2 * n, n);
    vector<int> a(2 * n);

    for (int i = 0; i < n * 2; i++)
        cin >> a[i];

    st.solve(a, n);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
