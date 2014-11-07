#pragma once

#include <map>
#include <string>

class DocumentHandler
{
	virtual ~DocumentHandler() {}
	virtual void process_document_start() = 0;
	virtual void process_document_end() = 0;
	virtual void process_tag_start(const std::string& name, const std::map<std::string, std::string>& attrs) = 0;
	virtual void process_tag_end(const std::string& name) = 0;
	virtual void process_value(const std::string& value) = 0;
};
