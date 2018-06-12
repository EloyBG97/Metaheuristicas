/*
 * move_initialize.c
 *
 * Code generation for function 'move_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "move.h"
#include "move_initialize.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "eml_rand_shr3cong_stateful.h"
#include "eml_rand_mcg16807_stateful.h"
#include "eml_rand.h"
#include "move_data.h"

/* Function Declarations */
static void move_once(void);

/* Function Definitions */
static void move_once(void)
{
  c_state_not_empty_init();
  b_state_not_empty_init();
  state_not_empty_init();
  method_not_empty_init();
  eml_rand_init();
  eml_rand_mcg16807_stateful_init();
  eml_rand_shr3cong_stateful_init();
  c_eml_rand_mt19937ar_stateful_i();
}

void move_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    move_once();
  }
}

/* End of code generation (move_initialize.c) */
