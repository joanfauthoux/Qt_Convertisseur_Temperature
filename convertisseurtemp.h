#ifndef CONVERTISSEURTEMP_H
#define CONVERTISSEURTEMP_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QFont>
#include <QDebug>
#include <QLayout>

//#include <QtObjects> //-- Inclus tout
class ConvertisseurTemp : public QWidget
{
    Q_OBJECT


private:

    //Définitions des Layout
    QVBoxLayout *mainLayout;

    QHBoxLayout *sectionLayout;
    QVBoxLayout *inputLayout;
    QVBoxLayout *responseLayout;

    QHBoxLayout *actionButtonLayout;

    //Définitions des Objets de la fenêtre
    QLabel *m_labelIntitule;
    QLabel *m_labelDegreC;
    QLabel *m_labelDegreF;
    QLabel *m_labelResult;
    QLineEdit *m_inputDegreC;
    QPushButton *m_ButtonClear;
    QPushButton *m_ButtonConvert;
    QPushButton *m_ButtonExit;

    float celsiusToFahrenheit(float);

private slots:
    void convertir(); //Déclenché lors du clic gauche sur le bouton Convertir et par Entrée dans la zone de saisie
    void effacer(); //Déclenché par un clic gauche sur le bouton Effacer
    //void quitter(); //Déclencher par un clic gauche sur le bouton Quitter - Inutile car la Fenetre à déjà un slot

public:
    ConvertisseurTemp(QWidget *parent = nullptr);
    ~ConvertisseurTemp();
};
#endif // CONVERTISSEURTEMP_H
