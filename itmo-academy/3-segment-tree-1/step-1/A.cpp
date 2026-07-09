// A. Дерево отрезков на сумму
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест1024 мегабайта

// В этой задаче вам нужно написать обычное дерево отрезков на сумму.

// Входные данные
// Первая строка содержит два числа n и m (1 ≤ n, m ≤ 100 000) — размер массива
// и число операций. Следующая строка содержит n чисел a_i — начальное состояние
// массива (0 ≤ a_i ≤ 10^9). Далее следует описание операций. Описание каждой операции
// имеет следующий вид:

// 1 i v — присвоить элементу с индексом i значение v (0 ≤ i < n, 0 ≤ v ≤ 10^9).
// 2 l r — вычислить сумму элементов с индексами от l до r−1 (0 ≤ l < r ≤ n).

// Выходные данные
// Для каждой операции второго типа выведите соответствующую сумму.

// ======================================================================
// Пример
// ======================================================================
// Входные данные
// ======================================================================
// 5 5
// 5 4 2 3 5
// 2 0 3
// 1 1 1
// 2 0 3
// 1 3 1
// 2 0 5
// ======================================================================
// Выходные данные
// ======================================================================
// 11
// 8
// 14
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long

class segtree
{
public:
    void init(int s)
    {
        while (size < s)
            size *= 2;
        tree.assign(2 * size - 1, 0);
    }

    void set(int t, int value)
    {
        set(t, value, 0, 0, size);
    }

    int sum(int l, int r)
    {
        return sum(l, r, 0, 0, size);
    }

private:
    vector<int> tree;
    int size = 1;

    void set(int t, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = v;
            return;
        }
        int m = (rx + lx) / 2;
        if (t < m)
            set(t, v, 2 * x + 1, lx, m);
        else
            set(t, v, 2 * x + 2, m, rx);

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    int sum(int l, int r, int x, int lx, int rx)
    {
        if (l >= rx || lx >= r)
            return 0;

        if (lx >= l && rx <= r)
            return tree[x];

        int mid = (lx + rx) / 2;

        int s1 = sum(l, r, 2 * x + 1, lx, mid);
        int s2 = sum(l, r, 2 * x + 2, mid, rx);
        return s1 + s2;
    }
};

segtree st;

void solve()
{
    int n, m;
    cin >> n >> m;
    st.init(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.set(i, x);
    }

    for (int i = 0; i < m; i++)
    {
        int code;
        cin >> code;
        if (code == 1)
        {
            int j, v;
            cin >> j >> v;
            st.set(j, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.sum(l, r) << "\n";
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
