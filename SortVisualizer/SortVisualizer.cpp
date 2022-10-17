#include "App.h"
#include "Manager.h"
#include <iostream>

class MyApp : public App {

    void startup() override {
        //data = Manager.getData();
    }

	void update() override {

        numbers = Manager.getData();
       
        ImPlot::BeginPlot("Bar Plot");
        //ImPlot::PlotBars("Vertical", data, 4);
        ImPlot::PlotBars("Vertical", numbers->data(), Manager.length);
        ImPlot::EndPlot();

        if (ImGui::Button("Show Length")) {
            std::cout << Manager.length << std::endl;
        } ImGui::SameLine();
        if (ImGui::Button("Show Data")) {
            for (int i = 0; i < Manager.length; ++i)
                std::cout << (*numbers)[i] << " ";
            std::cout << std::endl;
        } ImGui::SameLine();
        if (ImGui::Button("Start"))
            Manager.startSort(); 
        ImGui::SameLine();
        if (ImGui::Button("Stop"))
            Manager.stopSort();
        ImGui::SameLine();
        if (ImGui::Button("Shuffle"))
            Manager.doShuffle();

        //ImPlot::ShowDemoWindow();
	}

private:
    const std::vector<unsigned>* numbers = nullptr;
    MyManager Manager;
};

int main(int argc, char* args[]) {
	MyApp app;
    app.Run();
    return 0;
}