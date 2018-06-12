/*
 * _coder_move_api.c
 *
 * Code generation for function '_coder_move_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "move.h"
#include "_coder_move_api.h"
#include "move_emxutil.h"
#include "move_data.h"

/* Variable Definitions */
static emlrtRTEInfo c_emlrtRTEI = { 1, 1, "_coder_move_api", "" };

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier, emxArray_real_T *y);
static void emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv0[2];
  int32_T i;
  int32_T iv1[2];
  boolean_T bv0[2] = { true, true };

  for (i = 0; i < 2; i++) {
    iv0[i] = -1;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv0, &bv0[0],
    iv1);
  ret->size[0] = iv1[0];
  ret->size[1] = iv1[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(sp, emlrtAlias(X), &thisId, y);
  emlrtDestroyArray(&X);
}

static void emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y)
{
  mxSetData((mxArray *)y, (void *)u->data);
  emlrtSetDimensions((mxArray *)y, u->size, 2);
}

void move_api(const mxArray *prhs[3], const mxArray *plhs[2])
{
  emxArray_real_T *X;
  emxArray_real_T *a;
  emxArray_real_T *V;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &X, 2, &c_emlrtRTEI, true);
  emxInit_real_T(&st, &a, 2, &c_emlrtRTEI, true);
  emxInit_real_T(&st, &V, 2, &c_emlrtRTEI, true);
  prhs[0] = emlrtProtectR2012b(prhs[0], 0, true, -1);
  prhs[2] = emlrtProtectR2012b(prhs[2], 2, true, -1);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "X", X);
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "a", a);
  emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "V", V);

  /* Invoke the target function */
  move(&st, X, a, V);

  /* Marshall function outputs */
  emlrt_marshallOut(X, prhs[0]);
  plhs[0] = prhs[0];
  emlrt_marshallOut(V, prhs[2]);
  plhs[1] = prhs[2];
  V->canFreeData = false;
  emxFree_real_T(&V);
  a->canFreeData = false;
  emxFree_real_T(&a);
  X->canFreeData = false;
  emxFree_real_T(&X);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_move_api.c) */
