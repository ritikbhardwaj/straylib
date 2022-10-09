#pragma once

class App
{
    public:
        static App* getAppInstance(const int& width, const int& height, const char* title);
        void initApp();
    private:
        App(const int& width, const int& height, const char* title);
        ~App();
        static App* _instance;
        int _width;
        int _height;
        const char* _title;
};
