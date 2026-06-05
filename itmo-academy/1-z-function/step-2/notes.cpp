
// Z-функция (Z-algorithm)
//  ОПРЕДЕЛЕНИЕ:
//   Z-функция от строки S длины N — это массив Z длины N, где каждый элемент Z[i]
//  равен длине наибольшего общего префикса строки S и её i-го суффикса
//   (подстроки, начинающейся с позиции i).

//   На пальцах: Z[i] показывает, сколько первых символов всей строки полностью
//   совпадают с символами, начиная с позиции i.

//   ВАЖНО:
//   - Z[0] всегда полагается равным 0.
//  - Индексация строки и массива Z начинается с 0.

//   ПРИМЕР для строки "abacaba":
//   Индекс (i):  0   1   2   3   4   5   6
//   Символ:      a   b   a   c   a   b   a
//   Значение Z:  0   0   1   0   3   0   1

//   Пояснение для i = 4:
//   Суффикс строки равен "aba". Он полностью совпадает с префиксом всей строки
//   "aba"caba. Длина совпадения равна 3, поэтому Z[4] = 3.

#include <iostream>
#include <vector>
#include <string>

std::vector<int> zFoo(std::string s)
{
    int n = s.length();
    std::vector<int> result(n, 0);
    for (int i = 1; i < n; ++i)
    {
        int len = 0;
        while (i + len < n && s[len] == s[i + len])
        {
            ++len;
        }
        result[i] = len;
    }
    return result;
}

int main()
{
    std::string str;
    std::cin >> str;
    std::vector<int> data = zFoo(str);
    for (auto i = data.begin(); i != data.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}