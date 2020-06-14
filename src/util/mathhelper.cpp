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

const float PI = 3.14159265358979F;

namespace mh
{
	/**
	 * Returns the larger of two integers.
	 */
	int max(int a, int b)
	{
		return a>b ? a : b;
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
		if (min>max)
		{
			cout << "Exception in irandom(min, max) : min must not be greater than max" << endl;
			exit(1153);
		}
		//Initialize our mersenne twister with random seed
		static mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));
		uniform_int_distribution<> rand(min, max);
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
	 * Converts from radians to degrees.
	 */
	float deg(float rad)
	{
		return rad*PI/180;
	}
	
	/**
	 * Returns the sine of an angle in degrees.
	 */
	float sind(float angle)
	{
		return sin(deg(angle));
	}
	
	/**
	 * Returns the cosine of an angle in degrees.
	 */
	float cosd(float angle)
	{
		return cos(deg(angle));
	}
}