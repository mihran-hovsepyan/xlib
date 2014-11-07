#pragma once

#include <string>

class ErrorHandler
{
	virtual ~ErrorHandler() {}
	virtual void process_warning(const std::string& message) = 0;
	virtual void process_error(const std::string& message) = 0;
	virtual void process_fatal_error(const std::string& message) = 0;
};
