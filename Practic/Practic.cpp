#include <iostream>;
#include <cmath>;

using namespace std;

double Function(double x) {
	return x * x - 4;
}
double FunctionPr(double x) {
	return 2 * x;
}

double Bisection(double epsilon) {
	double a = 1;
	double b = 3;

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
	double x = 2;

	while (abs(Function(x)) >= epsilon && iteration < maxIterations) {
		x = x - Function(x) / FunctionPr(x);
		iteration++;
	}

	return x;
}
double Secant(double epsilon, int maxIterations) {
	double x0 = 1; double x1 = 2;
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
	double a = 1, b = 10, x;

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

	setlocale(LC_ALL, "rus");

	double e = 0.0001;

	cout << Bisection(e) << "\n\n";
	cout << Newton(e, 2000) << "\n\n";
	cout << Secant(e, 2000) << "\n\n";
	cout << Find(e) << "\n\n";
}