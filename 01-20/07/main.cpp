#include <cmath>
#include <iostream>
#include <string>

#define H_BASE 24
#define M_BASE 60
#define S_BASE 60

class Time
{
public:
	int h;
	int m;
	int s;
	
	Time(int, int, int);
	Time(std::string);

	Time operator+(Time);
	Time operator-(Time);
	Time operator/(double);

	std::string to_string();
};

Time::Time(int h, int m, int s) : h(h), m(m), s(s) {}

Time::Time(std::string s)
{
	this->h = std::stoi(s.substr(0, 2));
	this->m = std::stoi(s.substr(3, 2));
	this->s = std::stoi(s.substr(6, 2));
}

Time Time::operator+(Time t)
{
	int s = this->s + t.s;
	int m = this->m + t.m + s / S_BASE; 
	int h = this->h + t.h + m / M_BASE;
	return Time(h % H_BASE, m % M_BASE, s % S_BASE);
}

Time Time::operator-(Time t)
{
	int s = this->s - t.s + S_BASE;
	int m = this->m - t.m - (1 - s / S_BASE) + M_BASE;
	int h = this->h - t.h - (1 - m / M_BASE) + H_BASE;
	return Time(h % H_BASE, m % M_BASE, s % S_BASE);
}

Time Time::operator/(double n)
{
	int to_s = this->s + this->m * S_BASE + this->h * M_BASE * S_BASE;
	int half_s = std::round(to_s / n);
	int s = half_s % S_BASE;
	int m = (half_s /= S_BASE) % M_BASE;
	int h = (half_s /= M_BASE);
	return Time(h, m, s);
}

std::string Time::to_string()
{
	std::string s = "hh:mm:ss";
	s[0] = '0' + this->h / 10;
	s[1] = '0' + this->h % 10;
	s[3] = '0' + this->m / 10;
	s[4] = '0' + this->m % 10;
	s[6] = '0' + this->s / 10;
	s[7] = '0' + this->s % 10;
	return s;
}

int main()
{
	std::string A, B, C;
	std::cin >> A >> B >> C;
	
	Time a(A);
	Time b(B);
	Time c(C);
	
	std::cout << (b + (c - a) / 2).to_string() << std::endl;
	return 0;
}
