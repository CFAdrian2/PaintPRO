#pragma once
#include "Tool.h"

class SelectTool : public Tool
{
public:
	SelectTool(PaintView* view);

	void onMousePress(const QPointF& pos) override;
	void onMouseMove(const QPointF& pos) override;
};