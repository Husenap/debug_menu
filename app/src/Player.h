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

private:
	float mLocation = 0.5f;
	bool mShinMode  = false;

#ifdef _DEBUG
public:
	class PlayerDebugModule : public DebugModule {
		Player& mPlayer;

	public:
		PlayerDebugModule(Player& player)
		    : mPlayer(player) {}

		const char* GetTitle() override { return "Player Module##player_module"; }
		void Render() override {
			ImGui::SliderFloat("location", &mPlayer.mLocation, 0.f, 1.f);
			ImGui::Checkbox("shin mode", &mPlayer.mShinMode);
		}
	};
#endif
};
