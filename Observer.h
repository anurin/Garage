#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observer {
public:
	virtual void Update(unsigned long long) = 0;
};

#endif