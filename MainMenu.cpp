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
#include "MainMenu.h"

int MainMenu::doMenu(void)
{
	int m;
	cout << "--------------------------------" << endl;
	cout << "Welcome to Transformation System" << endl;
	cout << "--------------------------------" << endl;
	cout << "Please choose a transformation" << endl;
	cout << "1) Translate" << endl;
	cout << "2) Scale" << endl;
	cout << "3) Rotate around X" << endl;
	cout << "4) Rotate around Y" << endl;
	cout << "5) Rotate around Z" << endl;
	cout << "6) Done" << endl;
	cout << "Enter selection: ";
	cin >> m;
	cout << endl;
	return m;
}

void MainMenu::initPoint(Point &p)
{
	float f[3];
	cout << "Enter initial point: ";
	cin >> f[0] >> f[1] >> f[2];
	p.set(f);
	return;
}

void MainMenu::translate(Point &p, Point &t)
{
	this->printHeader(p);
	this->math.translate(p, t);
	this->printFooter(p);
	return;
}

void MainMenu::scale(Point &p, Point &s)
{
	this->printHeader(p);
	this->math.scale(p, s);
	this->printFooter(p);
	return;
}

void MainMenu::rotx(Point &p, float r)
{
	r = degreeToRadian(r);
	this->printHeader(p);
	this->math.rotx(p, r);
	this->printFooter(p);
	return;
}

void MainMenu::roty(Point &p, float r)
{
	r = degreeToRadian(r);
	this->printHeader(p);
	this->math.roty(p, r);
	this->printFooter(p);
	return;
}

void MainMenu::rotz(Point &p, float r)
{
	r = degreeToRadian(r);
	this->printHeader(p);
	this->math.rotz(p, r);
	this->printFooter(p);
	return;
}

void MainMenu::printHeader(Point &p)
{
	cout << "Input point: ";
	p.print();
	cout << "Transformation matrix: " << endl;
	return;
}

void MainMenu::printFooter(Point &p)
{
	this->math.print();	// Print the last used work matrix
	cout << "Resultant point: ";
	p.print();
	return;
}

float MainMenu::degreeToRadian(float r)
{
	return r * PI / 180.0;
}
