#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mission.h"
#include "points.h"
#include <QMessageBox>
#include <QCalendarWidget>
#include <QRadioButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Mtmp.afficher());
    ui->tableView_2->setModel(Ptmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::on_ajoutbtn_clicked()


void MainWindow::on_pb_ajouter_clicked()
{
    int ID_MISSION=ui->le_mission->text().toInt();
    int ID_ENFANT=ui->le_idenfant->text().toInt();
    int NB_POINT=ui->le_nb_point->text().toInt();
    QString NOM=ui->le_nom->text();
    QString DESCRIPTION=ui->R10->text();
    QString DATE_FIN=ui->date->text();

    Mission M(ID_MISSION,ID_ENFANT,NB_POINT,NOM,DESCRIPTION,DATE_FIN);
      bool test=M.ajouter();
      if (test){
          QMessageBox::information(nullptr,QObject::tr("OK"),
                  QObject::tr("ajout effectue\n""click cancel to exit."),QMessageBox::Cancel);

      }
      else{
          QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                   QObject::tr("ajout non effectuee! \n"
                                                "click Cancel to exit"),QMessageBox::Cancel);
  }
  }

void MainWindow::on_pushButton_2_clicked()
{
    int idenfant=ui->le_idenfant_2->text().toInt();
    int idmission=ui->le_idmission->text().toInt();
    bool test=Mtmp.supprimer(idenfant,idmission);
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("mission supprimer"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("mission non supprimer"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_miseajour_clicked()
{
    int ID_MISSION=ui->le_mission_2->text().toInt();
    int ID_ENFANT=ui->le_idenfant_3->text().toInt();
    int NB_POINT=ui->le_nb_point_2->text().toInt();
    QString NOM=ui->le_nom_2->text();
    QString DESCRIPTION=ui->R10_2->text();
    //QString DATE_FIN=ui->le_date_fin->selectedDate().toString();
    QString DATE_FIN=ui->date_2->text();
    Mission M(ID_MISSION,ID_ENFANT,NB_POINT,NOM,DESCRIPTION,DATE_FIN);
      bool test=M.miseajour(ID_ENFANT,ID_MISSION);
      if(test)
      {

          QMessageBox::information(nullptr, QObject::tr("MISSION modifier"),
                      QObject::tr("successful.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("MISSION non modifier"),
                      QObject::tr("failed.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

  }




void MainWindow::on_refresh_clicked()
{
    ui->tableView->setModel(Mtmp.afficher());

}

void MainWindow::on_pb_AJOUTER_clicked()
{
    int ID_ENFANT=ui->idenf->text().toInt();
    int NB_TOTAL=ui->nbtotal->text().toInt();
    bool EXIST=ui->radioButton->isChecked();
    points P(ID_ENFANT,NB_TOTAL);
    if (!EXIST){
        bool test=P.ajouter();

        if (test){
            ui->tableView_2->setModel(Ptmp.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                    QObject::tr("ajout effectue\n""click cancel to exit."),QMessageBox::Cancel);

        }
        else{
            QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                     QObject::tr("ajout non effectuee! \n"
                                                  "click Cancel to exit"),QMessageBox::Cancel);
        }
}else{
        bool test=P.miseajour(ID_ENFANT);
        if(test)
        {
            ui->tableView_2->setModel(Ptmp.afficher());

            QMessageBox::information(nullptr, QObject::tr("NOMBRE TOTAL est modifier"),
                        QObject::tr("successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

      }
        else{
            QMessageBox::critical(nullptr, QObject::tr("NOMBRE TOTAL n'est pas modifier"),
                        QObject::tr("failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }



    }
}

void MainWindow::on_pbsupp_clicked()
{
    int idenfant=ui->iden->text().toInt();
    bool test=Ptmp.supprimer(idenfant);

    if(test)

    {
         ui->tableView_2->setModel(Ptmp.afficher());

        QMessageBox::information(nullptr, QObject::tr("POINTS supprimer"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("POINTS non supprimer"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}






void MainWindow::on_pb_tri_clicked()
{
    ui->tableView_2->setModel(Ptmp.tri());
}
