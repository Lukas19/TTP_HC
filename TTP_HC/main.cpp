#include "input.h"
#include "initial_solution.h"
#include "evaluation.h"
#include "neighborhood.h"
using namespace std;

int main (int argc, const char * argv[]) {
    vector<vector<int>> distancias;
    distancias = cargar_distancias(argv[1]);
    vector<int> equipos = {1,2,3,4,5,6};
    // Generamos solución inicial
    vector<vector<int>> torneo = double_round_robin(equipos);
    
    //Calidad de solución    
    HC_swap_teams(distancias, equipos, "NL");
    
    
    //Limpiar memoria
    vector<vector<int>>().swap(distancias);
    vector<vector<int>>().swap(torneo);
    
    
    return 0;
}
