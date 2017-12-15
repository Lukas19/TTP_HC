#include "input.h"
#include "initial_solution.h"
#include "evaluation.h"
#include "neighborhood.h"
#include "time.h"

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
    time_t begin = clock();
    vector<vector<int>> torneo = double_round_robin(equipos);
    
    //Calidad de solución    
    //HC_swap_homes(distancias, equipos);
    HC_swap_rounds(distancias, equipos);
    //HC_swap_teams(distancias, equipos);
    
    
    //Limpiar memoria
    vector<vector<int>>().swap(distancias);
    vector<vector<int>>().swap(torneo);
    time_t end = clock();
    
    double execution_time = (double)(end -begin) /CLOCKS_PER_SEC;
    cout << execution_time <<endl;
    return 0;
}
