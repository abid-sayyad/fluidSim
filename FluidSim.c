#include <stdio.h>
#include <math.h>

/************************************macros*******************************/\

/***********************************typedefs******************************/
typedef struct {
    int height;
    int width;
    int distance;
    int nXCells;
    int nYCells;
    int nParticles;
    float density;
} grid_t;
/******************************global variables***************************/
grid_t grid = {0};

/*******************************function prototypes**********************/
grid_t init_grid(int, int, int, float);
int simulate();

int main(){

    grid = init_grid(/*Populate values here*/);
    simulate();
    return 0;
}

/******************************function definitions*********************/
grid_t init_grid(int length, int breadth, int spacing, float density){

    grid_t g;
    g.height = length;
    g.width = breadth;
    g.distance = spacing;
    g.density = density;
    g.nXCells = breadth / spacing;
    g.nYCells = length / spacing;
    g.nParticles = g.nXCells * g.nYCells;
    return g;
}