/********************************************************************************
** Form generated from reading UI file 'dlgdotedit.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGDOTEDIT_H
#define UI_DLGDOTEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dlgDotEdit
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *cbValue;
    QLabel *lblValue;
    QComboBox *cbGate;
    QLabel *lblGate;
    QWidget *layoutWidget;
    QHBoxLayout *lytNote;
    QComboBox *cbNote;
    QLabel *lblNote;
    QWidget *layoutWidget_2;
    QHBoxLayout *lytVarianz;
    QLabel *lblVarianzValue;
    QSlider *slVarianz;
    QWidget *layoutWidget1;
    QHBoxLayout *lytVelocity;
    QLabel *lblVelocityValue;
    QSlider *slVelocity;
    QWidget *layoutWidget2;
    QHBoxLayout *lytVelVar;
    QLabel *lblVelocity;
    QLabel *lblVarianz;
    QLabel *lblDotId;

    void setupUi(QDialog *dlgDotEdit)
    {
        if (dlgDotEdit->objectName().isEmpty())
            dlgDotEdit->setObjectName(QStringLiteral("dlgDotEdit"));
        dlgDotEdit->setWindowModality(Qt::WindowModal);
        dlgDotEdit->resize(303, 276);
        buttonBox = new QDialogButtonBox(dlgDotEdit);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 250, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        cbValue = new QComboBox(dlgDotEdit);
        cbValue->setObjectName(QStringLiteral("cbValue"));
        cbValue->setGeometry(QRect(10, 50, 69, 20));
        lblValue = new QLabel(dlgDotEdit);
        lblValue->setObjectName(QStringLiteral("lblValue"));
        lblValue->setGeometry(QRect(85, 50, 47, 20));
        cbGate = new QComboBox(dlgDotEdit);
        cbGate->setObjectName(QStringLiteral("cbGate"));
        cbGate->setGeometry(QRect(15, 90, 69, 20));
        lblGate = new QLabel(dlgDotEdit);
        lblGate->setObjectName(QStringLiteral("lblGate"));
        lblGate->setGeometry(QRect(90, 90, 47, 20));
        layoutWidget = new QWidget(dlgDotEdit);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 11, 124, 22));
        lytNote = new QHBoxLayout(layoutWidget);
        lytNote->setSpacing(6);
        lytNote->setContentsMargins(11, 11, 11, 11);
        lytNote->setObjectName(QStringLiteral("lytNote"));
        lytNote->setContentsMargins(0, 0, 0, 0);
        cbNote = new QComboBox(layoutWidget);
        cbNote->setObjectName(QStringLiteral("cbNote"));

        lytNote->addWidget(cbNote);

        lblNote = new QLabel(layoutWidget);
        lblNote->setObjectName(QStringLiteral("lblNote"));

        lytNote->addWidget(lblNote);

        layoutWidget_2 = new QWidget(dlgDotEdit);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(220, 10, 67, 211));
        lytVarianz = new QHBoxLayout(layoutWidget_2);
        lytVarianz->setSpacing(6);
        lytVarianz->setContentsMargins(11, 11, 11, 11);
        lytVarianz->setObjectName(QStringLiteral("lytVarianz"));
        lytVarianz->setContentsMargins(0, 0, 0, 0);
        lblVarianzValue = new QLabel(layoutWidget_2);
        lblVarianzValue->setObjectName(QStringLiteral("lblVarianzValue"));

        lytVarianz->addWidget(lblVarianzValue);

        slVarianz = new QSlider(layoutWidget_2);
        slVarianz->setObjectName(QStringLiteral("slVarianz"));
        slVarianz->setMaximum(47);
        slVarianz->setOrientation(Qt::Vertical);

        lytVarianz->addWidget(slVarianz);

        layoutWidget1 = new QWidget(dlgDotEdit);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(150, 10, 67, 211));
        lytVelocity = new QHBoxLayout(layoutWidget1);
        lytVelocity->setSpacing(6);
        lytVelocity->setContentsMargins(11, 11, 11, 11);
        lytVelocity->setObjectName(QStringLiteral("lytVelocity"));
        lytVelocity->setContentsMargins(0, 0, 0, 0);
        lblVelocityValue = new QLabel(layoutWidget1);
        lblVelocityValue->setObjectName(QStringLiteral("lblVelocityValue"));

        lytVelocity->addWidget(lblVelocityValue);

        slVelocity = new QSlider(layoutWidget1);
        slVelocity->setObjectName(QStringLiteral("slVelocity"));
        slVelocity->setMaximum(127);
        slVelocity->setValue(80);
        slVelocity->setOrientation(Qt::Vertical);

        lytVelocity->addWidget(slVelocity);

        layoutWidget2 = new QWidget(dlgDotEdit);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(150, 220, 141, 20));
        lytVelVar = new QHBoxLayout(layoutWidget2);
        lytVelVar->setSpacing(6);
        lytVelVar->setContentsMargins(11, 11, 11, 11);
        lytVelVar->setObjectName(QStringLiteral("lytVelVar"));
        lytVelVar->setContentsMargins(0, 0, 0, 0);
        lblVelocity = new QLabel(layoutWidget2);
        lblVelocity->setObjectName(QStringLiteral("lblVelocity"));
        QFont font;
        font.setPointSize(10);
        lblVelocity->setFont(font);

        lytVelVar->addWidget(lblVelocity);

        lblVarianz = new QLabel(layoutWidget2);
        lblVarianz->setObjectName(QStringLiteral("lblVarianz"));
        lblVarianz->setFont(font);

        lytVelVar->addWidget(lblVarianz);

        lblDotId = new QLabel(dlgDotEdit);
        lblDotId->setObjectName(QStringLiteral("lblDotId"));
        lblDotId->setGeometry(QRect(20, 150, 47, 41));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        lblDotId->setFont(font1);
        lblDotId->setFrameShape(QFrame::StyledPanel);
        lblDotId->setFrameShadow(QFrame::Sunken);
        lblDotId->setLineWidth(4);
        lblDotId->setAlignment(Qt::AlignCenter);
        layoutWidget->raise();
        buttonBox->raise();
        cbValue->raise();
        lblValue->raise();
        cbGate->raise();
        lblGate->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget_2->raise();
        lblDotId->raise();
#ifndef QT_NO_SHORTCUT
        lblValue->setBuddy(cbValue);
        lblGate->setBuddy(cbGate);
        lblNote->setBuddy(cbNote);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(cbNote, cbValue);
        QWidget::setTabOrder(cbValue, cbGate);
        QWidget::setTabOrder(cbGate, slVelocity);
        QWidget::setTabOrder(slVelocity, slVarianz);

        retranslateUi(dlgDotEdit);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgDotEdit, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgDotEdit, SLOT(reject()));
        QObject::connect(slVelocity, SIGNAL(valueChanged(int)), lblVelocityValue, SLOT(setNum(int)));
        QObject::connect(slVarianz, SIGNAL(valueChanged(int)), lblVarianzValue, SLOT(setNum(int)));
        QObject::connect(slVelocity, SIGNAL(valueChanged(int)), dlgDotEdit, SLOT(varianzMax(int)));

        QMetaObject::connectSlotsByName(dlgDotEdit);
    } // setupUi

    void retranslateUi(QDialog *dlgDotEdit)
    {
        dlgDotEdit->setWindowTitle(QApplication::translate("dlgDotEdit", "Spielsteine \303\244ndern", 0));
        lblValue->setText(QApplication::translate("dlgDotEdit", "Value", 0));
        lblGate->setText(QApplication::translate("dlgDotEdit", "Gate", 0));
        lblNote->setText(QApplication::translate("dlgDotEdit", "Note", 0));
        lblVarianzValue->setText(QApplication::translate("dlgDotEdit", "Varianz", 0));
        lblVelocityValue->setText(QApplication::translate("dlgDotEdit", "Velocity", 0));
        lblVelocity->setText(QApplication::translate("dlgDotEdit", "Velocity", 0));
        lblVarianz->setText(QApplication::translate("dlgDotEdit", "Varianz", 0));
        lblDotId->setText(QApplication::translate("dlgDotEdit", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class dlgDotEdit: public Ui_dlgDotEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGDOTEDIT_H
