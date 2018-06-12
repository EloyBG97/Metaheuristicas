/*
 * move.c
 *
 * Code generation for function 'move'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "move.h"
#include "move_emxutil.h"
#include "rand.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 13, "move",
  "/media/eloy/Datos/UGR/3\xc2\xba Carrera/2\xc2\xba\x43uatrimestre (CSI)/Metaheuristicas/Trabajo Examen/Gravitational Search Algorithm/Codigo Original/move.m"
};

static emlrtRTEInfo emlrtRTEI = { 8, 16, "move",
  "/media/eloy/Datos/UGR/3\xc2\xba Carrera/2\xc2\xba\x43uatrimestre (CSI)/Metaheuristicas/Trabajo Examen/Gravitational Search Algorithm/Codigo Original/move.m"
};

static emlrtECInfo emlrtECI = { 2, 13, 3, "move",
  "/media/eloy/Datos/UGR/3\xc2\xba Carrera/2\xc2\xba\x43uatrimestre (CSI)/Metaheuristicas/Trabajo Examen/Gravitational Search Algorithm/Codigo Original/move.m"
};

static emlrtECInfo b_emlrtECI = { 2, 14, 5, "move",
  "/media/eloy/Datos/UGR/3\xc2\xba Carrera/2\xc2\xba\x43uatrimestre (CSI)/Metaheuristicas/Trabajo Examen/Gravitational Search Algorithm/Codigo Original/move.m"
};

/* Function Definitions */
void move(const emlrtStack *sp, emxArray_real_T *X, const emxArray_real_T *a,
          emxArray_real_T *V)
{
  emxArray_real_T *r0;
  int32_T iv2[2];
  int32_T i1;
  int32_T b_V[2];
  int32_T i2;
  int32_T loop_ub;
  int32_T b_a[2];
  int32_T b_loop_ub;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &r0, 2, &emlrtRTEI, true);

  /*  GSA code v1.1. */
  /*  Generated by Esmat Rashedi, 2010.  */
  /*  "	E. Rashedi, H. Nezamabadi-pour and S. Saryazdi, */
  /* �GSA: A Gravitational Search Algorithm�, Information sciences, vol. 179, */
  /* no. 13, pp. 2232-2248, 2009." */
  /*  */
  /* This function updates the velocity and position of agents. */
  /* movement. */
  st.site = &emlrtRSI;
  b_rand(&st, X->size[0], X->size[1], r0);
  for (i1 = 0; i1 < 2; i1++) {
    iv2[i1] = r0->size[i1];
  }

  for (i1 = 0; i1 < 2; i1++) {
    b_V[i1] = V->size[i1];
  }

  if ((iv2[0] != b_V[0]) || (iv2[1] != b_V[1])) {
    emlrtSizeEqCheckNDR2012b(iv2, b_V, &emlrtECI, sp);
  }

  i1 = r0->size[0] * r0->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)r0, i1, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  i1 = r0->size[0];
  i2 = r0->size[1];
  loop_ub = i1 * i2;
  for (i1 = 0; i1 < loop_ub; i1++) {
    r0->data[i1] *= V->data[i1];
  }

  for (i1 = 0; i1 < 2; i1++) {
    iv2[i1] = r0->size[i1];
  }

  for (i1 = 0; i1 < 2; i1++) {
    b_a[i1] = a->size[i1];
  }

  if ((iv2[0] != b_a[0]) || (iv2[1] != b_a[1])) {
    emlrtSizeEqCheckNDR2012b(iv2, b_a, &emlrtECI, sp);
  }

  i1 = V->size[0] * V->size[1];
  V->size[0] = r0->size[0];
  V->size[1] = r0->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)V, i1, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = r0->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_loop_ub = r0->size[0];
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      V->data[i2 + V->size[0] * i1] = r0->data[i2 + r0->size[0] * i1] + a->
        data[i2 + a->size[0] * i1];
    }
  }

  emxFree_real_T(&r0);

  /* eq. 11. */
  for (i1 = 0; i1 < 2; i1++) {
    b_a[i1] = X->size[i1];
    b_V[i1] = V->size[i1];
  }

  if ((b_a[0] != b_V[0]) || (b_a[1] != b_V[1])) {
    emlrtSizeEqCheckNDR2012b(b_a, b_V, &b_emlrtECI, sp);
  }

  i1 = X->size[0] * X->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)X, i1, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = X->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_loop_ub = X->size[0];
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      X->data[i2 + X->size[0] * i1] += V->data[i2 + V->size[0] * i1];
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (move.c) */