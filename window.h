#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QFile>
#include <QLineEdit>
#include <QPushButton>
#include <QTextStream>

class QPushButton;
class QLineEdit;
class QFile;
class QTextStream;
class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
private slots:
    void slotButtonClicked();
private:
    QPushButton *m_button;
    QLineEdit *m_text;
signals:

};

#endif // WINDOW_H
