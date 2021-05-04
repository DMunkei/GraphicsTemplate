#pragma once

#include <string>
#include <unordered_map>
#include <cassert>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <ios>
#include <optional>

#include <glm/glm.hpp>
#include <glad/glad.h>

class Shader
{
	unsigned int m_Handle;
	std::unordered_map<std::string, int> m_UniformLocationCache;

public:
	Shader(const std::string &vsPath, const std::string &fsPath);
	~Shader();
	
	void Bind() const;
	
	[[maybe_unused]] void SetInt(const std::string &name, int value);
	[[maybe_unused]] void SetFloat(const std::string &name, float value);
	[[maybe_unused]] void SetVec2(const std::string &name, const glm::vec2 &value);
	[[maybe_unused]] void SetVec3(const std::string &name, const glm::vec3 &value);
	[[maybe_unused]] void SetVec4(const std::string &name, const glm::vec4 &value);
	[[maybe_unused]] void SetMat2(const std::string &name, const glm::mat2 &mat);
	[[maybe_unused]] void SetMat3(const std::string &name, const glm::mat3 &mat);
	[[maybe_unused]] void SetMat4(const std::string &name, const glm::mat4 &mat);

private:
	[[nodiscard]] int GetUniformLocation(const std::string &name);
	static unsigned int Compile(const std::string &source, GLenum type);
};
