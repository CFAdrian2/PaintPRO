#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    initView();
    initPen();
	initTopToolBar();
    initController();
    this->adjustSize();
}

void MainWindow::onColorSelected(const QColor& color)
{
	_topToolBar->widgetForAction(_colorAction)->setStyleSheet("background: " + color.name());
}

void MainWindow::initView()
{
	_view = new PaintView(this);
	this->setCentralWidget(_view);
}

void MainWindow::initPen()
{
	_pen = new Pen(_view);
}

void MainWindow::initController()
{
	_controller = new PaintController(this, _view, _pen);
	connect(_view, SIGNAL(mousePress(QPointF, Qt::MouseButtons)),
		_controller, SLOT(onMousePress(QPointF, Qt::MouseButtons)));
	connect(_view, SIGNAL(mouseMove(QPointF, Qt::MouseButtons)),
		_controller, SLOT(onMouseMove(QPointF, Qt::MouseButtons)));
	connect(_view, SIGNAL(mouseRelease(QPointF, Qt::MouseButtons)),
		_controller, SLOT(onMouseRelease(QPointF, Qt::MouseButtons)));
}

void MainWindow::initTopToolBar()
{
	_topToolBar = new QToolBar(this);
	_topToolBar->setIconSize(QSize(10, 10));
	this->addToolBar(Qt::TopToolBarArea, _topToolBar);

	// Color picker
	_colorAction = new QAction(QIcon(":/MainWindow/res/icons/Transparent.png"), "Color", this);
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

}

MainWindow::~MainWindow()
{}
