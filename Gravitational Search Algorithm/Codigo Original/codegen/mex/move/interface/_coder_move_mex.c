/*
 * _coder_move_mex.c
 *
 * Code generation for function '_coder_move_mex'
 *
 */

/* Include files */
#include "move.h"
#include "_coder_move_mex.h"
#include "move_terminate.h"
#include "_coder_move_api.h"
#include "move_initialize.h"
#include "move_data.h"

/* Function Declarations */
static void move_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs, const
  mxArray *prhs[3]);

/* Function Definitions */
static void move_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs, const
  mxArray *prhs[3])
{
  int32_T n;
  const mxArray *inputs[3];
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4, 4,
                        "move");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 4,
                        "move");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  move_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  move_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(move_atexit);

  /* Module initialization. */
  move_initialize();

  /* Dispatch the entry-point. */
  move_mexFunction(nlhs, plhs, nrhs, prhs);
}

/* End of code generation (_coder_move_mex.c) */
