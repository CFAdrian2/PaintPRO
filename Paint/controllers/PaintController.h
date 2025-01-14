#pragma once

#include <QtCore/QObject>
#include <QSharedPointer>

#include "PaintView.h"
#include "tools/Tool.h"

class PaintController : public QObject
{
	Q_OBJECT

public:
			PaintController(QObject* parent, PaintView* view);
	void	onToolSelected(ToolType type);

protected slots:
	void	onMousePress(const QPointF& pos, const Qt::MouseButtons& buttons);
	void	onMouseMove(const QPointF& pos, const Qt::MouseButtons& buttons);
	void	onMouseRelease(const QPointF& pos, const Qt::MouseButtons& buttons);

private:
	PaintView*				_view;
	QGraphicsItem*			_line;
	QSharedPointer<Tool>	_currentTool;
};