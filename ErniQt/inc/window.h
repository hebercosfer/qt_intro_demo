#ifndef WINDOW_H
#define WINDOW_H
#include <QWidget>

class QPushButton;
class QLineEdit;
class QLabel;
class CalculationModel;

class Window : public QWidget
{
Q_OBJECT
public:
    explicit Window(const CalculationModel& model, QWidget* parent = nullptr);
    virtual ~Window() = default;

signals:
    void firstValueChanged(int);
    void secondValueChanged(int);
    void operatorChanged(char);

private slots:
    void sendFirstValueChanged(const QString&);
    void sendSecondValueChanged(const QString&);
    void sendOperatorChanged(const QString&);

    void setResultValue(int result);

private:
    QPushButton* m_solveButton;
    QLabel* m_operatorLabel;
    QLineEdit* m_firstValueInput;
    QLineEdit* m_secondValueInput;
    QLabel* m_equalLabel;
    QLineEdit* m_resultInput;
};

#endif // WINDOW_H
