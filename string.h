#pragma once
#include <iostream>
using namespace std;


class String 
{
    private:
    char *str;

    public:
    
    String ();
    String (const char *s);
    String (char c);
    String (const String &other);
    String &operator=(const String &other);
    ~String();

    void print ();
    String operator+ (char c);
    String operator+ (String other);
    bool operator== (String other);
    bool operator< (String other);
    size_t length () const;
    char& operator[] (size_t position);
    const char& operator[] (size_t position) const;
    String operator= (char c);
    friend ostream& operator<< (ostream& out, const String &s);
    friend istream& operator>> (istream& in, String& s);
    friend String operator+ (char c, String s);
    String toUpper (String s);
    bool isInt(String str);
};


String toString (unsigned int x);


