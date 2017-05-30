#pragma once
#include <string>

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
	HasPtr& operator=(const HasPtr& rhs)
	{
		delete ps;
		ps = new std::string(*rhs.ps);
		i = rhs.i;
		return *this;
	}
	~HasPtr()
	{
		delete ps;
	}
private:
	std::string *ps;
	int i;
};