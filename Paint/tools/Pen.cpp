#include "Pen.h"

#include <QtWidgets/QGraphicsItem>

Pen::Pen(PaintView* view) :
	Tool(view)
{}

void Pen::onMousePress(const QPointF& pos)
{
	Tool::onMousePress(pos);
	QPainterPath path(_startPos);
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

	Tool::onMouseMove(pos);
}