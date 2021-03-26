#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_changeFontButton_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);

    if (ok)
    {
        // the user clicked OK and font is set to the font the user selected
    }
    else
    {
        // the user canceled the dialog; font is set to the initial
        // value, in this case Helvetica [Cronyx], 10
    }
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_submitButton_clicked()
{
    QMessageBox::information(this, tr("Submitted Message"), tr("User %1 submitted a message with a title %2. The message is %3")
                             .arg(ui->lineEditName->text())
                             .arg(ui->lineEditTitle->text())
                             .arg(ui->textEdit->toPlainText()));
}
