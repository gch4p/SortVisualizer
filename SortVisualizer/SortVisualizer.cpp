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
        ImGui::PushItemWidth(130);
        ImGui::Combo("##", &currentSort, sorts, IM_ARRAYSIZE(sorts));
        ImGui::PopItemWidth;

        if (currentSort != Manager.sortID)
            Manager.setSort(currentSort);

        ImGui::BeginDisabled(Manager.Sorter->isRunning()); {
            if (ImGui::Button("Start"))
                Manager.startSort();
        }
        ImGui::EndDisabled();
        ImGui::SameLine();
        
        if (ImGui::Button("Stop"))
            Manager.stopSort();
        ImGui::SameLine();
        if (ImGui::Button("Shuffle"))
            Manager.doShuffle();
        ImGui::Separator();

        float plotHeight = ImGui::GetWindowContentRegionMax().y - 80;
       
        if (ImPlot::BeginPlot("##Plot", { -1,plotHeight }, ImPlotFlags_NoMenus | ImPlotFlags_NoMouseText )) {
            ImPlot::PlotBars("Data", numbers->data(), Manager.length);
            ImPlot::PlotBars("Cursor", &cursorPos, &cursorVal, 1, 1.0);
            ImPlot::EndPlot();
        }

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