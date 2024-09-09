#include "dictionnaire.h"
#include <iostream>

int main() {
    dictionnaire dico(30),d2(30);
    
    traduction tr1 = {"bonjour", "hello"};
    traduction tr2 = {"au revoir", "goodbye"};
    traduction tr3 = {"merci", "thank you"};
    traduction tr4 = {"s'il vous plaît", "please"};

    dico.ajout(tr1);
    dico.ajout(tr2);
    dico.ajout(tr3);
    dico.ajout(tr4);
   
    cout << "Contenu du dictionnaire:" << endl;
    dico.afficher();
    
    char mot[] = "merci";
    char* traduction =dico.DSearch(0,(dico.getNbDic() - 1), mot);

    if (traduction != NULL) {
        cout << "La traduction de " << mot << " est " << traduction << endl;
    } else {
        cout << mot << " non trouvé dans le dictionnaire." << endl;
    }
     d2=dico;
     cout<<"dictionnaire apres affectation "<<endl;d2.afficher();
     cout<<endl;
     dictionnaire d3=dico;
     cout<<"apres le constructeur de recopie"<<endl;
     d3.afficher();
     situation1(dico);

    return 0;
}
