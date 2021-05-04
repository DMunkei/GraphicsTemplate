#include <iostream>
#include "Shader.h"

std::optional<std::string> ReadStringFromFile(const std::string &file_path)
{
	const std::ifstream input_stream(file_path, std::ios_base::binary);
	
	if (input_stream.fail())
		return std::nullopt;
	
	std::stringstream buffer;
	buffer << input_stream.rdbuf();
	
	return buffer.str();
}

Shader::Shader(const std::string &vsPath, const std::string &fsPath)
{
	unsigned int vs_handle = Compile(vsPath, GL_VERTEX_SHADER);
	unsigned int fs_handle = Compile(fsPath, GL_FRAGMENT_SHADER);
	
	m_Handle = glCreateProgram();
	assert(m_Handle);
	
	glAttachShader(m_Handle, vs_handle);
	glAttachShader(m_Handle, fs_handle);
	glDeleteShader(vs_handle);
	glDeleteShader(fs_handle);
	
	glLinkProgram(m_Handle);
	
	int linked;
	glGetProgramiv(m_Handle, GL_LINK_STATUS, &linked);
	if (!linked)
	{
		std::cerr << "Failed to link vertex shader (" << vsPath << ") and fragment shader (" << fsPath << ")\n";
		abort();
	}
	
	glValidateProgram(m_Handle);
	
}

unsigned int Shader::Compile(const std::string &path, const GLenum type)
{
	auto source = ReadStringFromFile(path);
	if (!source)
	{
		std::cerr << "Failed to open shader file from " << path << '\n';
		abort();
	}
	// attach source to shader
	const unsigned int handle = glCreateShader(type);
	const char *source_str = source->c_str();
	glShaderSource(handle, 1, &source_str, nullptr);
	// compile shader
	glCompileShader(handle);
	int compiled;
	glGetShaderiv(handle, GL_COMPILE_STATUS, &compiled);
	if (!compiled)
	{
		std::cerr << "Failed to compile shader from " << path << '\n';
		abort();
	}
	return handle;
}

Shader::~Shader()
{
	glDeleteProgram(m_Handle);
}

void Shader::Bind() const
{
	glUseProgram(m_Handle);
}

int Shader::GetUniformLocation(const std::string &name)
{
	if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
		return m_UniformLocationCache[name];
	
	m_UniformLocationCache[name] = glGetUniformLocation(m_Handle, name.c_str());
	assert(m_UniformLocationCache[name] != -1);
	return m_UniformLocationCache[name];
}

[[maybe_unused]] void Shader::SetInt(const std::string &name, int value)
{
	glUniform1i(GetUniformLocation(name), value);
}

[[maybe_unused]] void Shader::SetFloat(const std::string &name, float value)
{
	glUniform1f(GetUniformLocation(name), value);
}

[[maybe_unused]] void Shader::SetVec2(const std::string &name, const glm::vec2 &value)
{
	glUniform2f(GetUniformLocation(name), value[0], value[1]);
}

[[maybe_unused]] void Shader::SetVec3(const std::string &name, const glm::vec3 &value)
{
	glUniform3f(GetUniformLocation(name), value[0], value[1], value[2]);
}

[[maybe_unused]] void Shader::SetVec4(const std::string &name, const glm::vec4 &value)
{
	glUniform4f(GetUniformLocation(name), value[0], value[1], value[2], value[3]);
}

[[maybe_unused]] void Shader::SetMat2(const std::string &name, const glm::mat2 &mat)
{
	glUniformMatrix2fv(GetUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}

[[maybe_unused]] void Shader::SetMat3(const std::string &name, const glm::mat3 &mat)
{
	glUniformMatrix3fv(GetUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}

[[maybe_unused]] void Shader::SetMat4(const std::string &name, const glm::mat4 &mat)
{
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}
