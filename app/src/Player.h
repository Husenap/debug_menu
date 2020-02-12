#pragma once

#include "DebugMenu.h"

class Player {
public:
	void SetShinMode(bool enabled) { std::cout << "Shin Mode: " << enabled << std::endl; }
	void SetLocation(float location) { std::cout << "Player location: " << location << std::endl; }

private:
};

class PlayerDebugModule : public DebugModule {
public:
	PlayerDebugModule(Player& player)
	    : mPlayer(player) {}

	const char* GetTitle() { return "Player Module##player_module"; }

	void Render() override {
		if (ImGui::SliderFloat("location", &location, 0.f, 1.f)) {
			mPlayer.SetLocation(location);
		}
		if (ImGui::Checkbox("shin mode", &shinMode)) {
			mPlayer.SetShinMode(shinMode);
		}
	}

private:
	Player& mPlayer;
	float location = 0.5f;
	bool shinMode  = false;
};