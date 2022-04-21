#include <iostream>
#include <math.h>
using namespace std;

double f(double x)
{
	return x * x + 6 * x + 13;
}

int main()
{
	double x, t, a, b, L;
	int k = 0;
	double x1, x2;
	double fx1, fx2, fx;
	double xx, xk;
	double fxk, fxx;


	setlocale(LC_ALL, "rus");
	cout << "Шаг 1. Зададим произвольные значения x0 и t > 0: " << endl;
	cout << "Введите x0 ";
	cin >> x;
	cout << "Введите t > 0 ";
	cin >> t;
	cout << "Положим k = " << k << endl;
	cout << endl;

	cout << "Шаг 2. Вычислим значения в трех точках: x0 - t, x0 и x0 + t: " << endl;
	x1 = x - t;
	x2 = x + t;
	cout << " x0 - t = " << x1 << ", " << "x0 = " << x << ", " << "x0 + t = " << x2 << endl;
	fx1 = f(x1);
	fx2 = f(x2);
	fx = f(x);
	cout << " f(x0 - t) = " << fx1 << ", " << "f(x0) = " << fx << ", " << "f(x0 + t) = " << fx2 << endl;
	cout << endl;

	cout << "Шаг 3. Проверим условия окончания:" << endl;
	if ((fx1 >= fx) && (fx2 >= fx))
	{
		cout << "Условие а) выполняется! f(x0 - t) >=  f(x0) <= f(x0 + t) Начальный интервал неопределенности найден!" << endl;
		a = x1;
		b = x2;
		cout << "Полученный интервал: " << "[ " << a << "; " << b << " ]" << endl;
		return 0;
	}
	else
		if ((fx1 <= fx) && (fx2 <= fx))
		{
			cout << "Условие б) выполняется! f(x0 - t) <=  f(x0) >= f(x0 + t) Функция не является унимодальной, а требуемый интервал неопределенности не может быть найден!" << endl;
			return 0;
		}
		else
		{
			cout << "Условия окончания не выполняются!" << endl;
			cout << "Шаг 4. Определим величину L:" << endl;
			if ((fx1 >= fx) && (fx >= fx2))
			{
				L = t;
				a = x;
				x = x2;
				k++;
				cout << "L = " << L << "a = " << a << "x =" << x << endl;
			}
			if ((fx1 <= fx) && (fx <= fx2))
			{
				L = -t;
				b = x;
				x = x1;
				k++;
				cout << "L = " << L << "b = " << b << "x =" << x << endl;
			}
		}
	cout << endl;
	while (true)
	{
		cout << "Шаг 5. Найти точку x^(k+1) = x^k + 2^k * L:" << endl;
		xx = pow(x, k);
		xk = xx + pow(2, k) * L;
		cout << "x^(k + 1) = " << xk << endl;
		cout << endl;

		cout << "Шаг 6. Проверим условное убывание функции:" << endl;
		fxk = f(xk);
		fxx = f(xx);
		if ((fxk < fxx) && (L == t))
		{
			a = xx;
			k++;
		}
		if ((fxk < fxx) && (L == -t))
		{
			b = xx;
			k++;
		}

		if ((fxk >= fxx) && (L == t))
		{
			cout << "Так как f(x^(k+1)) < f(x^k) и L = t, Процедура завершена!" << endl;
			cout << "b = x^(k+1), a = x" << endl;
			b = xk;
			break;
		}
		if ((fxk >= fxx) && (L == -t))
		{
			cout << "Так как f(x^(k+1)) < f(x^k) и L = -t, Процедура завершена!" << endl;
			cout << "a = x^(k+1), b = t" << endl;
			a = xk;
			break;
		}
	}
	cout << "Полученный интервал: " << "[ " << a << "; " << b << " ]" << endl;
	system("pause");
	return 0;
}