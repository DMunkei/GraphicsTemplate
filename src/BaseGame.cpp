#include "BaseGame.h"

void BaseGame::Start()
{
	float lastTime = 0.0f;
	float lastCapTime = 0.0f;

	while (!m_Window->ShouldClose())
	{
		float time = m_Window->GetTime();
		float deltaTime = time - lastTime;
		lastTime = time;

		if (m_Window->IsFrameCapEnabled())
		{
			float targetFrameTime = 1.0f / m_Window->GetFrameCap();
			float deltaCapTime = time - lastCapTime;
			if (deltaCapTime < targetFrameTime)
			{
				long sleepTime =
					static_cast<long>((targetFrameTime - deltaCapTime) * 1000.0f);
				std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
			}
			lastCapTime = m_Window->GetTime();
		}

		m_Window->PollInput();
		Update(deltaTime);
		m_Window->PresentFrame();
	}
}

BaseGame::BaseGame(unsigned int width, unsigned int height, const std::string &title)
	: m_Window(std::make_shared<Window>(width, height, title))
{
	m_Window->AddInputListener(*this);
	Renderer::Init();
}
