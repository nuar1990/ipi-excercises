#include <iostream>
#include <cmath>
using namespace std;

class Point2D {
private:
  double x, y;
  
public:
  Point2D():x(0),y(0){}
  Point2D(double xNew, double yNew):x(xNew),y(yNew){}

  void setX(double xNew){
	  this->x=xNew;
  }
  void setY(double yNew){
	  this->y=yNew;
  }

  double getX() const{
	  return this->x;
  }
  double getY() const{
	  return this->y;
  }

  double calcDistance(const Point2D& newPoint) const{
	  //connecting vector coordinates P1&P2
	  double xNew=this->x-newPoint.getX();
	  double yNew=this->y-newPoint.getY();
	  //return length of connecting vector=distance
	  return sqrt(pow(xNew,2)+pow(yNew,2));
  }
  // d)
  /* 	I assume the exercise wanted to demonstrate how members, which are declared private can't be accessed by the children class.
  	  	There are several ways to bypass that problem:
  	  	1. Make the members public/protected(children only) - which is probably the worst solution(you don't want your members to be touched by outside references )
  	  	2. Declaration of a friend class like it is done here, this is basically the same thing as protected however, its not bound to inheritance and can be used
  	  	in a broader sense - for every class.
  	  	3. Children classes can use setMethods of the parent class to access the members ----> therefore this exercise was kinda redundant.
  	  	4. C++ is also able to initialize a children class by calling an constructor of the parent in the initializiation list, this makes the friend decleration just as redundant.
  */
  friend class Point3D;  //<--- however here is where the cookie crumbles, forward decl. of a friend class
  virtual ~Point2D(){}
};

class Point3D: public Point2D {
private:
	double z;
public:
	Point3D():z(0){}
	Point3D(double xNew,double yNew, double zNew):Point2D(xNew,yNew),z(zNew){}
	virtual ~Point3D(){}

	void setZ(double zNew){
		this->z=zNew;
	}
	double getZ() const{
		return this->z;
	}
	double calcDistance(const Point3D& newPoint) const{
		//connecting vector coordinates P1&P2&P3
		double xNew=this->getX()-newPoint.getX();
		double yNew=this->getY()-newPoint.getY();
		double zNew=this->z-newPoint.getZ();

		//return length of connecting vector=distance
		return sqrt(pow(xNew,2)+pow(yNew,2)+pow(zNew,2));
	}
};

int main() {
	Point2D P1=Point2D(2.0,5.0);
	Point2D P2=Point2D(3.0,-3.0);
	Point3D P3=Point3D();
	P3.setX(2);
	P3.setY(5);
	P3.setZ(4);
	Point3D P4=Point3D(3,-3,0);
	cout<<"Distance of P1_P2: ";
	cout<<P1.calcDistance(P2)<<endl;
	cout<<"Distance of P3_P4: ";
	cout<<P3.calcDistance(P4)<<endl;

	return 0;
}
