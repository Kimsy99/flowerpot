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
	int max(int a, int b);
	int max(int a, int b, int c);
	int irandom(int min, int max);
	float frandom(float min, float max);
	int gcd(int a, int b);
	float deg(float rad);
	float sind(float angle);
	float cosd(float angle);
}