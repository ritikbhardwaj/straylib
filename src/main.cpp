#include <iostream>
#include "app.hpp"

int main(void)
{
    App* appInstance = App::getAppInstance(800, 450, "My application");
    appInstance->initApp();
    return 0;
}