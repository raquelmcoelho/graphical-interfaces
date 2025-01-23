#include "mainwindow.h"

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QMenu *file = new QMenu("File");
    QMenu *options = new QMenu("Options");
    QMenu *help = new QMenu("Help");

    QAction* exit = new QAction(tr("&Exit"), this);
    exit->setShortcuts(QKeySequence::Quit);
    exit->setStatusTip(tr("Exit"));
    connect(exit, &QAction::triggered, this, &MainWindow::onExit);
    file->addAction(exit);

    QAction* about = new QAction(tr("&About"), this);
    about->setShortcuts(QKeySequence::HelpContents);
    about->setStatusTip(tr("Exit"));
    connect(about, &QAction::triggered, this, &MainWindow::onAbout);
    help->addAction(about);

    this->menuBar()->addMenu(file);
    this->menuBar()->addMenu(options);
    this->menuBar()->addMenu(help);

    QLabel *label = new QLabel("Calculatrice");
    QLineEdit *lineEdit = new QLineEdit("0");
    lineEdit->setAlignment(Qt::AlignRight);
    lineEdit->setReadOnly(true);
    QWidget *mainWidget = new QWidget();
    QWidget *buttonWidget = new QWidget();
    QVBoxLayout *vboxLayout = new QVBoxLayout(nullptr);
    QGridLayout *gridLayout = new QGridLayout(nullptr);

    QPushButton *buttonA = new QPushButton("A");
    QPushButton *buttonB = new QPushButton("B");
    QPushButton *buttonC = new QPushButton("C");
    QPushButton *buttonD = new QPushButton("D");
    QPushButton *buttonE = new QPushButton("E");
    QPushButton *buttonF = new QPushButton("F");

    buttonA->setEnabled(false);
    buttonB->setEnabled(false);
    buttonC->setEnabled(false);
    buttonD->setEnabled(false);
    buttonE->setEnabled(false);
    buttonF->setEnabled(false);

    QPushButton *buttonPlus = new QPushButton("+");
    QPushButton *buttonMinus = new QPushButton("-");
    QPushButton *buttonDivide = new QPushButton("/");
    QPushButton *buttonTimes = new QPushButton("*");
    QPushButton *buttonEquals = new QPushButton("=");
    QPushButton *buttonComma = new QPushButton(",");
    QPushButton *buttonClear = new QPushButton("C");
    QPushButton *buttonQuit = new QPushButton("Quit");
    QPushButton *button0 = new QPushButton("0");
    QPushButton *button1 = new QPushButton("1");
    QPushButton *button2 = new QPushButton("2");
    QPushButton *button3 = new QPushButton("3");
    QPushButton *button4 = new QPushButton("4");
    QPushButton *button5 = new QPushButton("5");
    QPushButton *button6 = new QPushButton("6");
    QPushButton *button7 = new QPushButton("7");
    QPushButton *button8 = new QPushButton("8");
    QPushButton *button9 = new QPushButton("9");

    QLabel *baseLabel = new QLabel("Base");
    baseLabel->setAlignment(Qt::AlignRight | Qt::AlignBaseline);

    QComboBox *baseSelection = new QComboBox;
    baseSelection->addItem(tr("Bin"));
    baseSelection->addItem(tr("Dec"));
    baseSelection->addItem(tr("Hex"));

    gridLayout->addWidget(buttonE, 0, 0);
    gridLayout->addWidget(buttonF, 0, 1);
    gridLayout->addWidget(baseLabel, 0, 2);
    gridLayout->addWidget(baseSelection, 0, 3);

    gridLayout->addWidget(buttonA, 1, 0);
    gridLayout->addWidget(buttonB, 1, 1);
    gridLayout->addWidget(buttonC, 1, 2);
    gridLayout->addWidget(buttonD, 1, 3);

    gridLayout->addWidget(button7, 2, 0);
    gridLayout->addWidget(button8, 2, 1);
    gridLayout->addWidget(button9, 2, 2);
    gridLayout->addWidget(buttonPlus, 2, 3);

    gridLayout->addWidget(button4, 3, 0);
    gridLayout->addWidget(button5, 3, 1);
    gridLayout->addWidget(button6, 3, 2);
    gridLayout->addWidget(buttonMinus, 3, 3);

    gridLayout->addWidget(button1, 4, 0);
    gridLayout->addWidget(button2, 4, 1);
    gridLayout->addWidget(button3, 4, 2);
    gridLayout->addWidget(buttonDivide, 4, 3);

    gridLayout->addWidget(button0, 5, 0);
    gridLayout->addWidget(buttonComma, 5, 1);
    gridLayout->addWidget(buttonEquals, 5, 2);
    gridLayout->addWidget(buttonTimes, 5, 3);


    vboxLayout->addWidget(label);
    vboxLayout->addWidget(lineEdit);
    vboxLayout->addWidget(buttonWidget);
    vboxLayout->addWidget(buttonClear);
    vboxLayout->addWidget(buttonQuit);
    mainWidget->setLayout(vboxLayout);
    buttonWidget->setLayout(gridLayout);
    this->setCentralWidget(mainWidget);
}

MainWindow::~MainWindow() {
    // TODO: clean pointers created?
}

void MainWindow::onExit(bool checked) {
    qDebug() << "Exit: " << checked;
}


void MainWindow::onAbout(bool checked) {
    qDebug() << "About: " << checked;
    QMessageBox dialog = QMessageBox();
    dialog.setText("Calculatrice \n(c) Sébastien Fourey");
    QMessageBox::about(this, "About", "Calculatrice \n(c) Sébastien Fourey");
}
