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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeneratorQTClass
{
public:
    QWidget *wdgCentral;
    QSpinBox *sbNumberOfDots;
    QSlider *slSpeed;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *lblSpeed;
    QTableWidget *tblDots;
    QPushButton *btnStart;
    QWidget *layoutWidget1;
    QHBoxLayout *loMidiIn;
    QLabel *lblMidiIn;
    QComboBox *cbMidiIn;
    QCheckBox *cbSync;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *lblMidiOut;
    QComboBox *cbMidiOut;
    QMenuBar *menuBar;
    QMenu *menu_Regeln;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *GeneratorQTClass)
    {
        if (GeneratorQTClass->objectName().isEmpty())
            GeneratorQTClass->setObjectName(QStringLiteral("GeneratorQTClass"));
        GeneratorQTClass->resize(953, 606);
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
        layoutWidget = new QWidget(wdgCentral);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(440, 400, 48, 15));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lblSpeed = new QLabel(layoutWidget);
        lblSpeed->setObjectName(QStringLiteral("lblSpeed"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lblSpeed);

        tblDots = new QTableWidget(wdgCentral);
        if (tblDots->columnCount() < 7)
            tblDots->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblDots->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblDots->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblDots->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblDots->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblDots->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblDots->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tblDots->rowCount() < 32)
            tblDots->setRowCount(32);
        tblDots->setObjectName(QStringLiteral("tblDots"));
        tblDots->setGeometry(QRect(510, 10, 291, 400));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tblDots->sizePolicy().hasHeightForWidth());
        tblDots->setSizePolicy(sizePolicy1);
        tblDots->viewport()->setProperty("cursor", QVariant(QCursor(Qt::UpArrowCursor)));
        tblDots->setMouseTracking(true);
        tblDots->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblDots->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tblDots->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblDots->setAlternatingRowColors(true);
        tblDots->setSelectionMode(QAbstractItemView::SingleSelection);
        tblDots->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblDots->setSortingEnabled(true);
        tblDots->setWordWrap(false);
        tblDots->setCornerButtonEnabled(false);
        tblDots->setRowCount(32);
        tblDots->setColumnCount(7);
        tblDots->horizontalHeader()->setCascadingSectionResizes(false);
        tblDots->horizontalHeader()->setDefaultSectionSize(45);
        tblDots->horizontalHeader()->setHighlightSections(true);
        tblDots->horizontalHeader()->setMinimumSectionSize(0);
        tblDots->verticalHeader()->setVisible(false);
        tblDots->verticalHeader()->setDefaultSectionSize(16);
        tblDots->verticalHeader()->setMinimumSectionSize(12);
        btnStart = new QPushButton(wdgCentral);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setGeometry(QRect(650, 480, 91, 31));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(0, 255, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        QBrush brush2(QColor(214, 255, 207, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        btnStart->setPalette(palette);
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        btnStart->setFont(font);
        btnStart->setAutoFillBackground(false);
        btnStart->setCheckable(true);
        btnStart->setChecked(false);
        layoutWidget1 = new QWidget(wdgCentral);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 460, 501, 22));
        loMidiIn = new QHBoxLayout(layoutWidget1);
        loMidiIn->setSpacing(5);
        loMidiIn->setContentsMargins(11, 11, 11, 11);
        loMidiIn->setObjectName(QStringLiteral("loMidiIn"));
        loMidiIn->setContentsMargins(0, 0, 0, 0);
        lblMidiIn = new QLabel(layoutWidget1);
        lblMidiIn->setObjectName(QStringLiteral("lblMidiIn"));

        loMidiIn->addWidget(lblMidiIn);

        cbMidiIn = new QComboBox(layoutWidget1);
        cbMidiIn->setObjectName(QStringLiteral("cbMidiIn"));

        loMidiIn->addWidget(cbMidiIn);

        cbSync = new QCheckBox(layoutWidget1);
        cbSync->setObjectName(QStringLiteral("cbSync"));

        loMidiIn->addWidget(cbSync);

        loMidiIn->setStretch(0, 1);
        loMidiIn->setStretch(1, 4);
        layoutWidget2 = new QWidget(wdgCentral);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 500, 411, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lblMidiOut = new QLabel(layoutWidget2);
        lblMidiOut->setObjectName(QStringLiteral("lblMidiOut"));

        horizontalLayout->addWidget(lblMidiOut);

        cbMidiOut = new QComboBox(layoutWidget2);
        cbMidiOut->setObjectName(QStringLiteral("cbMidiOut"));

        horizontalLayout->addWidget(cbMidiOut);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);
        GeneratorQTClass->setCentralWidget(wdgCentral);
        menuBar = new QMenuBar(GeneratorQTClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 953, 21));
        menu_Regeln = new QMenu(menuBar);
        menu_Regeln->setObjectName(QStringLiteral("menu_Regeln"));
        GeneratorQTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GeneratorQTClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setOrientation(Qt::Horizontal);
        GeneratorQTClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
#ifndef QT_NO_SHORTCUT
        lblSpeed->setBuddy(slSpeed);
#endif // QT_NO_SHORTCUT

        menuBar->addAction(menu_Regeln->menuAction());
        mainToolBar->addSeparator();

        retranslateUi(GeneratorQTClass);
        QObject::connect(sbNumberOfDots, SIGNAL(valueChanged(int)), GeneratorQTClass, SLOT(dotsNumChanged()));
        QObject::connect(slSpeed, SIGNAL(valueChanged(int)), GeneratorQTClass, SLOT(slSpeedChanged(int)));
        QObject::connect(slSpeed, SIGNAL(valueChanged(int)), lblSpeed, SLOT(setNum(int)));
        QObject::connect(tblDots, SIGNAL(doubleClicked(QModelIndex)), GeneratorQTClass, SLOT(editDot()));
        QObject::connect(btnStart, SIGNAL(toggled(bool)), GeneratorQTClass, SLOT(startStop(bool)));
        QObject::connect(cbMidiIn, SIGNAL(currentIndexChanged(int)), GeneratorQTClass, SLOT(midiInChanged(int)));
        QObject::connect(cbMidiOut, SIGNAL(currentIndexChanged(int)), GeneratorQTClass, SLOT(midiOutChanged(int)));
        QObject::connect(cbSync, SIGNAL(toggled(bool)), GeneratorQTClass, SLOT(externalSync(bool)));

        QMetaObject::connectSlotsByName(GeneratorQTClass);
    } // setupUi

    void retranslateUi(QMainWindow *GeneratorQTClass)
    {
        GeneratorQTClass->setWindowTitle(QApplication::translate("GeneratorQTClass", "GeneratorQT", 0));
        label->setText(QApplication::translate("GeneratorQTClass", "BPM", 0));
        lblSpeed->setText(QApplication::translate("GeneratorQTClass", "BPM", 0));
        QTableWidgetItem *___qtablewidgetitem = tblDots->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("GeneratorQTClass", "Id", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tblDots->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("GeneratorQTClass", "Note", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tblDots->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("GeneratorQTClass", "Value", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tblDots->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("GeneratorQTClass", "Gate", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tblDots->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("GeneratorQTClass", "Vel", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tblDots->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("GeneratorQTClass", "Varianz", 0));
        btnStart->setText(QApplication::translate("GeneratorQTClass", "Start!", 0));
        lblMidiIn->setText(QApplication::translate("GeneratorQTClass", "Midi In", 0));
        cbSync->setText(QApplication::translate("GeneratorQTClass", "Ext. Sync", 0));
        lblMidiOut->setText(QApplication::translate("GeneratorQTClass", "Midi Out", 0));
        menu_Regeln->setTitle(QApplication::translate("GeneratorQTClass", "&Regeln", 0));
    } // retranslateUi

};

namespace Ui {
    class GeneratorQTClass: public Ui_GeneratorQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATORQT_H
