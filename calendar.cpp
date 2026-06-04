#include <iostream>
#include <string>
using namespace std;

// Проверяет, является ли год високосным
bool visokosny(int god) {
    return (god % 4 == 0 && god % 100 != 0) || (god % 400 == 0);
}

// Возвращает количество дней в месяце
int dneyvMesyatse(int mesyats, int god) {
    if (mesyats == 2)
        return visokosny(god) ? 29 : 28;
    if (mesyats == 4 || mesyats == 6 || mesyats == 9 || mesyats == 11)
        return 30;
    return 31;
}

// Алгоритм Зеллера — определяет день недели для 1-го числа месяца.
// Возвращает: 0=Пн, 1=Вт, 2=Ср, 3=Чт, 4=Пт, 5=Сб, 6=Вс
int denNedeliPervogo(int mesyats, int god) {
    int m = mesyats;
    int g = god;
    // В алгоритме январь и февраль считаются 13-м и 14-м месяцем предыдущего года
    if (m <= 2) {
        m += 12;
        g--;
    }
    int K = g % 100;  // год в веке (0..99)
    int J = g / 100;  // номер века

    // Формула Зеллера для григорианского календаря
    int h = (1 + (13 * (m + 1)) / 5 + K + K / 4 + J / 4 - 2 * J) % 7;
    if (h < 0) h += 7;

    // Зеллер даёт: 0=Сб, 1=Вс, 2=Пн, 3=Вт, 4=Ср, 5=Чт, 6=Пт
    // Переводим в удобный вид: 0=Пн, 1=Вт, 2=Ср, 3=Чт, 4=Пт, 5=Сб, 6=Вс
    return (h + 5) % 7;
}

// Выводит одну ячейку (3 символа).
// Если это выбранный день — маркируем звёздочкой вместо ведущего пробела.
void pechatatYacheiku(int den, bool vybrannyy) {
    if (vybrannyy) {
        if (den < 10) cout << " *" << den;
        else          cout << "*" << den;
    } else {
        if (den < 10) cout << "  " << den;
        else          cout << " " << den;
    }
}

// Выводит календарь на заданный месяц и год.
// Вводимый день выделяется звёздочкой (*).
void vyvestiKalendar(int mesyats, int god, int vvedenniyDen) {
    string nazvaniya[] = {
        "", "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
        "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
    };

    int dney     = dneyvMesyatse(mesyats, god);
    int pervyDen = denNedeliPervogo(mesyats, god);  // 0=Пн .. 6=Вс

    cout << "\n      " << nazvaniya[mesyats] << " " << god << "\n";
    cout << " Пн  Вт  Ср  Чт  Пт  Сб  Вс\n";

    // Пустые ячейки до первого числа
    for (int i = 0; i < pervyDen; i++) {
        cout << "   ";
    }

    for (int den = 1; den <= dney; den++) {
        pechatatYacheiku(den, den == vvedenniyDen);

        // После воскресенья (позиция 6) переходим на новую строку
        int pozitsiya = (pervyDen + den - 1) % 7;
        if (pozitsiya == 6) {
            cout << "\n";
        }
    }
    cout << "\n";
}

// Считает количество дней, прошедших с 1 января 1583 года до заданной даты
int daysSince1583(int den, int mesyats, int god) {
    int total = 0;
    for (int g = 1583; g < god; g++) {
        total += visokosny(g) ? 366 : 365;
    }
    for (int m = 1; m < mesyats; m++) {
        total += dneyvMesyatse(m, god);
    }
    total += den;
    return total;
}

int main() {
    int den, mesyats, god;

    cout << "=== Вечный календарь ===" << endl;
    cout << "Введите день   (1-31):  ";
    cin >> den;
    cout << "Введите месяц  (1-12):  ";
    cin >> mesyats;
    cout << "Введите год    (>=1583): ";
    cin >> god;

    // Проверка корректности ввода
    if (mesyats < 1 || mesyats > 12) {
        cout << "Ошибка: месяц должен быть от 1 до 12" << endl;
        return 1;
    }
    if (god < 1583) {
        cout << "Ошибка: год должен быть не меньше 1583 "
                "(год введения григорианского календаря)" << endl;
        return 1;
    }
    int maxDen = dneyvMesyatse(mesyats, god);
    if (den < 1 || den > maxDen) {
        cout << "Ошибка: в данном месяце дней от 1 до " << maxDen << endl;
        return 1;
    }

    // Вывод календаря (введённый день отмечен *)
    vyvestiKalendar(mesyats, god, den);

    // Бонус 1: день недели для введённой даты
    string dniNedeli[] = {
        "понедельник", "вторник", "среда", "четверг",
        "пятница", "суббота", "воскресенье"
    };
    int pervyDen       = denNedeliPervogo(mesyats, god);
    int denNedeliDaty  = (pervyDen + den - 1) % 7;

    cout << den << "."
         << (mesyats < 10 ? "0" : "") << mesyats << "."
         << god << " — " << dniNedeli[denNedeliDaty] << endl;

    // Бонус 2: разница между двумя датами
    cout << "\nПосчитать разницу между датами? (1 — да, 0 — нет): ";
    int otvet;
    cin >> otvet;

    if (otvet == 1) {
        int den2, mesyats2, god2;
        cout << "Введите вторую дату:" << endl;
        cout << "День:   ";
        cin >> den2;
        cout << "Месяц:  ";
        cin >> mesyats2;
        cout << "Год:    ";
        cin >> god2;

        if (mesyats2 < 1 || mesyats2 > 12 || god2 < 1583) {
            cout << "Ошибка: некорректная дата" << endl;
        } else {
            int maxDen2 = dneyvMesyatse(mesyats2, god2);
            if (den2 < 1 || den2 > maxDen2) {
                cout << "Ошибка: некорректный день" << endl;
            } else {
                int d1 = daysSince1583(den,  mesyats,  god);
                int d2 = daysSince1583(den2, mesyats2, god2);
                int raznitsa = d2 - d1;
                if (raznitsa < 0) raznitsa = -raznitsa;
                cout << "Разница между датами: " << raznitsa << " дней" << endl;
            }
        }
    }

    return 0;
}
