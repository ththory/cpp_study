#include <iostream>
class Complex
{
private:
    double real, img;

public:
    Complex(double real, double img) : real(real), img(img) {}

    Complex operator+(const Complex &complex) const;
    Complex operator-(const Complex &complex) const;
    Complex operator*(const Complex &complex) const;
    Complex operator/(const Complex &complex) const;
    Complex &operator=(const Complex &complex);

    void print();
};

void Complex::print()
{
    std::cout << this->real;
    if (this->img > 0)
        std::cout << "+";
    std::cout << this->img << "i" << std::endl;
}

Complex Complex::operator+(const Complex &complex) const { return Complex(real + complex.real, img + complex.img); }
Complex Complex::operator-(const Complex &complex) const { return Complex(real - complex.real, img - complex.img); }
Complex Complex::operator*(const Complex &complex) const { return Complex(real * complex.real - img * complex.img, real * complex.img + img * complex.real); }
Complex Complex::operator/(const Complex &complex) const { return Complex((real * complex.real + img * complex.img) / (complex.real * complex.real + complex.img * complex.img),
                                                                          (img * complex.real - real * complex.img) / (complex.real * complex.real + complex.img * complex.img)); }
Complex &Complex::operator=(const Complex &complex)
{
    real = complex.real;
    img = complex.img;
    return *this;
}

int main()
{
    Complex complex1 = Complex(1, 2);
    Complex complex2 = Complex(-3, -5);

    complex1.print();
    complex2.print();
    Complex complex3 = complex1 + complex2;
    complex3.print();
}