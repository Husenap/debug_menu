#include "DebugMenu.h"

#include <imgui.h>

DebugMenu::DebugMenu(const char* title)
    : mTitle(title) {}

void DebugMenu::Render() {
	if (ImGui::Begin(mTitle.c_str())) {
		for (const auto& moduleId : mModuleOrder) {
			auto& module = mModules.at(moduleId).mModule;
			if (ImGui::CollapsingHeader(module->GetTitle())) {
				module->Render();
			}
		}

		ImGui::End();
	}
}
