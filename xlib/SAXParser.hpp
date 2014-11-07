#pragma once
#include <list>

class ErrorHandler;
class DocumentHandler;

class SAXParser
{
	void add_error_handler(ErrorHandler* eh);
	void add_document_handler(DocumentHandler* dh);
	void clear();
	void parse(const std::string filepath);

private:
	std::list<ErrorHandler*> error_handlers_;
	std::list<DocumentHandler*> document_handlers_;
};
