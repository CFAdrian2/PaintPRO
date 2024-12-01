#include "PaintController.h"

#include <QtWidgets/QGraphicsLineItem>

PaintController::PaintController(QObject* parent, PaintView* view, Pen* pen) :
	QObject(parent),
	_view(view),
	_pen(pen)
{}

void PaintController::onMousePress(const QPointF& pos, const Qt::MouseButtons& buttons)
{
	if (buttons != Qt::MouseButton::LeftButton)
		return;

	_pen->onMousePress(pos);
}

void PaintController::onMouseMove(const QPointF& pos, const Qt::MouseButtons& buttons)
{
	if (buttons != Qt::MouseButton::LeftButton)
		return;

	_pen->onMouseMove(pos);
}

void PaintController::onMouseRelease(const QPointF& pos, const Qt::MouseButtons& buttons)
{
	_pen->onMouseRelease(pos);
}