#include <stdio.h>
#include <math.h>

/************************************macros*******************************/ \
#define GRID_WIDTH 16
#define GRID_HEIGHT 16
#define SPACING 1
#define NUM_PARTICLES (GRID_HEIGHT * GRID_WIDTH)
#define RADIUS_OF_PARTICLES 0.3 * (1)
#define DENSITY 1000

/***********************************typedefs******************************/
typedef struct
{
    int x;
    int y;
} position_t;

typedef struct
{
    float u;
    float v;
} velocity_t;

typedef struct
{
    int height;
    int width;
    int distance;
    int nXCells;
    int nYCells;
    int nCells;
    float density;
} grid_t;

typedef struct
{
    position_t pPos;
    velocity_t pVel;
} particle_t;
/******************************global variables***************************/
grid_t grid = {0};
velocity_t gravity = {0, -9.81};
particle_t particles[NUM_PARTICLES] = {0};
int dt;

/*******************************function prototypes**********************/
grid_t init_grid(int, int, int, float, int, float);
int simulate();

/************************************************************************/

int main()
{
    grid = init_grid(GRID_WIDTH, GRID_HEIGHT, SPACING, DENSITY, NUM_PARTICLES, RADIUS_OF_PARTICLES);
    simulate();
    return 0;
}

/******************************function definitions*********************/
grid_t init_grid(int length, int breadth, int spacing, float density, int num_particles, float radius_of_particles)
{

    grid_t g;
    g.height = length;
    g.width = breadth;
    g.distance = spacing;
    g.density = density;
    g.nXCells = breadth / spacing;
    g.nYCells = length / spacing;
    g.nCells = g.nXCells * g.nYCells;
    return g;
}

int integrate_particles(){

    for (int i = 0; i < NUM_PARTICLES; i++)
    {
        particles[i].pVel.v += dt * gravity.v;
        particles[i].pPos.x += dt * particles[i].pVel.v;
    }

    return 0;
}

int particle_to_cell() {
    return 0;
}

int simulate()
{
    integrate_particles();
    return 0;
}