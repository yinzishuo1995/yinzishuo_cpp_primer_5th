#include <map>
#include <string>
#include <iostream>

int main()
{
	std::multimap<std::string, std::string> authors{ {"yinzishuo", "c++"}, {"yinzishuo", "abc"}, {"leeminho", "adsfs"} };
	auto found = authors.find("yinzishuo");
	if (found != authors.end())
		if (found->second == "c++")
			found = authors.erase(found);
	for (const auto &a : authors)
		std::cout << a.first << a.second << std::endl;
	system("pause");
	return 0;
}