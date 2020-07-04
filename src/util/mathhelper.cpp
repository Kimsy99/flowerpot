#include <iostream>
#include <cmath>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * mathhelper.cpp
 * Useful math functions.
 *
 *  Version: 6
 *  Updated: 2 Jun 2020
 *   Author: Mister_Bander
 */
extern const float PI = 3.14159265359F;

namespace mh
{
	/**
	 * Returns the larger of two integers.
	 */
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
	
	/**
	 * Returns the largest of three integers.
	 */
	int max(int a, int b, int c)
	{
		return max(max(a, b), c);
	}
	
	/**
	 * Returns a random integer from min to max inclusive. min must be smaller or equal to max.
	 */
	int irandom(int min, int max)
	{
		if (min > max)
		{
			cout << "Exception in irandom(min, max) : min must not be greater than max" << endl;
			exit(1153);
		}
		// Initialize our mersenne twister with random seed
		static mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));
		uniform_int_distribution<> rand(min, max);
		return rand(mersenne);
	}

	/**
	 * Returns a random float from min (inclusive) to max (exclusive). min must be smaller or equal to max.
	 */
	float frandom(float min, float max)
	{
		if (min > max)
		{
			cout << "Exception in frandom(min, max) : min must not be greater than max" << endl;
			exit(1153);
		}
		// Initialize our mersenne twister with random seed
		static mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));
		uniform_real_distribution<> rand(min, max);
		return rand(mersenne);
	}
	
	/**
	 * Returns the greatest common divisor of two numbers.
	 */
	int gcd(int a, int b)
	{
		int c(abs(a)), d(abs(b));
		return d==0 ? c : gcd(d, c%d);
	}
	
	/**
	 * Converts from degrees to radians.
	 */
	float rad(float degrees)
	{
		return degrees*PI/180;
	}
	
	/**
	 * Returns the sine of an angle in degrees.
	 */
	float sind(float degrees)
	{
		return sin(rad(degrees));
	}
	
	/**
	 * Returns the cosine of an angle in degrees.
	 */
	float cosd(float degrees)
	{
		return cos(rad(degrees));
	}
	
	/**
	 * Returns the tangent of an angle in degrees.
	 */
	float tand(float degrees)
	{
		return tan(rad(degrees));
	}
}