#include "dictionnaire.h"
dictionnaire::dictionnaire(int n)  {
    cout << "\nAppel du constructeur pour l'objet " << this << endl;
     nb_dic=0;
    tab = new traduction*[n];
    if (tab == NULL) {
        cerr << "Erreur d'allocation dynamique";
        exit(-1);
    }
    for (int i = 0; i < n; i++) {
        tab[i] = NULL;
    }
}
dictionnaire::~dictionnaire() {
    if (tab) {
        for (int i = 0; i < nb_dic; i++) {
            delete[] tab[i]->mot1;
            delete[] tab[i]->mot2;
            delete tab[i];
        }
        delete[] tab;
    }
}
void dictionnaire::ajout(traduction& tr) {
    if (nb_dic >= 30) {
        cerr << "Le dictionnaire est plein" << endl;
        exit(-1);
    }
    tab[nb_dic] = new traduction;
    tab[nb_dic]->mot1 = new char[strlen(tr.mot1) + 1];
    tab[nb_dic]->mot2 = new char[strlen(tr.mot2) + 1];
    strcpy(tab[nb_dic]->mot1, tr.mot1);
    strcpy(tab[nb_dic]->mot2, tr.mot2);
    nb_dic++;
}
char* dictionnaire::DSearch(int gauche, int droite,const char* mot) {
    if (droite < gauche) {
        return NULL;
    }
    int milieu = (droite + gauche) / 2;
    int cmp = strcmp(tab[milieu]->mot1, mot);
    if (cmp == 0) {
        return tab[milieu]->mot2;
    } else if (cmp > 0) {
        return DSearch(gauche, milieu - 1, mot);
    } else {
        return DSearch(milieu + 1, droite, mot);
    }
}
dictionnaire::dictionnaire(dictionnaire& tr2) {
      nb_dic=tr2.nb_dic;
    tab = new traduction*[nb_dic];
    for (int i = 0; i < nb_dic; i++) {
        tab[i] = new traduction;
        tab[i]->mot1 = new char[strlen(tr2.tab[i]->mot1) + 1];
        tab[i]->mot2 = new char[strlen(tr2.tab[i]->mot2) + 1];
        strcpy(tab[i]->mot1, tr2.tab[i]->mot1);
        strcpy(tab[i]->mot2, tr2.tab[i]->mot2);
    }
}
dictionnaire& dictionnaire::operator=(const dictionnaire& d2) {
    if (this != &d2) {
        for (int i = 0; i < nb_dic; i++) {
            delete[] tab[i]->mot1;
            delete[] tab[i]->mot2;
            delete tab[i];
        }
        delete[] tab;

        nb_dic = d2.nb_dic;
        tab = new traduction*[nb_dic];
        for (int i = 0; i < nb_dic; i++) {
            tab[i] = new traduction;
            tab[i]->mot1 = new char[strlen(d2.tab[i]->mot1) + 1];
            tab[i]->mot2 = new char[strlen(d2.tab[i]->mot2) + 1];
            strcpy(tab[i]->mot1, d2.tab[i]->mot1);
            strcpy(tab[i]->mot2, d2.tab[i]->mot2);
        }
    }
    return *this;
}
void dictionnaire::afficher() {
    for (int i = 0; i < nb_dic; i++) {
        cout << "Mot source: " << tab[i]->mot1 << " - Traduction: " << tab[i]->mot2 << endl;
    }
}

 void situation1(dictionnaire d){
    cout<<"situation d'invocation pour le constructeur de recopie"<<d.nb_dic<<endl;
 }
 int dictionnaire::getNbDic() const {
    return nb_dic;
}
