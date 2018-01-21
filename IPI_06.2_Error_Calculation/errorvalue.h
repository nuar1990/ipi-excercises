/*
 * errorvalue.h
 *
 *  Created on: Dec 2, 2017
 *      Author: nuar
 */

#ifndef ERRORVALUE_H_
#define ERRORVALUE_H_

class ErrorValue {
private:
	double w;
	double abs_error;
public:
	ErrorValue();
	ErrorValue(double w, double abs_error);
	void setW(double w);
	void set_abs_error(double abs_error);
	double value()const;
	double absolute()const;
	double relative();
	ErrorValue operator+(const ErrorValue& b);
	ErrorValue fromMeasurements(double* values,int N);

	virtual ~ErrorValue();
};

#endif /* ERRORVALUE_H_ */
