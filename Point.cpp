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
#include "Point.h"

Point::Point()
{
	// Initialize the point to sit at origin
	for(int a = 0; a < 3; a++) this->p[a] = 0;
	return;
}

void Point::set(float *point)
{
	for(int a = 0; a < 3; a++) this->p[a] = point[a];
	return;
}

void Point::get(float *point)
{
	for(int a = 0; a < 3; a++) point[a] = this->p[a];
	return;
}

void Point::print(void)
{
	cout << this->p[0] << " ";
	cout << this->p[1] << " ";
	cout << this->p[2] << " ";
	cout << endl;
	return;
}
