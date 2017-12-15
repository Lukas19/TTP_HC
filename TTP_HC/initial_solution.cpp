//
//  initial_solution.cpp
//  TTP_HC
//
//  Created by Lukas Zamora on 12/12/17.
//  Copyright © 2017 Lukas Zamora. All rights reserved.
//

#include "initial_solution.h"

vector<vector<int>> double_round_robin(vector<int> equipos) {
    int n = int(equipos.size());
    vector<int> teams_array = equipos; //Hardcode for now.
    random_shuffle(teams_array.begin(), teams_array.end());
    int totalRounds = (n - 1)*2;
    int matchesPerRound = n / 2;
    int halfRoundMark = (totalRounds/2);
    vector<vector<int>> solucion(n, vector<int>(totalRounds,1));
    
    for (int round = 0; round < totalRounds; round++) {
        for (int match = 0; match < matchesPerRound; match++) {
            int home = (round + match) % (n - 1);
            int away = (n - 1 - match + round) % (n - 1);
            
            // Last team stays in the same place while the others
            // rotate around it.
            if (match == 0) {
                away = n - 1;
            }
            
            // Add one so teams are number 1 to teams not 0 to teams - 1
            // upon display.
            if (round < halfRoundMark) {
                solucion[teams_array[home] - 1][round] = teams_array[away];
                solucion[teams_array[away] - 1][round] = -(teams_array[home]);
            } else {
                solucion[teams_array[home] - 1][round] = -(teams_array[away]);
                solucion[teams_array[away] - 1][round] = teams_array[home];
            }
        }
    }
    vector<int>().swap(teams_array);
    vector<int>().swap(equipos);
    return solucion;
}
