#include <QtWidgets>

#include "finddialog.h"

FindDialog::FindDialog(QWidget* parent) : QDialog(parent) {
    
    label = new QLabel(tr("&Localizar"));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);
    
    caseCheckBox = new QCheckBox(tr("&Diferenciar maiúsculas/minúsculas"));
    backwardCheckBox = new QCheckBox(tr("Procurar &retroativamente"));
    
    findButton = new QPushButton(tr("&Procurar"));
    findButton->setDefault(true);
    findButton->setEnabled(false);
    
    closeButton = new QPushButton(tr("&Fechar"));
    
    connect(lineEdit, SIGNAL(textChanged(const QString &)), 
            this, SLOT(enableFindButton(const QString &)));
    connect(findButton, SIGNAL(clicked()), 
            this, SLOT(findClicked()));
    connect(closeButton, SIGNAL(clicked()), 
            this, SLOT(close()));
    
    QHBoxLayout* topLeft = new QHBoxLayout;
    topLeft->addWidget(label);
    topLeft->addWidget(lineEdit);
    
    QVBoxLayout* left = new QVBoxLayout;
    left->addLayout(topLeft);
    left->addWidget(caseCheckBox);
    left->addWidget(backwardCheckBox);
    topLeft->addWidget(label);
    
    QVBoxLayout* right = new QVBoxLayout;
    right->addWidget(findButton);
    right->addWidget(closeButton);
    right->addStretch();
    
    QHBoxLayout* main = new QHBoxLayout;
    main->addLayout(left);
    main->addLayout(right);
    
    setLayout(main);
    setWindowTitle(tr("Procurar"));
    setFixedHeight(sizeHint().height());
}

void FindDialog::findClicked() {
    
    QString text = lineEdit->text();
    Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive 
                                                       : Qt::CaseInsensitive;
    
    if(backwardCheckBox->isChecked())
        emit findPrevious(text, cs);
    else
        emit findNext(text, cs);
}

void FindDialog::enableFindButton(const QString &text){
    
    findButton->setEnabled(!text.isEmpty());
}
