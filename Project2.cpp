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
#include <iostream>
#include "MainMenu.h"

int main(void)
{
	MainMenu menu;
	float f[3];	// General purpose array used to obtain user input
	Point p, x; // p is the main point, x is auxiliary for holding temp data
	int a = 1;	// Loop flag
	menu.initPoint(p);	// Main Menu gets initial point here
	while(a)
	{
		switch(menu.doMenu())
		{
			case 1:
				cout << "Enter +/- translation units x y z: ";
				cin >> f[0] >> f[1] >> f[2];
				x.set(f);	// Use this point to hold onto the translation values
				menu.translate(p, x);
			break;
			case 2:
				cout << "Enter +/- scale units x y z: ";
				cin >> f[0] >> f[1] >> f[2];
				x.set(f); // Use this point to hold onto the scale values
				menu.scale(p, x);
			break;
			case 3:
				cout << "Enter +/- degrees about x axis: ";
				cin >> f[0];	// Use this float to hold onto angle
				menu.rotx(p, f[0]);
			break;
			case 4:
				cout << "Enter +/- degrees about y axis: ";
				cin >> f[0];	// Use this float to hold onto angle
				menu.roty(p, f[0]);
			break;
			case 5:
				cout << "Enter +/- degrees about z axis: ";
				cin >> f[0];	// Use this float to hold onto angle
				menu.rotz(p, f[0]);
			break;
			case 6:
				a = 0;	// All done
			break;
		}
	}
	return 0;
}
