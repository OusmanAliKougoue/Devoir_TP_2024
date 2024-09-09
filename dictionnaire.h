#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H
#include <iostream>
#include<cstring>
using namespace std;
struct traduction{
    char* mot1;
    char* mot2;
};
class dictionnaire
{
private:
    traduction** tab;
    int nb_dic;

public:
    dictionnaire(int n);
    ~dictionnaire();
    void ajout(traduction&);
    char* DSearch(int gauche,int droite,const char* mot);
    int getNbDic() const;
    dictionnaire(dictionnaire&);
    dictionnaire& operator=(const dictionnaire&);
    void afficher();
    friend void situation1(dictionnaire d);

};
#endif