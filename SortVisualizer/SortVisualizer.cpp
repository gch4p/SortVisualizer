#include "SortVisualizer.h"


void MyApp::startup() {
	//startup
}

void MyApp::update() {

	numbers = Manager.Sorter->getNumbers();
	cursorPos = *Manager.Sorter->getCursorPos();
	cursorVal = (*numbers)[cursorPos];

	const char* sorts[] = { "Bubble Sort","Insertion Sort","Selection Sort","Gnome Sort","Pancake Sort","Cocktail Sort"};
	ImGui::PushItemWidth(130);
	if (ImGui::Combo("##", &currentSort, sorts, IM_ARRAYSIZE(sorts)))
		Manager.setSort(currentSort);
	ImGui::PopItemWidth;

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
	ImGui::SameLine();
	if (ImGui::SliderInt("Delay", &delay, 1, 50))
		Manager.setDelay(delay);
	ImGui::Separator();

	float plotHeight = ImGui::GetWindowContentRegionMax().y - 80;

	if (ImPlot::BeginPlot("##Plot", { -1,plotHeight }, ImPlotFlags_CanvasOnly)) {
		ImPlot::SetupAxes(nullptr, nullptr, ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_NoDecorations);
		ImPlot::PlotBars("Data", numbers->data(), Manager.length);
		ImPlot::PlotBars("Cursor", &cursorPos, &cursorVal, 1, 1.0);
		ImPlot::EndPlot();
	}

}


int main(int argc, char* args[]) {
	MyApp app;
	app.Run();
	return 0;
}