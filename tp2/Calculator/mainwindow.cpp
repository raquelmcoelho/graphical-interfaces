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
#include <QButtonGroup>
#include <QShortcut>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Menu Buttons
    QMenu *file = new QMenu("File");
    QMenu *options = new QMenu("Options");
    QMenu *help = new QMenu("Help");

    // Menu SubItems
    QAction* exit = new QAction(tr("&Exit"), this);
    exit->setShortcuts(QKeySequence::Quit);
    exit->setStatusTip(tr("Exit"));
    connect(exit, &QAction::triggered, this, &MainWindow::onExit);
    file->addAction(exit);

    QAction* suffix = new QAction(tr("&Suffix"), this);
    suffix->setCheckable(true);
    options->addAction(suffix);

    QAction* about = new QAction(tr("&About"), this);
    about->setShortcuts(QKeySequence::HelpContents);
    about->setStatusTip(tr("Exit"));
    connect(about, &QAction::triggered, this, &MainWindow::onAbout);
    help->addAction(about);

    this->menuBar()->addMenu(file);
    this->menuBar()->addMenu(options);
    this->menuBar()->addMenu(help);

    // App Widgets
    QVBoxLayout *vboxLayout = new QVBoxLayout(nullptr);
    QWidget *mainWidget = new QWidget();
    QGridLayout *gridLayout = new QGridLayout(nullptr);
    QWidget *buttonWidget = new QWidget();

    QLabel *label = new QLabel("Calculatrice");
    QLineEdit *lineEdit = new QLineEdit("0");
    lineEdit->setAlignment(Qt::AlignRight);
    lineEdit->setReadOnly(true);
    connect(this, &MainWindow::write, [=](QString text) {
        if (suffix->isChecked()) {
            switch (model.base()) {
            case CalculatorModel::Base::Bin:
                text.append("b");
                break;
            case CalculatorModel::Base::Hex:
                text.append("h");
                break;
            default:
                break;
            }
        }

        lineEdit->setText(text);
    });

    QPushButton *buttonPlus = new QPushButton("+");
    QPushButton *buttonMinus = new QPushButton("-");
    QPushButton *buttonDivide = new QPushButton("/");
    QPushButton *buttonMultiply = new QPushButton("*");
    QPushButton *buttonEqual = new QPushButton("=");
    QPushButton *buttonComma = new QPushButton(",");
    QPushButton *buttonClear = new QPushButton("C");
    QPushButton *buttonQuit = new QPushButton("Quit");
    QPushButton *buttonA = new QPushButton("A");
    QPushButton *buttonB = new QPushButton("B");
    QPushButton *buttonC = new QPushButton("C");
    QPushButton *buttonD = new QPushButton("D");
    QPushButton *buttonE = new QPushButton("E");
    QPushButton *buttonF = new QPushButton("F");
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

    // Mapping Shortcuts
    button0->setShortcut(QKeySequence(Qt::Key_0));
    button1->setShortcut(QKeySequence(Qt::Key_1));
    button2->setShortcut(QKeySequence(Qt::Key_2));
    button3->setShortcut(QKeySequence(Qt::Key_3));
    button4->setShortcut(QKeySequence(Qt::Key_4));
    button5->setShortcut(QKeySequence(Qt::Key_5));
    button6->setShortcut(QKeySequence(Qt::Key_6));
    button7->setShortcut(QKeySequence(Qt::Key_7));
    button8->setShortcut(QKeySequence(Qt::Key_8));
    button9->setShortcut(QKeySequence(Qt::Key_9));
    buttonA->setShortcut(QKeySequence(Qt::Key_A));
    buttonB->setShortcut(QKeySequence(Qt::Key_B));
    buttonC->setShortcut(QKeySequence(Qt::Key_C));
    buttonD->setShortcut(QKeySequence(Qt::Key_D));
    buttonE->setShortcut(QKeySequence(Qt::Key_E));
    buttonF->setShortcut(QKeySequence(Qt::Key_F));
    buttonPlus->setShortcut(QKeySequence(Qt::Key_Plus));
    buttonMinus->setShortcut(QKeySequence(Qt::Key_Minus));
    buttonDivide->setShortcut(QKeySequence(Qt::Key_Slash));
    buttonMultiply->setShortcut(QKeySequence(Qt::Key_Asterisk));
    buttonEqual->setShortcut(QKeySequence(Qt::Key_Equal));
    buttonComma->setShortcut(QKeySequence(Qt::Key_Comma));
    buttonClear->setShortcut(QKeySequence(Qt::Key_Clear));

    QShortcut *enterShortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
    QShortcut *equalShortcut = new QShortcut(QKeySequence(Qt::Key_Enter), this);
    connect(enterShortcut, &QShortcut::activated, buttonEqual, &QPushButton::click);
    connect(equalShortcut, &QShortcut::activated, buttonEqual, &QPushButton::click);



    // Linking click signal
    QButtonGroup *buttons = new QButtonGroup(this);
    buttons->addButton(button0,CalculatorModel::ButtonID::Button_0);
    buttons->addButton(button1,CalculatorModel::ButtonID::Button_1);
    buttons->addButton(button2,CalculatorModel::ButtonID::Button_2);
    buttons->addButton(button3,CalculatorModel::ButtonID::Button_3);
    buttons->addButton(button4,CalculatorModel::ButtonID::Button_4);
    buttons->addButton(button5,CalculatorModel::ButtonID::Button_5);
    buttons->addButton(button6,CalculatorModel::ButtonID::Button_6);
    buttons->addButton(button7,CalculatorModel::ButtonID::Button_7);
    buttons->addButton(button8,CalculatorModel::ButtonID::Button_8);
    buttons->addButton(button9,CalculatorModel::ButtonID::Button_9);
    buttons->addButton(buttonA,CalculatorModel::ButtonID::Button_A);
    buttons->addButton(buttonB,CalculatorModel::ButtonID::Button_B);
    buttons->addButton(buttonC,CalculatorModel::ButtonID::Button_C);
    buttons->addButton(buttonD,CalculatorModel::ButtonID::Button_D);
    buttons->addButton(buttonE,CalculatorModel::ButtonID::Button_E);
    buttons->addButton(buttonF,CalculatorModel::ButtonID::Button_F);
    buttons->addButton(buttonComma, CalculatorModel::ButtonID::Button_Dot);
    buttons->addButton(buttonPlus, CalculatorModel::ButtonID::Button_Plus);
    buttons->addButton(buttonMinus, CalculatorModel::ButtonID::Button_Minus);
    buttons->addButton(buttonDivide, CalculatorModel::ButtonID::Button_Divide);
    buttons->addButton(buttonMultiply, CalculatorModel::ButtonID::Button_Multiply);
    buttons->addButton(buttonEqual, CalculatorModel::ButtonID::Button_Equal);
    buttons->addButton(buttonClear, CalculatorModel::ButtonID::Button_Clear);

    connect(buttonQuit, &QPushButton::clicked, this, &MainWindow::onExit);
    connect(buttons, &QButtonGroup::idClicked, this, &MainWindow::onButtonClickedId);

    // Base control widgets
    QLabel *baseLabel = new QLabel("Base");
    baseLabel->setAlignment(Qt::AlignRight | Qt::AlignHCenter);

    // TODO: makes the first selection sends the signal
    QComboBox *baseSelection = new QComboBox;
    baseSelection->addItem(tr("Bin"));
    baseSelection->addItem(tr("Dec"));
    baseSelection->addItem(tr("Hex"));
    connect(baseSelection, &QComboBox::currentIndexChanged, [=](int index){
        // Cleans input
        write("0");

        // Disable useless buttons
        switch(index) {
        case 0:
            model.setBase(CalculatorModel::Base::Bin);
            buttonA->setEnabled(false);
            buttonB->setEnabled(false);
            buttonC->setEnabled(false);
            buttonD->setEnabled(false);
            buttonE->setEnabled(false);
            buttonF->setEnabled(false);
            button0->setEnabled(true);
            button1->setEnabled(true);
            button2->setEnabled(false);
            button3->setEnabled(false);
            button4->setEnabled(false);
            button5->setEnabled(false);
            button6->setEnabled(false);
            button7->setEnabled(false);
            button8->setEnabled(false);
            button9->setEnabled(false);
            buttonComma->setEnabled(false);
            break;
        case 2:
            model.setBase(CalculatorModel::Base::Hex);
            buttonA->setEnabled(true);
            buttonB->setEnabled(true);
            buttonC->setEnabled(true);
            buttonD->setEnabled(true);
            buttonE->setEnabled(true);
            buttonF->setEnabled(true);
            button0->setEnabled(true);
            button1->setEnabled(true);
            button2->setEnabled(true);
            button3->setEnabled(true);
            button4->setEnabled(true);
            button5->setEnabled(true);
            button6->setEnabled(true);
            button7->setEnabled(true);
            button8->setEnabled(true);
            button9->setEnabled(true);
            buttonComma->setEnabled(false);
            break;
        default:
            model.setBase(CalculatorModel::Base::Dec);
            buttonA->setEnabled(false);
            buttonB->setEnabled(false);
            buttonC->setEnabled(false);
            buttonD->setEnabled(false);
            buttonE->setEnabled(false);
            buttonF->setEnabled(false);
            button0->setEnabled(true);
            button1->setEnabled(true);
            button2->setEnabled(true);
            button3->setEnabled(true);
            button4->setEnabled(true);
            button5->setEnabled(true);
            button6->setEnabled(true);
            button7->setEnabled(true);
            button8->setEnabled(true);
            button9->setEnabled(true);
            buttonComma->setEnabled(true);
            break;
        }
    });

    // Setting decimal as default
    baseSelection->setCurrentIndex(1);

    // Disposing widgets at grid
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
    gridLayout->addWidget(buttonEqual, 5, 2);
    gridLayout->addWidget(buttonMultiply, 5, 3);

    // Composing widgets
    vboxLayout->addWidget(label);
    vboxLayout->addWidget(lineEdit);
    vboxLayout->addWidget(buttonWidget);
    vboxLayout->addWidget(buttonClear);
    vboxLayout->addWidget(buttonQuit);
    mainWidget->setLayout(vboxLayout);
    buttonWidget->setLayout(gridLayout);
    this->setCentralWidget(mainWidget);
}

MainWindow::~MainWindow() {}

void MainWindow::onExit(bool checked=false) {
    qDebug() << "Exit: " << checked;
    // Avoid warnings
    Q_UNUSED(checked);

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Quitter", "Voulez-vous vraiment quitter?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        this->close();
    }
}


void MainWindow::onAbout(bool checked) {
    qDebug() << "About: " << checked;
    QMessageBox dialog = QMessageBox();
    dialog.setText("Calculatrice \n(c) Sébastien Fourey");
    QMessageBox::about(this, "About", "Calculatrice \n(c) Sébastien Fourey");
}

void MainWindow::onButtonClickedId(int id) {
    qDebug() << "Button Clicked Id: " << id;
    if(model.command((CalculatorModel::ButtonID)id)) {
        emit write(model.getText());
    }
}
