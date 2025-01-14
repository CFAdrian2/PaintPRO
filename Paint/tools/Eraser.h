#pragma once
#include "Tool.h"

class EraserTool : public Tool
{
public:
	EraserTool(PaintView* view);

	void onMousePress(const QPointF& pos) override;
	void onMouseMove(const QPointF& pos) override;
};