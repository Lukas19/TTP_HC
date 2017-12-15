//
//  evaluation.hpp
//  TTP_HC
//
//  Created by Lukas Zamora on 12/12/17.
//  Copyright © 2017 Lukas Zamora. All rights reserved.
//

#ifndef evaluation_h
#define evaluation_h

#include <iostream>
#include <vector>
#include <string>
 #include <cmath>

using namespace std;

vector<int> schedule_i(vector<vector<int>> schedule, int i);
int distancia_equipo(vector<vector<int>> distancias, vector<int> torneo_i, int equipo);
int calidad_solucion(vector<vector<int>> torneo, vector<vector<int>> distancias);
int largo_hs_rt (vector<vector<int>> torneo);
int no_repeaters (vector<vector<int>> torneo);
int restricciones (vector<vector<int>> torneo);
float f_castigo (int restricciones_rotas);
float f_evaluacion (vector<vector<int>> torneo, vector<vector<int>> distancias);







#endif /* evaluation_h */
