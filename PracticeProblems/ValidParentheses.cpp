#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	return 0;
}

class Solution {
public:
    // The function return the correspongind closing parenthesis:
    char checkCloseParen (char paren)
    {
	switch (paren)
	{
	    case '(':
		return ')';
	    case '{':
		return '}';
	    case '[':
		return ']';
	    default:
		return 0;
	}
    }
    // The function returns true if the paren is an open one:
    bool isOpenParen( char paren)
    {
	switch (paren)
	{
		case '(':
		    return true;
		case '{':
		    return true;
		case '[':
		    return true;
		default:
		    return false;
	}
    }	
		
	
    // The function concatenates to a string:
    void addToStack (string& s, char paran)
    {
	s += paran;
    }

    // The function pop the last character of a string and returns it:
    char pop (string& s)
    {
	char tmp {s[s.size() - 1]};
	s.pop_back();
	return tmp;	
    }
	
    bool isValid(string s) {
	string stackParen;
	char tmp;	
	for (const char *p {s.c_str()}; *p != '\0'; ++p)
	{
	    if (isOpenParen(*p))
		addToStack (stackParen, *p);
	    else
	    {
		if (stackParen.size() == 0)
		    return false;

		tmp  = pop (stackParen);
		if (*p != checkCloseParen(tmp))		
		    return false;
	    }
	}
	if (stackParen.size() == 0)
		return true;
	return false;
    }
};
