#pragma once

#include <memory>

#include "InputListener.h"
#include "Window.h"

class BaseGame : public InputListener
{
protected:
	std::shared_ptr<Window> m_Window;

public:
	BaseGame(unsigned int width, unsigned int height, const std::string &title);
	
	void Start();

	virtual void Update(float delta) = 0;

	void OnKeyInput(int key, int scancode, int action, int mods) override {}
	void OnMouseButtonInput(int button, int action, int mods) override {}
	void OnMouseMotionInput(double xpos, double ypos) override {}
	void OnScrollInput(double xoffset, double yoffset) override {}
};