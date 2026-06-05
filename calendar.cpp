#include <iostream>
#include <string>
using namespace std;

bool visokos(int g) {
	return (g % 4 == 0 && g % 100 != 0) || g % 400 == 0;
}

int dney(int m, int g) {
	if (m == 2) return visokos(g) ? 29 : 28;
	if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
	return 31;
}

// Алгоритм Зеллера — возвращает день недели 1-го числа: 0=Пн .. 6=Вс
int denNedeli(int m, int g) {
	if (m <= 2) { m += 12; g--; }
	int K = g % 100, J = g / 100;
	int h = (1 + (13*(m+1))/5 + K + K/4 + J/4 - 2*J) % 7;
	if (h < 0) h += 7;
	return (h + 5) % 7;
}

int main() {
	int d, m, g;
	cout << "День: ";   cin >> d;
	cout << "Месяц: ";  cin >> m;
	cout << "Год: ";    cin >> g;

	string mesyatsy[] = {"","Январь","Февраль","Март","Апрель","Май","Июнь",
	                     "Июль","Август","Сентябрь","Октябрь","Ноябрь","Декабрь"};
	string dni[] = {"понедельник","вторник","среда","четверг","пятница","суббота","воскресенье"};

	int pervyi = denNedeli(m, g);
	int kol    = dney(m, g);

	cout << "\n   " << mesyatsy[m] << " " << g << "\n";
	cout << " Пн  Вт  Ср  Чт  Пт  Сб  Вс\n";

	for (int i = 0; i < pervyi; i++) cout << "   ";

	for (int i = 1; i <= kol; i++) {
		if (i == d) {
			if (i < 10) cout << " *" << i;
			else        cout << "*" << i;
		} else {
			if (i < 10) cout << "  " << i;
			else        cout << " " << i;
		}
		if ((pervyi + i - 1) % 7 == 6) cout << "\n";
	}
	cout << "\n";

	cout << d << "." << m << "." << g << " — " << dni[(pervyi + d - 1) % 7] << endl;

	return 0;
}
