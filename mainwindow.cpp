#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QDir>
#include<QList>
#include<QDebug>
#include<QMessageBox>
#include <QtXml>
#include<QTreeWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QString pathclient;
    QStringList listclientName;
    QDomDocument doc  ;
    QString path="C:\\Projekte\\windekis_src\\GIT\\windekis\\windekis";
    QDir dir (path );
    QList <QFileInfo> clientList= dir.entryInfoList();
    QStandardItemModel *standardModel = new QStandardItemModel ;
    QStandardItem *rootNode = standardModel->invisibleRootItem();

    for(  const auto &e : qAsConst(clientList)){
        QString ClientName= e.baseName();

        QString pathclientName=path+"\\"+ClientName;
        QDir directory (pathclientName);
        QStringList filters;
        filters << "*.groupproj";
        directory.setNameFilters(filters);
        QStringList testlist = directory.entryList();
        for(  const auto &element : qAsConst(testlist)){


             if(element.contains(".groupproj")  ){

                 auto item = new QStandardItem (ClientName);

                 rootNode->appendRow(item);
                 item->appendRow(new QStandardItem ("Define"));
                 item->appendRow(new QStandardItem ("DBDesc"));
                 item->appendRow(new QStandardItem ("Configproperty"));
                 ui->treeView->setModel(standardModel);
                 break;


             }

         }

    }
    connect(ui->treeView->selectionModel(), &QItemSelectionModel::selectionChanged,
               this, &MainWindow::selectionChangedSlot);

  /*QFile file(pathclient);
   if (!file.open(QIODevice::ReadOnly))
   {
      qDebug()<< "Error while loading file";
   }

   doc.setContent(&file);
   file.close();
   QDomElement root=doc.documentElement();
   QDomElement group=root.firstChild().toElement();

       while(!group.isNull()){
           if (group.tagName()=="Target"){

              QString Name =group.attribute("Name");
              QDomElement Child=group.firstChild().toElement();
              if(Name=="WinDekis"){

                 while(!Child.isNull()){

                   if(Child.tagName()=="MSBuild"){
                       QString pathproj=Child.attribute("Projects");
                       Child = Child.nextSibling().toElement();
                       qDebug()<< pathproj;

                 }
             }
         }
   }

  }*/

}
void MainWindow::selectionChangedSlot(const QItemSelection)
{

    const QModelIndex index = ui->treeView->selectionModel()->currentIndex();
    QString selectedText = index.data(Qt::DisplayRole).toString();
    QModelIndex seekRoot = index;
    QString showparent = seekRoot.parent().data(Qt::DisplayRole).toString();
    QString text = QString("%1 of %2").arg(selectedText)
                            .arg(showparent);
     ui->label->setText(text);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: createTreeView(){

}
