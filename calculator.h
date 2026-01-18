#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);

private slots:
    void numberClicked();
    void operatorClicked();
    void equalClicked();
    void clearClicked();

private:
    QLineEdit *display;
    QPushButton *buttons[10];
    QPushButton *btnPlus;
    QPushButton *btnMinus;
    QPushButton *btnMul;
    QPushButton *btnDiv;
    QPushButton *btnEqual;
    QPushButton *btnClear;

    double firstNumber;
    QString operation;
};

#endif
