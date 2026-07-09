// C. Вложенные отрезки
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест1024 мегабайта

// Дан массив из 2n чисел, каждое число от 1 до n в нём встречается ровно два раза.
// Будем говорить, что отрезок y вложен в отрезок x, если оба вхождения числа y
// находятся между вхождениями числа x. Найдите для каждого отрезка i, сколько есть
// отрезков, которые в него вложены.

// Входные данные
// Первая строка содержит число n (1 ≤ n ≤ 10^5), вторая строка содержит 2n чисел.
// Гарантируется, что каждое число от 1 до n встречается ровно два раза.

// Выходные данные
// Выведите n чисел, i-е число равно числу отрезков, вложенных в отрезок i.

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
// 1 0 0 0 3
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct segtree
{

    vector<int> tree, res, memory;
    int size = 1;

    void init(int x, int n)
    {
        while (size < x)
            size *= 2;
        tree.assign(2 * size - 1, 0);
        res.assign(n + 1, 0);
        memory.assign(n + 1, -1);
    }

    void set(int i, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = 1;
            return;
        }
        int m = (rx + lx) / 2;
        if (i < m)
            set(i, 2 * x + 1, lx, m);
        else
            set(i, 2 * x + 2, m, rx);

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    int sum(int l, int r, int x, int lx, int rx)
    {
        if (l <= lx && r >= rx)
            return tree[x];
        if (l >= rx || r <= lx)
            return 0;
        int m = (rx + lx) / 2;
        int s1 = sum(l, r, 2 * x + 1, lx, m), s2 = sum(l, r, 2 * x + 2, m, rx);
        return s1 + s2;
    }

    int sum(int l, int r) { return sum(l, r, 0, 0, size); }

    void set(int i, int v)
    {

        if (memory[v] == -1)
        {
            memory[v] = i;
        }
        else
        {
            res[v] = sum(memory[v], i);
            set(memory[v], 0, 0, size);
        }
    }

    void solve()
    {
        for (int i = 1; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
    }
};

void solve()
{
    int n;
    segtree st;
    cin >> n;
    st.init(n * 2, n);
    for (int i = 0; i < n * 2; i++)
    {
        int x;
        cin >> x;
        st.set(i, x);
    }

    st.solve();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
