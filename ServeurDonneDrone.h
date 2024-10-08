﻿#ifndef ServeurDonneDrone_H
#define ServeurDonneDrone_H

#ifdef __unix__
#include <arpa/inet.h>
#include <unistd.h>
#elif _WIN32 || _WIN64
#include <winsock2.h>
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
//#pragma comment(lib, "Ws2_32.dll")
#include "IRServeurUDP.h"
#endif

#include <string>
using namespace  std;

class ServeurDonneDrone
{
    private :
          IRServeurUDP Client;

    public :
        ServeurDonneDrone();
        ~ServeurDonneDrone();
        string JSON;

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

        void ServerDonneDrone(std::string Pilote, std::string NumeroDrone);

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

        void OpenFile(std::string NomFile);

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

        void AjoutFichierLog(std::string Texte);

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

        void CloseFile();

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

          int RecevoirDonneesDrone();

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

         string CreeJson(std::string Pilote,std::string NumeroDrone);

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

         void EnvoyerDonneesBDD(std::string IPREST,std::string URLREST);

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

         void DebuterJSON(std::string Pilote,std::string NumeroDrone);

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

         void AjouterDonneesJSON(std::string Message);

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

         void CloseJSON();

//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

};

#endif