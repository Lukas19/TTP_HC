//
//  movements.cpp
//  TTP_HC
//
//  Created by Lukas Zamora on 12/12/17.
//  Copyright © 2017 Lukas Zamora. All rights reserved.
//

#include "movements.h"
//Revisar índices de matrices en general

vector<vector<int>> swap_homes(int t_1, int t_2, vector<vector<int>> schedule){
    int n = int(schedule[0].size());
    vector<vector<int>> solucion;
    for (int i = 0; i < n; i++){
        if (t_2 == schedule[abs(t_1)-1][i])
            schedule[abs(t_1)-1][i] *= -1;
        else if(-t_2 == schedule[abs(t_1)-1][i])
            schedule[abs(t_1)-1][i] *= -1;
    }
    for (int i = 0; i < n; i++){
        if (t_1 == schedule[abs(t_2)-1][i])
            schedule[abs(t_2)-1][i] *= -1;
        else if(-t_1 == schedule[abs(t_2)-1][i])
            schedule[abs(t_2)-1][i] *= -1;
    }
    solucion = schedule;
    vector<vector<int>>().swap(schedule);

    return solucion;
}

vector<vector<int>> swap_rounds(int r_1, int r_2, vector<vector<int>> schedule){
    int n = int(schedule.size());
    int aux = 0;
    vector<vector<int>> solucion;

    for (int i = 0; i < n; i++){
        aux = schedule[i][r_1];
        schedule[i][r_1] = schedule[i][r_2];
        schedule[i][r_2] = aux;
    }
    solucion = schedule;
    vector<vector<int>>().swap(schedule);
    return solucion;
}

vector<vector<int>> swap_teams(int t_1, int t_2, vector<vector<int>> schedule){
    int teams = int(schedule.size());
    int weeks = int(schedule[0].size());
    int aux1 = 0;
    int aux2 = 0;
    vector<vector<int>> solucion;
    
    for (int i = 0; i < weeks; i++){
        for (int j = 0; j < teams; j++){
            if (abs(schedule[t_1-1][i]) == t_2 || abs(schedule[t_2-1][i]) == t_1)
                continue;
            aux1 = schedule[t_1-1][i];
            aux2 = schedule[t_2-1][i];
            schedule[t_1-1][i] = aux2;
            schedule[t_2-1][i] = aux1;
            if (aux1 > 0)
                schedule[abs(aux1)-1][i] = -t_2;
            else if (aux1 <0)
                schedule[abs(aux1)-1][i] = t_2;
            if (aux2 > 0)
                schedule[abs(aux2)-1][i] = -t_1;
            else if(aux2 < 0)
                schedule[abs(aux2)-1][i] = t_1;
        }
    }
    solucion = schedule;
    vector<vector<int>>().swap(schedule);
    return solucion;
}
