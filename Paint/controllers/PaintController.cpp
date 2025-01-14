#include "PaintController.h"

#include <QtWidgets/QGraphicsLineItem>
#include <qdebug.h>

#include "tools/Pen.h"
#include "tools/EllipseTool.h"
#include "tools/Eraser.h"
#include "tools/LineTool.h"
#include "tools/RectangleTool.h"
#include "tools/SelectTool.h"
#include "tools/TriangleTool.h"

PaintController::PaintController(QObject* parent, PaintView* view) :
	QObject(parent),
	_view(view)
{}

void PaintController::onMousePress(const QPointF& pos, const Qt::MouseButtons& buttons)
{
	if (buttons != Qt::MouseButton::LeftButton)
		return;

	if (_currentTool)
		_currentTool->onMousePress(pos);
}

void PaintController::onMouseMove(const QPointF& pos, const Qt::MouseButtons& buttons)
{
	if (buttons != Qt::MouseButton::LeftButton)
		return;

	if (_currentTool)
		_currentTool->onMouseMove(pos);
}

void PaintController::onMouseRelease(const QPointF& pos, const Qt::MouseButtons& buttons)
{
	if (_currentTool)
		_currentTool->onMouseRelease(pos);
}

void PaintController::onToolSelected(ToolType type)
{
	switch (type)
	{
	case ToolType::ePen:
		_currentTool = QSharedPointer<Pen>(new Pen(_view));
		break;
	case ToolType::eLine:
		_currentTool = QSharedPointer<LineTool>(new LineTool(_view));
		break;
	case ToolType::eRectangle:
		_currentTool = QSharedPointer<RectangleTool>(new RectangleTool(_view));
		break;
	case ToolType::eEllipse:
		_currentTool = QSharedPointer<EllipseTool>(new EllipseTool(_view));
		break;
	case ToolType::eSelect:
		_currentTool = QSharedPointer<SelectTool>(new SelectTool(_view));
		break;
	case ToolType::eTriangle:
		_currentTool = QSharedPointer<TriangleTool>(new TriangleTool(_view));
		break;
	case ToolType::eEraser:
		_currentTool = QSharedPointer<EraserTool>(new EraserTool(_view));
		break;
	default:
		qDebug() << "invalid tool type";
		break;
	}
}