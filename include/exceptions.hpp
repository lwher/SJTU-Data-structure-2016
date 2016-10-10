#ifndef SJTU_EXCEPTIONS_HPP
#define SJTU_EXCEPTIONS_HPP

#include <cstddef>
#include <cstring>
#include <string>

namespace sjtu 
{

class exception 
{
protected:
	const std::string variant = "";
	std::string detail = "";
public:
	exception() {}
	exception(const exception &ec) : variant(ec.variant), detail(ec.detail){}
	virtual std::string what() 
	{
		return variant + " " + detail;
	}
};
class index_out_of_bound : public exception 
{
protected:
	const std::string variant;
public:
	index_out_of_bound(const std::string &ec = std :: string("")) : variant(ec) { detail = "error : index out of bound.";}
	
	virtual std::string what() { return variant + " " + detail;}
};

class runtime_error : public exception 
{
protected:
	const std::string variant;
public:
	runtime_error(const std::string &ec = std :: string("")) : variant(ec) { detail = "error : runtime error.";}
	
	virtual std::string what() { return variant + " " + detail;}
};

class invalid_iterator : public exception 
{
protected:
	const std::string variant;
public:
	invalid_iterator(const std::string &ec = std :: string("")) : variant(ec) { detail = "error : invalid iterator.";}
	
	virtual std::string what() { return variant + " " + detail;}
};

class container_is_empty : public exception 
{
protected:
	const std::string variant;
public:
	container_is_empty(const std::string &ec = std :: string("")) : variant(ec) { detail = "error : container is empty.";}
	
	virtual std::string what() { return variant + " " + detail;}
};
}

#endif
