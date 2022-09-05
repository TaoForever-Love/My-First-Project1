#include <iostream>
#include <cmath>
class fraction
{
	int molecule;              //分子
	int denominator;           //分母 
	void reduction();          //约分
	void commond(fraction);    //通分
public:
	fraction(int = 0, int = 1);
	fraction add(fraction);    // '+'
	fraction sub(fraction);    // '-'
	fraction mul(fraction);    // '*'
	fraction div(fraction);    // '/' 
	void input();
	fraction output(fraction);
	fraction operator<<(fraction);
	friend fraction operator+(const fraction &,const fraction&);
	friend fraction operator-(const fraction &,const fraction&); 
	friend fraction operator*(const fraction &,const fraction&);
	friend fraction operator/(const fraction &,const fraction&);
};
fraction::fraction(int i, int j)
{
	molecule = i;
	denominator = j;
}
void fraction::reduction()
{
	int i, j;
	if (molecule == 0)
	{
		denominator = 1;
		return;
	}
	if (abs(molecule) > abs(denominator))
		j = molecule;
	else
		j = denominator;
	for (i = j; i > 1; i--)
	{
		if (molecule % i == 0 && denominator % i == 0)
		{
			molecule /= i;
			denominator /= i;
			return;
		}
	}
}
void fraction::commond(fraction n)
{
	molecule = molecule * n.denominator;
	denominator = denominator * n.denominator;
}
void fraction::input()
{
	std::cout << "请分别输入分子与分母" << std::endl;
	std::cin >> molecule >> denominator;
}
fraction fraction::output(fraction n)
{
	if (molecule == 0)
		std::cout << '0' << std::endl;
	else if (denominator == 1)
		std::cout << molecule;
	else
		std::cout << molecule << "/" << denominator << std::endl;
	return n;
}

fraction fraction::add(fraction n)
{
	fraction n1(molecule,denominator);
	fraction tem_n(n.molecule, n.denominator);
	n.commond(n1);
	n1.commond(tem_n);
	n1.molecule += n.molecule;
	n1.reduction();
	return n1;
}
fraction fraction::sub(fraction n)
{
	fraction n1(molecule, denominator);
	fraction tem_n(n.molecule, n.denominator);
	n.commond(n1);
	n1.commond(tem_n);
	n1.molecule -= n.molecule;
	n1.reduction();
	return n1;
}
fraction fraction::mul(fraction n)
{
	n.molecule *= molecule;
	n.denominator *= denominator;
	n.reduction();
	return n;
}
fraction fraction::div(fraction n)
{
	n.molecule *= denominator;
	n.denominator *= molecule;
	n.reduction();
	return n;
}
fraction operator+(const fraction &a,const fraction &b)
{
	fraction tem_a(a.molecule, a.denominator);
	return 	tem_a.add(b);
}
fraction operator-(const fraction &a, const fraction &b)
{
	fraction tem_a(a.molecule, a.denominator);
	return 	tem_a.sub(b);
}
fraction operator*(const fraction &a, const fraction &b)
{
	fraction tem_a(a.molecule, a.denominator);
	return  tem_a.mul(b);
}
fraction operator/(const fraction &a, const fraction &b)
{
	fraction tem_a(a.molecule, a.denominator);
	return  tem_a.div(b);
}
fraction fraction::operator<<(fraction n)
{
	fraction temp(n.molecule, n.denominator);
	return output(temp);
}
int main()
{
	fraction n1, n2;
	fraction n[4];
	n1.input();
	n2.input();
	n[0] = n1 + n2;
	n[1] = n1 - n2;
	n[2] = n1 * n2;
	n[3] = n1 / n2;
	for (int i = 0; i < 4; i++)
	{
		n[i] << n[i];
	}
}