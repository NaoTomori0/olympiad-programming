// B. K-я единица
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест1024 мегабайта

// В этой задаче вам нужно добавить в дерево отрезков операцию нахождения k-й единицы.

// Входные данные
// Первая строка содержит два числа n и m (1 ≤ n, m ≤ 100 000) — размер массива
// и число операций. Следующая строка содержит n чисел a_i — начальное состояние
// массива (a_i ∈ {0, 1}). Далее следует описание операций. Описание каждой операции
// имеет следующий вид:

// 1 i — изменить элемент с индексом i на противоположный (0 ↔ 1).
// 2 k — найти k-ю единицу (единицы нумеруются с 0, гарантируется, что в массиве
// достаточное количество единиц).

// Выходные данные
// Для каждой операции второго типа выведите индекс соответствующей единицы
// (все индексы в этой задаче от 0).

// ======================================================================
// Пример
// ======================================================================
// Входные данные
// ======================================================================
// 5 7
// 1 1 0 1 0
// 2 0
// 2 1
// 2 2
// 1 2
// 2 3
// 1 0
// 2 0
// ======================================================================
// Выходные данные
// ======================================================================
// 0
// 1
// 3
// 3
// 1
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

    void set(int i, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = tree[x] == 1 ? 0 : 1;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            set(i, 2 * x + 1, lx, m);
        else
            set(i, 2 * x + 2, m, rx);

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void set(int i) { set(i, 0, 0, size); }

    void build(vector<int> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < a.size())
                tree[x] = a[lx];
        }
        else
        {
            int m = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        }
    }

    void build(vector<int> &a, int s)
    {
        init(s);
        build(a, 0, 0, size);
    }

    int find(int k, int x, int lx, int rx)
    {
        if (rx - lx == 1)
            return lx;
        int m = (lx + rx) / 2;
        if (k < tree[2 * x + 1])
            return find(k, 2 * x + 1, lx, m);
        else
            return find(k - tree[2 * x + 1], 2 * x + 2, m, rx);
    }

    int find(int k) { return find(k, 0, 0, size); }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    segtree st;
    st.build(a, n);
    while (m--)
    {
        int c, i;
        cin >> c >> i;
        if (c == 1)
            st.set(i);
        else
            cout << st.find(i) << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
