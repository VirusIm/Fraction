#include <iostream>
using namespace std;

#define delimiter "\n------------------------------------------\n"

/*
Home work: Проверчный код должен заработать
*/

class Fraction
{
	int integer;//целое 
	int numerator;// числитель
	int denominator;//знаменатель

public:
	int get_integer() const
	{
		return integer;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}



	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		this->denominator = denominator;
	}

	//			Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor: \t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Constructor: \t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "constructor: \t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor: \t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor: \t" << this << endl;
	}
	~Fraction()
	{
		cout << "destructor: \t" << this << endl;
	}

	//			Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment: \t" << this << endl;
	}



	//			Methods:
	void to_proper()
	{
		//переводит дробь в правильную
		integer = numerator / denominator;
		numerator %= denominator;
	}
	void to_improper()
	{
		//переводит дробь в неправильную
		numerator += denominator * integer;
		integer -= integer;
	}
	void reduce()
	{
		//сокращает дробь
	}
	void Print()
	{
		cout << integer << "(" << numerator << "/" << denominator << ")" << endl;
	}
};

Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*left.get_denominator()*right.get_denominator();*/
	Fraction temp(right.get_denominator()*left.get_numerator()
		+ left.get_denominator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator());
	//temp - временная переменная.
	temp.to_proper();			//Делает из неправильной дроби правильную
	return temp;
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*if (left.get_numerator() < right.get_numerator())
	{

	return Fraction(left.get_denominator()*right.get_numerator() -
					right.get_denominator()*left.get_numerator(),
					left.get_denominator()*right.get_denominator());
	}
	else
		return Fraction(right.get_denominator()*left.get_numerator()-
						left.get_denominator()*right.get_numerator(),
						left.get_denominator()*right.get_denominator());*/
	Fraction temp(left.get_numerator()*right.get_denominator() - right.get_numerator()*left.get_denominator(), left.get_denominator()*right.get_denominator());
	temp.to_proper();
	return temp;
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction(left.get_numerator()*right.get_numerator(), left.get_denominator()*right.get_denominator());
}
Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction(left.get_numerator() * right.get_denominator(), left.get_denominator() * right.get_numerator());
}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer() != 0)os << obj.get_integer();
	if (obj.get_numerator() != 0)
	{
		if (obj.get_integer() != 0)os << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")";
		else os << obj.get_numerator() << "/" << obj.get_denominator();
	}
	if (obj.get_numerator() == 0 && obj.get_integer() == 0)os << 0;
	return os;
}

void main()
{
	Fraction A(1, 1, 2);
	Fraction B(1, 3, 4);
	/*cout << A << " = A" << endl;
	std::cout << "A to improper: " << std::endl;
	A.to_improper();
	cout << A << endl;
	std::cout << "'A' to proper: " << std::endl;
	A.to_proper();
	cout << A << endl;
	std::cout << B << " = B" << std::endl;
	std::cout << "'B' to improper: " << std::endl;
	B.to_improper();
	std::cout << B << std::endl;*/

	cout << delimiter << endl;
	cout << A * B << endl;
	std::cout << A << " * " << B << " = " << A*B << std::endl;
	cout << delimiter << endl;
	std::cout << A << " / " << B << " = " << A / B << std::endl;
	cout << delimiter << endl;
	std::cout << A << " + " << B << " = " << A + B << std::endl;
	cout << delimiter << endl;
	std::cout << A << " - " << B << " = " << A - B << std::endl;
	//cout << A - B << endl;
	//cout << ++A << endl;
	//cout << B++ << endl;
}