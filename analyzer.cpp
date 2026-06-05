#include <iostream>
using namespace std;

bool delyatsya(int a, int b) {
	return a % b == 0;
}

void deliteli(int n) {
	for (int i = 1; i <= n; i++)
		if (n % i == 0) cout << i << " ";
	cout << endl;
}

bool prostoye(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}

int nod(int a, int b) {
	while (b != 0) { int t = b; b = a % b; a = t; }
	return a;
}

int nok(int a, int b) {
	return a / nod(a, b) * b;
}

void kratnie(int k, int ot, int do_) {
	for (int i = ot; i <= do_; i++)
		if (i % k == 0) cout << i << " ";
	cout << endl;
}

void prostie_v_diap(int ot, int do_) {
	for (int i = ot; i <= do_; i++)
		if (prostoye(i)) cout << i << " ";
	cout << endl;
}

void razlozhenie(int n) {
	for (int i = 2; i * i <= n; i++)
		while (n % i == 0) { cout << i << " "; n /= i; }
	if (n > 1) cout << n;
	cout << endl;
}

void priznaki(int n) {
	if (n < 0) n = -n;
	int last = n % 10;
	int sum = 0, t = n;
	while (t > 0) { sum += t % 10; t /= 10; }
	int alt = 0, pos = 0; t = n;
	while (t > 0) {
		if (pos % 2 == 0) alt += t % 10;
		else alt -= t % 10;
		t /= 10; pos++;
	}
	cout << "На  2: " << (last % 2 == 0 ? "ДА" : "НЕТ") << endl;
	cout << "На  3: " << (sum % 3 == 0 ? "ДА" : "НЕТ") << "  (сумма цифр = " << sum << ")" << endl;
	cout << "На  4: " << (n % 4 == 0 ? "ДА" : "НЕТ") << endl;
	cout << "На  5: " << (last == 0 || last == 5 ? "ДА" : "НЕТ") << endl;
	cout << "На  6: " << (last % 2 == 0 && sum % 3 == 0 ? "ДА" : "НЕТ") << endl;
	cout << "На  8: " << (n % 8 == 0 ? "ДА" : "НЕТ") << endl;
	cout << "На  9: " << (sum % 9 == 0 ? "ДА" : "НЕТ") << "  (сумма цифр = " << sum << ")" << endl;
	cout << "На 10: " << (last == 0 ? "ДА" : "НЕТ") << endl;
	cout << "На 11: " << (alt % 11 == 0 ? "ДА" : "НЕТ") << "  (знакочередующаяся сумма = " << alt << ")" << endl;
}

int main() {
	int v;
	do {
		cout << "\n=== Анализатор делимости ===" << endl;
		cout << "1. Делимость\n2. Делители\n3. Простое?\n";
		cout << "4. Кратные в диапазоне\n5. Простые в диапазоне\n";
		cout << "6. НОД и НОК\n7. Разложение на множители\n8. Признаки делимости\n0. Выход\n";
		cout << "Выбор: ";
		cin >> v;

		if (v == 1) {
			int a, b;
			cout << "Число и делитель: "; cin >> a >> b;
			if (delyatsya(a, b)) cout << a << " делится на " << b << " = " << a/b << endl;
			else cout << "Не делится" << endl;
		}
		else if (v == 2) {
			int n; cout << "Число: "; cin >> n;
			deliteli(n);
		}
		else if (v == 3) {
			int n; cout << "Число: "; cin >> n;
			cout << (prostoye(n) ? "Простое" : "Составное") << endl;
		}
		else if (v == 4) {
			int k, a, b;
			cout << "Кратные чему, от, до: "; cin >> k >> a >> b;
			kratnie(k, a, b);
		}
		else if (v == 5) {
			int a, b; cout << "От, до: "; cin >> a >> b;
			prostie_v_diap(a, b);
		}
		else if (v == 6) {
			int a, b; cout << "Два числа: "; cin >> a >> b;
			cout << "НОД = " << nod(a, b) << endl;
			cout << "НОК = " << nok(a, b) << endl;
		}
		else if (v == 7) {
			int n; cout << "Число: "; cin >> n;
			razlozhenie(n);
		}
		else if (v == 8) {
			int n; cout << "Число: "; cin >> n;
			priznaki(n);
		}
	} while (v != 0);

	return 0;
}
