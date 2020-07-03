#pragma once

/*
 * mathhelper.h
 *
 *  Version: 6
 *  Updated: 2 Jun 2020
 *   Author: Mister_Bander
 */

extern const float PI;

namespace mh
{
	/**
	 * Returns the larger of two integers.
	 */
	int max(int a, int b);
	
	/**
	 * Returns the largest of three integers.
	 */
	int max(int a, int b, int c);
	
	/**
	 * Returns a random integer from min to max inclusive. min must be smaller or equal to max.
	 */
	int irandom(int min, int max);
	
	/**
	 * Returns a random float from min (inclusive) to max (exclusive). min must be smaller or equal to max.
	 */
	float frandom(float min, float max);
	
	/**
	 * Returns the greatest common divisor of two numbers.
	 */
	int gcd(int a, int b);
	
	/**
	 * Converts from degrees to radians.
	 */
	float rad(float rad);
	
	/**
	 * Returns the sine of an angle in degrees.
	 */
	float sind(float degrees);
	
	/**
	 * Returns the cosine of an angle in degrees.
	 */
	float cosd(float degrees);
}