#include <iostream>
#include <cmath>

void getSinCos(double degrees, double& sinOut, double& cosOut)
{
	// std::sin and std::cos take radians not degrees
	static constexpr double pi{ 3.14159265358979323846 };
	double radians = degrees * pi / 180;
	sinOut = std::sin(radians);
	cosOut = std::cos(radians);
}

int main()
{
	double sin{ 0.0 };
	double cos{ 0.0 };

	getSinCos(60, sin, cos);
	std::cout << "sincos is: " << sin << ' ' << cos;

	return 0;
}