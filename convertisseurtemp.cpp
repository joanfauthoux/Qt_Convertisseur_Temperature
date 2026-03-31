#include "convertisseurtemp.h"
#include <QFont>
#include <QMessageBox>
#include <QLayout>

ConvertisseurTemp::ConvertisseurTemp(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("Convertisseur de température"));


    //Construction des layouts
    mainLayout = new QVBoxLayout;

    sectionLayout = new QHBoxLayout;
    inputLayout = new QVBoxLayout;
    responseLayout = new QVBoxLayout;

    actionButtonLayout = new QHBoxLayout;

    //Association des layouts
    mainLayout->addLayout(QVBoxLayout);

    //Construction des éléments de la fenêtre
    m_labelIntitule = new QLabel(this);
    m_labelDegreC = new QLabel(this);
    m_labelDegreF = new QLabel(this);
    m_labelResult = new QLabel(this);
    m_inputDegreC = new QLineEdit(this);
    m_ButtonClear = new QPushButton(this);
    m_ButtonConvert = new QPushButton(this);
    m_ButtonExit = new QPushButton(this);

    //Paramètrages des éléments

    //Définitions des font
    QFont IntituleFont("Arial", 14, QFont::Bold);
    QFont LabelFont("Arial", 11);


    //Label Intitulé
    m_labelIntitule->setText("Convertisseur de température");
    m_labelIntitule->setFont(IntituleFont);

    //Label Degré Celsius
    m_labelDegreC->setText("degrés Celsius");

    //Champ de saisi du degré celsius

    //Label Degré Fahrenheit
    m_labelDegreF->setText("degrés Fahrenheit");

    //Label Résultat de la conversion
    m_labelResult->setText("---.---");
    m_labelResult->setFont(LabelFont);

    //Bouton Effacer
    m_ButtonClear->setText("Effacer");

    //Bouton Convertir
    m_ButtonConvert->setText("Convertir");

    //Bouton Quitter
    m_ButtonExit->setText("Quitter");


    //Connexion enter signals et slots
    QObject::connect(m_ButtonClear, SIGNAL(clicked()),
                     this, SLOT(effacer()),
                     Qt::QueuedConnection);

    //QObject::connect(QKeyEvent::key(), this, SLOT(convertir()), Qt::QueuedConnection);

    QObject::connect(m_inputDegreC, SIGNAL(returnPressed()), this, SLOT(convertir()), Qt::QueuedConnection);

    QObject::connect(m_ButtonConvert, SIGNAL(clicked()),
                     this, SLOT(convertir()),
                     Qt::QueuedConnection);

    QObject::connect(m_ButtonExit, SIGNAL(clicked()),
                     this, SLOT(close()));
}
ConvertisseurTemp::~ConvertisseurTemp() {}


void ConvertisseurTemp::convertir()
{
    float tempF;
    bool check;

    try{
        tempF = celsiusToFahrenheit(m_inputDegreC->text().toFloat(&check));

        if(!check){
            throw("Erreur de typage");
        }
    }catch(...){
        int retour = QMessageBox::warning(this, tr("Convertisseur de température"),
                                          tr("Erreur : La saisie est incorrecte"),
                                          QMessageBox::Ok);
    }

    m_labelResult->setText(QString::number(tempF));
}

void ConvertisseurTemp::effacer()
{
    m_inputDegreC->clear();
    m_labelResult->setText("---.---");
}

float ConvertisseurTemp::celsiusToFahrenheit (float tempC){
    return tempC * 1.8 + 32;
}



