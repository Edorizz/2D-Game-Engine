#pragma once

#include "Renderer2D.h"
#include "Sprite.h"

#define RENDERER_MAX_SPRITES		10000
#define RENDERER_VERTEX_SIZE		sizeof(Vertex)
#define RENDERER_SPRITE_SIZE		RENDERER_VERTEX_SIZE * 4
#define RENDERER_VERTEX_BUFFER_SIZE	RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDEX_BUFFER_SIZE	RENDERER_MAX_SPRITES * 6

#define SHADER_POSITION_INDEX		0
#define SHADER_COLOR_INDEX			1

class BatchRenderer2D : public Renderer2D {
private:
	Vertex* m_Buffer;
public:
	BatchRenderer2D();
	~BatchRenderer2D();
	void Init() override;
	void Begin() override;
	void Submit(Sprite *sprite) override;
	void End() override;
	void Flush() override;
};

