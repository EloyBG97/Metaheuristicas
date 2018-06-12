/*
 * move.h
 *
 * Code generation for function 'move'
 *
 */

#ifndef __MOVE_H__
#define __MOVE_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "move_types.h"

/* Function Declarations */
extern void move(const emlrtStack *sp, emxArray_real_T *X, const emxArray_real_T
                 *a, emxArray_real_T *V);

#endif

/* End of code generation (move.h) */
