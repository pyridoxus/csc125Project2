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
#ifndef MAINMENU_H_
#define MAINMENU_H_
#include "MatrixMath.h"
#include "Point.h"

class MainMenu
{
	public:
		int doMenu(void);
		void initPoint(Point &p);
		void translate(Point &p, Point &t);
		void scale(Point &p, Point &s);
		void rotx(Point &p, float r);
		void roty(Point &p, float r);
		void rotz(Point &p, float r);
	private:
		MatrixMath math;
		void printHeader(Point &p);
		void printFooter(Point &p);
		float degreeToRadian(float r);
};

#endif
