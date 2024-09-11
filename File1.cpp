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
        std::ofstream fichier("Serveur.log");
       while(true)
         {
         cout<<"----------------------------------------------------------------------------------------------"<<endl;
         cout<<"Bienvenue dans le ServeurUDP,Taper la Commande, By CARREIRA JULIEN "<<endl<<endl;
         string IP = "127.0.0.1";
         int Temps = 3000000;            //3 sec
         string Message;
         char Tableau[1000];
         int TailleMax = 1000;
         IRServeurUDP Server;



         Server.OuvrirLaSocketDEcoute(8890,IP);
         Server.RecevoirUnMessage(Message,Temps);
         cout<<"Le resulta"<<" "<<Message<<endl;
         std::this_thread::sleep_for(std::chrono::seconds(5));

         	if (fichier.is_open()) {

         		fichier << Message << endl;
         		std::cout << "Le texte a été écrit dans le fichier." << std::endl;
				fichier.close();
              }
		 cout<<"----------------------------------------------------------------------------------------------"<<endl;

		}



    // Vérification si le fichier est bien ouvert











       return 0;
}






