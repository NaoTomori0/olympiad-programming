// B. Криптография
// ограничение по времени на тест2 секунды
// ограничение по памяти на тест1024 мегабайта

// Задано n матриц A1, A2, …, A_n размера 2×2. Необходимо для нескольких запросов
// вычислить произведение матриц A_i, A_{i+1}, …, A_j. Все вычисления производятся
// по модулю r.

// Входные данные
// Первая строка входного файла содержит числа r (1 ≤ r ≤ 10000), n (1 ≤ n ≤ 200000)
// и m (1 ≤ m ≤ 200000). Следующие n блоков по две строки, содержащие по два числа
// в строке — описания матриц. Затем следуют m пар целых чисел от 1 до n — запросы
// на произведение на отрезке.

// Выходные данные
// Выведите m блоков по две строки, по два числа в каждой — произведения на отрезках.
// Разделяйте блоки пустой строкой. Все вычисления производятся по модулю r.

// ======================================================================
// Пример
// ======================================================================
// Входные данные
// ======================================================================
// 3 4 4
// 0 1
// 0 0

// 2 1
// 1 2

// 0 0
// 0 2

// 1 0
// 0 2

// 1 4
// 2 3
// 1 3
// 2 2
// ======================================================================
// Выходные данные
// ======================================================================
// 0 2
// 0 0

// 0 2
// 0 1

// 0 1
// 0 0

// 2 1
// 1 2
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct matrix
{
    int x00, x01, x10, x11;

    void print()
    {
        cout << x00 << " " << x01 << "\n";
        cout << x10 << " " << x11 << "\n";
    }
};

struct segtree
{

    void build(vector<matrix> &a, int s, int r)
    {
        init(s, r);
        build(a, 0, 0, size);
    }

    matrix query(int l, int r)
    {
        return query(l, r, 0, 0, size);
    }

private:
    vector<matrix> tree;
    int size = 1, r;

    const matrix ONE = {1, 0, 0, 1};

    matrix query(int l, int r, int x, int lx, int rx)
    {
        if (lx >= l && rx <= r)
            return tree[x];
        if (lx >= r || rx <= l)
            return ONE;

        int m = (rx + lx) / 2;
        matrix ma1 = query(l, r, 2 * x + 1, lx, m), ma2 = query(l, r, 2 * x + 2, m, rx);
        return combine(ma1, ma2);
    }

    void init(int n, int r)
    {
        size = 1;
        while (size < n)
            size *= 2;
        tree.assign(2 * size - 1, ONE);
        this->r = r;
    }

    void build(vector<matrix> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < a.size())
                tree[x] = a[lx];
        }
        else
        {
            int m = (rx + lx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }

    matrix combine(matrix &a, matrix &b)
    {
        return {
            (a.x00 * b.x00 + a.x01 * b.x10) % r,
            (a.x00 * b.x01 + a.x01 * b.x11) % r,
            (a.x10 * b.x00 + a.x11 * b.x10) % r,
            (a.x10 * b.x01 + a.x11 * b.x11) % r};
    }
};

void solve()
{
    int r, n, m;
    cin >> r >> n >> m;
    segtree st;
    vector<matrix> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x00;
        cin >> a[i].x01;
        cin >> a[i].x10;
        cin >> a[i].x11;
    }

    st.build(a, n, r);

    while (m--)
    {
        int i, j;
        cin >> i >> j;
        st.query(i - 1, j).print();
        cout << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
