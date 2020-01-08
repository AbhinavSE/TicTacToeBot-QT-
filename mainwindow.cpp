#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::press(int a){
    switch(a){
        case 0: on_pushButton_clicked(); break;
        case 1: on_pushButton_2_clicked(); break;
        case 2: on_pushButton_3_clicked(); break;
        case 3: on_pushButton_4_clicked(); break;
        case 4: on_pushButton_5_clicked(); break;
        case 5: on_pushButton_6_clicked(); break;
        case 6: on_pushButton_7_clicked(); break;
        case 7: on_pushButton_8_clicked(); break;
        case 8: on_pushButton_9_clicked(); break;
    }
}

void MainWindow::playComputerTurn(){
    int max = -20;
    int toPlay;
    int score[3][3];
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(board[i][j]==0){
                board[i][j] = (turn)?('x'):('o');
                score[i][j] = minimax(0);
                board[i][j] = 0;
                if(score[i][j]>max){
                    max = score[i][j];
                    toPlay = i*3 + j;
                }
            }
        }
    }
    press(toPlay);
}

int MainWindow::minimax(int chance){
    char c = checkGameWon();
    if(c=='d')
        return 0;
    else if(c=='o')
        return 1;
    else if(c=='x')
        return -1;
    if(chance==1){
        int max = -20;
        int score[3][3];
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(board[i][j]==0){
                    board[i][j] = 'o';
                    score[i][j] = minimax(0);
                    board[i][j] = 0;
                    if(score[i][j]>max){
                        max = score[i][j];
                    }
                }
            }
        }
        return max;
    }
    else{
        int min = 20;
        int score[3][3];
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(board[i][j]==0){
                    board[i][j] = 'x';
                    score[i][j] = minimax(1);
                    board[i][j] = 0;
                    if(score[i][j]<min){
                        min = score[i][j];
                    }
                }
            }
        }
        return min;
    }
}

char MainWindow::checkGameWon(){
    for(int i = 0; i<3; i++){
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2] && board[i][0]!=0){
            return board[i][0];
        }
    }
    for(int i = 0; i<3; i++){
        if(board[0][i]==board[1][i] && board[0][i]==board[2][i] && board[0][i]!=0){
            return board[0][i];
        }
    }
    if(board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[0][0]!=0)
        return board[0][0];
    if(board[0][2]==board[1][1] && board[0][2]==board[2][0] && board[0][2]!=0)
        return board[0][2];

    bool isFilled = true;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            isFilled = isFilled && board[i][j]!=0;
        }
    }
    if(isFilled)
        return 'd';
    return NULL;
}

void MainWindow::on_pushButton_clicked()
{
    if(board[0][0]==0){
        char t = (turn)?('x'):('o');
        board[0][0] = t;
        ui->pushButton->setText((QString) t);

        turn = !turn;
        char c = checkGameWon();
        if(c!=NULL)
            usleep(10000);
        if(c=='d'){
            ui->label->setText("DRAW!");
        }
        if(c=='x'){
            ui->label->setText("YOU WON!");
        }
        if(c=='o'){
            ui->label->setText("YOU LOST!");
        }
        if(!turn)
            playComputerTurn();
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    if(board[0][1]==0){
        char t = (turn)?('x'):('o');
        board[0][1] = t;
        ui->pushButton_2->setText((QString) t);
        turn = !turn;
        char c = checkGameWon();
        if(c!=NULL)
            usleep(10000);
        if(c=='d'){
            ui->label->setText("DRAW!");
        }
        if(c=='x'){
            ui->label->setText("YOU WON!");
        }
        if(c=='o'){
            ui->label->setText("YOU LOST!");
        }
        if(!turn)
            playComputerTurn();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(board[0][2]==0){
        char t = (turn)?('x'):('o');
        board[0][2] = t;
        ui->pushButton_3->setText((QString) t);
        turn = !turn;
        char c = checkGameWon();
        if(c!=NULL)
            usleep(10000);
        if(c=='d'){
            ui->label->setText("DRAW!");
        }
        if(c=='x'){
            ui->label->setText("YOU WON!");
        }
        if(c=='o'){
            ui->label->setText("YOU LOST!");
        }
        if(!turn)
            playComputerTurn();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(board[1][0]==0){
        char t = (turn)?('x'):('o');
        board[1][0] = t;
        ui->pushButton_4->setText((QString) t);
        turn = !turn;
        char c = checkGameWon();
        if(c!=NULL)
            usleep(10000);
        if(c=='d'){
            ui->label->setText("DRAW!");
        }
        if(c=='x'){
            ui->label->setText("YOU WON!");
        }
        if(c=='o'){
            ui->label->setText("YOU LOST!");
        }
        if(!turn)
            playComputerTurn();
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if(board[1][1]==0){
        char t = (turn)?('x'):('o');
        board[1][1] = t;
        ui->pushButton_5->setText((QString) t);
        turn = !turn;
        char c = checkGameWon();
        if(c!=NULL)
            usleep(10000);
        if(c=='d'){
            ui->label->setText("DRAW!");
        }
        if(c=='x'){
            ui->label->setText("YOU WON!");
        }
        if(c=='o'){
            ui->label->setText("YOU LOST!");
        }
        if(!turn)
            playComputerTurn();
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    if(board[1][2]==0){
        char t = (turn)?('x'):('o');
        board[1][2] = t;
        ui->pushButton_6->setText((QString) t);
        turn = !turn;
        char c = checkGameWon();
        if(c!=NULL)
            usleep(10000);
        if(c=='d'){
            ui->label->setText("DRAW!");
        }
        if(c=='x'){
            ui->label->setText("YOU WON!");
        }
        if(c=='o'){
            ui->label->setText("YOU LOST!");
        }
        if(!turn)
            playComputerTurn();
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    if(board[2][0]==0){
        char t = (turn)?('x'):('o');
        board[2][0] = t;
        ui->pushButton_7->setText((QString) t);
        turn = !turn;
        char c = checkGameWon();
        if(c!=NULL)
            usleep(10000);
        if(c=='d'){
            ui->label->setText("DRAW!");
        }
        if(c=='x'){
            ui->label->setText("YOU WON!");
        }
        if(c=='o'){
            ui->label->setText("YOU LOST!");
        }
        if(!turn)
            playComputerTurn();
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    if(board[2][1]==0){
        char t = (turn)?('x'):('o');
        board[2][1] = t;
        ui->pushButton_8->setText((QString) t);
        turn = !turn;
        char c = checkGameWon();
        if(c!=NULL)
            usleep(10000);
        if(c=='d'){
            ui->label->setText("DRAW!");
        }
        if(c=='x'){
            ui->label->setText("YOU WON!");
        }
        if(c=='o'){
            ui->label->setText("YOU LOST!");
        }
        if(!turn)
            playComputerTurn();
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    if(board[2][2]==0){
        char t = (turn)?('x'):('o');
        board[2][2] = t;
        ui->pushButton_9->setText((QString) t);
        turn = !turn;
        char c = checkGameWon();
        if(c!=NULL)
            usleep(10000);
        if(c=='d'){
            ui->label->setText("DRAW!");
        }
        if(c=='x'){
            ui->label->setText("YOU WON!");
        }
        if(c=='o'){
            ui->label->setText("YOU LOST!");
        }
        if(!turn)
            playComputerTurn();
    }
}
