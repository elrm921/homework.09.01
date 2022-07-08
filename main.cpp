#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
    int find_gcd(int a, int b) {
        if (a > b) return find_gcd(a-b, b);
        else if (a < b) return find_gcd(a, b-a);
        else return a;
    }
    bool operator ==(Fraction other) {
        int cd = denominator_ * other.denominator_;
        return ((numerator_ * cd / denominator_) == (other.numerator_ * cd / other.denominator_));
    }
    bool operator <(Fraction other) {
        int cd = denominator_ * other.denominator_;
        return ((numerator_ * cd / denominator_) < (other.numerator_ * cd / other.denominator_));
    }
    bool operator >(Fraction other) {
        int cd = denominator_ * other.denominator_;
        return ((numerator_ * cd / denominator_) > (other.numerator_ * cd / other.denominator_));
    }
    bool operator !=(Fraction other) {
        return !(*this == other);
    }
    bool operator <=(Fraction other) {
        return !(*this > other);
    }
    bool operator >=(Fraction other) {
        return !(*this < other);
    }
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}