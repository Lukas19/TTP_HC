//
//  neighborhood.cpp
//  TTP_HC
//
//  Created by Lukas Zamora on 12/12/17.
//  Copyright © 2017 Lukas Zamora. All rights reserved.
//

//Usar más de un movimiento y asegurarse que la solución en verdad se mejoró sino detener el algoritmo o aplicar RESTART!fa
#include "neighborhood.h"

vector<string> nl_names = {"ATL", "NYM", "PHI", "MON", "FLA", "PIT", "CIN", "CHI", "STL", "MIL", "HOU", "COL", "SF", "SD", "LA", "ARI"};
vector<string> super_names =  {"BFN", "AKL", "CAN", "PRE", "HLM", "SYD", "JOH", "CHC", "BRI", "DUR", "DUN", "PER", "CPT", "WLG"};
vector<string> nfl_names =  {"BOS", "MIA", "BUF", "NYJ", "CIN", "PIT", "BAL", "CLE", "IND", "JAC", "NAS", "HOU", "DEN", "SAN", "KAN", "OAK", "NYG", "DAL", "WAS", "PHI", "CHI", "MIN", "DET", "GBY", "CHA", "TAM", "ATL", "NOR", "SEA", "STL", "PHO", "SFO"};


void HC_swap_rounds (vector<vector<int>> distancias, vector<int> equipos){
    vector<vector<int>> s_best_prima; //Revisar si es necesaria esta variable
    vector<vector<int>> s_prima;
    vector<vector<int>> s_inicial = double_round_robin(equipos);
    vector<vector<int>> s_best;
    bool local;
    int iteraciones = 3;
    int contador = 0;
    int weeks = int(s_inicial[0].size());
    float f_best_prima = numeric_limits<float>::max();
    float f_best = numeric_limits<float>::max();
    float f_prima = numeric_limits<float>::min();
    float f_inicial;
    int cont = 0;
    
    do {
        local = false;
        s_inicial = double_round_robin(equipos);
        f_inicial = f_evaluacion(s_inicial, distancias); //Revisar
        do {
            float maximum = numeric_limits<float>::max();
            for (int j = 1; j <weeks; j++ ){
                s_prima = swap_rounds(j-1, j, s_inicial);
                f_prima = f_evaluacion(s_prima, distancias);
                    if (f_prima < maximum ){
                        f_best_prima = f_prima;
                        s_best_prima = s_prima;
                        maximum = f_prima;
                    }
                vector<vector<int>>().swap(s_prima);
            }
            if (f_best_prima < f_inicial){
                s_inicial = s_best_prima;
                f_inicial = f_best_prima;
                local = false;
                cont = 0;
            }
            else {
                local = true;
                cont++;
            }
            if (cont == 10) {
                local = false;
            }
        } while (local);
        contador +=1;
        
        if (f_inicial < f_best){
            s_best = s_inicial;
            f_best = f_inicial;
        }
    } while(contador < iteraciones);
    
    for (int i = 0; i < weeks; i++) {
        for (int j = 0; j < int(s_best.size()); j++) {
            if (s_best[j][i] < 0){
                int a = abs(s_best[j][i])-1;
                cout << "@" << nl_names[a] <<"\t\t";
            }
            else{
                int a = s_best[j][i]-1;
                cout << nl_names[a] <<"\t\t";
            }
        }
        cout << endl;
    }
    cout << endl;

    
    cout <<"Lo mejor que conseguí con Swap_Rounds fue"<< f_evaluacion(s_best, distancias) << " con " << restricciones(s_best) << endl;
    
    vector<vector<int>>().swap(s_best);
    vector<vector<int>>().swap(s_prima);
    vector<vector<int>>().swap(s_best_prima);
    vector<vector<int>>().swap(s_inicial);
    vector<vector<int>>().swap(distancias);


}

void HC_swap_homes (vector<vector<int>> distancias, vector<int> equipos){
    vector<vector<int>> s_best_prima; //Revisar si es necesaria esta variable
    vector<vector<int>> s_prima;
    vector<vector<int>> s_inicial = double_round_robin(equipos);
    vector<vector<int>> s_best;
    int n = int(equipos.size());
    bool local;
    int iteraciones = 3;
    int contador = 0;
    int weeks = int(s_inicial[0].size());
    float f_best_prima = numeric_limits<float>::max();
    float f_best = numeric_limits<float>::max();
    float f_prima = numeric_limits<float>::min();
    float f_inicial;
    int cont = 0;
    
    do {
        local = false;
        s_inicial = double_round_robin(equipos);
        f_inicial = f_evaluacion(s_inicial, distancias); //Revisar
        do {
            float maximum = numeric_limits<float>::max();
            for (int i = 1; i < n-1; i++){
                for (int j = 1; j <weeks; j++ ){
                    s_prima = swap_homes(s_inicial[i][j-1], s_inicial[i][j], s_inicial);
                f_prima = f_evaluacion(s_prima, distancias);
                if (f_prima < maximum ){
                    f_best_prima = f_prima;
                    s_best_prima = s_prima;
                    maximum = f_prima;
                }
                vector<vector<int>>().swap(s_prima);
                }
            }
            if (f_best_prima < f_inicial){
                s_inicial = s_best_prima;
                f_inicial = f_best_prima;
                local = false;
                cont = 0;
            }
            else {
                local = true;
                cont++;
            }
            if (cont == 10) {
                local = false;
            }
        } while (local);
        contador +=1;
        
        if (f_inicial < f_best){
            s_best = s_inicial;
            f_best = f_inicial;
        }
    } while(contador < iteraciones);
    
    for (int i = 0; i < weeks; i++) {
        for (int j = 0; j < int(s_best.size()); j++) {
            if (s_best[j][i] < 0){
                int a = abs(s_best[j][i])-1;
                cout << "@" << nl_names[a] <<"\t\t";
            }
            else{
                int a = s_best[j][i]-1;
                cout << nl_names[a] <<"\t\t";
            }
        }
        cout << endl;
    }
    cout << endl;
    
    
    cout <<"Lo mejor que conseguí con Swap_homes fue"<< calidad_solucion(s_best, distancias) << " con " << restricciones(s_best) << endl;
    
    vector<vector<int>>().swap(s_best);
    vector<vector<int>>().swap(s_prima);
    vector<vector<int>>().swap(s_best_prima);
    vector<vector<int>>().swap(s_inicial);
    vector<vector<int>>().swap(distancias);

    
    
}

void HC_swap_teams (vector<vector<int>> distancias, vector<int> equipos){
    vector<vector<int>> s_best_prima; //Revisar si es necesaria esta variable
    vector<vector<int>> s_prima;
    vector<vector<int>> s_inicial = double_round_robin(equipos);
    vector<vector<int>> s_best;
    int n = int(equipos.size());
    bool local;
    int iteraciones = 3;
    int contador = 0;
    int weeks = int(s_inicial[0].size());
    float f_best_prima = numeric_limits<float>::max();
    float f_best = numeric_limits<float>::max();
    float f_prima = numeric_limits<float>::min();
    float f_inicial;
    int cont = 0;
    
    do {
        local = false;
        s_inicial = double_round_robin(equipos);
        f_inicial = f_evaluacion(s_inicial, distancias); //Revisar
        do {
            float maximum = numeric_limits<float>::max();
            for (int j = 1; j <n; j++ ){
                s_prima = swap_teams(j, j+1, s_inicial);
                    f_prima = f_evaluacion(s_prima, distancias);
                    if (f_prima < maximum ){
                        f_best_prima = f_prima;
                        s_best_prima = s_prima;
                        maximum = f_prima;
                    }
                    vector<vector<int>>().swap(s_prima);
                }
            
            if (f_best_prima < f_inicial){
                s_inicial = s_best_prima;
                f_inicial = f_best_prima;
                local = false;
                cont = 0;
            }
            else {
                local = true;
                cont++;
            }
            if (cont == 10) {
                local = false;
            }
        } while (local);
        contador +=1;
        
        if (f_inicial < f_best){
            s_best = s_inicial;
            f_best = f_inicial;
        }
    } while(contador < iteraciones);
    
    for (int i = 0; i < weeks; i++) {
        for (int j = 0; j < int(s_best.size()); j++) {
            if (s_best[j][i] < 0){
                int a = abs(s_best[j][i])-1;
                cout << "@" << nl_names[a] <<"\t\t";
            }
            else{
                int a = s_best[j][i]-1;
                cout << nl_names[a] <<"\t\t";
            }
        }
        cout << endl;
    }
    cout << endl;
    
    cout <<"Lo mejor que conseguí con Swap_Teams fue"<< calidad_solucion(s_best, distancias) << " con " << restricciones(s_best) << endl;
    
    vector<vector<int>>().swap(s_best);
    vector<vector<int>>().swap(s_prima);
    vector<vector<int>>().swap(s_best_prima);
    vector<vector<int>>().swap(s_inicial);
    vector<vector<int>>().swap(distancias);
    
    
}


