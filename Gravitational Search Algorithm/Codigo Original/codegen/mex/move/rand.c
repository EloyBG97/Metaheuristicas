/*
 * rand.c
 *
 * Code generation for function 'rand'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "move.h"
#include "rand.h"
#include "move_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo b_emlrtRTEI = { 1, 14, "rand",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/randfun/rand.m" };

/* Function Definitions */
void b_rand(const emlrtStack *sp, real_T varargin_1, real_T varargin_2,
            emxArray_real_T *r)
{
  int32_T i0;
  i0 = r->size[0] * r->size[1];
  r->size[0] = (int32_T)varargin_1;
  r->size[1] = (int32_T)varargin_2;
  emxEnsureCapacity(sp, (emxArray__common *)r, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  emlrtRandu(&r->data[0], (int32_T)varargin_1 * (int32_T)varargin_2);
}

/* End of code generation (rand.c) */
