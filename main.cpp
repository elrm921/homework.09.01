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
    bool operator <(Fraction other) {
        double lhs = (numerator_ * other.denominator_) / (denominator_ * other.denominator_);
        double rhs = (other.numerator_ * denominator_) / (denominator_ * other.denominator_);
        return (lhs) < (rhs);
    }
    bool operator >(Fraction other) {
        double lhs = (numerator_ * other.denominator_) / (denominator_ * other.denominator_);
        double rhs = (other.numerator_ * denominator_) / (denominator_ * other.denominator_);
        return (lhs > rhs);
    }
    bool operator ==(Fraction other) {
        return !(*this < other) && !(*this > other);
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