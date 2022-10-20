#include "App.h"
#include "Manager.h"
#include <iostream>

class MyApp : public App {

    void startup() override {
        //data = Manager.getData();
    }

	void update() override {

        numbers = Manager.Sorter->getNumbers();
        cursorPos = *Manager.Sorter->getCursorPos();
        cursorVal = (*numbers)[cursorPos];
       
        ImPlot::BeginPlot("Bar Plot");
        ImPlot::PlotBars("Vertical", numbers->data(), Manager.length);
        ImPlot::PlotBars("Cursor", &cursorPos, &cursorVal, 1, 1.0);
        ImPlot::EndPlot();

        if (ImGui::Button("Start"))
            Manager.startSort(); 
        ImGui::SameLine();
        if (ImGui::Button("Stop"))
            Manager.stopSort();
        ImGui::SameLine();
        if (ImGui::Button("Shuffle"))
            Manager.doShuffle();

	}

private:
    const std::vector<unsigned>* numbers = nullptr;
    MyManager Manager;
    unsigned cursorPos = 0;
    unsigned cursorVal = 0;

};

int main(int argc, char* args[]) {
	MyApp app;
    app.Run();
    return 0;
}