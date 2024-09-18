#include <iostream>
#include <tchar.h>
#include <string>
#include "IRServeurUDP.h"
#include "IRClientTCP.h"
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
    ofstream FichierJson("Drone.json", ios::app);
    IRServeurUDP Server;
    IRClientTCP Zopper;
    string IPClient =("172.20.21.62");
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
        		Message.replace(position, 1, "\",\"");
        		position += 3; // Incrémenter de 3 pour passer après '":"'
    		}
            cout << "----------------------------------------------------------------------------------------------" << endl<<endl;



    int Taille = Message.length(); // Variable de taile avec modification + La possition dans la ligne est importante
    Message.replace(149,1,"\"}");  //Change le 149 par une variable avenir
    cout << "Message modifie: " << Message << endl;   //Affichage du Resultat

               stringstream stimestamp;
int timestamp = (int)time(NULL);
stimestamp<<timestamp;    //Implementation de l'heure dans le future file json

    cout<<"Ajoue du HEAD"<<endl;
    string HEAD = "{\n \"donneesVol\": {\n \"nom\": \"Carreira\",\n \"numero\": \"C3B3FC\",\n \"time\": \""+ to_string(timestamp) +"\",\n \"etats\": [\n";

    Message.insert(0,HEAD);
    cout<<Message<<endl;  //Affichage du JSON
    cout << "----------------------------------------------------------------------------------------------" << endl<<endl;
    int TailleV2 = Message.length();
    cout<<"Ajoue du LEG"<<endl;
    string LEG = "]\n }\n}\n";

    Message.insert(TailleV2,LEG);


   string V2Message = "{\"donneesVol\": {"
                   "\"nom\": \"Carreira\","
                   "\"numero\": \"C3B3FC\","
                   "\"time\": \"1726478219\","
                   "\"etats\": [{"
                   "\"pitch\":\"0\","
                   "\"roll\":\"0\","
                   "\"yaw\":\"0\","
                   "\"vgx\":\"0\","
                   "\"vgy\":\"0\","
                   "\"vgz\":\"0\","
                   "\"templ\":\"0\","
                   "\"temph\":\"0\","
                   "\"tof\":\"0\","
                   "\"h\":\"50\","
                   "\"bat\":\"0\","
                   "\"baro\":\"0.00\","
                   "\"time\":\"0\","
                   "\"agx\":\"0.00\","
                   "\"agy\":\"0.00\","
                   "\"agz\":\"0.00\""
                   "}]}}";

    cout<<V2Message<<endl;  //Affichage du JSON

    FichierJson << V2Message  << endl;

    Zopper.SeConnecterAUnServeur(IPClient,80);
    cout << "----------------------------------------------------------------------------------------------" << endl<<endl;
    cout << "----------------------------------------------------------------------------------------------" << endl<<endl;


   

    cin.get();

    Zopper.Envoyer("POST /CARR/restTello.php/vol HTTP/1.1\r\n" + V2Message);




    cin.get();
    fichier.close();
    FichierJson.close();
    return 0;
}



