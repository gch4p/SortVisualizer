#include "App.h"
#include "Manager.h"
#include <iostream>

class MyApp : public App {

    void startup() override;

    void update() override;

private:
    const std::vector<unsigned>* numbers = nullptr;
    MyManager Manager;
    unsigned cursorPos = 0;
    unsigned cursorVal = 0;
    int delay = 10;
    int currentSort = 0;
};

int main(int argc, char* args[]);