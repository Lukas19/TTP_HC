//
//  input.h
//  TTP_HC
//
//  Created by Lukas Zamora on 12/12/17.
//  Copyright © 2017 Lukas Zamora. All rights reserved.
//

#ifndef input_h
#define input_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

vector<int> split(string s);
vector<vector<int>> cargar_distancias(string nombre);

#endif /* input_h */
