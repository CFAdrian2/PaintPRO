#include "Pen.h"

#include <QtWidgets/QGraphicsItem>

Pen::Pen(PaintView* view) :
	_view(view)
{}

void Pen::onMousePress(const QPointF& pos)
{
	Pen::penOnMousePress(pos);
	QPainterPath path(pos);
	path.moveTo(pos);
	_graphicsItem = _view->createPath(path);
}

void Pen::onMouseMove(const QPointF& pos)
{
	QGraphicsPathItem* pathItem = dynamic_cast<QGraphicsPathItem*>(_graphicsItem);
	if (!pathItem)
		return;

	QPainterPath path = pathItem->path();
	path.moveTo(_previousPos);
	path.lineTo(pos);
	pathItem->setPath(path);

	Pen::penOnMouseMove(pos);
}

void Pen::onMouseRelease(const QPointF& pos)
{
	_graphicsItem = nullptr;
	_startPos = QPointF();
}


void Pen::penOnMousePress(const QPointF& pos)
{
	_startPos = pos;
	_previousPos = pos;
}

void Pen::penOnMouseMove(const QPointF& pos)
{
	_previousPos = pos;
}