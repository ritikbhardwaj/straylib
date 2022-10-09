#include "subject.hpp"
#include "observerBase.hpp"
#include <iostream>


template<typename attachType>
void Subject<attachType>::attach(const ObserverBase& o)
{
    _observers.push_back(o);
}

template<typename attachType>
void Subject<attachType>::notify(const int& value) const
{
    for(auto& i : _observers)
    {
        i.notify(value);
    }
}

template<typename attachType>
void Subject<attachType>::detach(const ObserverBase& o)
{
    std::cout << "Detach" << std::endl;
}