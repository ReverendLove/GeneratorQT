#include "generatorqt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GeneratorQT w;
	w.show();
	return a.exec();
}
