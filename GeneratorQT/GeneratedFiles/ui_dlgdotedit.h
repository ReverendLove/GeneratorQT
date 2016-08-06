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
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_dlgDotEdit
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dlgDotEdit)
    {
        if (dlgDotEdit->objectName().isEmpty())
            dlgDotEdit->setObjectName(QStringLiteral("dlgDotEdit"));
        dlgDotEdit->setWindowModality(Qt::WindowModal);
        dlgDotEdit->resize(400, 300);
        buttonBox = new QDialogButtonBox(dlgDotEdit);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(210, 260, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(dlgDotEdit);
        QObject::connect(buttonBox, SIGNAL(accepted()), dlgDotEdit, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dlgDotEdit, SLOT(reject()));

        QMetaObject::connectSlotsByName(dlgDotEdit);
    } // setupUi

    void retranslateUi(QDialog *dlgDotEdit)
    {
        dlgDotEdit->setWindowTitle(QApplication::translate("dlgDotEdit", "dlgDotEdit", 0));
    } // retranslateUi

};

namespace Ui {
    class dlgDotEdit: public Ui_dlgDotEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGDOTEDIT_H
