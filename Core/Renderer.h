#pragma once

namespace FMango{
class Renderer
{
public:
	Renderer();
	virtual ~Renderer();

public:
	enum RENDERER_TYPE
	{
		OPENGL,
		DX,
		SOFT,
		MAX_RENDERER_TYPE,
	};
	virtual void Render() = 0;
	virtual RENDERER_TYPE GetType() const = 0;

	int GetWidth() const;
	int GetHeight() const;
	void DrawScene() const;

	//virtual void SetBackGroundColor(const )
private:
	int width;
	int height;
};

}