#pragma once

#include <iostream>
#include "Material.h"

class Primitive
{
	const VertexBuffer vertexBuffer;
	const std::optional<IndexBuffer> indexBuffer;
	const VertexArray vertexArray;

	const std::shared_ptr<Material> material;

	const unsigned int vertexCount;
	unsigned int mode = GL_TRIANGLES;

public:
	[[maybe_unused]] Primitive(const std::vector<float> &vertices,
		const VertexBufferLayout &layout, std::shared_ptr<Material> material)
		: vertexBuffer(vertices.size() * sizeof(float), vertices.data()), vertexArray(),
		  vertexCount(vertices.size()), material(material)
	{
		vertexArray.AddBuffer(vertexBuffer, layout);
	}

	Primitive(const std::vector<float> &vertices,
		const std::vector<unsigned int> &indices, const VertexBufferLayout &layout,
		std::shared_ptr<Material> material)
		: vertexBuffer(static_cast<unsigned int>(vertices.size() * sizeof(float)),
			vertices.data()),
		  indexBuffer(std::make_optional<IndexBuffer>(
			  static_cast<unsigned int>(vertices.size() * sizeof(unsigned int)),
			  indices.data())),
		  vertexArray(), vertexCount(vertices.size()), material(material)
	{
		vertexArray.AddBuffer(vertexBuffer, layout);
	}

	void Bind() const
	{
		vertexArray.Bind();
		if (indexBuffer)
			indexBuffer->Bind();
	}

	[[maybe_unused]] inline void SetMode(unsigned int newMode) { mode = newMode; }

	
	void Draw(glm::mat4 model = glm::mat4(1.0f)) const
	{
		material->SetUniform("model", model);
		material->Bind();
		Bind();
		if (indexBuffer)
		{
			glDrawElements(mode, static_cast<GLsizei>(vertexCount), GL_UNSIGNED_INT,
				nullptr);
		}
		else
		{
			glDrawArrays(mode, 0, vertexCount);
		}
	}
};

/*
struct Mesh
{
	std::vector<Primitive> primitives;
	
	void Draw(glm::mat4 transform) const
	{
		for (const auto& primitive : primitives)
		{
			primitive.Draw(transform);
		}
	}
};

*/
/*

class Node
{
	glm::mat4 transform;
	std::optional<std::shared_ptr<Mesh>> mesh;
	std::vector<Node> children;

public:
	explicit Node(glm::mat4 transform = glm::mat4(1.0f)) : transform(transform) {}
	
	explicit Node(std::shared_ptr<Mesh> mesh, glm::mat4 transform = glm::mat4(1.0f))
		: transform(transform), mesh(mesh)
	{
	}
	
	void AddChild(const Node& node) { children.push_back(node); }
	void DrawTree(glm::mat4 root = glm::mat4(1.0f)) const
	{
		root *= transform;
		if (mesh)
		{
			// a rare double dereference
			(*mesh)->Draw(root);
		}
		for (const auto& child : children)
		{
			child.DrawTree(root);
		}
	}
};
*/
