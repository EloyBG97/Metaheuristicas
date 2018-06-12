/*
 * move_terminate.c
 *
 * Code generation for function 'move_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "move.h"
#include "move_terminate.h"
#include "move_data.h"

/* Function Definitions */
void move_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void move_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (move_terminate.c) */
