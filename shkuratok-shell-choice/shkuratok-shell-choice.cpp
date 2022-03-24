#include <iostream>
using namespace std;

int check() {
    int N;
    cin >> N;
    while (N <= 1) {
        cout << "Ошибка. Массив не может состоять из такого кол - ва эллементов. Пожалуйста повторите.";
        cin >> N;
    }
    return N;
}

void shell(int* a, int n) {
    int* p = new int [n];
    int d = n / 2;
    for (int i = 0; i < n; i++) {
        p[i] = a[i];
    }
    cout << "-----\n";
    while (d > 0) {
        for (int i = 0; i < n - d; i++) {
            int j = i;
            while (j >= 0 && p[j] > p[j + d]) {
                swap(p[j], p[j + d]);
                j--;
                for (int i = 0; i < n; i++) {
                    cout << p[i];
                }
                cout << endl;
            }
        }
        d = d / 2;
    }
    cout << "-----\n";
    cout << "Результат сортировки Шелла:\n";
    for (int i = 0; i < n; i++) {
        cout << p[i];
    }
    cout << endl;
}

void choice(int* a, int n) {
    int* c = new int[n];
    for (int i = 0; i < n; i++) {
        c[i] = a[i];
    }
    cout << "-----\n";
    int m = n - 1;
    while (m + 1 != 0) {
        int max = c[0];
        int maxi=0;
        for (int i = 0; i < m; i++) {
            if (c[i] > max) {
                max = c[i];
                maxi = i;
            }
        }
        swap(c[maxi], c[m]);
        for (int i = 0; i < n; i++) {
            cout << c[i];
        }
        cout << endl;
        m--;
    }
    cout << "-----\n";
    cout << "Результат сортировки выбором:\n";
    for (int i = 0; i < n; i++) {
        cout << c[i];
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    cout << "Колличество элементов: ";
    int n = check();
    int* a = new int[n];
    cout << "Введите " << n << " эллементов. \n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    shell(a, n);
    choice(a, n);
}
