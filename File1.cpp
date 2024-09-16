#include <iostream>
#include <tchar.h>
#include <string>
#include "IRServeurUDP.h"
#include <chrono> // For time
#include <thread> // For sleep
#include <sstream>  // Pour std::istringstream
#include <iostream>
#include <fstream>  // Pour la gestion des fichiers
#include <string>   // Pour utiliser std::string
using namespace   std;


int main()
{
    ofstream fichier("Serveur.log", ios::app);
    IRServeurUDP Server;
    string Message;

    if (!fichier.is_open()) {   //Creation du fichier
        cerr << "Erreur d'ouverture du fichier !" << endl;
        return 1;
   }

   	cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Bienvenue dans le ServeurUDP, Taper la Commande, By CARREIRA JULIEN " << endl << endl;
    string IP = "127.0.0.1";
    int Temps = 2000000; // 3 sec

	    Server.OuvrirLaSocketDEcoute(8890, IP);
        Server.RecevoirUnMessage(Message, Temps);
        cout << "Le resultat: " << Message << endl;

        fichier << Message  << endl;        //Sa ecrie dans file
        cout << "Ecriture dans le fichier " << endl << endl;
        cout << "----------------------------------------------------------------------------------------------" << endl<<endl;



        Message.insert(0,"{\"");      //Demarage du debut du fichier JSON

        size_t position = 0; // pour stocker la position de ':'

    		while ((position = Message.find(":", position)) != string::npos) {
        		cout << "Position du : " << position << endl;
        		// Remplacer ':' par '":"'
        		Message.replace(position, 1, "\":\"");
        		position += 3; // Incrémenter de 3 pour passer après '":"'
    		}
            cout << "----------------------------------------------------------------------------------------------" << endl<<endl;


    int Taille = Message.length(); // Variable de taile avec modification + La possition dans la ligne est importante
    Message.replace(149,1,"\"}");  //Change le 149 par une variable avenir
    cout << "Message modifie: " << Message << endl;   //Affichage du Resultat

    stringstream stimestamp;
	int timestamp = (int)time(NULL);
	stimestamp<<timestamp;              //Implementation de l'heure dans le future file json

    cout<<"Ajoue du HEAD"<<endl;
    string HEAD = "{\n \"donneesVol\": {\n \"nom\": \"Carreira\",\n \"numero\": \"C3B3FC\",\n \"time\": \""+ to_string(timestamp) +"\",\n \"etats\": [\n";

    Message.insert(0,HEAD);








    cout<<Message<<endl;  //Affichage du JSON
    cin.get();
    fichier.close();

    return 0;
}







