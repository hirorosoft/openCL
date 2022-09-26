#include "Rect.h"
#include "glut.h"

Rect::Rect(vec2 const& _pos, vec2 const& _size) {

	m_pos = _pos;
	m_size = _size;
}

void Rect::Draw() {
	
	glRectf(m_pos.x, m_pos.y,
		m_pos.x + m_size.x,
		m_pos.y + m_size.y
	);


}

