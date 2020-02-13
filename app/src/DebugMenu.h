#pragma once

#include <map>
#include <memory>
#include <typeindex>
#include <vector>
#include <string>

#include <imgui.h>

class IDebugModule {
public:
	virtual ~IDebugModule() = default;

	virtual const char* GetTitle() = 0;
	virtual void Render()          = 0;
};

class DebugMenu {
public:
	DebugMenu(const char* title);
	void Render();

	template <class T, class... Args>
	void RegisterModule(Args&&... args) {
		auto id = std::type_index(typeid(T));
		if (mModules.find(id) == mModules.end()) {
			mModules[id] = ModuleEntry{std::make_unique<T>(args...)};
			mModuleOrder.emplace_back(id);
		}
	}

	template <class T>
	T& Get() {
		auto id = std::type_index(typeid(T));
		return static_cast<T&>(*mModules.at(id).mModule);
	}
	template <class T>
	const T& Get() const {
		auto id = std::type_index(typeid(T));
		return static_cast<T&>(*mModules.at(id).mModule);
	}

private:
	template <class T>
	void Invoke(const T& data) {
		mListeners[std::type_index(typeid(T))]();
	}

	struct ModuleEntry {
		std::unique_ptr<IDebugModule> mModule;
	};

	std::string mTitle = "Debug Menu";
	std::map<std::type_index, ModuleEntry> mModules;
	std::vector<std::type_index> mModuleOrder;
};