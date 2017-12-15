default: hc
  
hc: main.o input.o initial_solution.o evaluation.o movements.o neighborhood.o
        g++ -std=c++11 -o hc main.o input.o initial_solution.o evaluation.o movements.o neighborhood.o -lm

main.o: main.cpp input.h initial_solution.h evaluation.h neighborhood.h
        g++ -std=c++11  -c main.cpp

input.o: input.cpp
        g++ -std=c++11 -c input.cpp

initial_solution.cpp: initial_solution.cpp
        g++ -std=c++11 -c initial_solution.cpp

evaluation.o: evaluation.cpp
        g++ -std=c++11 -c evaluation.cpp

movements.o: movements.cpp
        g++ -std=c++11 -c movements.cpp

neighborhood.o: neighborhood.cpp movements.h evaluation.h initial_solution.h
        g++ -std=c++11 -c neighborhood.cpp

clean:
        rm *.o

