#include "App.h"
#include "Manager.h"
#include <iostream>

class MyApp : public App {

    void startup() override {
        //startup
    }

	void update() override {

        numbers = Manager.Sorter->getNumbers();
        cursorPos = *Manager.Sorter->getCursorPos();
        cursorVal = (*numbers)[cursorPos];
        
        const char* sorts[] = { "Bubble Sort","Insertion Sort" };
        ImGui::Combo("Sort", &currentSort, sorts, IM_ARRAYSIZE(sorts));
        if (currentSort != Manager.sortID)
            Manager.setSort(currentSort);

        if (ImGui::Button("Start"))
            Manager.startSort();
        ImGui::SameLine();
        if (ImGui::Button("Stop"))
            Manager.stopSort();
        ImGui::SameLine();
        if (ImGui::Button("Shuffle"))
            Manager.doShuffle();
       
        ImPlot::BeginPlot("Bar Plot");
        ImPlot::PlotBars("Vertical", numbers->data(), Manager.length);
        ImPlot::PlotBars("Cursor", &cursorPos, &cursorVal, 1, 1.0);
        ImPlot::EndPlot();

	}

private:
    const std::vector<unsigned>* numbers = nullptr;
    MyManager Manager;
    unsigned cursorPos = 0;
    unsigned cursorVal = 0;
    int currentSort = 0;

};

int main(int argc, char* args[]) {
	MyApp app;
    app.Run();
    return 0;
}