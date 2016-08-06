/********************************************************************************
** Form generated from reading UI file 'generatorqt.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATORQT_H
#define UI_GENERATORQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeneratorQTClass
{
public:
    QWidget *wdgCentral;
    QSpinBox *sbNumberOfDots;
    QSlider *slSpeed;
    QMenuBar *menuBar;
    QMenu *menu_Regeln;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GeneratorQTClass)
    {
        if (GeneratorQTClass->objectName().isEmpty())
            GeneratorQTClass->setObjectName(QStringLiteral("GeneratorQTClass"));
        GeneratorQTClass->resize(816, 606);
        wdgCentral = new QWidget(GeneratorQTClass);
        wdgCentral->setObjectName(QStringLiteral("wdgCentral"));
        sbNumberOfDots = new QSpinBox(wdgCentral);
        sbNumberOfDots->setObjectName(QStringLiteral("sbNumberOfDots"));
        sbNumberOfDots->setGeometry(QRect(10, 420, 42, 22));
        sbNumberOfDots->setMinimum(1);
        sbNumberOfDots->setMaximum(32);
        sbNumberOfDots->setValue(1);
        slSpeed = new QSlider(wdgCentral);
        slSpeed->setObjectName(QStringLiteral("slSpeed"));
        slSpeed->setEnabled(true);
        slSpeed->setGeometry(QRect(450, 0, 30, 397));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(slSpeed->sizePolicy().hasHeightForWidth());
        slSpeed->setSizePolicy(sizePolicy);
        slSpeed->setMinimum(24);
        slSpeed->setMaximum(264);
        slSpeed->setSliderPosition(119);
        slSpeed->setOrientation(Qt::Vertical);
        slSpeed->setTickPosition(QSlider::TicksBelow);
        slSpeed->setTickInterval(10);
        GeneratorQTClass->setCentralWidget(wdgCentral);
        menuBar = new QMenuBar(GeneratorQTClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 816, 21));
        menu_Regeln = new QMenu(menuBar);
        menu_Regeln->setObjectName(QStringLiteral("menu_Regeln"));
        GeneratorQTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GeneratorQTClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GeneratorQTClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GeneratorQTClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GeneratorQTClass->setStatusBar(statusBar);

        menuBar->addAction(menu_Regeln->menuAction());

        retranslateUi(GeneratorQTClass);

        QMetaObject::connectSlotsByName(GeneratorQTClass);
    } // setupUi

    void retranslateUi(QMainWindow *GeneratorQTClass)
    {
        GeneratorQTClass->setWindowTitle(QApplication::translate("GeneratorQTClass", "GeneratorQT", 0));
        menu_Regeln->setTitle(QApplication::translate("GeneratorQTClass", "&Regeln", 0));
    } // retranslateUi

};

namespace Ui {
    class GeneratorQTClass: public Ui_GeneratorQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATORQT_H
