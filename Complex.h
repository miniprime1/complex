#pragma once

class complex {
	double Re;
	double Im;

public:
	complex(double R, double I) :Re{ R }, Im{ I } {};
	complex(double R) :Re{ R }, Im{ 0 } {};
	complex() : Re{ 0 }, Im{ 0 } { };

	double real() const { return Re; }
	void real(double R) { Re = R; }
	double imag() const { return Im; }
	void imag(double I) { Re = I; }

	complex& operator+=(complex z) {
		double a = Re, b = Im, c = z.Re, d = z.Im;
		Re = a + c;
		Im = b + d;
		return *this;
	}
	complex& operator-=(complex z) {
		double a = Re, b = Im, c = z.Re, d = z.Im;
		Re = a - c;
		Im = b - d;
		return *this;
	}
	complex& operator*=(complex z) {
		double a = Re, b = Im, c = z.Re, d = z.Im;
		Re = a * c - b * d;
		Im = a * d + b * c;
		return *this;
	}
	complex& operator/=(complex z) {
		double a = Re, b = Im, c = z.Re, d = z.Im;
		Re = (a * c + b * d) / (c * c + d * d);
		Im = (b * c - a * d) / (c * c + d * d);
		return *this;
	}
};

complex operator+(complex z1, complex z2) { return z1 += z2; }
complex operator-(complex z1, complex z2) { return z1 -= z2; }
complex operator-(complex z1) { return { -z1.real(), -z1.imag() }; }
complex operator*(complex z1, complex z2) { return z1 *= z2; }
complex operator/(complex z1, complex z2) { return z1 /= z2; }

bool operator==(complex z1, complex z2) { return z1.real() == z2.real() && z1.imag() == z2.imag(); }
bool operator==(complex z1, complex z2) { return !(z1 == z2); }