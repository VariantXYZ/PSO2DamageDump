#include <string>

void strReplace(std::wstring &s, const std::wstring &search, const std::wstring &replace)
{
	for (size_t pos = 0; ; pos += replace.length())
	{
		pos = s.find(search, pos);
		if (pos == std::wstring::npos)
			break;
		s.erase(pos, search.length());
		s.insert(pos, replace);
	}
}
