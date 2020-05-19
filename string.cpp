#include <iostream>
#include <cstring>
#include "string.h"

using namespace std;

    //konstruktor po podrazbirane - bez parametur
    String::String ()
    {
        str = nullptr; 
    }
    
    String::String (const char *s)
    {
        str = new char [strlen(s) + 2];
        strcpy(str,s);
        str [length() + 1] = '\0';
    }

    String::String (char c)
    {
        str = new char[2];
        str[0] = c;
        str[1] = '\0';
    }

    String::String (const String &other)
    {
        str = new char [other.length() + 1];
        strcpy (str, other.str);
    }

    String &String::operator=(const String &other)
    {
        if (this != &other)
        {
            delete[] str;
            str = new char[other.length() + 1];
            strcpy(str, other.str);
        }
            return *this;
    }

    //destruktor
    String::~String()
    {
        delete[] str;
    }

    /* //i don't think i need it anymore
    void String::init (const char *s)
    {
        str = new char [strlen(s)+1];
        strcpy(str,s);
    }
    */

    //s1.print()
    void String::print (){
        cout<<str<<endl;
    }

    String String::operator+ (char c)
    {
        String result;
        //this->str = a b c \0 ... |+ z
        result.str = new char [length() + 1 + 1];
        //X X X X X 5 elementa, za noviq element i \0
        strcpy (result.str, str);
        //a b c \0 X
        result.str[this->length()] = c;
        //a b c z X
        result.str[this->length()+1] = 0;
        // a b c z \0
        return result;
    }

    


    //vmesto imeto concat pishem operator+ za da imame s1 + s2 
    //operator e key word
    String String::operator+ (String other)
    {
        String result;
        result.str= new char[strlen(str)+strlen(other.str)+1];

        strcpy(result.str, str);
        strcat(result.str, other.str);

        return result;
    }

    //if(s1==s2)
    bool String::operator== (String other)
    {
        return strcmp (str, other.str) == 0;
    }
    
    bool String::operator< (String other)
    {
        return strcmp (str, other.str) < 0;
    }

    size_t String::length () const
    {  
        if(str != nullptr)
        {
        return strlen(str);
        }
    }


    char& String::operator[] (size_t position)
    {
        return str[position];
    }

    const char& String::operator[] (size_t position) const
    {
        return str[position];
    }

    String String::operator= (char c)
    {
        delete[] str;
        str = new char[2];
        str[0]=c;
        str[1]='\0';
        return *this;
        //int x = 5;
        //int *px = &x;
        //*px =6;
    }

    
ostream& operator<< (ostream& out, const String &s)
{
    out<<s.str;
    return out;
}

istream& operator>> (istream& in, String& s)
{
    char c;
    do
    {   
        in.get(c);

        if( c!= '\n')
        {
            s = s + c;
        }

    } while (c!= '\n');

    return in;
}

    /*
    void append(char* s, char c)
    {
    
        s[lenght()] = c;
        s[length() + 1] = '\0';
    }
    */  

String operator+ (char c, String s)
{
    String result;

    result = c;
    result = result + s;

    return result;
}

String toString (unsigned int x)
{
    String result;

    if (x<10)
    {
        //result.operator= ('0'+x)
        result = '0' + x;
        
        return result;
    }
    while(x>0)
    {   
        //A @ B
        // A.operator@(B)
        //result.operator+ ('0' + x%10)
        //izvajdaneto na operatora izvun klasa ni pozvolqva sami da opredelim reda na operandite
        result = ('0' + x%10) + result ; 
        x /= 10;
    }
    return result;
}

String String::toUpper (String s)
{
    String result = s.str; //veche moje da inicializirame nizove kato " " ili s *char

    for (size_t i=0; i<s.length(); i++)
    {
        if (result[i] >= 'a' && result[i] <= 'z')
        {
            //s.getAt(i) = s.getAt(i) + ('A' - 'a')
            result[i] = result[i] + ( 'A' - 'a');
        }
    }
    return result;
}

bool String::isInt(String str) 
{
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] >= '0' && str[i] <= '9') 
        {
            continue;
        } else return false;
        
    }
    return true;
}

/*
//copied from GeeksforGeeks
int myAtoi(char* str) 
{ 
    int res = 0; // Initialize result 
  
    // Iterate through all characters of input string and 
    // update result 
    for (int i = 0; str[i] != '\0'; ++i) 
        res = res * 10 + str[i] - '0'; 
  
    // return result. 
    return res; 
} 
*/


