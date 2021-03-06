// 11.9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Rectangle2D  {
	public:
		Rectangle2D() {
			x = 0;
			y = 0;
			width = 1;
			height = 1;
		}

		Rectangle2D(double a, double b, double widthparameter, double heightparameter) {
			x = a;
			y = b;
			width = widthparameter;
			height = heightparameter;
		}

	double setX(double a) const {
		a = x;
}

		double getX() const {
			return x;
	}

		double setY(double b) const {
			b = y;
		}

		double getY() const {
			return y;
		}
		
		double setWidth(double c) const {
			c = width;

		}
		
		double getWidth() const {
			return width;
		}

		double setHeight(double d) const {
			d = height;
		}

		double getHeight() const {
			return height;
		}

		double getArea() const {
			return height * width;
		}

		double getPerimeter() const {
			return 2 * (height + width);
		}

	
		
		bool contains(double x, double y) const {
			

		// If the parameter point at x is less than the width and the parameter point 
		// at y is less than height, the point is inside the rectangle.
			if (x < width && y < height)
				return true;
			else
				return false;
		}

		bool contains(const Rectangle2D& r) const {
			// These following equations are finding the four corners of the two different rectangles. 
			// Referencing the webstie below. They helped me figure out how to 
			// calculate the x and y coordinates of the four corners. 
			// https://math.stackexchange.com/questions/598270/how-can-i-figure-out-the-points-of-a-rectangle-by-just-knowing-the-origin-width
			
			// Top left corner
			double firstx = (1 / 2) * width;
			double firsty = (1 / 2) * height;

			// Top right
			double secondx = (-1 / 2) * width;
			double secondy = (1 / 2) * height;

			// Bottom left corner
			double thirdx = (-1 / 2) * width;
			double thirdy = (-1 / 2) * height;
			
			// Bottom right corner
			double fourthx = (1 / 2) * width;
			double fourthy = (-1 / 2) * height;

			double objectx1 = (1 / 2) * r.getWidth();
			double objecty1 = (1 / 2) * r.getHeight();
			double objectx2 = (-1 / 2) * r.getWidth();
			double objecty2 = (1 / 2) * r.getHeight();
			double objectx3 = (1 / 2) * r.getWidth();
			double objecty3 = (1 / 2) * r.getHeight();
			double objectx4 = (-1 / 2) * r.getWidth();
			double objecty4 = (1 / 2) * r.getHeight();

			// If all the object corners are less than the original rectangle,
			// then the rectangle will contain the object. 
			if (objectx1 < firstx && objecty1 < firsty && 
				objectx2< secondx && objecty2 < secondy &&
				objectx3 < thirdx && objecty3 < thirdy &&
				objectx4 < fourthx && objecty4 < fourthy ) 
				return true;
			else
				return false;
		}
			
		bool overlaps(const Rectangle2D &r) const {
			double firstx = (1 / 2) * width;
			double firsty = (1 / 2) * height;
			double secondx = (-1 / 2) * width;
			double secondy = (1 / 2) * height;
			double thirdx = (-1 / 2) * width;
			double thirdy = (-1 / 2) * height;
			double fourthx = (1 / 2) * width;
			double fourthy = (-1 / 2) * height;

			double objectx1 = (1 / 2) * r.getWidth();
			double objecty1 = (1 / 2) * r.getHeight();
			double objectx2 = (-1 / 2) * r.getWidth();
			double objecty2 = (1 / 2) * r.getHeight();
			double objectx3 = (1 / 2) * r.getWidth();
			double objecty3 = (1 / 2) * r.getHeight();
			double objectx4 = (-1 / 2) * r.getWidth();
			double objecty4 = (1 / 2) * r.getHeight();

			// If the coordinate of x and y corner in the object inputted is less than or equal
			// to any corners of the default rectangle, then the rectangles overlap.
			// 
			if (objectx1 <= firstx && objecty1 <= firsty ||
				objectx2 <= secondx && objecty2 <= secondy ||
				objectx3 <= thirdx && objecty3 <= thirdy ||
				objectx4 <= fourthx && objecty4 <= fourthy)
				return true;
			else
				return false;
		}

	private:
		double x;
		double y;
		double width;
		double height;


		};

int main()
{

	Rectangle2D r1(2, 2, 5.5, 4.9);
	Rectangle2D r2(4, 5, 10.5, 3.2);
	Rectangle2D r3(3, 5, 2.3, 5.4);

	cout << "The area for r1 is " << r1.getArea() << endl;
	cout << "The perimeter for r1 is " << r1.getPerimeter() << endl;

	if (r1.contains(3, 3) == true) {
		cout << "The specified point is inside this rectangle ";
		if (r1.contains(3, 3) == false) {
			cout << "The specified point is outside this rectangle ";
		}
		cout << endl;

		if (r1.contains(r2) == true)
			cout << "The specified rectangle is inside this rectangle";
		if (r1.contains(r2) == false)
			cout << "The specified rectangle is not inside this rectangle ";

		cout << endl;

		if (r1.overlaps(r3) == true) {
			cout << "The specified rectangle overlaps this rectangle ";
		}
		if (r1.overlaps(r3) == false) {
			cout << "The specified rectangle does not overlap this rectangle ";
		}
		cout << endl;
		return 0;
	}

}