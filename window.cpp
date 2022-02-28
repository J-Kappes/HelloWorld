#include "window.h"
#include <QLineEdit>
#include <QPushButton>
#include <QFile>

Window::Window(QWidget *parent) :
 QWidget(parent)
{
 // Set size of the window
 setFixedSize(400, 50);

 // Create and position the button
m_button = new QPushButton("Save", this);
m_button->setGeometry(260, 10, 80, 30);

// Create, position and fill Line Editor
m_text = new QLineEdit (this);
m_text->setGeometry(10,10,240,30);
QFile data("./save.txt");
data.open(QFile::ReadOnly);
QTextStream in(&data);
m_text->setText(in.readAll());
data.close();

//Connect Save button to method
connect(m_button, SIGNAL (clicked()), this, SLOT (slotButtonClicked()));
}

void Window::slotButtonClicked( )
{
    QFile data("./save.txt");
    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&data);
        out << m_text->text();
    }
}

