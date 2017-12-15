//
//  movements.h
//  TTP_HC
//
//  Created by Lukas Zamora on 12/12/17.
//  Copyright © 2017 Lukas Zamora. All rights reserved.
//

#ifndef movements_h
#define movements_h

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> swap_homes(int t_1, int t_2, vector<vector<int>> schedule);
vector<vector<int>> swap_rounds(int r_1, int r_2, vector<vector<int>> schedule);
vector<vector<int>> swap_teams(int t_1, int t_2, vector<vector<int>> schedule);

#endif /* movements_h */
