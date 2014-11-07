#pragma once

#include <map>
#include <string>

#include <xlib/Utils.hpp>

class XMLTree
{
public:
	class Tag
	{
	public:
		typedef std::map<std::string, std::string> attrs_t;
		typedef attrs_t::iterator attr_iterator;
		typedef attrs_t::const_iterator attr_const_iterator;
		typedef std::multimap<std::string, Tag*> childs_t;
		typedef childs_t::iterator tag_iterator;
		typedef childs_t::const_iterator tag_const_iterator;
		
		template<class T>
		T get_attribute(const std::string& name, T default_value = T())
		{
			attr_iterator ait = attrs_.find(name);
			if(ait != attrs_.end()) {
				return lexical_cast<T>(ait->second);
			}
			return default_value;
		}
		template<class T>
		void set_attr(const std::string& name, const T& value);

		attr_iterator attr_begin();
		attr_iterator attr_end();
		attr_const_iterator attr_begin() const;
		attr_const_iterator attr_end() const;
		
		tag_iterator tag_begin();
		tag_iterator tag_end();
		tag_const_iterator tag_begin() const;
		tag_const_iterator tag_end() const;
		
		template<class Stream>
		void print(Stream stream, int depth = 0);
			
	private:
		std::string name;
		Tag* parent_;
		attrs_t attrs_;
		childs_t childs_;
	};
	
	Tag* get_root_tag();
	const Tag* get_root_tag() const;
	
private:
	std::string filename_;
	Tag* root_tag_;	
};
