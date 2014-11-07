#pragma once

#include <sstream>

namespace utils
{
	template<class From, class To>
	To lexical_cast(const From& from)
	{
		std::stringstream str;
		str << from;
		To to;
		str >> to;
		return to;
	}
};
