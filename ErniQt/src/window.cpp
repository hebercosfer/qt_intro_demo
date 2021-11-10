#include "window.h"
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QIntValidator>
#include "calculationmodel.h"

Window::Window(const CalculationModel& model, QWidget* parent)
    : QWidget(parent)
{
    setFixedSize(260,80);

    //m_solveButton = new QPushButton("Solve", this);
    m_operatorLabel = new QLabel("+", this);
    m_firstValueInput = new QLineEdit("0", this);
    m_secondValueInput = new QLineEdit("0", this);
    m_equalLabel = new QLabel("=", this);
    m_resultInput = new QLineEdit("0", this);

    m_firstValueInput->setGeometry(10,20,40,40);
    m_operatorLabel->setGeometry(55,35,10,10);
    m_secondValueInput->setGeometry(70,20,40,40);
    m_equalLabel->setGeometry(115,35,10,10);
    m_resultInput->setGeometry(130,20,40,40);
    //m_solveButton->setGeometry(170,20,60,40);

    m_firstValueInput->setValidator( new QIntValidator(0, 100, this) );
    m_secondValueInput->setValidator( new QIntValidator(0, 100, this) );
    m_resultInput->setReadOnly(true);

    //connect(m_solveButton, &QPushButton::clicked, this, &Window::makeCalculation);
    connect(m_firstValueInput, &QLineEdit::textChanged, this, &Window::sendFirstValueChanged);
    connect(m_secondValueInput, &QLineEdit::returnPressed, [this]() {emit secondValueChanged(m_secondValueInput->text().toInt());});

    connect(this, &Window::firstValueChanged, &model, &CalculationModel::setFirstValue);
    connect(this, &Window::secondValueChanged, &model, &CalculationModel::setSecondValue);
    connect(this, &Window::operatorChanged, &model, &CalculationModel::setCalcOperator);

    connect(&model, &CalculationModel::resultValueChanged, this, &Window::setResultValue);
}

void Window::sendFirstValueChanged(const QString& text)
{
    emit firstValueChanged(text.toInt());
}

void Window::sendSecondValueChanged(const QString& text)
{
    emit secondValueChanged(text.toInt());
}

void Window::sendOperatorChanged(const QString& text)
{
    emit operatorChanged(text.at(0).toLatin1());
}

void Window::setResultValue(int result)
{
    m_resultInput->setText(QString::number(result));
}
