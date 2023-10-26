#include <string>
#include <iostream>

using namespace std;

class Figure {
protected:
	string name = "фигура: ";
	int sides_count = 0;
	int angle_A = 0;
public:
	Figure() {}
	int getter_sides_count() {
		return sides_count;
	}
	string get_Figure() {
		return name;
	}
	void get_ALL() {
		cout << get_Figure() << getter_sides_count() << endl;
	}
	virtual string kekw() {
		if (sides_count == 0) {
			 
			return "OK";
		}
		else {
			 
			return "NOT OK";
		}
	}; 
};

class Triangle: public Figure {
protected:
	string name = "Треугольник: ";
	int side_a, side_b, side_c;
	int angle_A, angle_B, angle_C;
public:
	Triangle(string Name, int sidea, int sideb, int sidec, int angA, int angB, int angC) {
		this->name = Name;
		this->side_a = sidea;
		this->side_b = sideb;
		this->side_c = sidec;
		this->angle_A = angA;
		this->angle_B = angB;
		this->angle_C = angC;
		sides_count = 3;
	}
	string kekw() override {
		if (angle_A + angle_B + angle_C == 180 && sides_count ==3) {
			return "OK";
		}
		else {
			return "NOT OK";
		}
	}; 
	void print_info() {
		cout << name << endl << Triangle::kekw() << endl << "Количество сторон " << sides_count << endl << "Стороны: a=" << side_a << " b=" << side_b << " c=" << side_c << endl << "Углы: A=" << angle_A << " B=" << angle_B << " C=" << angle_C << endl;
	}
};

class RA_Triangle : public Triangle {
public:
	RA_Triangle(string name, int sidea, int sideb, int sidec, int angA, int angB, int angC) : Triangle(name, sidea, sideb, sidec, angA, angB, 90) {
	}
	string kekw() override {
		if (Triangle::kekw() == "OK" && angle_C == 90) {
			return "OK";
		}
		else {
			return "NOT OK";
		}
	}
};

class Isosceles_Triangle : public Triangle {
public:
	Isosceles_Triangle(string name, int sidea, int sideBC, int angA, int angBC) : Triangle(name, sidea, sideBC, sideBC, angA, angBC, angBC) {
	}
	string kekw() override {
		if (Triangle::kekw() == "OK" && angle_A == angle_C && side_a == side_c) {
			return "OK";
		}
		else {
			return "NOT OK";
		}
	}
};

class Equilateral_Triangle : public Triangle {
public:
	Equilateral_Triangle(string name, int sideABC, int angABC) : Triangle(name, sideABC, sideABC, sideABC, 60, 60, 60) {
	}
	string kekw() override {
		if (Triangle::kekw() == "OK" && side_a == side_b == side_c && angle_A == angle_B == angle_C == 60) {
			return "OK";
		}
		else {
			return "NOT OK";
		}
	}
};

class Quadrangle: public Figure {
protected:
	string name;
	int side_a, side_b, side_c, side_d;
	int angle_A, angle_B, angle_C, angle_D;
public:
	Quadrangle(string Name, int sidea, int sideb, int sidec, int sided, int angA, int angB, int angC, int angD) {
		this->name = Name;
		this->side_a = 10;
		this->side_b = 20;
		this->side_c = 30;
		this->side_d = 40;
		this->angle_A = 50;
		this->angle_B = 60;
		this->angle_C = 70;
		this->angle_D = 80;
		sides_count = 4;
	}
	string kekw() override {
		if (sides_count == 4 && angle_A + angle_B + angle_C + angle_D == 360) {
			return "OK";
		}
		else {
			return "NOT OK";
		}
	}
	void print_info() {
		cout << name << endl << Quadrangle::kekw() << endl << "Количество сторон " << sides_count << endl << "Стороны: a=" << side_a << " b=" << side_b << " c=" << side_c << " d=" << side_d << endl << "Углы: A=" << angle_A << " B=" << angle_B << " C=" << angle_C << " D=" << angle_D << endl;
	}
};

class Rectangle : public Quadrangle {
	Rectangle(string name, int side_a_c, int side_b_d, int angABCD) : Quadrangle(name, side_a_c, side_b_d, side_a_c, side_b_d, 90, 90, 90, 90) {
	}
	string kekw() override {
		if (Quadrangle::kekw() == "OK" && side_a == side_c && side_b == side_d && angle_A == angle_B == angle_C == angle_D == 90) {
			return "OK";
		}
		else {
			return "NOT OK";
		}
	}
};

class Square : public Quadrangle {
public:
	Square(string name, int sideABCD, int angABCD) : Quadrangle(name, sideABCD, sideABCD, sideABCD, sideABCD, 90, 90, 90, 90) {
	}
	string kekw() override {
		if (Quadrangle::kekw() == "OK" && side_a == side_b == side_c == side_d && angle_A == angle_B == angle_C == angle_D == 90) {
			return "OK";
		}
		else {
			return "NOT OK";
		}
	}
};

class Parallelogram : public Quadrangle {
public:
	Parallelogram(string name, int sideAC, int sideBD, int angAC, int angBD) : Quadrangle(name, sideAC, sideAC, sideBD, sideBD, angAC, angAC, angBD, angBD) {
	}
	string kekw() override {
		if (Quadrangle::kekw() == "OK" && side_a == side_c && side_b == side_d && angle_A == angle_C && angle_B == angle_D) {
			return "OK";
		}
		else {
			return "NOT OK";
		}
	}
};

class Rhomb : public Quadrangle {
public:
	Rhomb(string name, int sideABCD, int angAC, int angBD) : Quadrangle(name, sideABCD, sideABCD, sideABCD, sideABCD, angAC, angAC, angBD, angBD) {
	}
	string kekw() override {
		if (Quadrangle::kekw() == "OK" && side_a == side_b == side_c == side_d && angle_A == angle_C && angle_B == angle_D) {
			return "OK";
		}
		else {
			return "NOT OK";
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Triangle triangle("треугольник", 10, 20, 30, 50, 60, 70);
	RA_Triangle ra_triang("прямоугольный треугольник", 10, 20, 30, 50, 60, 90);
	Isosceles_Triangle iso_tri("Равнобедренный треугольник: ", 10, 20, 50, 60);
	Equilateral_Triangle eq_tri("Равносторонний треугольник", 10, 50);
	Quadrangle quadrangle("Четырёхугольник", 10, 20, 30, 40, 50, 60, 70, 80);
	Square square("Квадрат: ", 10, 90);
	Parallelogram parallelogram("Параллелограмм: ", 10, 20, 30, 60);
	Rhomb rhomb("Ромб: ", 10, 60, 30);
	triangle.print_info();
	ra_triang.print_info();
	iso_tri.print_info();
	eq_tri.print_info();
	quadrangle.print_info();
	square.print_info();
	parallelogram.print_info();
	rhomb.print_info();
}