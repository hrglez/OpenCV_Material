#ifndef point_h
#define point_h

//Point class
class CPoint
{
private:
	int x_;
	int y_;

public:
	CPoint (int x_=0, int y_=0);
	int getX(void) const;
	int getY(void) const;
	void setX(int x_);
	void setY(int y_);
	void setXY(int x_, int y_);
	double getMagnitude(void) const;
	double getArgument(void) const;
	void print() const; 

};

#endif
