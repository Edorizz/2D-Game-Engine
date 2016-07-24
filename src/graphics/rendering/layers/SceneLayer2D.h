#pragma once

#include "Layer.h"
#include "../../../game/Camera2D.h"
#include <string>

class SceneLayer2D : public Layer {
private:
	Camera2D *m_Camera;
public:
	SceneLayer2D(std::string *shaders, Camera2D *camera);
	void Draw() override;
	void Add(Renderable2D *renderable) override;
	void SetCamera(Camera2D *camera) { m_Camera = camera; }
};
