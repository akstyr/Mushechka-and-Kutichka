#pragma once

class Sort
{
public:
	int NumSwaps = 0;
	int NumComp = 0;
public:
	Sort() {};
	virtual ~Sort() {};
	virtual unsigned int MetodSort() const = 0;
};