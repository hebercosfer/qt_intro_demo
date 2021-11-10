#include "calculationmodel.h"

CalculationModel::CalculationModel(QObject *parent)
    : QObject(parent),
      m_firstValue(0),
      m_secondValue(0),
      m_calcOperator('+')
{
}

void CalculationModel::setFirstValue(int firstValue)
{
    if (m_firstValue != firstValue)
    {
        m_firstValue = firstValue;
        emit firstValueChanged(m_firstValue);
    }
}

void CalculationModel::setSecondValue(int secondValue)
{
    if (m_secondValue != secondValue)
    {
        m_secondValue = secondValue;
        emit secondValueChanged(m_secondValue);
    }
}

void CalculationModel::setResultValue(int resultValue)
{
    if (m_resultValue != resultValue)
    {
        m_resultValue = resultValue;
        emit resultValueChanged(m_resultValue);
    }
}

void CalculationModel::setCalcOperator(char calcOperator)
{
    if (m_calcOperator != calcOperator)
    {
        m_calcOperator = calcOperator;
        emit calcOperatorChanged(m_calcOperator);
    }
}

const int& CalculationModel::getFirstValue() const
{
    return m_firstValue;
}

const int& CalculationModel::getSecondValue() const
{
    return m_secondValue;
}

const int& CalculationModel::getResultValue() const
{
    return m_resultValue;
}

const char& CalculationModel::getCalcOperator() const
{
    return m_calcOperator;
}
