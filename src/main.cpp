#include "BaseGame.h"
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

const std::vector<float> floorVertices{
	 0.5f, -0.5f,  0.0f,    0.4f, 0.8f, 0.6f,
	 0.5f,  0.5f,  0.0f,    0.4f, 0.8f, 0.6f,
	-0.5f,  0.5f,  0.0f,    0.4f, 0.8f, 0.6f,
	-0.5f,  0.5f,  0.0f,    0.4f, 0.8f, 0.6f,
	-0.5f, -0.5f,  0.0f,    0.4f, 0.8f, 0.6f,
	 0.5f, -0.5f,  0.0f,    0.4f, 0.8f, 0.6f,
};

const std::vector<float> cubeVertices{
	// x      y      z        r     g     b
	-0.5f, -0.5f, -0.5f,    0.0f, 1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,    0.0f, 1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,    0.0f, 1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,    0.0f, 1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,    0.0f, 1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,    0.0f, 1.0f, 1.0f,
	
	-0.5f, -0.5f,  0.5f,    1.0f, 0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,    1.0f, 0.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,    1.0f, 0.0f, 1.0f,
	
	-0.5f,  0.5f,  0.5f,    0.0f, 1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,    0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,    0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,    0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,    0.0f, 1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,    0.0f, 1.0f, 0.0f,
	
	 0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,    0.0f, 0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,
	
	-0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,    1.0f, 0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,    1.0f, 0.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,    1.0f, 0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,
	
	-0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 0.0f,
};

const std::vector<float> billboardVertices{
	 0.5f, -0.5f, 0.0f,     1.0f, 0.8f, 0.6f,
	 0.5f,  0.5f, 0.0f,     1.0f, 0.8f, 0.6f,
	-0.5f,  0.5f, 0.0f,     1.0f, 0.8f, 0.6f,
	-0.5f,  0.5f, 0.0f,     1.0f, 0.8f, 0.6f,
	-0.5f, -0.5f, 0.0f,     1.0f, 0.8f, 0.6f,
	 0.5f, -0.5f, 0.0f,     1.0f, 0.8f, 0.6f,
};

const std::vector<float> originVertices{
	-5000.0f,     0.0f,     0.0f,       1.0f, 0.0f, 0.0f,
	 5000.0f,     0.0f,     0.0f,       1.0f, 0.0f, 0.0f,
	    0.0f, -5000.0f,     0.0f,       0.0f, 1.0f, 0.0f,
		0.0f,  5000.0f,     0.0f,       0.0f, 1.0f, 0.0f,
	    0.0f,     0.0f, -5000.0f,       0.0f, 0.0f, 1.0f,
	    0.0f,     0.0f,  5000.0f,       0.0f, 0.0f, 1.0f,
};

class Camera
{
	glm::vec3 position, front, up, right, worldUp;
	float yaw, pitch;

public:
	explicit Camera(glm::vec3 position, glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f),
		float yaw = -90.0f, float pitch = 0.0f)
		: position(position), worldUp(worldUp), yaw(yaw), pitch(pitch)
	{
		UpdateVectors();
	}

	inline glm::mat4 GetView() const
	{
		return glm::lookAt(position, position + front, up);
	}

	inline void Move(glm::vec3 velocity)
	{
		position += velocity.x * right + velocity.y * up + velocity.z * front;
	}

	void Rotate(glm::vec3 rotation)
	{
		yaw += rotation.y;
		pitch = glm::clamp(pitch - rotation.x, -89.0f, 89.0f);
		UpdateVectors();
	}

private:
	void UpdateVectors()
	{
		front.x = glm::cos(glm::radians(yaw)) * glm::cos(glm::radians(pitch));
		front.y = glm::sin(glm::radians(pitch));
		front.z = glm::sin(glm::radians(yaw)) * glm::cos(glm::radians(pitch));
		front = glm::normalize(front);
		right = glm::normalize(glm::cross(front, worldUp));
		up = glm::normalize(glm::cross(right, front));
	}
};

class Game : public BaseGame
{
	std::shared_ptr<Shader> m_Shader;
	std::shared_ptr<Material> m_Material;
	std::shared_ptr<Primitive> m_Floor;
	std::shared_ptr<Primitive> m_Cube;
	std::shared_ptr<Primitive> m_Billboard;
	std::shared_ptr<Primitive> m_Origin;

	std::shared_ptr<Camera> m_Camera;
	glm::vec3 m_CameraMoveDirection{0.0f};
	glm::vec2 m_MousePosition{0.0f};
	glm::vec2 m_MouseDelta{0.0f};

public:
	Game(unsigned int width, unsigned int height, const std::string& title)
		: BaseGame(width, height, title), m_MousePosition(m_Window->GetMousePosition())
	{
		m_Shader =
			std::make_shared<Shader>("shaders/MyShader.vert", "shaders/MyShader.frag");

		m_Material = std::make_shared<Material>(m_Shader);

		VertexBufferLayout layout;
		layout.Push<float>(3).Push<float>(3);
		m_Floor = std::make_shared<Primitive>(floorVertices, layout, m_Material);
		m_Cube = std::make_shared<Primitive>(cubeVertices, layout, m_Material);
		m_Billboard = std::make_shared<Primitive>(billboardVertices, layout, m_Material);
		m_Origin = std::make_shared<Primitive>(originVertices, layout, m_Material);
		m_Origin->SetMode(GL_LINES);

		glm::mat4 view(1.0f);
		glm::mat4 projection = glm::perspective(glm::radians(75.0f),
			static_cast<float>(width) / static_cast<float>(height), 0.1f, 5000.0f);

		m_Material->SetUniform("projection", projection);
		m_Material->SetUniform("view", view);

		m_Camera = std::make_shared<Camera>(glm::vec3(1.0f, 1.0f, 2.0f));
	}

	void Update(float delta) override
	{
		glm::vec3 move(0.0f);
		if (glm::length(m_CameraMoveDirection) >= 0.001f)
		{
			move = glm::normalize(m_CameraMoveDirection);
		}
		m_Camera->Move(move * delta * 35.0f);
		m_Camera->Rotate(glm::vec3(m_MouseDelta.y, m_MouseDelta.x, 0.0f) * delta * 50.0f);
		m_MouseDelta = glm::vec2(0.0f);

		glm::mat4 view = m_Camera->GetView();

		m_Material->SetUniform("view", view);

		Renderer::Clear();
		m_Floor->Draw(
			glm::rotate(glm::translate(glm::mat4(1.0f), glm::vec3(1.0f, 0.0f, -5.0f)),
				m_Window->GetTime(), glm::vec3(1.0f, 1.0f, 0.0f)));
		m_Cube->Draw(
			glm::rotate(glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, 0.0f, -5.0f)),
				glm::radians(45.0f), glm::vec3(1.0f, 1.0f, 0.0f)));
		m_Origin->Draw();

		glm::mat4 billboardModel =
			glm::translate(glm::mat4(1.0f), glm::vec3(5.0f, 0.0f, -5.0f));

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				billboardModel[i][j] = view[j][i];
			}
		}
		m_Billboard->Draw(billboardModel);
	}

	void OnKeyInput(int key, int scancode, int action, int mods) override
	{
		float actionDir =
			action == GLFW_PRESS ? 1.0f : (action == GLFW_RELEASE ? -1.0f : 0.0f);
		if (actionDir)
		{
			switch (key)
			{
				case GLFW_KEY_W:
					m_CameraMoveDirection += glm::vec3(0.0f, 0.0f, actionDir);
					break;
				case GLFW_KEY_S:
					m_CameraMoveDirection -= glm::vec3(0.0f, 0.0f, actionDir);
					break;
				case GLFW_KEY_A:
					m_CameraMoveDirection -= glm::vec3(actionDir, 0.0f, 0.0f);
					break;
				case GLFW_KEY_D:
					m_CameraMoveDirection += glm::vec3(actionDir, 0.0f, 0.0f);
					break;
				case GLFW_KEY_Q:
					m_CameraMoveDirection += glm::vec3(0.0f, actionDir, 0.0f);
					break;
				case GLFW_KEY_E:
					m_CameraMoveDirection -= glm::vec3(0.0f, actionDir, 0.0f);
					break;
				case GLFW_KEY_ESCAPE: m_Window->Quit();
			}
		}
	}

	void OnMouseMotionInput(double xpos, double ypos) override
	{
		glm::vec2 newMousePosition(xpos, ypos);
		m_MouseDelta = newMousePosition - m_MousePosition;
		m_MousePosition = newMousePosition;
	}
};

int main()
{
	Game(1280, 720, "MyGame").Start();
	return 0;
}
