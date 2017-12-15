//
//  input.cpp
//  TTP_HC
//
//  Created by Lukas Zamora on 12/12/17.
//  Copyright © 2017 Lukas Zamora. All rights reserved.
//

#include "input.h"

vector<int> split(string s){
    std::string delimiter = " ";
    vector<int> aux;
    
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        aux.push_back(stoi(token));
        s.erase(0, pos + delimiter.length());
    }
    aux.push_back(stoi(s));
    return aux;
}

vector<vector<int>> cargar_distancias(string nombre){
    fstream archivo;
    string linea;
    vector<vector<int>> distancias;
    vector<int> aux;
    
    archivo.open (nombre.c_str() , ios::in);
    
    while (! archivo.eof() ) {
        getline (archivo,linea);
        cout << "Leído: " << linea << endl;
        if (linea != ""){
            aux = split(linea);
            distancias.push_back(aux);
        }
    }
    archivo.close();
    return distancias;
}



