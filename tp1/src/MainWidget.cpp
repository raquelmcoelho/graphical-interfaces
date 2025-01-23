/**
 * @file   MainWidget.cpp
 * @author Sebastien Fourey
 */
#include "MainWidget.h"
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QString>
#include "ColorWidget.h"
using namespace std;

MainWidget::MainWidget(QWidget * parent) : QWidget(parent)
{
  this->setWindowTitle("Vinicius and Raquel TP");
  setGeometry(100, 100, 640, 480);

  QLabel * label = new QLabel("Colors, signals, and slots", this);
  label->setGeometry(10, 10, 290, 30);
  label->setFont(QFont("Arial", 14, QFont::Bold));

  _colorValueDisplay = new QLineEdit(this);
  _colorValueDisplay->setReadOnly(true);
  _colorValueDisplay->setGeometry(200, 120, 300, 30);
  _colorValueDisplay->setAlignment(Qt::AlignHCenter);

  _mousePositionDisplay = new QLineEdit(this);
  _mousePositionDisplay->setReadOnly(true);
  _mousePositionDisplay->setGeometry(200, 160, 300, 30);
  _mousePositionDisplay->setAlignment(Qt::AlignHCenter);

  ColorWidget * colorWidget = new ColorWidget(this);
  colorWidget->setGeometry(300, 200, 80, 30);

  QPushButton * pushButtonRandomColor = new QPushButton("Random color", this);
  pushButtonRandomColor->setGeometry(260, 240, 160, 30);

  QPushButton * pushButtonQuiter = new QPushButton("Quit", this);
  pushButtonQuiter->setGeometry(260, 340, 160, 30);

  connect(pushButtonRandomColor, &QPushButton::clicked, colorWidget, &ColorWidget::changeColor);
  connect(pushButtonQuiter, &QPushButton::clicked, this, &MainWidget::onQuitPressed);
  connect(colorWidget, SIGNAL(colorChanged(int, int, int)), this, SLOT(onColorChanged(int, int, int)));
}

void MainWidget::onQuitPressed()
{
  QMessageBox::StandardButton button = QMessageBox::question(this, "You want to quit...",
                                                             "Are you sure that you want to quit"
                                                             " this great application?",
                                                             QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
  if (button == QMessageBox::Yes) {
    close();
  }
}

void MainWidget::onColorChanged(int r, int g, int b)
{
  QString text("Color: R(%1) G(%2) B(%3)");
  _colorValueDisplay->setText(text.arg(r).arg(g).arg(b));
}

    void MainWidget::updateMousePosition(const QPoint &pos, Qt::MouseButton button) {
      QString positionText = QString("(%1, %2)").arg(pos.x()).arg(pos.y());

      if (button == Qt::LeftButton) {
        _mousePositionDisplay->setAlignment(Qt::AlignLeft);
      } else if (button == Qt::RightButton) {
        _mousePositionDisplay->setAlignment(Qt::AlignRight);
      } else if (button == Qt::MiddleButton) {
        _mousePositionDisplay->setAlignment(Qt::AlignCenter);
      }

      _mousePositionDisplay->setText(positionText);

      _mousePositionDisplay->repaint();
    }

    void MainWidget::mouseMoveEvent(QMouseEvent *event) {
      Qt::MouseButton button = Qt::NoButton;
      if (event->buttons() & Qt::LeftButton) {
        button = Qt::LeftButton;
      } else if (event->buttons() & Qt::RightButton) {
        button = Qt::RightButton;
      } else if (event->buttons() & Qt::MiddleButton) {
        button = Qt::MiddleButton;
      }

      updateMousePosition(event->pos(), button);
    }
