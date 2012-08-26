//This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#ifndef MATRIXMATH_H_
#define MATRIXMATH_H_
#include "Point.h"
#include <math.h>
using namespace std;

#define PI (float)3.141592654

class MatrixMath
{
	// This class contains the translating, scaling and rotation functions.
	public:
		MatrixMath();
		void translate(Point &p, Point &t);	// p is translated by t
		void scale(Point &p, Point &s);			// p is scaled by s
		void rotx(Point &p, float r);				// p is rotated on x axis by r
		void roty(Point &p, float r);				// p is rotated on y axis by r
		void rotz(Point &p, float r);				// p is rotated on z axis by r
		void print(void);										// print the 4x4 matrix (work)
	private:
		float work[4][4];		// all work is done using this matrix
		void initWorkTranslate(Point &t);		// init work matrix for translation
		void initWorkScale(Point &s);				// init work matrix for scaling
		void initWorkRotx(float r);					// init work matrix for x axis rotation
		void initWorkRoty(float r);					// init work matrix for y axis rotation
		void initWorkRotz(float r);					// init work matrix for z axis rotation
		void multiply(Point &p);						// Find product of p and work, put in p
};

#endif
