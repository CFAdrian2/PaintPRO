#pragma once

#include <QtCore/QObject>

#include "PaintView.h"
#include "Pen.h"

class PaintController : public QObject
{
	Q_OBJECT

public:
	PaintController(QObject* parent, PaintView* view, Pen* pen);

protected slots:
	void	onMousePress(const QPointF& pos, const Qt::MouseButtons& buttons);
	void	onMouseMove(const QPointF& pos, const Qt::MouseButtons& buttons);
	void	onMouseRelease(const QPointF& pos, const Qt::MouseButtons& buttons);

private:
	PaintView*	_view;
	Pen*		_pen;
};