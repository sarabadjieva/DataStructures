#pragma once
#include <string>

class GenericException
{
private:
	std::string errorMsg;
public:
	GenericException(const std::string& err) { errorMsg = err; }
	std::string getMessage() const { return errorMsg; }
};

