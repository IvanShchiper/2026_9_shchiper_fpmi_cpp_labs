#pragma once

#include <cmath>

class Complex {
private:
	double a_;
	double b_;
public:
	double Real() const {
		return a_;
	}
	double Real(int a) {
		a_ = a;
		return a_;
	}
	double Imag() const {
		return b_;
	}
	double Imag(int b) {
		b_ = b;
		return b_;
	}

	double Abs() const {
		double c = sqrt(a_ * a_ + b_ * b_);
		return c;
	}

	void Set_a(double a) {
		a_ = a;
	}
	void Set_b(double b) {
		b_ = b;
	}

	Complex() : a_(0), b_(0) {}
	Complex(double a, double b) : a_(a), b_(b) {}
	Complex(double a) : a_(a), b_(0) {}

	///чтобы присвоил (0,b)?????

	//
	//копирование
	Complex(Complex& num) : a_(num.Real()), b_(num.Imag()) {}

	Complex& operator=(Complex& num) {
		a_ = num.Real();
		b_ = num.Imag();
		return *this;
	}
	//a == b/a.operator==(b)
	bool operator==(const Complex& num) const {
		return a_ == num.Real() && b_ == num.Imag();
	}
	bool operator!=(const Complex& num) const {
		return a_ != num.Real() || b_ != num.Imag();
	}

	Complex operator+() const {
		return Complex(a_, b_);
	}
	Complex operator-() const {
		return Complex(-1 * a_, -1 * b_);
	}
	//a += b/a.operator+(b)
	Complex& operator+=(const Complex& num) {
		a_ += num.Real();
		b_ += num.Imag();
		return *this;
	}
	Complex& operator-=(const Complex& num) {
		a_ -= num.Real();
		b_ -= num.Imag();
		return *this;
	}
	Complex& operator*=(const Complex& num) {
		double new_a = a_ * num.Real() - b_ * num.Imag();
		double new_b = a_ * num.Imag() + b_ * num.Real();
		a_ = new_a;
		b_ = new_b;
		return *this;
	}
	Complex& operator/=(const Complex& num) {
		double new_a = (a_ * num.Real() + b_ * num.Imag()) / (num.Real() * num.Real() + num.Imag() * num.Imag());
		double new_b = (b_ * num.Real() - a_ * num.Imag()) / (num.Real() * num.Real() + num.Imag() * num.Imag());
		a_ = new_a;
		b_ = new_b;
		return *this;
	}
	//a = b + c/a = b.operator+(c);
	Complex operator+(const Complex& num) {
		Complex c(a_ + num.Real(), b_ + num.Imag());
		return c;
	}
	Complex operator-(const Complex& num) {
		Complex c(a_ - num.Real(), b_ - num.Imag());
		return c;
	}
	Complex operator*(const Complex& num) {
		double new_a = a_ * num.Real() - b_ * num.Imag();
		double new_b = a_ * num.Imag() + b_ * num.Real();
		Complex c(new_a, new_b);
		return c;
	}
	Complex operator/(const Complex& num) {
		double new_a = (a_ * num.Real() + b_ * num.Imag()) / (num.Real() * num.Real() + num.Imag() * num.Imag());
		double new_b = (b_ * num.Real() - a_ * num.Imag()) / (num.Real() * num.Real() + num.Imag() * num.Imag());
		Complex c(new_a, new_b);
		return c;
	}
};