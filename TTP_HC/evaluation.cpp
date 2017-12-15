//
//  evaluation.cpp
//  TTP_HC
//
//  Created by Lukas Zamora on 12/12/17.
//  Copyright © 2017 Lukas Zamora. All rights reserved.
//

#include "evaluation.h"

vector<int> schedule_i(vector<vector<int>> schedule, int i){
    int n = int(schedule.size());
    vector<int> schedule_i;
    for (int j=0; j< 2*(n-1); j++){
        schedule_i.push_back(schedule[i][j]);
    }
    return schedule_i;
}

int distancia_equipo(vector<vector<int>> distancias, vector<int> torneo_i, int equipo){
    int n = int(torneo_i.size());
    int d = 0;
    int origen = 0;
    int destino = 0;
    if (torneo_i[0] < 0){
        d+= distancias[equipo-1][abs(torneo_i[0])-1];
    }
    for (int i = 1; i < n; i ++){
        if (torneo_i[i-1]>0 && torneo_i[i]>0)
            continue;
        else if(torneo_i[i-1]>0 && torneo_i[i]<0){
            origen = equipo-1;
            destino = abs(torneo_i[i])-1;
            d += distancias[origen][destino];
        }
        else if(torneo_i[i-1]<0 && torneo_i[i]<0){
            origen = abs(torneo_i[i-1])-1;
            destino = abs(torneo_i[i])-1;
            d += distancias[origen][destino];
        }
        else if(torneo_i[i-1]<0 && torneo_i[i]>0){
            origen = abs(torneo_i[i])-1;
            destino = equipo-1;
            d += distancias[origen][destino];
        }
        
    }
    if (torneo_i[n-1]<0){
        origen = abs(torneo_i[n-1])-1;
        destino = equipo-1;
        d += distancias[origen][destino];
    }
    vector<vector<int>>().swap(distancias);
    vector<int>().swap(torneo_i);

    return d;
}

int calidad_solucion(vector<vector<int>> torneo, vector<vector<int>> distancias){
    int n = int(torneo.size());
    vector<int> schedule;
    int dist = 0;
    //Calcular costo de una solución
    for (int i = 1; i <= n; i++){
        schedule = schedule_i(torneo,i-1);
        dist += distancia_equipo(distancias, schedule, i);
    }
    vector<vector<int>>().swap(torneo);
    vector<vector<int>>().swap(distancias);
    return dist;
}

int largo_hs_rt (vector<vector<int>> torneo){
    int teams = int(torneo.size());
    int weeks = int(torneo[0].size());
    int count = 0;
    
    for (int i = 0; i < teams; i++){
        for(int j = 0; j < weeks-2; j++){
            if ( torneo[i][j] < 0 && torneo[i][j+1] <0 && torneo[i][j+2] < 0){
                if (torneo[i][j+3] < 0){
                    count += 1;
                    continue;
                }
            }
            else if ( torneo[i][j] > 0 && torneo[i][j+1] > 0 && torneo[i][j+2] >0){
                if (torneo[i][j+3] > 0){
                    count += 1;
                    continue;
                }
            }
        }
    }
    vector<vector<int>>().swap(torneo);
    return count;
}

int no_repeaters (vector<vector<int>> torneo){
    int teams = int(torneo.size());
    int weeks = int(torneo[0].size());
    int count = 0;
    
    for (int i = 0; i < teams; i ++){
        for (int j = 0; j < weeks-1; j++){
            if (abs(torneo[i][j]) == abs(torneo[i][j+1]))
                count += 1;
        }
    }
    vector<vector<int>>().swap(torneo);
    return (count/2);
    
}

int restricciones (vector<vector<int>> torneo){
    int count = 0;
    count += largo_hs_rt(torneo);
    count += no_repeaters(torneo);
    return count;
}

float f_castigo (int restricciones_rotas){
    return (1 + (sqrt(restricciones_rotas)*log(restricciones_rotas))/2);
}

float f_evaluacion (vector<vector<int>> torneo, vector<vector<int>> distancias){
    int costo = calidad_solucion(torneo, distancias);
    int restricciones_rotas = restricciones(torneo);
    
    if(restricciones_rotas == 0)
        return costo;
    else{
        return costo + 1000*f_castigo(restricciones_rotas); // Cambiar ahora!!
    }
}
