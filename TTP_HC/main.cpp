#include "input.h"
#include "initial_solution.h"
#include "evaluation.h"
#include "neighborhood.h"
using namespace std;

int main (int argc, const char * argv[]) {
    vector<vector<int>> distancias;
    distancias = cargar_distancias(argv[1]);
    vector<int> equipos;
    int n = atoi(argv[2]);
    for (int i = 1; i <= n; i++ ){
        equipos.push_back(i);
    }
        
    // Generamos solución inicial
    vector<vector<int>> torneo = double_round_robin(equipos);
    
    //Calidad de solución    
    HC_swap_teams(distancias, equipos);
    HC_swap_homes(distancias, equipos);
    HC_swap_rounds(distancias, equipos);
    
    
    //Limpiar memoria
    vector<vector<int>>().swap(distancias);
    vector<vector<int>>().swap(torneo);
    
    
    return 0;
}
