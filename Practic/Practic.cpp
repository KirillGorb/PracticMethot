#include <iostream>;
#include <cmath>;
#include <iomanip>;

using namespace std;

double Function(double x) {
	return cos(x) + sin(log10(x));
}
double FunctionPr(double x) {
	return cos(log10(x)) / (log(10) * x) * 1 / x - sin(x);
}

double Function2(double x) {
	return 8 * x * sin(x) - log(x);
}
double FunctionPr2(double x) {
	return 8 * (sin(x) + x * cos(x)) - 1 / x;
}

double Bisection(double epsilon) {
	double a = 1.75;
	double b = 2;

	if (Function(a) * Function(b) >= 0) {
		cout << "Ошибка: функция не удовлетворяет условию f(a) * f(b) < 0" << endl;
		return 0;
	}

	double c;
	while ((b - a) >= epsilon) {
		c = (a + b) / 2;

		if (Function(c) == 0.0) {
			break;
		}
		else if (Function(c) * Function(a) < 0) {
			b = c;
		}
		else {
			a = c;
		}
	}
	return c;
}

double Newton(double epsilon, int maxIterations) {
	int iteration = 0;
	double x = 1.75;

	while (abs(Function(x)) >= epsilon && iteration < maxIterations) {
		x = x - Function(x) / FunctionPr(x);
		iteration++;
	}

	return x;
}
double Secant(double epsilon, int maxIterations) {
	double x0 = 1.75;
	double x1 = 2;

	int iteration = 0;
	double x = x1;

	while (abs(Function(x)) >= epsilon && iteration < maxIterations) {
		double denominator = Function(x1) - Function(x0);
		if (denominator == 0) {
			cout << "Деление на ноль. Метод секущих не может продолжаться." << endl;
			return x;
		}

		double deltaX = Function(x1) * (x1 - x0) / denominator;
		x = x1 - deltaX;

		x0 = x1;
		x1 = x;
		iteration++;
	}

	return x;
}

double Find(float eps)
{
	double a = 1.75;
	double b = 2, x;

	while (abs(a - b) > eps) {
		x = (a + b) / 2;

		if (Function(a) * Function(x) < 0)
			b = x;
		else
			a = x;
	}

	return x;
}

void main() {

	system("color F0");

	setlocale(LC_ALL, "rus");

	double e = 0.0001;

	cout << setprecision(52);
	cout << Bisection(e) << "\n\n";
	cout << Newton(e, 2000) << "\n\n";
	cout << Secant(e, 2000) << "\n\n";
	cout << Find(e) << "\n\n";

	//////////////////////////////////
	int arr[20];
	int x = 1;
	int j = 0;
	int i = 2;
	while (true)
	{
		if (x % 2 == 0)
			x /= 2;
		else
			x = 3 * x + 1;

		if (x == 8848) {
			arr[j++] = i;
			cout << i << "\n";
			x = i++;
			if (j > 3)
				break;
		}
		if (x > 8848 || x <= 1) {
			x = i++;
			if (j > 3)
				break;
		}
	}

	int k;
	cin >> k;
	k--;
	if (k < 20 && k >= 0)
		cout << arr[k];
	else
		cout << -1;
	/////////////////////////////////////////

	int a, b;
	cin >> a >> b;
	float s = (a + b * sqrt(2));
	float rez = sqrt(s/ (2+2*sqrt(2)));
	if (rez == (int)rez)
		cout << 1;
	else cout << 0;
}