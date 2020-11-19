#ifndef pendulum_h
#define pendulum_h

//Pendulum class
class CPendulum
{
private:
	double length_; //  meters
	double gravity_; //  m/s²

public:
	CPendulum (double length_ = 1, double gravity_ = 9.81);
	double getL(void) const;
	double getG(void) const;
	void setL(double l_);
	void setG(double g_);
	void setLG(double l_, double g_);
	double getPeriod(void) const;
	double getFrequency(void) const;
	void print() const;
};

#endif
