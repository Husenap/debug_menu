#include "DebugMenu.h"

#include <imgui.h>

void DebugMenu::Render() {
	ImGui::Begin("debug menu LOL");

	for (const auto& moduleId : mModuleOrder) {
		auto& module = mModules.at(moduleId).mModule;
		if (ImGui::CollapsingHeader(module->GetTitle())) {
			module->Render();
		}
	}

	ImGui::End();
}
