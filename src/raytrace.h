
#ifndef _RAYTRACE_H
#define _RAYTRACE_H

#include "model.h"
#include "matrix.h"

typedef enum 
  { PointToPoint=0, PointToBearingRange } 
itl_mode_t;

typedef struct
{
  double x, y, a;
  double cosa, sina;
  double range;
  double max_range;
  double big_incr;
  double small_incr;
  double med_incr;

  GPtrArray* models;
  int index;
  stg_matrix_t* matrix;

} itl_t;


itl_t* itl_create( double x, double y, double a, double b, 
		   stg_matrix_t* matrix, itl_mode_t pmode );

model_t* itl_next( itl_t* itl );

void itl_destroy( itl_t* itl );
void itl_raytrace( itl_t* itl );


#endif