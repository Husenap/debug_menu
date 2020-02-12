#pragma once

#include "DebugMenu.h"

class Player {
public:
	void Render() {
		ImGui::Begin("Player");

		ImGui::Text("location: %f", mLocation);
		ImGui::Text("shin mode: %d", mShinMode);

		ImGui::End();
	}

	void SetShinMode(bool enabled) { mShinMode = enabled; }
	void SetLocation(float location) { mLocation = location; }
	float GetLocation() const { return mLocation; }
	bool GetShinMode() const { return mShinMode; }

private:
	float mLocation = 0.5f;
	bool mShinMode  = false;
};

class PlayerDebugModule : public DebugModule {
public:
	PlayerDebugModule(Player& player)
	    : mPlayer(player)
	    , location(player.GetLocation())
	    , shinMode(player.GetShinMode()) {}

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
	float location;
	bool shinMode;
};