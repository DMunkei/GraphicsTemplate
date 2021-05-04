#pragma once

#include <vector>
#include <cassert>

#include <glad/glad.h>

class VertexBuffer
{
	unsigned int m_Handle;

public:
	VertexBuffer(unsigned int size, const void *data);
	~VertexBuffer();

	void Bind() const;
};

class IndexBuffer
{
	unsigned int m_Handle;
	unsigned int m_Count;

public:
	IndexBuffer(unsigned int count, const void *data);
	~IndexBuffer();

	void Bind() const;
	[[nodiscard]] inline unsigned int GetCount() const { return m_Count; }
};

struct VertexBufferElement
{
	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
			case GL_FLOAT: return 4;
			case GL_UNSIGNED_INT: return 4;
			case GL_UNSIGNED_BYTE: return 4;
			default: assert(false); return 0;
		};
	}
};

class VertexBufferLayout
{
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;

public:
	VertexBufferLayout() : m_Stride{0} {};

	template<typename T>
	VertexBufferLayout& Push(unsigned int count);

	template<>
	VertexBufferLayout& Push<float>(unsigned int count)
	{
		m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
		m_Stride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * count;
		return *this;
	}

	template<>
	VertexBufferLayout& Push<unsigned int>(unsigned int count)
	{
		m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
		m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT) * count;
		return *this;
	}

	template<>
	VertexBufferLayout& Push<unsigned char>(unsigned int count)
	{
		m_Elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
		m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE) * count;
		return *this;
	}

	[[nodiscard]] inline const std::vector<VertexBufferElement> &GetElements() const
	{
		return m_Elements;
	}

	[[nodiscard]] inline unsigned int GetStride() const { return m_Stride; }
};

class VertexArray
{
	unsigned int m_Handle;

public:
	VertexArray();
	~VertexArray();

	void Bind() const;
	void AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout) const;
};
