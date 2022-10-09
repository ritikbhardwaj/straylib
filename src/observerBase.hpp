#pragma once

/** Acts as in interface */
class ObserverBase
{
    public:
        virtual void notify(const int& value) const = 0;
        virtual ~ObserverBase();
};
