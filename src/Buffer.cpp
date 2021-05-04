#include "Buffer.h"

VertexBuffer::VertexBuffer(unsigned int size, const void *data)
{
	glGenBuffers(1, &m_Handle);
	Bind();
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_Handle);
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_Handle);
}

IndexBuffer::IndexBuffer(unsigned int count, const void *data) : m_Count{count}
{
	glGenBuffers(1, &m_Handle);
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count, data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_Handle);
}

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Handle);
}

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_Handle);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_Handle);
}

void VertexArray::Bind() const
{
	glBindVertexArray(m_Handle);
}

void VertexArray::AddBuffer(const VertexBuffer &vb,
                            const VertexBufferLayout &layout) const
{
	Bind();
	vb.Bind();
	const auto &elements = layout.GetElements();
	unsigned int offset = 0;
	
	for (size_t i = 0; i < elements.size(); ++i)
	{
		const auto &element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type,
		                      element.normalized, layout.GetStride(),
		                      (const void *) offset);
		offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
	}
}
