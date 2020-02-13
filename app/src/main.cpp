#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <imgui.h>

#include <examples/imgui_impl_glfw.h>
#include <examples/imgui_impl_opengl3.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "DebugMenu.h"
#include "Player.h"

static void error_callback(int error, const char* description) {
	fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(void) {
	GLFWwindow* window;

	glfwSetErrorCallback(error_callback);

	if (!glfwInit()) exit(EXIT_FAILURE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwSetKeyCallback(window, key_callback);

	glfwMakeContextCurrent(window);
	gladLoadGL();
	glfwSwapInterval(1);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 450");

	Player player;

#ifdef _DEBUG
	DebugMenu debugMenu("Game");
	debugMenu.RegisterModule<Player::DebugModule>(player);
#endif

	while (!glfwWindowShouldClose(window)) {
		int width, height;

		glClear(GL_COLOR_BUFFER_BIT);

		glfwGetFramebufferSize(window, &width, &height);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

#ifdef _DEBUG
		debugMenu.Render();
#endif

		player.Render();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Teardown
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}