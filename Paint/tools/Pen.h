#pragma once

#include "Tool.h"

class Pen : public Tool
{
public:
			Pen(PaintView* view);

	void	onMousePress(const QPointF& pos);
	void	onMouseMove(const QPointF& pos);
};
