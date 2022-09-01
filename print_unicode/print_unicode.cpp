#include <iostream>
#include <string>
#include <boost/locale.hpp>
#include <unicode/unistr.h>
#include <unicode/ustream.h>

std::string codepoint_to_utf8(char32_t codepoint) {
	return boost::locale::conv::utf_to_utf<char>(&codepoint, &codepoint + 1);
}

int main()
{
	
	for (unsigned int i{ 0x1F300 }; i < 0x1F400; ++i)
	{
		std::cout << codepoint_to_utf8(i);
	}

	std::cout << std::endl;

	for (int32_t  i{ 0x1F400 }; i < 0x1F500; ++i)
	{
		std::cout << icu::UnicodeString{ i };
	}

	std::cout << std::endl;
}
