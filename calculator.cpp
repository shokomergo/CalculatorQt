#include "calculator.h"
#include <QHBoxLayout>
#include <QString>

Calculator::Calculator(QWidget *parent)
    :QWidget(parent), firstNumber(0)
{
    display = new QLineEdit(this);
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setFixedHeight(40);

    for(int i = 0; i < 10; i++) {
        buttons[i] = new QPushButton(QString::number(i), this);
            buttons[i]->setFixedSize(40, 40);
            connect(buttons[i], &QPushButton::clicked, this, &Calculator::numberClicked);
        }

    btnPlus = new QPushButton("+", this);
    btnMinus = new QPushButton("-", this);
    btnMul = new QPushButton("*", this);
    btnDiv = new QPushButton("/", this);
    btnEqual = new QPushButton("=", this);
    btnClear = new QPushButton("C", this);

    QPushButton* ops[] = { btnPlus, btnMinus, btnMul, btnDiv, btnEqual, btnClear};
    for (auto b : ops) {
        b->setFixedSize(40, 40);
    }

    connect(btnPlus, &QPushButton::clicked, this, &Calculator::operatorClicked);
    connect(btnMinus, &QPushButton::clicked, this, &Calculator::operatorClicked);
    connect(btnMul, &QPushButton::clicked, this, &Calculator::operatorClicked);
    connect(btnDiv, &QPushButton::clicked, this, &Calculator::operatorClicked);
    connect(btnEqual, &QPushButton::clicked, this, &Calculator::equalClicked);
    connect(btnClear, &QPushButton::clicked, this, &Calculator::clearClicked);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(display);

    QGridLayout *grid = new QGridLayout();

    int k = 1;
    for(int row = 0; row < 3; ++row) {
        for(int col = 0; col < 3; ++col) {
            grid->addWidget(buttons[k++], row, col);
        }
    }
    grid->addWidget(buttons[0], 3, 1);

    grid->addWidget(btnPlus, 0, 3);
    grid->addWidget(btnMinus, 1, 3);
    grid->addWidget(btnMul, 2, 3);
    grid->addWidget(btnDiv, 3, 3);
    grid->addWidget(btnEqual, 3, 2);
    grid->addWidget(btnClear, 3, 0);

    mainLayout->addLayout(grid);
    setLayout(mainLayout);
}

void Calculator::numberClicked()
{
    QPushButton* b = qobject_cast<QPushButton*>(sender());
    display->setText(display->text() + b->text());
}

void Calculator::operatorClicked()
{
    QPushButton* b = qobject_cast<QPushButton*>(sender());
    firstNumber = display->text().toDouble();
    operation = b->text();
    display->clear();
}

void Calculator::equalClicked()
{
    double secondNumber = display->text().toDouble();
    double result = 0;

    if (operation == "+") result = firstNumber + secondNumber;
    else if (operation == "-") result = firstNumber - secondNumber;
    else if (operation == "*") result = firstNumber * secondNumber;
    else if (operation == "/"){
        if(secondNumber != 0)
            result = firstNumber / secondNumber;
        else
            result = 0;
        }


    display->setText(QString::number(result));
}

void Calculator::clearClicked()
{
        display->clear();
        firstNumber = 0;
        operation.clear();
}





