#pragma once
#include <memory>
#include <string>
#include <vector>
#include <initializer_list>

class StrBlob {
public:
	using size_type = std::vector<std::string>::size_type;
	StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
	StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}
	StrBlob(const StrBlob&);
	StrBlob& StrBlob::operator=(const StrBlob& sb)
	{
		data = std::make_shared<std::vector<std::string>>(*sb.data);
		return *this;
	}



	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	
	void push_back(const std::string& s) { data->push_back(s); };
	void pop_back()
	{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}

	std::string& front()
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}

	std::string& back()
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}

	const std::string& front() const
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}
	const std::string& back() const
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string& msg) const
	{
		if (i >= data->size()) throw std::out_of_range(msg);
	}

};