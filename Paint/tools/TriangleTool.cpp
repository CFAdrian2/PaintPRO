#include "tools/TriangleTool.h"

#include <QtGui/QGuiApplication>
#include <QtWidgets/QGraphicsItem>

TriangleTool::TriangleTool(PaintView* view) :
	Tool(view)
{}

void TriangleTool::onMousePress(const QPointF& pos)
{

	QPolygonF triangle;

	triangle << pos << pos << pos;

	_graphicsItem = _view->createTriangle(triangle);

	Tool::onMousePress(pos);
}

void TriangleTool::onMouseMove(const QPointF& pos)
{
	QGraphicsPolygonItem* triangleItem = dynamic_cast<QGraphicsPolygonItem*>(_graphicsItem);
	if (!triangleItem)
		return;

	QPointF endPos = pos;
	bool shiftPressed = QGuiApplication::keyboardModifiers() == Qt::ShiftModifier;
	if (shiftPressed)
		endPos = proportionalPos(_startPos, endPos);

	QPolygonF triangle;
	triangle << QPointF(pos.x(), pos.y() - 50) << endPos << _startPos;
	triangleItem->setPolygon(triangle);

	Tool::onMouseMove(pos);
}
