#pragma once

class Renderer2D;

namespace Sphinx {

	class Renderable2D {
	public:
		virtual void Sumbit(Renderer2D) = 0;
	protected:
		Renderable2D() {}
	};

}