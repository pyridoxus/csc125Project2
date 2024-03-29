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
#include "MatrixMath.h"

MatrixMath::MatrixMath()
{
	int a, b;
	for(a = 0; a < 4; a++)
	{
		for(b = 0; b < 4; b++)
		{
			work[a][b] = 0.0;
		}
	}
	work[3][3] = 1.0;
}

void MatrixMath::translate(Point &p, Point &t)	// p is translated by t
{
	this->initWorkTranslate(t);
	this->multiply(p);
	return;
}

void MatrixMath::scale(Point &p, Point &s)			// p is scaled by s
{
	this->initWorkScale(s);
	this->multiply(p);
	return;
}

void MatrixMath::rotx(Point &p, float r)				// p is rotated on x axis by r
{
	this->initWorkRotx(r);	// r must be in radians
	this->multiply(p);
	return;
}

void MatrixMath::roty(Point &p, float r)				// p is rotated on y axis by r
{
	this->initWorkRoty(r);	// r must be in radians
	this->multiply(p);
	return;
}

void MatrixMath::rotz(Point &p, float r)				// p is rotated on z axis by r
{
	this->initWorkRotz(r);	// r must be in radians
	this->multiply(p);
	return;
}

void MatrixMath::initWorkTranslate(Point &t)// init work matrix for translation
{
	float f[3];
	t.get(f);
	this->work[0][0] = 1.0;
	this->work[0][1] = 0.0;
	this->work[0][2] = 0.0;
	this->work[0][3] = f[0];
	this->work[1][0] = 0.0;
	this->work[1][1] = 1.0;
	this->work[1][2] = 0.0;
	this->work[1][3] = f[1];
	this->work[2][0] = 0.0;
	this->work[2][1] = 0.0;
	this->work[2][2] = 1.0;
	this->work[2][3] = f[2];
	return;
}

void MatrixMath::initWorkScale(Point &s)				// init work matrix for scaling
{
	float f[3];
	s.get(f);
	this->work[0][0] = f[0];
	this->work[0][1] = 0.0;
	this->work[0][2] = 0.0;
	this->work[0][3] = 0.0;
	this->work[1][0] = 0.0;
	this->work[1][1] = f[1];
	this->work[1][2] = 0.0;
	this->work[1][3] = 0.0;
	this->work[2][0] = 0.0;
	this->work[2][1] = 0.0;
	this->work[2][2] = f[2];
	this->work[2][3] = 0.0;
	return;
}

void MatrixMath::initWorkRotx(float r)	// init work matrix for x axis rotation
{
	this->work[0][0] = 1.0;
	this->work[0][1] = 0.0;
	this->work[0][2] = 0.0;
	this->work[0][3] = 0.0;
	this->work[1][0] = 0.0;
	this->work[1][1] = cos(r);
	this->work[1][2] = -sin(r);
	this->work[1][3] = 0.0;
	this->work[2][0] = 0.0;
	this->work[2][1] = sin(r);
	this->work[2][2] = cos(r);
	this->work[2][3] = 0.0;
	return;
}

void MatrixMath::initWorkRoty(float r)	// init work matrix for y axis rotation
{
	this->work[0][0] = cos(r);
	this->work[0][1] = 0.0;
	this->work[0][2] = sin(r);
	this->work[0][3] = 0.0;
	this->work[1][0] = 0.0;
	this->work[1][1] = 1.0;
	this->work[1][2] = 0.0;
	this->work[1][3] = 0.0;
	this->work[2][0] = -sin(r);
	this->work[2][1] = 0.0;
	this->work[2][2] = cos(r);
	this->work[2][3] = 0.0;
	return;
}

void MatrixMath::initWorkRotz(float r)	// init work matrix for z axis rotation
{
	this->work[0][0] = cos(r);
	this->work[0][1] = -sin(r);
	this->work[0][2] = 0.0;
	this->work[0][3] = 0.0;
	this->work[1][0] = sin(r);
	this->work[1][1] = cos(r);
	this->work[1][2] = 0.0;
	this->work[1][3] = 0.0;
	this->work[2][0] = 0.0;
	this->work[2][1] = 0.0;
	this->work[2][2] = 1.0;
	this->work[2][3] = 0.0;
	return;
}

void MatrixMath::multiply(Point &p)		// Find product of p and work, put in p
{
	int row, col;
	float f[4];
	float g[3];
	p.get(f);
	f[3] = 1.0;
	for(row = 0; row < 3; row++)
	{
		g[row] = 0.0;
		for(col = 0; col < 4; col++)
		{
			g[row] += this->work[row][col] * f[col];
		}
	}
	p.set(g);
	return;
}

// the work matrix needs to be initialized first
void MatrixMath::print(void)										// print the 4x4 matrix (work)
{
	int a, b;
	for(a = 0; a < 4; a++)
	{
		for(b = 0; b < 4; b++) cout << this->work[a][b] << " ";
		cout << endl;
	}
	return;
}

