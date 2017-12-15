//
//  neighborhood.h
//  TTP_HC
//
//  Created by Lukas Zamora on 12/12/17.
//  Copyright © 2017 Lukas Zamora. All rights reserved.
//

#ifndef neighborhood_h
#define neighborhood_h

#include <stdio.h>
#include "movements.h"
#include "evaluation.h"
#include "initial_solution.h"
#include <limits>

void HC_swap_homes (vector<vector<int>> distancias, vector<int> equipos);
void HC_swap_rounds (vector<vector<int>> distancias, vector<int> equipos);
void HC_swap_teams (vector<vector<int>> distancias, vector<int> equipos, string nombre_instancia);


#endif /* neighborhood_h */
