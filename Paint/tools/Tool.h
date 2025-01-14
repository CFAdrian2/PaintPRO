#pragma once

#include "PaintView.h"

enum class ToolType
{
	ePen,
	eLine,
	eRectangle,
	eEllipse,
	eTriangle,
	eSelect,
	eEraser
};

class Tool
{
public:
					Tool(PaintView* view);

	virtual void	onMousePress(const QPointF& pos);
	virtual void	onMouseMove(const QPointF& pos);
	virtual void	onMouseRelease(const QPointF& pos);

protected:
	QPointF			proportionalPos(const QPointF& startPos, const QPointF& endPos);

protected:
	PaintView*		_view;
	QGraphicsItem*	_graphicsItem;
	QPointF			_startPos;
	QPointF			_previousPos;
};
