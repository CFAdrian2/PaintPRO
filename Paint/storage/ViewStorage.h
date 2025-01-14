#pragma once

#include "PaintView.h"

class ViewStorage
{
public:
	static bool saveView(PaintView* view, const QString& path);
	static void openView(PaintView* view, const QString& path);

private:
	static void saveToImage(PaintView* view, const QString& path);
};