#pragma once
#include "glm\glm.hpp"

using namespace glm;

struct Rect {
	vec2 m_pos;
	vec2 m_size;

	Rect(vec2 const& _pos, vec2 const& _size);

	void Draw();

};