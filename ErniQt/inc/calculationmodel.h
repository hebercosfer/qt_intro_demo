#ifndef CALCULATIONMODEL_H
#define CALCULATIONMODEL_H

#include <QObject>

class CalculationModel : public QObject
{
    Q_OBJECT
public:
    explicit CalculationModel(QObject *parent = nullptr);
    virtual ~CalculationModel() = default;

    const int& getFirstValue() const;
    const int& getSecondValue() const;
    const int& getResultValue() const;
    const char& getCalcOperator() const;

public slots:
    void setFirstValue(int firstValue);
    void setSecondValue(int secondValue);
    void setResultValue(int resultValue);
    void setCalcOperator(char calcOperator);

signals:
    void firstValueChanged(int firstValue);
    void secondValueChanged(int secondValue);
    void resultValueChanged(int resultValue);
    void calcOperatorChanged(char calcOperator);

private:
    int m_firstValue;
    int m_secondValue;
    int m_resultValue;
    char m_calcOperator;
};

#endif // CALCULATIONMODEL_H
