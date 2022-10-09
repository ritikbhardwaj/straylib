#pragma once

#include "observerBase.hpp"
#include <vector>

template<typename attachType>
class Subject
{
    public:
        Subject();
        ~Subject();
        void attach(const ObserverBase& o);
        void notify(const int& value) const;
        void detach(const ObserverBase& o);
    private:
        std::vector<attachType> _observers;
};
