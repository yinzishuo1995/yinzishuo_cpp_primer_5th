#include <map>
#include <string>
#include <set>
#include <iostream>

int main()
{
	std::multimap<std::string, std::string> yinzishuo_musiclist{ {"placebo", "drag"},{"Avril", "How Does It Feel"},{"Avril", "My Happy Ending"} };
	std::map<std::string, std::set<std::string>> unique_list;
	for (const auto &multi : yinzishuo_musiclist)
		unique_list[multi.first].insert(multi.second);
	for (const auto &unique : unique_list) {
		std::cout << unique.first << std::endl;
		for (const auto &set : unique.second)
			std::cout << '\t' << set << std::endl;
	}
		
	system("pause");
	return 0;
}