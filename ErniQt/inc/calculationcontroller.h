#ifndef CALCULATIONCONTROLLER_H
#define CALCULATIONCONTROLLER_H

#include <QObject>
#include "calculationmodel.h"

class CalculationController : public QObject
{
    Q_OBJECT
public:
    explicit CalculationController(QObject *parent = nullptr);

    const CalculationModel& getCalculationModel() const;

public slots:
    void makeCalculation();

private:
    CalculationModel m_calcModel;
};

#endif // CALCULATIONCONTROLLER_H
