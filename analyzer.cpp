#include <iostream>
using namespace std;

// Проверяет, делится ли a на b
bool delyatsya(int a, int b) {
    return a % b == 0;
}

// Находит и выводит все делители числа n
void naytiDeliteli(int n) {
    cout << "Делители числа " << n << ": ";
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Проверяет, является ли число простым
bool prostoye(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Наибольший общий делитель (алгоритм Евклида)
int nod(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Наименьшее общее кратное
int nok(int a, int b) {
    return a / nod(a, b) * b;
}

// Выводит числа, кратные k, в диапазоне [ot, do_]
void kratnyeVDiapazoneFunc(int k, int ot, int do_) {
    cout << "Числа, кратные " << k << " в диапазоне ["
         << ot << ", " << do_ << "]: ";
    bool nashli = false;
    for (int i = ot; i <= do_; i++) {
        if (i % k == 0) {
            cout << i << " ";
            nashli = true;
        }
    }
    if (!nashli) cout << "(нет)";
    cout << endl;
}

// Выводит числа, кратные сразу двум числам, в диапазоне [ot, do_]
void kratnyeDvumFunc(int k1, int k2, int ot, int do_) {
    cout << "Числа, кратные " << k1 << " и " << k2
         << " в диапазоне [" << ot << ", " << do_ << "]: ";
    bool nashli = false;
    for (int i = ot; i <= do_; i++) {
        if (i % k1 == 0 && i % k2 == 0) {
            cout << i << " ";
            nashli = true;
        }
    }
    if (!nashli) cout << "(нет)";
    cout << endl;
}

// Выводит простые числа в диапазоне [ot, do_]
void prostyeVDiapazoneFunc(int ot, int do_) {
    cout << "Простые числа в диапазоне [" << ot << ", " << do_ << "]: ";
    bool nashli = false;
    for (int i = ot; i <= do_; i++) {
        if (prostoye(i)) {
            cout << i << " ";
            nashli = true;
        }
    }
    if (!nashli) cout << "(нет)";
    cout << endl;
}

// Разложение числа на простые множители
void razlozhenie(int n) {
    cout << n << " = ";
    bool pervyi = true;
    int temp = n;
    for (int i = 2; i * i <= temp; i++) {
        while (temp % i == 0) {
            if (!pervyi) cout << " * ";
            cout << i;
            pervyi = false;
            temp /= i;
        }
    }
    if (temp > 1) {
        if (!pervyi) cout << " * ";
        cout << temp;
    }
    cout << endl;
}

// Считает сумму цифр числа
int summaTsifr(int n) {
    if (n < 0) n = -n;
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

// Проверяет делимость по математическим признакам
void priznakyDelimosti(int n) {
    int abs_n = (n < 0) ? -n : n;

    int posled1 = abs_n % 10;         // последняя цифра
    int posled2 = abs_n % 100;        // последние 2 цифры
    int posled3 = abs_n % 1000;       // последние 3 цифры
    int summa   = summaTsifr(abs_n);  // сумма цифр

    // Знакочередующаяся сумма — признак делимости на 11
    int znakSum = 0, razryad = 0;
    int temp = abs_n;
    while (temp > 0) {
        if (razryad % 2 == 0) znakSum += temp % 10;
        else                  znakSum -= temp % 10;
        temp /= 10;
        razryad++;
    }

    cout << "\nПризнаки делимости для числа " << n << ":\n";
    cout << "На  2: " << (posled1 % 2 == 0 ? "ДА " : "НЕТ")
         << "  (последняя цифра: " << posled1 << ")\n";
    cout << "На  3: " << (summa % 3 == 0 ? "ДА " : "НЕТ")
         << "  (сумма цифр = " << summa << ")\n";
    cout << "На  4: " << (posled2 % 4 == 0 ? "ДА " : "НЕТ")
         << "  (последние 2 цифры: " << posled2 << ")\n";
    cout << "На  5: " << ((posled1 == 0 || posled1 == 5) ? "ДА " : "НЕТ")
         << "  (последняя цифра: " << posled1 << ")\n";
    cout << "На  6: " << ((posled1 % 2 == 0 && summa % 3 == 0) ? "ДА " : "НЕТ")
         << "  (делится на 2 и на 3)\n";
    cout << "На  8: " << (posled3 % 8 == 0 ? "ДА " : "НЕТ")
         << "  (последние 3 цифры: " << posled3 << ")\n";
    cout << "На  9: " << (summa % 9 == 0 ? "ДА " : "НЕТ")
         << "  (сумма цифр = " << summa << ")\n";
    cout << "На 10: " << (posled1 == 0 ? "ДА " : "НЕТ")
         << "  (последняя цифра: " << posled1 << ")\n";
    cout << "На 11: " << (znakSum % 11 == 0 ? "ДА " : "НЕТ")
         << "  (знакочередующаяся сумма = " << znakSum << ")\n";
}

int main() {
    int vybor;
    do {
        cout << "\n=== Анализатор делимости ===" << endl;
        cout << "1. Проверить делимость" << endl;
        cout << "2. Найти делители числа" << endl;
        cout << "3. Проверить на простоту" << endl;
        cout << "4. Числа, кратные заданному в диапазоне" << endl;
        cout << "5. Числа, кратные двум числам одновременно" << endl;
        cout << "6. Простые числа в диапазоне" << endl;
        cout << "7. Найти НОД и НОК" << endl;
        cout << "8. Разложить на простые множители" << endl;
        cout << "9. Признаки делимости" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> vybor;

        if (vybor == 1) {
            int a, b;
            cout << "Введите число: ";
            cin >> a;
            cout << "Введите делитель: ";
            cin >> b;
            if (b == 0) {
                cout << "Ошибка: делитель не может быть 0" << endl;
            } else if (delyatsya(a, b)) {
                cout << a << " делится на " << b
                     << " (" << a << " / " << b << " = " << a / b << ")" << endl;
            } else {
                cout << a << " НЕ делится на " << b << endl;
            }
        }
        else if (vybor == 2) {
            int n;
            cout << "Введите натуральное число: ";
            cin >> n;
            if (n <= 0)
                cout << "Ошибка: введите натуральное число (больше 0)" << endl;
            else
                naytiDeliteli(n);
        }
        else if (vybor == 3) {
            int n;
            cout << "Введите число: ";
            cin >> n;
            if (prostoye(n))
                cout << n << " — простое число" << endl;
            else
                cout << n << " — НЕ простое" << endl;
        }
        else if (vybor == 4) {
            int k, ot, do_;
            cout << "Кратные какому числу искать: ";
            cin >> k;
            if (k == 0) {
                cout << "Ошибка: число не может быть 0" << endl;
            } else {
                cout << "Диапазон от: ";
                cin >> ot;
                cout << "До: ";
                cin >> do_;
                if (ot > do_)
                    cout << "Ошибка: начало диапазона больше конца" << endl;
                else
                    kratnyeVDiapazoneFunc(k, ot, do_);
            }
        }
        else if (vybor == 5) {
            int k1, k2, ot, do_;
            cout << "Первое число: ";
            cin >> k1;
            cout << "Второе число: ";
            cin >> k2;
            if (k1 == 0 || k2 == 0) {
                cout << "Ошибка: числа не могут быть 0" << endl;
            } else {
                cout << "Диапазон от: ";
                cin >> ot;
                cout << "До: ";
                cin >> do_;
                kratnyeDvumFunc(k1, k2, ot, do_);
            }
        }
        else if (vybor == 6) {
            int ot, do_;
            cout << "Диапазон от: ";
            cin >> ot;
            cout << "До: ";
            cin >> do_;
            if (ot > do_)
                cout << "Ошибка: начало диапазона больше конца" << endl;
            else
                prostyeVDiapazoneFunc(ot, do_);
        }
        else if (vybor == 7) {
            int a, b;
            cout << "Введите первое число: ";
            cin >> a;
            cout << "Введите второе число: ";
            cin >> b;
            if (a <= 0 || b <= 0) {
                cout << "Ошибка: введите натуральные числа (больше 0)" << endl;
            } else {
                cout << "НОД(" << a << ", " << b << ") = " << nod(a, b) << endl;
                cout << "НОК(" << a << ", " << b << ") = " << nok(a, b) << endl;
            }
        }
        else if (vybor == 8) {
            int n;
            cout << "Введите натуральное число (больше 1): ";
            cin >> n;
            if (n <= 1)
                cout << "Ошибка: введите число больше 1" << endl;
            else
                razlozhenie(n);
        }
        else if (vybor == 9) {
            int n;
            cout << "Введите число: ";
            cin >> n;
            priznakyDelimosti(n);
        }
        else if (vybor != 0) {
            cout << "Неверный выбор. Введите число от 0 до 9." << endl;
        }

    } while (vybor != 0);

    cout << "До свидания!" << endl;
    return 0;
}
