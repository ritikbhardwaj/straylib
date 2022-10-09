#include <iostream>
#include "app.hpp"

int main(void)
{
    App* appInstance = App::getAppInstance(1280, 720, "My application");
    appInstance->initApp();
    return 0;
}