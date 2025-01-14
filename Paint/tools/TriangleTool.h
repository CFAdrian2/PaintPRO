#pragma once

#include "Tools/Tool.h"

class TriangleTool : public Tool
{
public:
	TriangleTool(PaintView* view);
	void onMousePress(const QPointF& pos) override;
	void onMouseMove(const QPointF& pos) override;
};