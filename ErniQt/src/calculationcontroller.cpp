#include "calculationcontroller.h"

CalculationController::CalculationController(QObject *parent)
    : QObject(parent),
      m_calcModel(this)
{
    connect(&m_calcModel, &CalculationModel::firstValueChanged, this, &CalculationController::makeCalculation);
    connect(&m_calcModel, &CalculationModel::secondValueChanged, this, &CalculationController::makeCalculation);
    connect(&m_calcModel, &CalculationModel::calcOperatorChanged, this, &CalculationController::makeCalculation);
}

const CalculationModel& CalculationController::getCalculationModel() const
{
    return m_calcModel;
}

void CalculationController::makeCalculation()
{
    int result = 0;
    switch (m_calcModel.getCalcOperator())
    {
    case '+':
        result = m_calcModel.getFirstValue() + m_calcModel.getSecondValue();
        break;
    }

    m_calcModel.setResultValue(result);
}
