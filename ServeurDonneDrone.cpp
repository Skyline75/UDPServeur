#include "ServeurDonneDrone.h"
#include <thread> // For sleep
#include <sstream>  // Pour std::istringstream
#include <iostream>
#include <fstream>  // Pour la gestion des fichiers
#include <iostream>
 using namespace  std;


 ServeurDonneDrone::ServeurDonneDrone()
 {
    	std::string Drone = "192.168.10.1";
        std::string ParDefault = "127.0.0.1";
   		Client.OuvrirLaSocketDEcoute(8890,ParDefault);

 }
 //-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

        void ServeurDonneDrone::ServerDonneDrone(std::string Pilote, std::string NumeroDrone){}

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

        void ServeurDonneDrone::OpenFile(std::string NomFile){

        std::ofstream fichier(NomFile, ios::app);            //Sa cree le fichier avec le name de la methode
        }

////-----------------------------------------------------------------------------------------------------
////-----------------------------------------------------------------------------------------------------

//        void ServeurDonneDrone::AjoutFichierLog(std::string Texte);
//
////-----------------------------------------------------------------------------------------------------
////-----------------------------------------------------------------------------------------------------
//
//        void ServeurDonneDrone::CloseFile();
//
////-----------------------------------------------------------------------------------------------------
////-----------------------------------------------------------------------------------------------------
//
//          int ServeurDonneDrone::RecevoirDonneesDrone();
//
////-----------------------------------------------------------------------------------------------------
////-----------------------------------------------------------------------------------------------------
//
//         string ServeurDonneDrone::CreeJson(std::string Pilote,std::string NumeroDrone);
//
////-----------------------------------------------------------------------------------------------------
////-----------------------------------------------------------------------------------------------------
//
//         void ServeurDonneDrone::EnvoyerDonneesBDD(std::string IPREST,std::string URLREST);
//
////-----------------------------------------------------------------------------------------------------
////-----------------------------------------------------------------------------------------------------
//
//         void ServeurDonneDrone::DebuterJSON(std::string Pilote,std::string NumeroDrone);
//
////-----------------------------------------------------------------------------------------------------
////-----------------------------------------------------------------------------------------------------

         void ServeurDonneDrone::AjouterDonneesJSON(std::string Message){

          size_t position = 0; // pour stocker la position de ':'

    		while ((position = Message.find(":", position)) != string::npos) {
        		cout << "Position du : " << position << endl;
        		// Remplacer ':' par '":"'
        		Message.replace(position, 1, "\":\"");
        		position += 3; // Incrémenter de 3 pour passer après '":"'
    		}
            JSON    = Message;
         }

////-----------------------------------------------------------------------------------------------------
////-----------------------------------------------------------------------------------------------------
//
//         void ServeurDonneDrone::CloseJSON();
//
////-----------------------------------------------------------------------------------------------------
////-----------------------------------------------------------------------------------------------------
//
//
// }




 //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// {
//    m_adresseIPServeur = "127.0.0.1";
//    m_portServeur = 4000;
//    if(m_nbClientUDP == 0)
//    {
//		#if defined(_WIN32) || defined(_WIN64)
//		WSADATA wsaData ;
//		int iResult;
//		iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
//		if(iResult != 0)
//		{
//			std::cout << "Echec lors de l'initialisation de la DLL Winsock" << std::endl;
//		}
//		#endif
//    }
//	m_nbClientUDP++;
//
//}
//
//ServeurDonneDrone::~ServeurDonneDrone()
//{
//    FermerLaSocket();
//}
//
//
//
// bool ServeurDonneDrone::OuvrirLaSocketDeCommunication(std::string adresseIPServeur, unsigned short portServeur)
// {
//    m_adresseIPServeur = adresseIPServeur;
//    m_portServeur = portServeur;
//    m_socketClientUDP = socket ( AF_INET, SOCK_DGRAM, IPPROTO_UDP );
//    if ( m_socketClientUDP == -1 )
//    {
//        std::cout << "Erreur de création de socket." << std::endl;
//        return false;
//    }
//
//    m_addrServeur.sin_family = AF_INET;
//    m_addrServeur.sin_port = htons ( m_portServeur );
//    m_addrServeur.sin_addr.s_addr = inet_addr(m_adresseIPServeur.c_str());
//
//
//    return true;
//}
//
//bool ServeurDonneDrone::FermerLaSocket()
//{
//    #ifdef __unix__
//    close(m_socketClientUDP);
//    #elif defined(_WIN32) || defined(_WIN64)
//    closesocket(m_socketClientUDP);
//    #endif
//
//    return true;
//
//}
//
//bool ServeurDonneDrone::EnvoyerUnMessage(std::string message)
//{
//    int nbCaractEmi;
//    nbCaractEmi = sendto ( m_socketClientUDP, message.c_str(), message.length()+1 , 0, (struct sockaddr *) &m_addrServeur, sizeof(m_addrServeur));
//    // On vérifie qu'un message a bien été reçu
//    if(nbCaractEmi == -1)
//    {
//        return false;
//    }
//    return true;
//}
//
//bool ServeurDonneDrone::EnvoyerDesOctets(const unsigned char * tableau, int taille)
//{
//    int nbCaractEmi;
//    nbCaractEmi = sendto ( m_socketClientUDP, (const char*)tableau, taille , 0, (struct sockaddr *) &m_addrServeur, sizeof(m_addrServeur));
//    // On vérifie qu'un message a bien été reçu
//    if(nbCaractEmi == -1)
//    {
//        return false;
//    }
//    return true;
//}
//
//int ServeurDonneDrone::RecevoirUnMessage(std::string & message, int timeout_us)
//{   char msg[1500];
//	int nbCaracteresRecus=RecevoirDesOctets((unsigned char *)msg, 1500, timeout_us);
//	if(nbCaracteresRecus > 1)
//	{   msg[nbCaracteresRecus]=0;
//		message = msg;
//		return nbCaracteresRecus;
//	}
//    message = "";
//    return -1;
//}
//
//int ServeurDonneDrone::RecevoirDesOctets(unsigned char * tableau, int tailleMax, int timeout_us)
//{
//	fd_set fds;
//	int n;
//    struct timeval tv;
//    FD_ZERO(&fds);
//    FD_SET(m_socketClientUDP, &fds);
//	tv.tv_sec =  timeout_us/1000000;
//	tv.tv_usec = timeout_us%1000000;
//
//    n = select(m_socketClientUDP, &fds, NULL, NULL, &tv);
//    if(n==0)
//    {
//        //std::cout << "Timeout.." << std::endl;
//        return 0;
//    }
//    else if(n==-1)
//    {
//        //std::cout << "Error.." << std::endl;
//        return -1;
//    }
//
//    struct sockaddr_in from;
//    int length = sizeof(from);
//    int nbCaracteresRecus = recvfrom(m_socketClientUDP, (char *)tableau, tailleMax, 0, (struct sockaddr *)&from, &length);
//    if(nbCaracteresRecus > 1)
//    {
//        return nbCaracteresRecus;
//    }
//    return -1;
//}}
