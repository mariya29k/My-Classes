#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

template <class T> //zashtoto iskame da si polzvame tozi klas i s double i tn....
class Vector
{   
    private: //vidimost - do private nqma dostup // tova e osnovnata razlika mejdu struct i vektor
    T *data;
    size_t size;

    public:
    Vector ();
    Vector (const Vector<T>& v); //copy constructor
    void push_back (const T& x); //T e mnogo golqm type, primerno vektor ot studenti
    void push (const T& x);
    void erase(const size_t& position);
    Vector<T>& operator+= (const T& x);
    Vector<T> operator+ (const T& x) const;
    Vector<T>& operator+= (const Vector<T>& other);
    Vector<T> operator+ (const Vector<T>& other) const;
    T& operator[] (size_t i);
    T operator[] (size_t i) const;
    Vector<T>& operator= (const T& v);
    bool operator!= (const Vector<T>& other) const;
    bool operator== (const Vector<T>& other) const;
    size_t length () const; 
    void begin() const ;
    

    ~Vector (); 
    
};

template <class T>
ostream& operator<< (ostream& stream, const Vector<T>& v);