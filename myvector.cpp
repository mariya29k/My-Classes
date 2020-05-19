#pragma once

#include <iostream>
#include "myvector.h"

using namespace std;

    template <class T>
    Vector<T>::Vector ()
    {
        size = 0;
        data = nullptr;
    }

    template <class T>
    Vector<T>::Vector (const Vector<T>& v) //copy constructor
    {
        this->size=v.size;
        this->data= new T [v.size];
        for(size_t i = 0; i<size; ++i)
        {
            this->data[i]=v.data[i];
        }
        
    }

    template <class T>
    void Vector<T>::push_back (const T& x) //T e mnogo golqm type, primerno vektor ot studenti
    {
        //data-> [1,2,3,4,5,6,7,8]; size=8;

       T *biggerBiffer = new T[size+1];
       for (size_t i=0; i<size; ++i)
       {
           biggerBiffer[i] = data[i];
        }
        biggerBiffer[size]=x;
        ++size;
        
        delete []data; //osvobojdavame pametta ot data

        data = biggerBiffer;

    }

    template <class T>
    void Vector<T>::push (const T& x)
    {
        T *biggerBiffer = new T[size+1];
       for (size_t i=0; i<size; ++i)
       {
           biggerBiffer[i+1] = data[i];
        }
        biggerBiffer[0]=x; //sushtoto kato push_back samo che mestim elementite v dr posoka
        ++size;
        
        delete []data; //osvobojdavame pametta ot data

        data = biggerBiffer;

    }

    //metod, koito trie daden element ot vektor
    template <class T>
    void Vector<T>:: erase(const size_t& position) 
    {
        T *newBuffer = new T[size-1];

        for(size_t i=position; i<size-1; i++)
        {
            newBuffer[i]=data[i+1];   
        }
        delete []data;
        data = newBuffer;

    }

    template <class T>
    Vector<T>& Vector<T>::operator+= (const T& x)
    {
        this->push_back(x);
        return *this;
    }

    template <class T>
    Vector<T> Vector<T>::operator+ (const T& x) const
    {
        Vector<T> result(*this);
        result+=x;
        return result;
    }

    template <class T>
    Vector<T>& Vector<T>::operator+= (const Vector<T>& other)
    {
        T *newBuffer = new T [this->size+other.size];
        for (size_t i = 0; i< this->size; ++i)
        {
            newBuffer[i] = data.size[i];
        }
        for (size_t i=0; i< other.size; ++i)
        {
            newBuffer [this->size + i] = other.data[i];
        }

        delete []this->data;
        this->data=newBuffer;
        this->size = this->size + other.size;

        return *this;
    }

    template <class T>
    Vector<T> Vector<T>::operator+ (const Vector<T>& other) const
    {
        Vector<T> result;
        

        result.data = new T [this->size + other.size];
        for (size_t i=0; i < this->size; ++i) 
        {
            result.data[i]= this->data[i];
        }
        for (size_t i=0; i < other.size; ++i) 
        {
            result.data[this->size+i]= other.data[i];
        }

        result.size= this->size + other.size;
        return result;

    }

    template <class T>
    T& Vector<T>::operator[] (size_t i)
    {
        
       return data[i];
    }

    template <class T>
    T Vector<T>::operator[] (size_t i) const
    {
       return data[i];
    }
    
    template <class T>
    Vector<T>& Vector<T>::operator= (const T& v)
    {
        if (this != &v)
        {
            delete []data;

            this->size = v.size;
            this->data = new T [v.size];
            for (size_t i=0; i<size; i++)
            {
                this->data[i]=v.data[i];
            }
        }

        return *this;
    }

    template<class T>
    bool Vector<T>::operator!= (const Vector<T>& other) const
    {
        return !(*this == other);
    }

    template<class T>
    bool Vector<T>::operator== (const Vector<T>& other) const
    {        
        if (this->size != other.size)
        {
            return false;
        }

        for (size_t i = 0; i < size; ++i)
        {
            if (data[i] != other.data[i])
            {
                return false;
            }
        }

        return true;
    }
    
    // ako iskame da dostupvame method na obekt, koito e konstanten, vs methodi trqbva da deklarirat, che nqma da promenqt vektora
    template <class T>
    size_t Vector<T>::length () const //metod, koito dava dostup do stoinostta na poleto i ne pozvolqva tova pole da bude promenqno; naricha se sushto accsesor
    {
       return size; 
    }

/* //tozi begin e iterator
    template<class T>
    const_iterator Vector<T>:: begin() const 
		{	// return iterator for beginning of nonmutable sequence
		return (const_iterator(this->_Myfirst(), &this->_Get_data()));
		}
*/

    template <class T>
    Vector<T>::~Vector () 
    {
        delete []data;  
    }

};
template <class T>
ostream& operator << (ostream& stream, const Vector<T>& v)
{
    
    for (size_t i = 0; i < v.length(); i++)
    {
        stream << v[i] << " ";
    }
    return stream;

}
