#include "Stem.h"
#include "DaisyCenter.h"
#include "Leaf.h"
#include "../util/mathhelper.h"
#include "../util/colors.h"

Stem::Stem(float x, float y, float z, int stemPartCount, float stemPartHeight)
 : GLObject(x, y, z), stemPartCount(stemPartCount), stemPartHeight(stemPartHeight)
{
	daisyCenter = new DaisyCenter(0, 0, 0);
	const int LEAF_COUNT = mh::irandom(4, 7);
	for (int i = 0; i < LEAF_COUNT; ++i)
	{
		Leaf* leaf = new Leaf;
		while (true)
		{
			int index = mh::irandom(1, stemPartCount - 4);
			if (leaves.find(index) == leaves.end())
			{
				leaves[index] = leaf;
				break;
			}
		}
	}
}

void Stem::simulateWind()
{
	dCurvingDirection += mh::frandom(-1, 1);
	dCurvingDirection = mh::clamp(dCurvingDirection, -2, 2);
	curvingDirection += dCurvingDirection;
	
	dCurveAngleFactor += mh::frandom(-0.05F, 0.05F);
	dCurveAngleFactor = mh::clamp(dCurveAngleFactor, -1, 1);
	
	curveAngleFactor += dCurveAngleFactor;
	curveAngleFactor = mh::clamp(curveAngleFactor, -2, 2);
	curvingAngle = 2*(mh::sigmoid(curveAngleFactor) - 0.5F);
}

void Stem::grow()
{
	const int DURATION = 12;
	time += 1/60.0F;
	
	float t = mh::clamp(time, 0.0001F, DURATION); 
	
	stemPartGrowth = stemPartHeight*mh::easeOutCubic(t/DURATION);
	daisyCenter->bloomFactor = mh::easeOutCubic(t/DURATION);
	
	std::map<int, Leaf*>::iterator itr;
	for (itr = leaves.begin(); itr != leaves.end(); ++itr )
		itr->second->growthFactor = mh::easeOutCubic(t/DURATION);
}

void Stem::draw()
{
	simulateWind();
	grow();
	
	// Draw stems
	const float STEM_RADIUS = 0.03F;
	
	glPushMatrix();
	static GLUquadricObj* quadric = gluNewQuadric();
	setColor(DARK_GREEN);
	rotateY(curvingDirection);
	glPushMatrix();
	rotateX(-90);
	gluCylinder(quadric, STEM_RADIUS, STEM_RADIUS, stemPartGrowth, 32, 32);
	glPopMatrix();
	float dtotal = 0, dytotal = 0;
	for (int i = 1; i <= stemPartCount; i++)
	{
		float d = stemPartGrowth*mh::sind(curvingAngle*i);
		dtotal += d;
		float dy = abs(STEM_RADIUS*mh::sind(curvingAngle*i)*1.5F);
		dytotal += dy;
		glTranslatef(0, stemPartGrowth - dy, 0);
		
		glPushMatrix();
		rotateZ(-curvingAngle*i);
		rotateX(-90);
		gluCylinder(quadric, STEM_RADIUS, STEM_RADIUS, stemPartGrowth, 32, 32);
		glPopMatrix();
		
		// Is there a leaf attached to this stem part? If so, draw it!
		if (leaves.find(i) != leaves.end())
		{
			glPushMatrix();
			glRotatef(curvingAngle*i, mh::cosd(curvingDirection + 90), 0, mh::sind(-curvingDirection + 90));
			rotateY(-curvingDirection);
			leaves[i]->beginDraw();
			glPopMatrix();
		}
		
		glTranslatef(d, 0, 0);
	}
	glPopMatrix();
	
	// Draw daisy
	glTranslatef(dtotal*mh::cosd(-curvingDirection), (stemPartCount + 1)*stemPartGrowth - dytotal, dtotal*mh::sind(-curvingDirection));
	glRotatef(curvingAngle*stemPartCount, mh::cosd(curvingDirection + 90), 0, mh::sind(curvingDirection - 90));
	daisyCenter->beginDraw();
}