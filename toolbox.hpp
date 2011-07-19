#ifndef TOOLBOX_HPP
#define TOOLBOX_HPP

// includes
#include <sstream>

namespace Toolbox
{
	static std::string itos(int num)
	{
		std::ostringstream str; 
		str << num; 
		return str.str();
	}	
}
#endif