#include <iostream>
#include <tchar.h>
#include <string>
#include "IRServeurUDP.h"
#include <sstream>  // Pour std::istringstream
using namespace   std;


int main()
{
         cout<<"Bienvenue dans le ServeurUDP,Taper la Commande, ATTENTION ONLY MASJUCULE "<<endl<<endl;
         string IP = "172.20.21.62";
         int Temps = 3000000;            //3 sec
         string Message;
         char Tableau[1000];
         int TailleMax = 1000;
         IRServeurUDP Server;



         Server.OuvrirLaSocketDEcoute(8890,IP);
         Server.RecevoirUnMessage(Message,Temps);




         cout<<"Le resulta"<<" "<<Message<<endl  ;
         cin.get();




       return 0;
}






