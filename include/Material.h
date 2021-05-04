#pragma once

#include <variant>
#include <glm/glm.hpp>

#include "Shader.h"

class Material
{
	enum class UniformType
	{
		INT,
		FLOAT,
		VEC2,
		VEC3,
		VEC4,
		MAT2,
		MAT3,
		MAT4
	};

	struct UniformValue
	{
		std::variant<int, float, glm::vec2, glm::vec3, glm::vec4, glm::mat2, glm::mat3,
			glm::mat4>
			value;
		UniformType type;
	};

	std::shared_ptr<Shader> m_Shader;
	std::unordered_map<std::string, UniformValue> m_Uniforms;

public:
	explicit Material(std::shared_ptr<Shader> shader) : m_Shader(shader) {}

	template<typename T>
	[[maybe_unused]] const T &GetUniform(const std::string &name) const
	{
		return m_Uniforms.at(name);
	}

	template<typename T>
	void SetUniform(const std::string &name, T value)
	{
		static_assert("Unsupported SetUniform Type");
	}

	template<>
	[[maybe_unused]] void SetUniform<int>(const std::string &name, int value)
	{
		m_Uniforms[name] = {value, UniformType::INT};
	}

	template<>
	[[maybe_unused]] void SetUniform<float>(const std::string &name, float value)
	{
		m_Uniforms[name] = {value, UniformType::FLOAT};
	}

	template<>
	[[maybe_unused]] void SetUniform<glm::vec2>(const std::string &name, glm::vec2 value)
	{
		m_Uniforms[name] = {value, UniformType::VEC2};
	}

	template<>
	[[maybe_unused]] void SetUniform<glm::vec3>(const std::string &name, glm::vec3 value)
	{
		m_Uniforms[name] = {value, UniformType::VEC3};
	}

	template<>
	[[maybe_unused]] void SetUniform<glm::vec4>(const std::string &name, glm::vec4 value)
	{
		m_Uniforms[name] = {value, UniformType::VEC4};
	}

	template<>
	[[maybe_unused]] void SetUniform<glm::mat2>(const std::string &name, glm::mat2 value)
	{
		m_Uniforms[name] = {value, UniformType::MAT2};
	}

	template<>
	[[maybe_unused]] void SetUniform<glm::mat3>(const std::string &name, glm::mat3 value)
	{
		m_Uniforms[name] = {value, UniformType::MAT3};
	}

	template<>
	[[maybe_unused]] void SetUniform<glm::mat4>(const std::string &name, glm::mat4 value)
	{
		m_Uniforms[name] = {value, UniformType::MAT4};
	}

	void Bind()
	{
		m_Shader->Bind();

		for (auto &m_Uniform : m_Uniforms)
		{
			const UniformValue &uniform = m_Uniform.second;
			switch (uniform.type)
			{
				case UniformType::INT:
					m_Shader->SetInt(m_Uniform.first, std::get<int>(uniform.value));
					break;
				case UniformType::FLOAT:
					m_Shader->SetFloat(m_Uniform.first, std::get<float>(uniform.value));
					break;
				case UniformType::VEC2:
					m_Shader->SetVec2(m_Uniform.first,
						std::get<glm::vec2>(uniform.value));
					break;
				case UniformType::VEC3:
					m_Shader->SetVec3(m_Uniform.first,
						std::get<glm::vec3>(uniform.value));
					break;
				case UniformType::VEC4:
					m_Shader->SetVec4(m_Uniform.first,
						std::get<glm::vec4>(uniform.value));
					break;
				case UniformType::MAT2:
					m_Shader->SetMat2(m_Uniform.first,
						std::get<glm::mat2>(uniform.value));
					break;
				case UniformType::MAT3:
					m_Shader->SetMat3(m_Uniform.first,
						std::get<glm::mat3>(uniform.value));
					break;
				case UniformType::MAT4:
					m_Shader->SetMat4(m_Uniform.first,
						std::get<glm::mat4>(uniform.value));
					break;
			}
		}
	}
};
