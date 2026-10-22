// B. Умножение и сумма
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест1024 мегабайта

// Есть массив из n элементов, изначально заполненный единицами. Вам нужно написать
// структуру данных, которая обрабатывает два вида запросов:

// - умножить все элементы от l до r−1 на число v;
// - найти сумму на отрезке от l до r−1.

// Обе операции выполняются по модулю 10^9 + 7.

// Входные данные
// Первая строка содержит два числа n и m (1 ≤ n, m ≤ 100000) — размер массива
// и число операций. Далее следует описание операций. Описание каждой операции
// имеет следующий вид:

// 1 l r v — умножить все элементы от l до r−1 на число v
// (0 ≤ l < r ≤ n, 1 ≤ v < 10^9 + 7).
// 2 l r — найти сумму на отрезке от l до r−1 (0 ≤ l < r ≤ n).

// Выходные данные
// Для каждой операции второго типа выведите соответствующее значение.

// ======================================================================
// Примеры
// ======================================================================
// Входные данные
// ======================================================================
// 5 6
// 1 0 3 3
// 2 1 2
// 1 1 4 4
// 2 1 3
// 2 1 4
// 2 3 5
// ======================================================================
// Выходные данные
// ======================================================================
// 3
// 24
// 28
// 5

// ======================================================================
// Входные данные
// ======================================================================
// 2 3
// 1 0 1 1000000
// 1 0 2 1000000
// 2 0 2
// ======================================================================
// Выходные данные
// ======================================================================
// 993000
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define forr(i, n) for (int i = 0; i < n; i++)

const int MOD = 1e9 + 7;

struct SegTree
{
public:
    SegTree(int n)
    {
        while (size < n)
            size *= 2;
        vector<int> a(n, 1);
        tree.assign(2 * size - 1, NULLNODE);
        build(a, 0, 0, size);
    }

    int get(int l, int r) { return get(l, r, 0, 0, size); }

    void modify(int l, int r, int v) { modify(l, r, v, 0, 0, size); }

private:
    struct Node
    {
        int sum, a;
    };
    const Node NULLNODE = {0, 1};
    vector<Node> tree;
    int size = 1;

    void build(vector<int> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < a.size())
                tree[x].sum = a[lx];
        }
        else
        {
            int m = (rx + lx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x].sum = (tree[2 * x + 1].sum + tree[2 * x + 2].sum) * tree[x].a % MOD;
        }
    }

    int get(int l, int r, int x, int lx, int rx)
    {
        if (lx >= l && rx <= r)
            return tree[x].sum;
        if (rx <= l || lx >= r)
            return 0;
        int m = (lx + rx) / 2;
        int r1 = get(l, r, 2 * x + 1, lx, m), r2 = get(l, r, 2 * x + 2, m, rx);
        return (r1 + r2) * tree[x].a % MOD;
    }

    // void popogate(int x, int lx, int rx) {if (tree[x])}

    void modify(int l, int r, int v, int x, int lx, int rx)
    {
        if (lx >= l && rx <= r)
        {
            tree[x].sum = tree[x].sum * v % MOD;
            tree[x].a = tree[x].a * v % MOD;
            return;
        }
        if (rx <= l || lx >= r)
            return;
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
        tree[x].sum = (tree[2 * x + 1].sum + tree[2 * x + 2].sum) * tree[x].a % MOD;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    SegTree st(n);
    while (m--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            int v;
            cin >> v;
            st.modify(l, r, v);
        }
        else
            cout << st.get(l, r) << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
