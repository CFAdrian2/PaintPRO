#pragma once

#include "PaintView.h"

class Pen
{
public:
	Pen(PaintView* view);

	void	onMousePress(const QPointF& pos);
	void	onMouseMove(const QPointF& pos);
	void	onMouseRelease(const QPointF& pos);
private:
	void	penOnMousePress(const QPointF& pos);
	void	penOnMouseMove(const QPointF& pos);
private:
	PaintView*		_view;
	QGraphicsItem*	_graphicsItem;
	QPointF			_startPos;
	QPointF			_previousPos;
};
