#include "MainWindow.h"

#include <QComboBox>
#include <QLabel>
#include <QStatusBar>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

#include <string>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	_ui.setupUi(this);
	initView();
	initController();
	initLeftToolbar();
	initTopToolBar();
	this->adjustSize();
}

void MainWindow::initView()
{
	_view = new PaintView(this);
	this->setCentralWidget(_view);
}

void MainWindow::initController()
{
	_controller = new PaintController(this, _view);
	connect(_view, SIGNAL(mousePress(QPointF, Qt::MouseButtons)),
		_controller, SLOT(onMousePress(QPointF, Qt::MouseButtons)));
	connect(_view, SIGNAL(mouseMove(QPointF, Qt::MouseButtons)),
		_controller, SLOT(onMouseMove(QPointF, Qt::MouseButtons)));
	connect(_view, SIGNAL(mouseRelease(QPointF, Qt::MouseButtons)),
		_controller, SLOT(onMouseRelease(QPointF, Qt::MouseButtons)));
	connect(_view, SIGNAL(mouseMove(QPointF, Qt::MouseButtons)),
		this, SLOT(onMouseMove(QPointF, Qt::MouseButtons)));
}

void MainWindow::onColorSelected(const QColor& color)
{
	_topToolBar->widgetForAction(_colorAction)->setStyleSheet("background: " + color.name());
}

void MainWindow::onToolSelected(const ToolType type)
{
	_controller->onToolSelected(type);
}

void MainWindow::initLeftToolbar()
{
	_leftToolBar = new QToolBar(this);
	_leftToolBar->setIconSize(QSize(30, 30));
	this->addToolBar(Qt::LeftToolBarArea, _leftToolBar);

	_lineAction = new QAction(QIcon(":/MainWindow/icons/Line.png"), "Line", this);
	_penAction = new QAction(QIcon(":/MainWindow/icons/Pen.png"), "Pen", this);
	_selectAction = new QAction(QIcon(":/MainWindow/icons/Select.png"), "Select", this);
	_rectangleAction = new QAction(QIcon(":/MainWindow/icons/Rectangle.png"), "Rectangle", this);
	_ellipseAction = new QAction(QIcon(":/MainWindow/icons/Ellipse.png"), "Ellipse", this);
	_triangleAction = new QAction(QIcon(":/MainWindow/icons/shape_triangle.png"), "Triangle", this);
	_eraserAction = new QAction(QIcon(":/MainWindow/icons/Eraser.png"), "Eraser", this);

	_leftToolBar->addAction(_selectAction);
	_leftToolBar->addSeparator();
	_leftToolBar->addAction(_penAction);
	_leftToolBar->addSeparator();
	_leftToolBar->addAction(_lineAction);
	_leftToolBar->addSeparator();
	_leftToolBar->addAction(_rectangleAction);
	_leftToolBar->addSeparator();
	_leftToolBar->addAction(_ellipseAction);
	_leftToolBar->addSeparator();
	_leftToolBar->addAction(_triangleAction);
	_leftToolBar->addSeparator();
	_leftToolBar->addAction(_eraserAction);

	connect(_lineAction, &QAction::triggered, [this]() { onToolSelected(ToolType::eLine); });
	connect(_penAction, &QAction::triggered, [this]() { onToolSelected(ToolType::ePen); });
	connect(_selectAction, &QAction::triggered, [this]() { onToolSelected(ToolType::eSelect); });
	connect(_rectangleAction, &QAction::triggered, [this]() { onToolSelected(ToolType::eRectangle); });
	connect(_ellipseAction, &QAction::triggered, [this]() { onToolSelected(ToolType::eEllipse); });
	connect(_triangleAction, &QAction::triggered, [this]() { onToolSelected(ToolType::eTriangle); });
	connect(_eraserAction, &QAction::triggered, [this]() { onToolSelected(ToolType::eEraser); });

	_penAction->setChecked(true);
	_penAction->trigger();
}

void MainWindow::initTopToolBar()
{
	_topToolBar = new QToolBar(this);
	_topToolBar->setIconSize(QSize(10, 10));
	this->addToolBar(Qt::TopToolBarArea, _topToolBar);

	_colorAction = new QAction(QIcon(":/MainWindow/icons/Transparent.png"), "Color", this);
	_colorAction->setToolTip("Change color of the drawing item");
	_topToolBar->addAction(_colorAction);
	_topToolBar->widgetForAction(_colorAction)->setStyleSheet("background: black");

	_colorDialog = new QColorDialog(this);
	connect(_colorAction, SIGNAL(triggered()),
		_colorDialog, SLOT(open()));
	connect(_colorDialog, &QColorDialog::colorSelected,
		_view, &PaintView::onColorSelected);
	connect(_colorDialog, &QColorDialog::colorSelected,
		this, &MainWindow::onColorSelected);

	_topToolBar->addSeparator();

	QComboBox* lineThicknessComboBox = new QComboBox(this);

	for (int iter = 1; iter <= 20; iter++)
	{
		lineThicknessComboBox->addItem(std::to_string(iter).c_str());
	}

	connect(lineThicknessComboBox, &QComboBox::currentTextChanged,
		_view, &PaintView::onActionLineThicknessTriggered);

	_topToolBar->addWidget(new QLabel("Line Thickness: ", this));
	_topToolBar->addWidget(lineThicknessComboBox);
}

void MainWindow::onMouseMove(const QPointF& pos, const Qt::MouseButtons& /*buttons*/)
{
	QString msg;
	msg = QString("%1x%2").arg(pos.x(), 0, 'f', 0).arg(pos.y(), 0, 'f', 0);
	statusBar()->showMessage(msg);
	this->statusBar()->show();
}

MainWindow::~MainWindow()
{}
