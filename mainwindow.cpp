#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList wordList;

    for(int i = 0; i < 100000; i++){
        //  wordList << "alpha" << "omega" << "omicron" << "zeta";
        wordList << "alpha"+ QString("%1").arg(i,5,10,QChar('0'));; //  fill with 0
    }

    QCompleter *completer = new QCompleter(wordList, this);

    //  completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setFilterMode(Qt::MatchContains);

    QTableView *popup = new QTableView();
    // 列ヘッダを非表示にする。
    popup->horizontalHeader()->hide();
    // 候補の右側に余計なスペースが表示されないようにストレッチモードを変更
    popup->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // Qt4 だと setResizeMode()
    // 行ヘッダを非表示にする
    popup->verticalHeader()->hide();
    // 候補１行の高さを調整
    popup->verticalHeader()->setDefaultSectionSize(20);
    // Grid線を消す
    popup->setShowGrid(false);

    // 候補のポップアップに QTableView を使う
    completer->setPopup(popup);

    ui->lineEdit->setCompleter(completer);

}

MainWindow::~MainWindow()
{
    delete ui;
}

