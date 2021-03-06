// lab6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "lab6.h"
Complex::Complex() :Re(0.0), Im(0.0) {};//конструктор по умолчанию;

Complex::Complex(double re, double im) : Re(re), Im(im) {}//список инициализации;

Complex::Complex(const Complex& other) : Re(other.Re), Im(other.Im) {}//конструктор копирования, куда передается ссылка на объект const (const 
//здесь используется для того, чтобы вызываемая функция не смогла изменить объект other);



void Complex::print(ostream& os) {

	if (Im < 0) {

		os << Re << Im << "i" << endl;

	}
	else {

		os << Re << "+" << Im << "i" << endl;

	}

}//вывод в консоль компл. числа;



double Complex::real() {

	return Re;

}

double Complex::imaginary() {

	return Im;

}
//get-методы для полей действ. и мнимой частей компл. числа;




Complex Complex::add(const Complex& other) {

	return Complex(Re + other.Re, Im + other.Im);

}

Complex Complex::sub(const Complex& other) {

	return Complex(Re - other.Re, Im - other.Im);

}

Complex Complex::mul(int number) {

	return Complex(Re*number, Im*number);

}

Complex Complex::div(int number) {

	try {//начало блока исключений;

		if (number == 0) {

			throw 1;//возбуждение исключения с помощью throw;

		}

		Re = Re / number;

		Im = Im / number;

	}
	catch (int number) {//начало блока, ловящего исключения;

		cout << "Division by zero" << endl;



	}

	return Complex(Re, Im);

}



Complex Complex::operator*(const Complex& other) {

	return Complex(Re*other.Re - Im * other.Im, Im*other.Re + Re * other.Im);

}//компл. числа a+b*i и a1+b1*i, тогда произведение: (a*a1-b*b1)+(a*b1+b*a1)*i;

Complex Complex::operator/(const Complex& other) {

	return Complex((Re*other.Re + Im * other.Im) / (other.Re*other.Re + other.Im*other.Im), (-Re * other.Im + Im * other.Re) / (other.Re*other.Re + other.Im*other.Im));

}//компл. числа a+b*i и a1+b1*i, тогда частное: (a*a1+b*b1)/(a1^2+b1^2)+((b*a1-b1*a)/(a1^2+b1^2))*i;
//далее реализованы операторы присвоения;
Complex Complex::operator+=(const Complex& other) {

	Re += other.Re;

	Im += other.Im;

	return Complex(Re, Im);

}

Complex Complex::operator-=(const Complex& other) {

	Re -= other.Re;

	Im -= other.Im;

	return Complex(Re, Im);

}

Complex Complex::operator*=(const Complex& other) {

	double  tmp;

	tmp = Re * other.Re - Im * other.Im;

	Im = Im * other.Re + Re * other.Im;

	Re = tmp;

	return Complex(Re, Im);

}

Complex Complex::operator/=(const Complex& other) {

	double tmp;

	tmp = (Re*other.Re + Im * other.Im) / (other.Re*other.Re + other.Im*other.Im);

	Im = (-Re * other.Im + Im * other.Re) / (other.Re*other.Re + other.Im*other.Im);

	Re = tmp;

	return Complex(Re, Im);

}

Complex Complex::operator=(const Complex& other) {

	Re = other.Re;

	Im = other.Im;

	return Complex(Re, Im);

}//оператор присваивания;

bool Complex::operator==(const Complex& other) {

	return (Re == other.Re && Im == other.Im);

}//оператор сравнения;
template <class CharT, class Traits>//реализация перегрузки << и >> в случае наследования и необходимости поддержки шаблонных версий 
//классов потоков; шаблонный класс basic_ostream предоставляет поддержку высокоуровневых операций вывода для символьных потоков. 
//Поддерживаемые операции включают форматированный вывод (например целых чисел) и неформатированный вывод (например неформатированных 
//символов и массивов символов).

basic_ostream<CharT, Traits>& operator<<(basic_ostream<CharT, Traits>& os, const Complex& other) {

	if (other.Im < 0)

	{

		os << other.Re << other.Im << "i" << std::endl;

	}

	else

	{

		os << other.Re << "+" << other.Im << "i" << std::endl;

	}

	return os;

}



template <class CharT, class Traits>

basic_istream<CharT, Traits>& operator>>(basic_istream<CharT, Traits>& is, Complex& other) {

	cout << "Введите дeйcтвительную и мнимую части числа: ";

	is >> other.Re >> other.Im;

	return is;

};
int main()
{
	setlocale(LC_ALL, "Russian");

	Complex complex1, complex2, complex3, complex4, complex5;

	cin >> complex1;
	cout << "Комплексное число 1: " << complex1 << endl;

	cin >> complex2;
	cout << "Комплексное число 2: " << complex2 << endl;

	cin >> complex3;
	cout << "Комплексное число 3: " << complex3 << endl;

	cin >> complex4;
	cout << "Комплексное число 4: " << complex4 << endl;

	cin >> complex5;
	cout << "Комплексное число 5: " << complex5 << endl;

	cout << "Произведение 1 и 2: " << complex1*complex2 << endl;

	cout << "Деление 1 на 2: " << complex1 / complex2 << endl;

	complex2 += complex1;
	cout << "Присвоение += для 1 и 2: " << complex2 << endl;

	complex3 -= complex1;
	cout << "Присвоение -= для 1 и 3: " << complex3 << endl;

	complex4 *= complex1;
	cout << "Присвоение *= для 1 и 4: " << complex4 << endl;

	complex5 /= complex1;
	cout << "Присвоение /= для 1 и 5: " << complex5 << endl;

	complex2 = complex1;

	cout << "оператор сравнения 1 и 2: " << (complex1 == complex2) << endl;



	system("PAUSE");
    return 0;
}

