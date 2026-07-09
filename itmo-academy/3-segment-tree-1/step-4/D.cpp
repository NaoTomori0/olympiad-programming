// D. Число различных на отрезке
// ограничение по времени на тест4 секунды
// ограничение по памяти на тест1024 мегабайта

// Дан массив a, состоящий из небольших целых чисел (1 ≤ a_i ≤ 40). Нужно построить
// структуру данных, которая обрабатывает два вида запросов:

// - найти число различных элементов на отрезке массива;
// - изменить элемент массива.

// Входные данные
// В первой строке два целых числа n и q — длина массива и число запросов соответственно
// (1 ≤ n, q ≤ 10^5).

// Во второй строке через пробел записано n чисел a1, a2, …, a_n, где a_i — начальное
// состояние массива (1 ≤ a_i ≤ 40).

// Следующие q строк описывают запросы. Каждая из этих строк имеет формат
// «type_i x_i y_i».

// - Если type_i = 1, то в i-м запросе требуется определить число различных элементов
//   на отрезке от x_i до y_i включительно (в этом случае 1 ≤ x_i ≤ y_i ≤ n).

// - Если type_i = 2, то элемент с индексом x_i заменяется на y_i (в этом случае
//   1 ≤ x_i ≤ n, 1 ≤ y_i ≤ 40).

// Выходные данные
// Для каждого запроса типа 1 выведите ответ на этот запрос на отдельной строке.

// ======================================================================
// Пример
// ======================================================================
// Входные данные
// ======================================================================
// 7 6
// 1 2 3 6 5 4 19
// 1 1 3
// 1 2 5
// 1 2 4
// 2 2 8
// 1 1 6
// 1 1 3
// ======================================================================
// Выходные данные
// ======================================================================
// 3
// 4
// 3
// 6
// 3
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node
{
    int unic_count;
    vector<int> unic;
};

struct SegTree
{

    int unic_count(int l, int r) { return unic_count(l, r, 0, 0, size).unic_count; }

    void set(int i, int v) { set(i, v, 0, 0, size); }

    void build(vector<int> &a, int s)
    {
        init(s);
        build(a, 0, 0, size);
    }

private:
    vector<Node> tree;
    int size;

    Node one_element(int v)
    {
        Node ret_val;
        ret_val.unic.assign(41, 0);
        ret_val.unic[v] = 1;
        ret_val.unic_count = 1;
        return ret_val;
    }

    Node void_element()
    {
        Node ret_val;
        ret_val.unic_count = 0;
        ret_val.unic.assign(41, 0);
        return ret_val;
    }

    Node merge(Node a, Node b)
    {
        Node res = void_element();
        for (int i = 0; i < 41; i++)
        {
            if (a.unic[i] != 0 || b.unic[i] != 0)
            {
                res.unic[i] = 1;
                res.unic_count++;
            }
        }

        return res;
    }

    void init(int x)
    {
        size = 1;
        while (size < x)
            size *= 2;
        tree.assign(2 * size - 1, void_element());
    }

    void build(vector<int> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < a.size())
                tree[x] = one_element(a[lx]);
        }
        else
        {
            int m = (rx + lx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = one_element(v);
            return;
        }
        int m = (rx + lx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    Node unic_count(int l, int r, int x, int lx, int rx)
    {
        if (lx >= l && rx <= r)
            return tree[x];
        if (rx <= l || lx >= r)
            return void_element();
        int m = (rx + lx) / 2;
        Node n1 = unic_count(l, r, 2 * x + 1, lx, m), n2 = unic_count(l, r, 2 * x + 2, m, rx);
        return merge(n1, n2);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    SegTree st;
    st.build(a, n);

    while (q--)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 2)
            st.set(x - 1, y);
        else
            cout << st.unic_count(x - 1, y) << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
