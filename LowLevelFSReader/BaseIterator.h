#pragma once
template <class Element> class BaseIterator
{
public:
	virtual void First() {};
	virtual void Next() {};
	virtual bool IsDone() {
		return true;
	};
	Element GetCurrent() {};
	BaseIterator() {};
	~BaseIterator() {};
};

