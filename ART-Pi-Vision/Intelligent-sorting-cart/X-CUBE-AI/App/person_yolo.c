/**
  ******************************************************************************
  * @file    person_yolo.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Mon Jul 17 17:26:55 2023
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "person_yolo.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "layers.h"



#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#define AI_TOOLS_VERSION_MAJOR 5
#define AI_TOOLS_VERSION_MINOR 2
#define AI_TOOLS_VERSION_MICRO 0


#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 3
#define AI_TOOLS_API_VERSION_MICRO 0

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_person_yolo
 
#undef AI_PERSON_YOLO_MODEL_SIGNATURE
#define AI_PERSON_YOLO_MODEL_SIGNATURE     "5226cb330c235cc6cf97d2455b27f8bd"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-5.2.0)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Mon Jul 17 17:26:55 2023"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_PERSON_YOLO_N_BATCHES
#define AI_PERSON_YOLO_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array conv2d_35_scratch0_array;   /* Array #0 */
AI_STATIC ai_array conv2d_34_scratch0_array;   /* Array #1 */
AI_STATIC ai_array conv2d_33_scratch0_array;   /* Array #2 */
AI_STATIC ai_array conv2d_32_scratch0_array;   /* Array #3 */
AI_STATIC ai_array conv2d_30_scratch0_array;   /* Array #4 */
AI_STATIC ai_array conv2d_27_scratch0_array;   /* Array #5 */
AI_STATIC ai_array conv2d_26_scratch0_array;   /* Array #6 */
AI_STATIC ai_array conv2d_25_scratch0_array;   /* Array #7 */
AI_STATIC ai_array conv2d_23_scratch0_array;   /* Array #8 */
AI_STATIC ai_array conv2d_22_scratch0_array;   /* Array #9 */
AI_STATIC ai_array conv2d_21_scratch0_array;   /* Array #10 */
AI_STATIC ai_array conv2d_19_scratch0_array;   /* Array #11 */
AI_STATIC ai_array conv2d_18_scratch0_array;   /* Array #12 */
AI_STATIC ai_array conv2d_17_scratch0_array;   /* Array #13 */
AI_STATIC ai_array conv2d_16_scratch0_array;   /* Array #14 */
AI_STATIC ai_array conv2d_15_scratch1_array;   /* Array #15 */
AI_STATIC ai_array conv2d_15_scratch0_array;   /* Array #16 */
AI_STATIC ai_array conv2d_13_scratch0_array;   /* Array #17 */
AI_STATIC ai_array conv2d_11_scratch0_array;   /* Array #18 */
AI_STATIC ai_array conv2d_10_scratch0_array;   /* Array #19 */
AI_STATIC ai_array conv2d_9_scratch0_array;   /* Array #20 */
AI_STATIC ai_array conv2d_8_scratch1_array;   /* Array #21 */
AI_STATIC ai_array conv2d_8_scratch0_array;   /* Array #22 */
AI_STATIC ai_array conv2d_6_scratch0_array;   /* Array #23 */
AI_STATIC ai_array conv2d_5_scratch0_array;   /* Array #24 */
AI_STATIC ai_array conv2d_3_scratch0_array;   /* Array #25 */
AI_STATIC ai_array conv2d_2_scratch0_array;   /* Array #26 */
AI_STATIC ai_array conv2d_35_bias_array;   /* Array #27 */
AI_STATIC ai_array conv2d_35_weights_array;   /* Array #28 */
AI_STATIC ai_array conv2d_34_bias_array;   /* Array #29 */
AI_STATIC ai_array conv2d_34_weights_array;   /* Array #30 */
AI_STATIC ai_array conv2d_33_bias_array;   /* Array #31 */
AI_STATIC ai_array conv2d_33_weights_array;   /* Array #32 */
AI_STATIC ai_array conv2d_32_bias_array;   /* Array #33 */
AI_STATIC ai_array conv2d_32_weights_array;   /* Array #34 */
AI_STATIC ai_array conv2d_30_bias_array;   /* Array #35 */
AI_STATIC ai_array conv2d_30_weights_array;   /* Array #36 */
AI_STATIC ai_array conv2d_27_bias_array;   /* Array #37 */
AI_STATIC ai_array conv2d_27_weights_array;   /* Array #38 */
AI_STATIC ai_array conv2d_26_bias_array;   /* Array #39 */
AI_STATIC ai_array conv2d_26_weights_array;   /* Array #40 */
AI_STATIC ai_array conv2d_25_bias_array;   /* Array #41 */
AI_STATIC ai_array conv2d_25_weights_array;   /* Array #42 */
AI_STATIC ai_array conv2d_23_bias_array;   /* Array #43 */
AI_STATIC ai_array conv2d_23_weights_array;   /* Array #44 */
AI_STATIC ai_array conv2d_22_bias_array;   /* Array #45 */
AI_STATIC ai_array conv2d_22_weights_array;   /* Array #46 */
AI_STATIC ai_array conv2d_21_bias_array;   /* Array #47 */
AI_STATIC ai_array conv2d_21_weights_array;   /* Array #48 */
AI_STATIC ai_array conv2d_19_bias_array;   /* Array #49 */
AI_STATIC ai_array conv2d_19_weights_array;   /* Array #50 */
AI_STATIC ai_array conv2d_18_bias_array;   /* Array #51 */
AI_STATIC ai_array conv2d_18_weights_array;   /* Array #52 */
AI_STATIC ai_array conv2d_17_bias_array;   /* Array #53 */
AI_STATIC ai_array conv2d_17_weights_array;   /* Array #54 */
AI_STATIC ai_array conv2d_16_bias_array;   /* Array #55 */
AI_STATIC ai_array conv2d_16_weights_array;   /* Array #56 */
AI_STATIC ai_array conv2d_15_bias_array;   /* Array #57 */
AI_STATIC ai_array conv2d_15_weights_array;   /* Array #58 */
AI_STATIC ai_array conv2d_13_bias_array;   /* Array #59 */
AI_STATIC ai_array conv2d_13_weights_array;   /* Array #60 */
AI_STATIC ai_array conv2d_11_bias_array;   /* Array #61 */
AI_STATIC ai_array conv2d_11_weights_array;   /* Array #62 */
AI_STATIC ai_array conv2d_10_bias_array;   /* Array #63 */
AI_STATIC ai_array conv2d_10_weights_array;   /* Array #64 */
AI_STATIC ai_array conv2d_9_bias_array;   /* Array #65 */
AI_STATIC ai_array conv2d_9_weights_array;   /* Array #66 */
AI_STATIC ai_array conv2d_8_bias_array;   /* Array #67 */
AI_STATIC ai_array conv2d_8_weights_array;   /* Array #68 */
AI_STATIC ai_array conv2d_6_bias_array;   /* Array #69 */
AI_STATIC ai_array conv2d_6_weights_array;   /* Array #70 */
AI_STATIC ai_array conv2d_5_bias_array;   /* Array #71 */
AI_STATIC ai_array conv2d_5_weights_array;   /* Array #72 */
AI_STATIC ai_array conv2d_3_bias_array;   /* Array #73 */
AI_STATIC ai_array conv2d_3_weights_array;   /* Array #74 */
AI_STATIC ai_array conv2d_2_bias_array;   /* Array #75 */
AI_STATIC ai_array conv2d_2_weights_array;   /* Array #76 */
AI_STATIC ai_array serving_default_image_input0_output_array;   /* Array #77 */
AI_STATIC ai_array conversion_0_output_array;   /* Array #78 */
AI_STATIC ai_array conv2d_2_output_array;   /* Array #79 */
AI_STATIC ai_array conv2d_3_output_array;   /* Array #80 */
AI_STATIC ai_array conv2d_5_output_array;   /* Array #81 */
AI_STATIC ai_array conv2d_6_output_array;   /* Array #82 */
AI_STATIC ai_array conv2d_8_output_array;   /* Array #83 */
AI_STATIC ai_array conv2d_9_output_array;   /* Array #84 */
AI_STATIC ai_array conv2d_10_output_array;   /* Array #85 */
AI_STATIC ai_array conv2d_11_output_array;   /* Array #86 */
AI_STATIC ai_array concat_12_output_array;   /* Array #87 */
AI_STATIC ai_array conv2d_13_output_array;   /* Array #88 */
AI_STATIC ai_array conv2d_15_output_array;   /* Array #89 */
AI_STATIC ai_array conv2d_16_output_array;   /* Array #90 */
AI_STATIC ai_array conv2d_17_output_array;   /* Array #91 */
AI_STATIC ai_array conv2d_18_output_array;   /* Array #92 */
AI_STATIC ai_array conv2d_19_output_array;   /* Array #93 */
AI_STATIC ai_array eltwise_20_output_array;   /* Array #94 */
AI_STATIC ai_array conv2d_21_output_array;   /* Array #95 */
AI_STATIC ai_array conv2d_22_output_array;   /* Array #96 */
AI_STATIC ai_array conv2d_23_output_array;   /* Array #97 */
AI_STATIC ai_array eltwise_24_output_array;   /* Array #98 */
AI_STATIC ai_array conv2d_25_output_array;   /* Array #99 */
AI_STATIC ai_array conv2d_26_output_array;   /* Array #100 */
AI_STATIC ai_array conv2d_27_output_array;   /* Array #101 */
AI_STATIC ai_array eltwise_28_output_array;   /* Array #102 */
AI_STATIC ai_array concat_29_output_array;   /* Array #103 */
AI_STATIC ai_array conv2d_30_output_array;   /* Array #104 */
AI_STATIC ai_array conv2d_32_output_array;   /* Array #105 */
AI_STATIC ai_array conv2d_33_output_array;   /* Array #106 */
AI_STATIC ai_array conv2d_34_output_array;   /* Array #107 */
AI_STATIC ai_array conv2d_35_output_array;   /* Array #108 */
AI_STATIC ai_array conversion_36_output_array;   /* Array #109 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor conv2d_35_scratch0;   /* Tensor #0 */
AI_STATIC ai_tensor conv2d_34_scratch0;   /* Tensor #1 */
AI_STATIC ai_tensor conv2d_33_scratch0;   /* Tensor #2 */
AI_STATIC ai_tensor conv2d_32_scratch0;   /* Tensor #3 */
AI_STATIC ai_tensor conv2d_30_scratch0;   /* Tensor #4 */
AI_STATIC ai_tensor conv2d_27_scratch0;   /* Tensor #5 */
AI_STATIC ai_tensor conv2d_26_scratch0;   /* Tensor #6 */
AI_STATIC ai_tensor conv2d_25_scratch0;   /* Tensor #7 */
AI_STATIC ai_tensor conv2d_23_scratch0;   /* Tensor #8 */
AI_STATIC ai_tensor conv2d_22_scratch0;   /* Tensor #9 */
AI_STATIC ai_tensor conv2d_21_scratch0;   /* Tensor #10 */
AI_STATIC ai_tensor conv2d_19_scratch0;   /* Tensor #11 */
AI_STATIC ai_tensor conv2d_18_scratch0;   /* Tensor #12 */
AI_STATIC ai_tensor conv2d_17_scratch0;   /* Tensor #13 */
AI_STATIC ai_tensor conv2d_16_scratch0;   /* Tensor #14 */
AI_STATIC ai_tensor conv2d_15_scratch1;   /* Tensor #15 */
AI_STATIC ai_tensor conv2d_15_scratch0;   /* Tensor #16 */
AI_STATIC ai_tensor conv2d_13_scratch0;   /* Tensor #17 */
AI_STATIC ai_tensor conv2d_11_scratch0;   /* Tensor #18 */
AI_STATIC ai_tensor conv2d_10_scratch0;   /* Tensor #19 */
AI_STATIC ai_tensor conv2d_9_scratch0;   /* Tensor #20 */
AI_STATIC ai_tensor conv2d_8_scratch1;   /* Tensor #21 */
AI_STATIC ai_tensor conv2d_8_scratch0;   /* Tensor #22 */
AI_STATIC ai_tensor conv2d_6_scratch0;   /* Tensor #23 */
AI_STATIC ai_tensor conv2d_5_scratch0;   /* Tensor #24 */
AI_STATIC ai_tensor conv2d_3_scratch0;   /* Tensor #25 */
AI_STATIC ai_tensor conv2d_2_scratch0;   /* Tensor #26 */
AI_STATIC ai_tensor conv2d_35_bias;   /* Tensor #27 */
AI_STATIC ai_tensor conv2d_35_weights;   /* Tensor #28 */
AI_STATIC ai_tensor conv2d_34_bias;   /* Tensor #29 */
AI_STATIC ai_tensor conv2d_34_weights;   /* Tensor #30 */
AI_STATIC ai_tensor conv2d_33_bias;   /* Tensor #31 */
AI_STATIC ai_tensor conv2d_33_weights;   /* Tensor #32 */
AI_STATIC ai_tensor conv2d_32_bias;   /* Tensor #33 */
AI_STATIC ai_tensor conv2d_32_weights;   /* Tensor #34 */
AI_STATIC ai_tensor conv2d_30_bias;   /* Tensor #35 */
AI_STATIC ai_tensor conv2d_30_weights;   /* Tensor #36 */
AI_STATIC ai_tensor conv2d_27_bias;   /* Tensor #37 */
AI_STATIC ai_tensor conv2d_27_weights;   /* Tensor #38 */
AI_STATIC ai_tensor conv2d_26_bias;   /* Tensor #39 */
AI_STATIC ai_tensor conv2d_26_weights;   /* Tensor #40 */
AI_STATIC ai_tensor conv2d_25_bias;   /* Tensor #41 */
AI_STATIC ai_tensor conv2d_25_weights;   /* Tensor #42 */
AI_STATIC ai_tensor conv2d_23_bias;   /* Tensor #43 */
AI_STATIC ai_tensor conv2d_23_weights;   /* Tensor #44 */
AI_STATIC ai_tensor conv2d_22_bias;   /* Tensor #45 */
AI_STATIC ai_tensor conv2d_22_weights;   /* Tensor #46 */
AI_STATIC ai_tensor conv2d_21_bias;   /* Tensor #47 */
AI_STATIC ai_tensor conv2d_21_weights;   /* Tensor #48 */
AI_STATIC ai_tensor conv2d_19_bias;   /* Tensor #49 */
AI_STATIC ai_tensor conv2d_19_weights;   /* Tensor #50 */
AI_STATIC ai_tensor conv2d_18_bias;   /* Tensor #51 */
AI_STATIC ai_tensor conv2d_18_weights;   /* Tensor #52 */
AI_STATIC ai_tensor conv2d_17_bias;   /* Tensor #53 */
AI_STATIC ai_tensor conv2d_17_weights;   /* Tensor #54 */
AI_STATIC ai_tensor conv2d_16_bias;   /* Tensor #55 */
AI_STATIC ai_tensor conv2d_16_weights;   /* Tensor #56 */
AI_STATIC ai_tensor conv2d_15_bias;   /* Tensor #57 */
AI_STATIC ai_tensor conv2d_15_weights;   /* Tensor #58 */
AI_STATIC ai_tensor conv2d_13_bias;   /* Tensor #59 */
AI_STATIC ai_tensor conv2d_13_weights;   /* Tensor #60 */
AI_STATIC ai_tensor conv2d_11_bias;   /* Tensor #61 */
AI_STATIC ai_tensor conv2d_11_weights;   /* Tensor #62 */
AI_STATIC ai_tensor conv2d_10_bias;   /* Tensor #63 */
AI_STATIC ai_tensor conv2d_10_weights;   /* Tensor #64 */
AI_STATIC ai_tensor conv2d_9_bias;   /* Tensor #65 */
AI_STATIC ai_tensor conv2d_9_weights;   /* Tensor #66 */
AI_STATIC ai_tensor conv2d_8_bias;   /* Tensor #67 */
AI_STATIC ai_tensor conv2d_8_weights;   /* Tensor #68 */
AI_STATIC ai_tensor conv2d_6_bias;   /* Tensor #69 */
AI_STATIC ai_tensor conv2d_6_weights;   /* Tensor #70 */
AI_STATIC ai_tensor conv2d_5_bias;   /* Tensor #71 */
AI_STATIC ai_tensor conv2d_5_weights;   /* Tensor #72 */
AI_STATIC ai_tensor conv2d_3_bias;   /* Tensor #73 */
AI_STATIC ai_tensor conv2d_3_weights;   /* Tensor #74 */
AI_STATIC ai_tensor conv2d_2_bias;   /* Tensor #75 */
AI_STATIC ai_tensor conv2d_2_weights;   /* Tensor #76 */
AI_STATIC ai_tensor serving_default_image_input0_output;   /* Tensor #77 */
AI_STATIC ai_tensor conversion_0_output;   /* Tensor #78 */
AI_STATIC ai_tensor conv2d_2_output;   /* Tensor #79 */
AI_STATIC ai_tensor conv2d_3_output;   /* Tensor #80 */
AI_STATIC ai_tensor conv2d_5_output;   /* Tensor #81 */
AI_STATIC ai_tensor conv2d_6_output;   /* Tensor #82 */
AI_STATIC ai_tensor conv2d_8_output;   /* Tensor #83 */
AI_STATIC ai_tensor conv2d_9_output;   /* Tensor #84 */
AI_STATIC ai_tensor conv2d_10_output;   /* Tensor #85 */
AI_STATIC ai_tensor conv2d_11_output;   /* Tensor #86 */
AI_STATIC ai_tensor concat_12_output;   /* Tensor #87 */
AI_STATIC ai_tensor conv2d_13_output;   /* Tensor #88 */
AI_STATIC ai_tensor conv2d_15_output;   /* Tensor #89 */
AI_STATIC ai_tensor conv2d_16_output;   /* Tensor #90 */
AI_STATIC ai_tensor conv2d_17_output;   /* Tensor #91 */
AI_STATIC ai_tensor conv2d_18_output;   /* Tensor #92 */
AI_STATIC ai_tensor conv2d_19_output;   /* Tensor #93 */
AI_STATIC ai_tensor eltwise_20_output;   /* Tensor #94 */
AI_STATIC ai_tensor conv2d_21_output;   /* Tensor #95 */
AI_STATIC ai_tensor conv2d_22_output;   /* Tensor #96 */
AI_STATIC ai_tensor conv2d_23_output;   /* Tensor #97 */
AI_STATIC ai_tensor eltwise_24_output;   /* Tensor #98 */
AI_STATIC ai_tensor conv2d_25_output;   /* Tensor #99 */
AI_STATIC ai_tensor conv2d_26_output;   /* Tensor #100 */
AI_STATIC ai_tensor conv2d_27_output;   /* Tensor #101 */
AI_STATIC ai_tensor eltwise_28_output;   /* Tensor #102 */
AI_STATIC ai_tensor concat_29_output;   /* Tensor #103 */
AI_STATIC ai_tensor conv2d_30_output;   /* Tensor #104 */
AI_STATIC ai_tensor conv2d_32_output;   /* Tensor #105 */
AI_STATIC ai_tensor conv2d_33_output;   /* Tensor #106 */
AI_STATIC ai_tensor conv2d_34_output;   /* Tensor #107 */
AI_STATIC ai_tensor conv2d_35_output;   /* Tensor #108 */
AI_STATIC ai_tensor conversion_36_output;   /* Tensor #109 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conversion_0_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv2d_2_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain conv2d_3_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain conv2d_5_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain conv2d_6_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain conv2d_8_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain conv2d_9_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain conv2d_10_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain conv2d_11_chain;   /* Chain #8 */
AI_STATIC_CONST ai_tensor_chain concat_12_chain;   /* Chain #9 */
AI_STATIC_CONST ai_tensor_chain conv2d_13_chain;   /* Chain #10 */
AI_STATIC_CONST ai_tensor_chain conv2d_15_chain;   /* Chain #11 */
AI_STATIC_CONST ai_tensor_chain conv2d_16_chain;   /* Chain #12 */
AI_STATIC_CONST ai_tensor_chain conv2d_17_chain;   /* Chain #13 */
AI_STATIC_CONST ai_tensor_chain conv2d_18_chain;   /* Chain #14 */
AI_STATIC_CONST ai_tensor_chain conv2d_19_chain;   /* Chain #15 */
AI_STATIC_CONST ai_tensor_chain eltwise_20_chain;   /* Chain #16 */
AI_STATIC_CONST ai_tensor_chain conv2d_21_chain;   /* Chain #17 */
AI_STATIC_CONST ai_tensor_chain conv2d_22_chain;   /* Chain #18 */
AI_STATIC_CONST ai_tensor_chain conv2d_23_chain;   /* Chain #19 */
AI_STATIC_CONST ai_tensor_chain eltwise_24_chain;   /* Chain #20 */
AI_STATIC_CONST ai_tensor_chain conv2d_25_chain;   /* Chain #21 */
AI_STATIC_CONST ai_tensor_chain conv2d_26_chain;   /* Chain #22 */
AI_STATIC_CONST ai_tensor_chain conv2d_27_chain;   /* Chain #23 */
AI_STATIC_CONST ai_tensor_chain eltwise_28_chain;   /* Chain #24 */
AI_STATIC_CONST ai_tensor_chain concat_29_chain;   /* Chain #25 */
AI_STATIC_CONST ai_tensor_chain conv2d_30_chain;   /* Chain #26 */
AI_STATIC_CONST ai_tensor_chain conv2d_32_chain;   /* Chain #27 */
AI_STATIC_CONST ai_tensor_chain conv2d_33_chain;   /* Chain #28 */
AI_STATIC_CONST ai_tensor_chain conv2d_34_chain;   /* Chain #29 */
AI_STATIC_CONST ai_tensor_chain conv2d_35_chain;   /* Chain #30 */
AI_STATIC_CONST ai_tensor_chain conversion_36_chain;   /* Chain #31 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_nl conversion_0_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d conv2d_2_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d conv2d_3_layer; /* Layer #2 */
AI_STATIC ai_layer_conv2d conv2d_5_layer; /* Layer #3 */
AI_STATIC ai_layer_conv2d conv2d_6_layer; /* Layer #4 */
AI_STATIC ai_layer_conv2d conv2d_8_layer; /* Layer #5 */
AI_STATIC ai_layer_conv2d conv2d_9_layer; /* Layer #6 */
AI_STATIC ai_layer_conv2d conv2d_10_layer; /* Layer #7 */
AI_STATIC ai_layer_conv2d conv2d_11_layer; /* Layer #8 */
AI_STATIC ai_layer_concat concat_12_layer; /* Layer #9 */
AI_STATIC ai_layer_conv2d conv2d_13_layer; /* Layer #10 */
AI_STATIC ai_layer_conv2d conv2d_15_layer; /* Layer #11 */
AI_STATIC ai_layer_conv2d conv2d_16_layer; /* Layer #12 */
AI_STATIC ai_layer_conv2d conv2d_17_layer; /* Layer #13 */
AI_STATIC ai_layer_conv2d conv2d_18_layer; /* Layer #14 */
AI_STATIC ai_layer_conv2d conv2d_19_layer; /* Layer #15 */
AI_STATIC ai_layer_eltwise eltwise_20_layer; /* Layer #16 */
AI_STATIC ai_layer_conv2d conv2d_21_layer; /* Layer #17 */
AI_STATIC ai_layer_conv2d conv2d_22_layer; /* Layer #18 */
AI_STATIC ai_layer_conv2d conv2d_23_layer; /* Layer #19 */
AI_STATIC ai_layer_eltwise eltwise_24_layer; /* Layer #20 */
AI_STATIC ai_layer_conv2d conv2d_25_layer; /* Layer #21 */
AI_STATIC ai_layer_conv2d conv2d_26_layer; /* Layer #22 */
AI_STATIC ai_layer_conv2d conv2d_27_layer; /* Layer #23 */
AI_STATIC ai_layer_eltwise eltwise_28_layer; /* Layer #24 */
AI_STATIC ai_layer_concat concat_29_layer; /* Layer #25 */
AI_STATIC ai_layer_conv2d conv2d_30_layer; /* Layer #26 */
AI_STATIC ai_layer_conv2d conv2d_32_layer; /* Layer #27 */
AI_STATIC ai_layer_conv2d conv2d_33_layer; /* Layer #28 */
AI_STATIC ai_layer_conv2d conv2d_34_layer; /* Layer #29 */
AI_STATIC ai_layer_conv2d conv2d_35_layer; /* Layer #30 */
AI_STATIC ai_layer_nl conversion_36_layer; /* Layer #31 */


/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1374, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2816, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4737, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1632, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 624, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1056, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 624, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1056, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 624, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1056, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 496, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2369, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 736, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 352, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1777, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 832, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 72, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 297, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 112, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 292, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 35, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8960, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 11264, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 576, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 768, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 4, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 72, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 72, AI_STATIC)

/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_image_input0_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 25600, AI_STATIC)

/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  conversion_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 51200, AI_STATIC)

/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 19200, AI_STATIC)

/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 19200, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  concat_12_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25600, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_20_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_24_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9600, AI_STATIC)

/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_28_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2400, AI_STATIC)

/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  concat_29_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8800, AI_STATIC)

/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3200, AI_STATIC)

/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1600, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#108 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 875, AI_STATIC)

/* Array#109 */
AI_ARRAY_OBJ_DECLARE(
  conversion_36_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 875, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1209874153137207f),
    AI_PACK_INTQ_ZP(-32)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12171875685453415f),
    AI_PACK_INTQ_ZP(-11)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_35_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 35,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(3.631223808042705e-05f, 3.997981548309326e-05f, 3.109538374701515e-05f, 2.49685635935748e-05f, 0.00011714753054548055f, 8.69349532877095e-05f, 7.645087316632271e-05f, 3.974419450969435e-05f, 4.037326652905904e-05f, 3.093624400207773e-05f, 4.35159272456076e-05f, 8.685873035574332e-05f, 8.368436829186976e-05f, 7.56354711484164e-05f, 4.0938939491752535e-05f, 3.7464611523319036e-05f, 4.081245060660876e-05f, 4.997599171474576e-05f, 9.525848872726783e-05f, 7.836476288503036e-05f, 7.009522232692689e-05f, 3.889948129653931e-05f, 5.3476607718039304e-05f, 4.8219331802101806e-05f, 2.9704122425755486e-05f, 0.00011301248014206067f, 7.114659820217639e-05f, 8.006527787074447e-05f, 6.531825783895329e-05f, 5.044131103204563e-05f, 2.509384648874402e-05f, 2.2760901629226282e-05f, 0.00010330158693250269f, 8.240805618697777e-05f, 8.060551772359759e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_35_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 35,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0009613119764253497f, 0.0010584056144580245f, 0.0008232035906985402f, 0.0006610052660107613f, 0.003101305104792118f, 0.002301472472026944f, 0.002023922046646476f, 0.0010521678486838937f, 0.0010688216425478458f, 0.0008189905784092844f, 0.0011520189000293612f, 0.002299454528838396f, 0.0022154180333018303f, 0.0020023356191813946f, 0.0010837969603016973f, 0.000991819310002029f, 0.0010804483899846673f, 0.001323039410635829f, 0.0025218254886567593f, 0.0020745894871652126f, 0.0018556658178567886f, 0.0010298053966835141f, 0.0014157128753140569f, 0.0012765343999490142f, 0.0007863720529712737f, 0.002991835819557309f, 0.0018834994407370687f, 0.0021196079906076193f, 0.001729202806018293f, 0.001335358014330268f, 0.0006643219385296106f, 0.000602560699917376f, 0.002734754467383027f, 0.0021816296502947807f, 0.0021339100785553455f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(2.4619086616439745e-05f, 5.416118074208498e-05f, 7.497751357732341e-05f, 3.245861444156617e-05f, 3.934805863536894e-05f, 4.1831357521004975e-05f, 2.2592688765143976e-05f, 2.2515407181344926e-05f, 5.2018469432368875e-05f, 3.3857100788736716e-05f, 3.513456613291055e-05f, 3.673621540656313e-05f, 4.2370433220639825e-05f, 4.175822323304601e-05f, 4.3784013541880995e-05f, 4.640005136025138e-05f, 4.4580938265426084e-05f, 5.732915815315209e-05f, 3.297558578196913e-05f, 6.551238766405731e-05f, 3.896567795891315e-05f, 5.791880175820552e-05f, 2.7263176889391616e-05f, 2.7622234483715147e-05f, 5.000642340746708e-05f, 3.824273153441027e-05f, 9.313373448094353e-05f, 2.7355554266250692e-05f, 4.887974137091078e-05f, 3.7546320527326316e-05f, 3.94509406760335e-05f, 3.7160367355681956e-05f, 1.8463419110048562e-05f, 3.370709964656271e-05f, 3.9844915590947494e-05f, 3.0951709049986675e-05f, 4.183287455816753e-05f, 3.90436289308127e-05f, 4.867751704296097e-05f, 2.2236437871470116e-05f, 4.2313840822316706e-05f, 2.9086148060741834e-05f, 3.247702989028767e-05f, 4.9909136578207836e-05f, 3.588014078559354e-05f, 3.5581604606704786e-05f, 4.329739022068679e-05f, 5.6404089264106005e-05f, 2.4463815861963667e-05f, 5.32223166374024e-05f, 3.837496478809044e-05f, 3.727809962583706e-05f, 3.092260885750875e-05f, 4.588373121805489e-05f, 6.286640564212576e-05f, 6.69372093398124e-05f, 2.929511720139999e-05f, 4.1763119952520356e-05f, 3.3066582545870915e-05f, 5.464454443426803e-05f, 4.022755456389859e-05f, 3.8291058444883674e-05f, 4.074267781106755e-05f, 2.5897248633555137e-05f, 4.006116068921983e-05f, 3.222298255423084e-05f, 3.3647640520939603e-05f, 2.5440558601985686e-05f, 3.1048202799865976e-05f, 3.541630212566815e-05f, 3.063150143134408e-05f, 3.977604501415044e-05f, 5.308522668201476e-05f, 7.52764317439869e-05f, 3.0307330234791152e-05f, 3.225088948966004e-05f, 6.506666977657005e-05f, 2.2910444386070594e-05f, 3.398577973712236e-05f, 3.8364098145393655e-05f, 3.625063254730776e-05f, 3.7979083572281525e-05f, 3.0890663765603676e-05f, 4.2765892430907115e-05f, 4.414984505274333e-05f, 4.07601437473204e-05f, 5.258862438495271e-05f, 5.027943552704528e-05f, 5.4363983508665115e-05f, 4.373491901787929e-05f, 2.628596848808229e-05f, 7.60370385251008e-05f, 2.674373536137864e-05f, 3.15405304718297e-05f, 3.24121028825175e-05f, 4.3662690586643293e-05f, 0.00013531999138649553f, 4.0478218579664826e-05f, 4.828405144507997e-05f, 4.106265987502411e-05f, 7.758849096717313e-05f, 5.004287595511414e-05f, 4.679607809521258e-05f, 6.308155570877716e-05f, 3.9426988223567605e-05f, 3.1084444344742224e-05f, 5.210658491705544e-05f, 5.271298505249433e-05f, 5.5858610721770674e-05f, 3.2755531719885767e-05f, 2.8349870262900367e-05f, 2.4621363991172984e-05f, 3.173748336848803e-05f, 5.1098591939080507e-05f, 4.1620703996159136e-05f, 6.961735198274255e-05f, 2.6641017029760405e-05f, 3.947104778490029e-05f, 3.374740117578767e-05f, 6.552063132403418e-05f, 3.5080007364740595e-05f, 4.551882011583075e-05f, 2.9187489417381585e-05f, 5.238472658675164e-05f, 5.4061190894572064e-05f, 6.455377297243103e-05f, 4.5918164687464014e-05f, 3.3857089874800295e-05f, 4.570668897940777e-05f, 5.463876004796475e-05f, 7.892598659964278e-05f, 2.645847234816756e-05f, 5.346082252799533e-05f, 2.5170356821035966e-05f, 4.2957883124472573e-05f, 4.32802080467809e-05f, 4.023478686576709e-05f, 3.8563754060305655e-05f, 4.017643004772253e-05f, 2.8397602363838814e-05f, 3.435604594415054e-05f, 3.2116786314873025e-05f, 4.190239269519225e-05f, 3.537671364028938e-05f, 7.026090315775946e-05f, 4.8623736802255735e-05f, 3.247712447773665e-05f, 5.0347152864560485e-05f, 3.1563500670017675e-05f, 6.473471148638055e-05f, 4.5486063754651695e-05f, 4.0477370930602774e-05f, 3.834971721516922e-05f, 4.573403930407949e-05f, 6.260562076931819e-05f, 5.240643076831475e-05f, 3.8868136471137404e-05f, 7.055864261928946e-05f, 4.390762478578836e-05f, 3.90899003832601e-05f, 3.5875342291546986e-05f, 4.14767928305082e-05f, 3.1424064218299463e-05f, 3.617907714215107e-05f, 3.514937270665541e-05f, 5.529728878173046e-05f, 3.449047289905138e-05f, 2.6390591301606037e-05f, 5.0024569645756856e-05f, 3.001624281750992e-05f, 2.823108843585942e-05f, 3.0955812690081075e-05f, 4.162213735980913e-05f, 3.742217813851312e-05f, 4.355597047833726e-05f, 5.179797517484985e-05f, 3.532191112753935e-05f, 3.099446985288523e-05f, 3.626578109106049e-05f, 4.028685361845419e-05f, 5.267601227387786e-05f, 3.727638249984011e-05f, 6.453564128605649e-05f, 3.213177842553705e-05f, 3.778006794163957e-05f, 3.638443013187498e-05f, 2.821610905812122e-05f, 3.214603566448204e-05f, 4.4066768168704584e-05f, 8.892012556316331e-05f, 3.2392184948548675e-05f, 3.224587635486387e-05f, 2.755891728156712e-05f, 3.374866719241254e-05f, 3.181025022058748e-05f, 5.8774119679583237e-05f, 2.3755821530357935e-05f, 5.6613727792864665e-05f, 3.9664835639996454e-05f, 2.7771493478212506e-05f, 2.18345012399368e-05f, 4.8313762817997485e-05f, 3.459424988250248e-05f, 4.534247636911459e-05f, 4.033962613902986e-05f, 4.279944550944492e-05f, 3.957723674830049e-05f, 5.617195347440429e-05f, 0.00012467980559449643f, 2.678346572793089e-05f, 3.363319774507545e-05f, 2.7888367185369134e-05f, 3.39485086442437e-05f, 4.098931822227314e-05f, 3.300417301943526e-05f, 2.657282675500028e-05f, 3.244491745135747e-05f, 5.864043123438023e-05f, 3.8416110328398645e-05f, 3.0516104743583128e-05f, 2.977274743898306e-05f, 3.6980902223149315e-05f, 3.3526539482409135e-05f, 4.612609336618334e-05f, 2.1979871235089377e-05f, 5.9627273003570735e-05f, 4.6508463128702715e-05f, 3.9739861676935107e-05f, 4.580628956318833e-05f, 3.209731949027628e-05f, 3.855941031360999e-05f, 4.150722088525072e-05f, 3.5646928154164925e-05f, 2.505776319594588e-05f, 3.4207678254460916e-05f, 2.7139985832036473e-05f, 3.229434514651075e-05f, 3.756854493985884e-05f, 2.829948607541155e-05f, 3.213182935724035e-05f, 4.504525713855401e-05f, 7.965929398778826e-05f, 3.8311434764182195e-05f, 4.7775862185517326e-05f, 3.177008329657838e-05f, 3.0957202397985384e-05f, 4.5852702896809205e-05f, 4.1173745557898656e-05f, 3.7595833418890834e-05f, 3.264141923864372e-05f, 4.862565765506588e-05f, 5.878110823687166e-05f, 4.609288589563221e-05f, 3.899441799148917e-05f, 5.0334394472884014e-05f, 7.021683995844796e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 256,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005020794342271984f, 0.0011045582359656692f, 0.0015290846349671483f, 0.0006619580672122538f, 0.0008024607668630779f, 0.0008531049825251102f, 0.0004607532755471766f, 0.00045917718671262264f, 0.0010608599986881018f, 0.0006904786569066346f, 0.0007165311835706234f, 0.0007491950527764857f, 0.0008640987798571587f, 0.0008516134694218636f, 0.0008929272298701108f, 0.0009462784510105848f, 0.0009091796819120646f, 0.0011691657127812505f, 0.0006725011044181883f, 0.0013360537122935057f, 0.0007946625119075179f, 0.0011811908334493637f, 0.0005560027784667909f, 0.000563325360417366f, 0.001019826508127153f, 0.0007799188606441021f, 0.0018993610283359885f, 0.0005578867276199162f, 0.0009968490339815617f, 0.0007657163077965379f, 0.0008045589784160256f, 0.0007578451768495142f, 0.00037654131301678717f, 0.0006874195532873273f, 0.0008125936146825552f, 0.0006312264013104141f, 0.0008531358907930553f, 0.0007962522795423865f, 0.0009927249047905207f, 0.0004534879117272794f, 0.0008629446383565664f, 0.0005931803025305271f, 0.0006623336230404675f, 0.0010178424417972565f, 0.0007317363633774221f, 0.0007256480748765171f, 0.0008830031147226691f, 0.0011502999113872647f, 0.0004989128792658448f, 0.0010854111751541495f, 0.000782615621574223f, 0.0007602461846545339f, 0.0006306329159997404f, 0.0009357486851513386f, 0.0012820918345823884f, 0.001365111442282796f, 0.0005974419764243066f, 0.0008517133537679911f, 0.0006743568810634315f, 0.0011144159361720085f, 0.0008203971665352583f, 0.000780904374551028f, 0.0008309025433845818f, 0.0005281461635604501f, 0.0008170037181116641f, 0.0006571526173502207f, 0.0006862069712951779f, 0.000518832472153008f, 0.0006331942859105766f, 0.0007222769199870527f, 0.0006246960838325322f, 0.0008111890638247132f, 0.0010826153447851539f, 0.0015351808397099376f, 0.0006180849741213024f, 0.0006577217136509717f, 0.001326963771134615f, 0.0004672335635405034f, 0.0006931029492989182f, 0.0007823939668014646f, 0.0007392921252176166f, 0.0007745420443825424f, 0.0006299814558587968f, 0.0008721637423150241f, 0.0009003879968076944f, 0.0008312587160617113f, 0.0010724876774474978f, 0.0010253943037241697f, 0.0011086942395195365f, 0.0008919259998947382f, 0.0005360736977308989f, 0.0015506924828514457f, 0.0005454093334265053f, 0.0006432347581721842f, 0.0006610095151700079f, 0.000890452996827662f, 0.002759703667834401f, 0.0008255091379396617f, 0.0009847006294876337f, 0.0008374282042495906f, 0.0015823326539248228f, 0.0010205699363723397f, 0.0009543549967929721f, 0.0012864795280620456f, 0.0008040704415179789f, 0.0006339333485811949f, 0.0010626569855958223f, 0.0010750239016488194f, 0.0011391754960641265f, 0.0006680134101770818f, 0.0005781647050753236f, 0.0005021258839406073f, 0.000647251377813518f, 0.0010421001352369785f, 0.0008488089079037309f, 0.0014197700656950474f, 0.0005433144979178905f, 0.0008049689931795001f, 0.0006882415036670864f, 0.0013362218160182238f, 0.0007154185441322625f, 0.0009283067192882299f, 0.0005952470237389207f, 0.0010683294385671616f, 0.0011025191051885486f, 0.0013165038544684649f, 0.0009364509023725986f, 0.0006904784822836518f, 0.0009321381221525371f, 0.0011142980074509978f, 0.0016096094623208046f, 0.0005395917105488479f, 0.0010902752401307225f, 0.0005133220111019909f, 0.0008760791970416903f, 0.0008826526463963091f, 0.0008205446065403521f, 0.0007864657673053443f, 0.0008193544927053154f, 0.0005791381699964404f, 0.0007006541127339005f, 0.0006549868267029524f, 0.0008545536547899246f, 0.000721469521522522f, 0.0014328944962471724f, 0.0009916281560435891f, 0.0006623355438932776f, 0.0010267753386870027f, 0.0006437032134272158f, 0.0013201938709244132f, 0.000927638728171587f, 0.0008254919084720314f, 0.0007821007166057825f, 0.0009326959261670709f, 0.0012767734006047249f, 0.0010687720496207476f, 0.0007926733233034611f, 0.0014389666030183434f, 0.0008954481454566121f, 0.0007971959421411157f, 0.0007316385162994266f, 0.0008458740194328129f, 0.0006408595363609493f, 0.0007378328591585159f, 0.0007168331649154425f, 0.0011277279118075967f, 0.000703395635355264f, 0.0005382073577493429f, 0.0010201965924352407f, 0.0006121485494077206f, 0.0005757422768510878f, 0.0006313101039268076f, 0.0008488381281495094f, 0.0007631845655851066f, 0.0008882765541784465f, 0.0010563632240518928f, 0.0007203518762253225f, 0.0006320984684862196f, 0.0007396010914817452f, 0.0008216064888983965f, 0.0010742698796093464f, 0.0007602112018503249f, 0.0013161341194063425f, 0.0006552925915457308f, 0.0007704833406023681f, 0.0007420207839459181f, 0.0005754368030466139f, 0.0006555833388119936f, 0.0008986936882138252f, 0.0018134290585294366f, 0.0006606032839044929f, 0.0006576195009984076f, 0.0005620340816676617f, 0.000688267289660871f, 0.0006487353821285069f, 0.0011986341560259461f, 0.0004844740906264633f, 0.001154575264081359f, 0.0008089211187325418f, 0.0005663693300448358f, 0.0004452908760868013f, 0.000985306571237743f, 0.0007055120076984167f, 0.0009247103589586914f, 0.0008226827485486865f, 0.0008728480315767229f, 0.0008071346092037857f, 0.0011455657659098506f, 0.002542708767578006f, 0.0005462195840664208f, 0.0006859124405309558f, 0.0005687528755515814f, 0.0006923428154550493f, 0.0008359324419870973f, 0.0006730841123498976f, 0.0005419238586910069f, 0.0006616787286475301f, 0.0011959077091887593f, 0.0007834546850062907f, 0.0006223426898941398f, 0.0006071827374398708f, 0.0007541851955465972f, 0.0006837372202426195f, 0.0009406913886778057f, 0.000448255508672446f, 0.0012160332407802343f, 0.000948489410802722f, 0.0008104511653073132f, 0.0009341693366877735f, 0.0006545898504555225f, 0.000786377175245434f, 0.0008464945713058114f, 0.0007269802736118436f, 0.0005110257770866156f, 0.0006976283038966358f, 0.0005534904194064438f, 0.0006586079834960401f, 0.0007661695126444101f, 0.0005771371652372181f, 0.0006552936392836273f, 0.0009186489623971283f, 0.0016245645238086581f, 0.0007813199772499502f, 0.000974336639046669f, 0.0006479162257164717f, 0.0006313383928500116f, 0.0009351159096695483f, 0.0008396936464123428f, 0.0007667260360904038f, 0.0006656861514784396f, 0.000991667271591723f, 0.0011987766483798623f, 0.0009400142007507384f, 0.0007952486630529165f, 0.0010265151504427195f, 0.001431996002793312f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.589113789028488e-05f, 9.146509546553716e-05f, 9.254715405404568e-05f, 0.00016319200221914798f, 0.00010349689546274021f, 8.021497342269868e-05f, 0.00016481058264616877f, 7.101801020326093e-05f, 7.877290772739798e-05f, 7.169383752625436e-05f, 0.00016013513959478587f, 6.032257806509733e-05f, 0.00010921034117927775f, 0.0003497157886158675f, 0.00011105371959274635f, 0.00010391889372840524f, 0.00010190062312176451f, 0.00011458925291663036f, 6.337348895613104e-05f, 0.00010247400496155024f, 9.51643887674436e-05f, 0.0001425012742402032f, 0.00014993642980698496f, 0.00013069722626823932f, 0.00011931690823985264f, 0.000125630060210824f, 8.282926864922047e-05f, 6.77941570756957e-05f, 9.461613080929965e-05f, 0.00014715459838043898f, 6.196689355419949e-05f, 0.00010247441969113424f, 0.00012316521315369755f, 0.00015308339789044112f, 0.000192709470866248f, 0.00012952224642504007f, 0.00013473314174916595f, 5.8186487876810133e-05f, 7.33206543372944e-05f, 5.851667083334178e-05f, 0.0001008119506877847f, 0.00013041614147368819f, 0.00013274392404127866f, 9.557399607729167e-05f, 0.0001688711199676618f, 7.321464363485575e-05f, 9.06679779291153e-05f, 7.79140173108317e-05f, 8.807029371382669e-05f, 5.752667857450433e-05f, 0.00013016494631301612f, 0.00016567290003877133f, 0.0001397070154780522f, 0.00011004434782080352f, 7.206103327916935e-05f, 0.00018762129184324294f, 9.298375516664237e-05f, 0.00013900292105972767f, 6.863953603897244e-05f, 0.0001390835823258385f, 6.496529385913163e-05f, 5.625658013741486e-05f, 0.00010318687418475747f, 0.0001109361692215316f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0013336719712242484f, 0.002182536292821169f, 0.0022083562798798084f, 0.003894080640748143f, 0.0024696385953575373f, 0.0019140864023938775f, 0.003932703286409378f, 0.0016946288524195552f, 0.0018796758959069848f, 0.0017107552848756313f, 0.003821138059720397f, 0.0014394148020073771f, 0.0026059725787490606f, 0.008344903588294983f, 0.0026499591767787933f, 0.0024797082878649235f, 0.002431548433378339f, 0.002734323963522911f, 0.0015122155891731381f, 0.002445230493322015f, 0.0022708086762577295f, 0.0034003593027591705f, 0.0035777767188847065f, 0.003118691733106971f, 0.002847135066986084f, 0.0029977792873978615f, 0.001976468600332737f, 0.001617701374925673f, 0.0022577261552214622f, 0.0035113967023789883f, 0.0014786514220759273f, 0.0024452402722090483f, 0.002938963007181883f, 0.00365286972373724f, 0.004598425235599279f, 0.0030906544998288155f, 0.0032149965409189463f, 0.001388443517498672f, 0.0017495743231847882f, 0.0013963223900645971f, 0.002405570587143302f, 0.0031119845807552338f, 0.003167530056089163f, 0.0022805826738476753f, 0.004029595758765936f, 0.0017470447346568108f, 0.0021635154262185097f, 0.0018591810949146748f, 0.002101529622450471f, 0.0013726991601288319f, 0.0031059905886650085f, 0.0039532799273729324f, 0.0033336831256747246f, 0.0026258735451847315f, 0.0017195172840729356f, 0.004477011505514383f, 0.0022187745198607445f, 0.0033168818335980177f, 0.0016378738218918443f, 0.0033188066445291042f, 0.0015501991147175431f, 0.0013423921773210168f, 0.002462240867316723f, 0.002647154266014695f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_32_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00010769630171125755f, 0.00022538464691024274f, 7.212252239696681e-05f, 7.106200064299628e-05f, 0.00017110322369262576f, 9.456244151806459e-05f, 0.00018269762222189456f, 0.00018498617282602936f, 0.0002909978502430022f, 0.0001707521005300805f, 0.0001487685221945867f, 0.0001313014217885211f, 0.00012288527796044946f, 0.00010460198973305523f, 0.00010363356705056503f, 0.0004925071261823177f, 0.0002810003643389791f, 0.0001952637976501137f, 0.00010501396900508553f, 0.00011630084918579087f, 0.00013197884254623204f, 0.0001398771273670718f, 9.452000813325867e-05f, 0.00010715621465351433f, 9.630754357203841e-05f, 0.00016432395204901695f, 0.0001541383971925825f, 0.00010080832726089284f, 9.026004408951849e-05f, 0.0001632657222216949f, 9.228981070918962e-05f, 0.00013716235116589814f, 7.704669405939057e-05f, 0.000138302959385328f, 0.00022676307708024979f, 0.00022319320123642683f, 9.775510989129543e-05f, 8.426990825682878e-05f, 0.0002578175044618547f, 0.00012499588774517179f, 0.00013783943722955883f, 0.00013885660155210644f, 0.00016910799604374915f, 9.365580626763403e-05f, 0.00015844232984818518f, 8.345730020664632e-05f, 0.00019046582747250795f, 0.00012645503738895059f, 0.00013884408690501004f, 0.0004704247694462538f, 0.00014317609020508826f, 0.00012159621837781742f, 0.00017218492575921118f, 0.00043733176426030695f, 9.550633694743738e-05f, 0.00011959409312112257f, 0.0001541817473480478f, 0.0002567850169725716f, 9.560630860505626e-05f, 0.00012583895295392722f, 7.523240492446348e-05f, 0.00027046006289310753f, 0.00012506100756581873f, 0.00012175520532764494f, 8.988904301077127e-05f, 0.00020688351651187986f, 0.00019229778263252228f, 0.00010041839414043352f, 9.374153160024434e-05f, 7.804859342286363e-05f, 0.00014614505926147103f, 0.0002127228071913123f, 0.00012958979641553015f, 0.00010588220902718604f, 0.00018168488168157637f, 7.865671796025708e-05f, 9.907782805385068e-05f, 0.00023586433962918818f, 7.474656740669161e-05f, 0.0001528451102785766f, 0.0001594464119989425f, 0.00011797267507063225f, 0.00010424834908917546f, 0.00017741534975357354f, 9.503750334260985e-05f, 0.0005269231041893363f, 0.00011462716065580025f, 0.00036383027327246964f, 0.00028091476997360587f, 0.00017345574451610446f, 0.00010698797268560156f, 0.00010404545901110396f, 0.00011152889783261344f, 9.169332770397887e-05f, 7.753739191684872e-05f, 8.208363578887656e-05f, 0.00010281903814757243f, 5.745410453528166e-05f, 0.00015609567344654351f, 0.0001134714693762362f, 0.00011788430128945038f, 0.00015730301674921066f, 4.239774352754466e-05f, 0.00012663591769523919f, 0.00014047662261873484f, 0.00015623995568603277f, 6.924162880750373e-05f, 7.460398774128407e-05f, 9.734072227729484e-05f, 0.00012274016626179218f, 0.0009762847330421209f, 0.00012320610403548926f, 7.980703958310187e-05f, 0.00017098650278057903f, 0.0004305760667193681f, 6.724834383931011e-05f, 0.00012538967712316662f, 0.00031801682780496776f, 7.607597945025191e-05f, 6.964046770008281e-05f, 0.00017401248624082655f, 8.033259655348957e-05f, 0.0001141881657531485f, 0.00037551551940850914f, 0.00010671264317352325f, 0.00016080372733995318f, 7.77680761530064e-05f, 0.00011378402996342629f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_32_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00470581604167819f, 0.009848237037658691f, 0.0031514111906290054f, 0.003105071373283863f, 0.007476396858692169f, 0.004131929017603397f, 0.007983016781508923f, 0.00808301568031311f, 0.012715221382677555f, 0.007461054716259241f, 0.0065004765056073666f, 0.005737247411161661f, 0.005369502119719982f, 0.004570609424263239f, 0.00452829385176301f, 0.02152021788060665f, 0.012278379872441292f, 0.008532099425792694f, 0.0045886109583079815f, 0.005081793759018183f, 0.005766847636550665f, 0.006111965049058199f, 0.004130074754357338f, 0.004682216793298721f, 0.004208181519061327f, 0.00718017527833581f, 0.006735114846378565f, 0.0044048442505300045f, 0.003943934570997953f, 0.007133935112506151f, 0.004032625816762447f, 0.005993342492729425f, 0.003366574179381132f, 0.006043181288987398f, 0.009908467531204224f, 0.009752481244504452f, 0.004271433223038912f, 0.0036821940448135138f, 0.011265398003160954f, 0.005461725872009993f, 0.006022927816957235f, 0.0060673728585243225f, 0.007389215286821127f, 0.004092313349246979f, 0.006923175882548094f, 0.0036466869059950113f, 0.008322450332343578f, 0.005525483749806881f, 0.006066826172173023f, 0.020555324852466583f, 0.006256114225834608f, 0.005313176196068525f, 0.007523662410676479f, 0.019109318032860756f, 0.004173172637820244f, 0.005225692875683308f, 0.006737008690834045f, 0.011220283806324005f, 0.004177541006356478f, 0.0054985638707876205f, 0.0032872981391847134f, 0.011817817576229572f, 0.005464571062475443f, 0.0053201233968138695f, 0.003927723504602909f, 0.00903982575982809f, 0.008402498438954353f, 0.004387806169688702f, 0.004096059128642082f, 0.0034103523939847946f, 0.006385843735188246f, 0.009294974617660046f, 0.005662457551807165f, 0.00462654884904623f, 0.007938764989376068f, 0.003436924424022436f, 0.0043292297050356865f, 0.01030614972114563f, 0.0032660693395882845f, 0.006678604520857334f, 0.006967049557715654f, 0.005154844839125872f, 0.004555156920105219f, 0.007752206642180681f, 0.0041526868008077145f, 0.02302403189241886f, 0.005008661653846502f, 0.015897652134299278f, 0.012274638749659061f, 0.007579191122204065f, 0.004674865398555994f, 0.004546291660517454f, 0.00487328227609396f, 0.004006562288850546f, 0.0033880153205245733f, 0.003586664330214262f, 0.004492702893912792f, 0.002510471036657691f, 0.0068206386640667915f, 0.004958163481205702f, 0.005150983110070229f, 0.006873393431305885f, 0.0018525797640904784f, 0.005533386953175068f, 0.0061381603591144085f, 0.006826942786574364f, 0.003025529906153679f, 0.0032598392572253942f, 0.004253326449543238f, 0.005363161675632f, 0.04265899956226349f, 0.005383520387113094f, 0.003487188136205077f, 0.007471296936273575f, 0.018814126029610634f, 0.0029384326189756393f, 0.005478932522237301f, 0.013895822688937187f, 0.003324158489704132f, 0.003042957279831171f, 0.007603518199175596f, 0.0035101522225886583f, 0.004989479668438435f, 0.016408242285251617f, 0.004662835039198399f, 0.007026358041912317f, 0.0033980950247496367f, 0.0049718208611011505f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00016218559176195413f, 0.00012806725862901658f, 0.00013022149505559355f, 0.00011968835315201432f, 0.0002750094572547823f, 0.00019881426123902202f, 6.387285247910768e-05f, 0.00017453322652727365f, 0.00013884104555472732f, 0.00011763005022658035f, 0.00023073550255503505f, 0.0001584935816936195f, 0.00013966139522381127f, 0.0001743808970786631f, 0.00021398294484242797f, 0.0001462167128920555f, 0.00010274703527102247f, 0.00013879031757824123f, 0.0001456412865081802f, 0.00015791345504112542f, 0.0001169043462141417f, 0.00018321532115805894f, 0.00012851045175921172f, 0.00019187135330867022f, 0.000164812954608351f, 0.0001483469532104209f, 0.00015843103756196797f, 0.00014613043458666652f, 0.00011841175000881776f, 0.0001293124514631927f, 0.0001588350860401988f, 0.00018831640772987157f, 0.00018694749451242387f, 0.00014378174091689289f, 9.741389658302069e-05f, 0.00010033993021352217f, 0.00017784569354262203f, 0.00022099837951827794f, 0.00011046128201996908f, 0.00018614782311487943f, 0.00013939474592916667f, 0.000181173236342147f, 0.00019826543575618416f, 0.00011353530862834305f, 0.00011759907647501677f, 0.00014543301949743181f, 0.000149507584865205f, 0.00016599107766523957f, 0.0001734756224323064f, 0.0001545080594951287f, 0.00013300376303959638f, 0.00014147147885523736f, 0.00015541362517978996f, 0.00011221971362829208f, 0.0001154954734374769f, 0.00015702046221122146f, 0.00016182578110601753f, 0.00011644018377410248f, 0.0001583447738084942f, 0.00015112660184968263f, 0.00014993135118857026f, 0.0001613822823856026f, 0.00014602160081267357f, 0.00013536980259232223f, 0.00012058682477800176f, 0.0001037048568832688f, 7.472190918633714e-05f, 0.00013338377175386995f, 0.00014362561341840774f, 0.0001622356503503397f, 0.0001644415024202317f, 0.00011954613728448749f, 0.0001510556467110291f, 0.00015171695849858224f, 0.00011329678818583488f, 0.00011633393296506256f, 0.00021349903545342386f, 6.539164314744994e-05f, 0.00016572467575315386f, 0.00016762800805736333f, 0.00011057712254114449f, 0.00012102298205718398f, 0.00015526427887380123f, 0.00013756506086792797f, 0.00013807874347548932f, 0.0001516497286502272f, 0.0001192715426441282f, 0.00014283068594522774f, 0.00010588286386337131f, 8.712090493645519e-05f, 0.00020574616792146116f, 0.00013333749666344374f, 0.0001714239624561742f, 0.00017316431330982596f, 0.0001338464062428102f, 0.00013168671284802258f, 0.00011950003681704402f, 0.0001414414291502908f, 0.00021826218289788812f, 0.00018020649440586567f, 0.0001631724153412506f, 0.000114815506094601f, 0.00017974800721276551f, 0.0001630076440051198f, 0.00018245023966301233f, 0.00019832406542263925f, 0.00012141397746745497f, 0.00011683637421811f, 0.00013753715029451996f, 0.00015314649499487132f, 6.511725223390386e-05f, 0.00015307217836380005f, 0.0001564222911838442f, 0.00012582445924635977f, 8.560490823583677e-05f, 0.00013828184455633163f, 0.00013152486644685268f, 0.00011611128138611093f, 0.00013962805678602308f, 0.00015571496624033898f, 0.00015642328071407974f, 0.00018075970001518726f, 0.00016170868184417486f, 0.00010694771481212229f, 0.00014180885045789182f, 0.00011717680172296241f, 8.300812623929232e-05f, 0.0001738639548420906f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0013405162608250976f, 0.0010585171403363347f, 0.0010763226309791207f, 0.0009892628295347095f, 0.002273041754961014f, 0.0016432639677077532f, 0.0005279297474771738f, 0.0014425733825191855f, 0.001147566013969481f, 0.0009722503018565476f, 0.0019071033457294106f, 0.0013100005453452468f, 0.001154346507973969f, 0.0014413143508136272f, 0.0017686380306258798f, 0.0012085282942280173f, 0.0008492373744957149f, 0.0011471466859802604f, 0.001203772146254778f, 0.001305205631069839f, 0.0009662521188147366f, 0.0015143337659537792f, 0.001062180264852941f, 0.0015858785482123494f, 0.0013622322585433722f, 0.0012261354131624103f, 0.0013094836613163352f, 0.0012078151339665055f, 0.0009787112940102816f, 0.0010688090696930885f, 0.0013128231512382627f, 0.0015564957866445184f, 0.0015451813815161586f, 0.0011884024133905768f, 0.0008051572367548943f, 0.0008293418795801699f, 0.001469952054321766f, 0.0018266228726133704f, 0.000912998104467988f, 0.0015385717852041125f, 0.0011521425331011415f, 0.0014974551741033792f, 0.0016387277282774448f, 0.0009384059230796993f, 0.0009719943045638502f, 0.0012020508293062449f, 0.0012357283849269152f, 0.0013719698181375861f, 0.0014338319888338447f, 0.0012770589673891664f, 0.001099318964406848f, 0.0011693073902279139f, 0.0012845437740907073f, 0.0009275320917367935f, 0.000954607327003032f, 0.0012978247832506895f, 0.0013375423150137067f, 0.00096241565188393f, 0.0013087706174701452f, 0.0012491100933402777f, 0.0012392309727147222f, 0.0013338766293600202f, 0.0012069155927747488f, 0.0011188751086592674f, 0.0009966889629140496f, 0.0008571540820412338f, 0.0006176006863825023f, 0.0011024598497897387f, 0.0011871119495481253f, 0.0013409300008788705f, 0.0013591620372608304f, 0.000988087384030223f, 0.0012485235929489136f, 0.0012539896415546536f, 0.000936434487812221f, 0.0009615374729037285f, 0.0017646383494138718f, 0.0005404829862527549f, 0.0013697679387405515f, 0.0013854994904249907f, 0.0009139555622823536f, 0.0010002939961850643f, 0.0012833093060180545f, 0.0011370196007192135f, 0.0011412653839215636f, 0.0012534338748082519f, 0.000985817750915885f, 0.0011805417016148567f, 0.0008751560235396028f, 0.0007200823747552931f, 0.0017005584668368101f, 0.0011020774254575372f, 0.0014168743509799242f, 0.001431258860975504f, 0.001106283743865788f, 0.001088433084078133f, 0.0009877063566818833f, 0.0011690589599311352f, 0.001804007333703339f, 0.001489464775659144f, 0.001348672667518258f, 0.000948987202718854f, 0.0014856752241030335f, 0.0013473107246682048f, 0.0015080100856721401f, 0.0016392123652622104f, 0.00100352568551898f, 0.0009656902984715998f, 0.0011367888655513525f, 0.0012658052146434784f, 0.0005382150993682444f, 0.0012651908909901977f, 0.0012928806245326996f, 0.0010399797465652227f, 0.0007075521862134337f, 0.0011429439764469862f, 0.0010870954720303416f, 0.0009596971794962883f, 0.0011540709529072046f, 0.0012870343634858727f, 0.0012928888900205493f, 0.0014940372202545404f, 0.0013365744380280375f, 0.0008839573711156845f, 0.0011720958864316344f, 0.0009685040568001568f, 0.0006860889261588454f, 0.001437041675671935f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00012531844549812376f, 0.0001254809758393094f, 0.0001685309107415378f, 0.00018275080947205424f, 0.00014946273586247116f, 0.00014936890511307865f, 0.00012085588241461664f, 9.282065730076283e-05f, 0.00013958914496470243f, 0.00013304715685080737f, 0.00012827850878238678f, 0.00010639136598911136f, 0.00015711317246314138f, 0.00013922240759711713f, 0.00010448475950397551f, 0.00013832452532369643f, 0.00015056888514664024f, 8.734547009225935e-05f, 0.0001479472266510129f, 0.0001748690992826596f, 0.00010091882722917944f, 0.00011767515388783067f, 0.00012071563833160326f, 0.00012794298527296633f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004140907432883978f, 0.004146277904510498f, 0.005568780470639467f, 0.006038649473339319f, 0.004938709083944559f, 0.004935608711093664f, 0.003993450663983822f, 0.003067080397158861f, 0.004612455144524574f, 0.004396287724375725f, 0.004238716792315245f, 0.0035154984798282385f, 0.005191503092646599f, 0.004600337240844965f, 0.0034524982329458f, 0.004570668563246727f, 0.004975259769707918f, 0.002886163303628564f, 0.004888631869107485f, 0.005778213497251272f, 0.003334668930619955f, 0.003888349514454603f, 0.003988816402852535f, 0.004227630328387022f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(6.813453364884481e-05f, 0.00013215222861617804f, 0.00012687555863521993f, 0.00025025854120031f, 0.00012281379895284772f, 0.00016293281805701554f, 0.0001240589190274477f, 0.00014181449660100043f, 0.0001067431439878419f, 0.00023658815189264715f, 0.00016110432625282556f, 0.00017369842680636793f, 0.00014558139082510024f, 0.00017924918211065233f, 0.00018902825831901282f, 9.589389810571447e-05f, 0.00016550967120565474f, 0.00016120594227686524f, 0.00010995252523571253f, 0.0001672300713835284f, 0.0001265315804630518f, 0.00016506326210219413f, 0.00015499159053433686f, 0.00011751619604183361f, 0.00010657335951691493f, 0.0002028694871114567f, 0.00011729151447070763f, 0.00018254842143505812f, 0.0001798399753170088f, 0.0001613040512893349f, 0.00011088183964602649f, 0.00010763644968392327f, 0.0002282400819240138f, 0.0001680670538917184f, 0.00015165422519203275f, 0.00010378456499893218f, 6.963797932257876e-05f, 0.00013269040209706873f, 0.00013680038682650775f, 0.00014175570686347783f, 9.698145731817931e-05f, 9.554439020575956e-05f, 9.324706479674205e-05f, 0.00015297318168450147f, 0.00021776588982902467f, 0.00019165273988619447f, 0.0001822436897782609f, 0.00010971328447340056f, 0.00010140494850929826f, 0.00013186769501771778f, 7.95844171079807e-05f, 0.0001088165445253253f, 0.00015225062088575214f, 0.00012081591557944193f, 8.106737368507311e-05f, 0.00014867584104649723f, 9.03273539734073e-05f, 0.00011122613796032965f, 0.00011176779662491754f, 0.00011307623935863376f, 0.0001249617344001308f, 0.00015030699432827532f, 0.0001267799234483391f, 0.0002108904009219259f, 9.530055831419304e-05f, 0.000144775360240601f, 0.00016495978343300521f, 0.00019215587235521525f, 7.626877777511254e-05f, 0.00017588739865459502f, 0.00014328314864542335f, 0.00014061390538699925f, 0.00011114697554148734f, 0.00010658364772098139f, 0.00011864890257129446f, 0.00014514238864649087f, 0.00012841013085562736f, 0.00013033828872721642f, 0.00020268090884201229f, 0.00013383802433963865f, 0.00021766549616586417f, 0.00012287461140658706f, 0.00018174595606978983f, 0.00014938988897483796f, 0.00013731716899201274f, 0.00013359441072680056f, 0.00014278266462497413f, 9.025349572766572e-05f, 0.00030945727485232055f, 0.00020425324328243732f, 0.00017206430493388325f, 8.922223787521943e-05f, 9.864980529528111e-05f, 0.00011189259384991601f, 0.00014391721924766898f, 0.00014924474817235023f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003262280486524105f, 0.006327446550130844f, 0.006074799690395594f, 0.01198237482458353f, 0.005880322773009539f, 0.007801221217960119f, 0.005939939524978399f, 0.006790075916796923f, 0.005110860336571932f, 0.011327837593853474f, 0.0077136727049946785f, 0.008316677995026112f, 0.006970434915274382f, 0.008582448586821556f, 0.009050670079886913f, 0.004591398406773806f, 0.007924600504338741f, 0.007718538399785757f, 0.005264525301754475f, 0.008006973192095757f, 0.0060583301819860935f, 0.007903226651251316f, 0.007420995272696018f, 0.005626673810184002f, 0.005102730821818113f, 0.009713388048112392f, 0.0056159161031246185f, 0.008740415796637535f, 0.008610735647380352f, 0.0077232359908521175f, 0.005309021100401878f, 0.005153631791472435f, 0.010928131639957428f, 0.00804704800248146f, 0.007261202204972506f, 0.004969203379005194f, 0.003334265435114503f, 0.006353214383125305f, 0.0065500009804964066f, 0.006787261459976435f, 0.0046434709802269936f, 0.004574663937091827f, 0.004464668221771717f, 0.007324353791773319f, 0.010426627472043037f, 0.009176330640912056f, 0.008725825697183609f, 0.0052530704997479916f, 0.004855267703533173f, 0.006313823629170656f, 0.0038105007261037827f, 0.005210134666413069f, 0.007289757952094078f, 0.005784664303064346f, 0.0038815047591924667f, 0.007118597161024809f, 0.004324872512370348f, 0.00532550597563386f, 0.005351440515369177f, 0.005414088722318411f, 0.005983165930956602f, 0.007196696475148201f, 0.006070221308618784f, 0.010097429156303406f, 0.004562989342957735f, 0.006931842304766178f, 0.007898272015154362f, 0.00920042023062706f, 0.0036517479456961155f, 0.008421486243605614f, 0.006860394962131977f, 0.0067325918935239315f, 0.005321715492755175f, 0.005103223491460085f, 0.005680907983332872f, 0.006949415430426598f, 0.00614827498793602f, 0.00624059559777379f, 0.009704358875751495f, 0.006408162415027618f, 0.010421820916235447f, 0.005883234553039074f, 0.008701994083821774f, 0.007152785547077656f, 0.006574744358658791f, 0.006396498531103134f, 0.006836432032287121f, 0.004321336280554533f, 0.014816809445619583f, 0.009779642336070538f, 0.00823843665421009f, 0.0042719594202935696f, 0.004723351448774338f, 0.00535741588100791f, 0.00689075468108058f, 0.007145836483687162f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00015589396934956312f, 0.00013747724005952477f, 0.00011618073767749593f, 0.0001500931684859097f, 0.00012537860311567783f, 0.00010542618110775948f, 0.0001310850930167362f, 0.00010561114322626963f, 0.0001541723177069798f, 0.00012158460594946519f, 0.00015288607391994447f, 0.00012125160719733685f, 0.00013999482325743884f, 0.00010759048018371686f, 0.00016259972471743822f, 0.00011934108624700457f, 0.0001255109382327646f, 0.00018183870997745544f, 0.00015272843302227557f, 0.00010373882832936943f, 0.00011706908844644204f, 0.00015263802197296172f, 0.00010823350748978555f, 0.00012943333422299474f, 0.00013736724213231355f, 0.00013449399557430297f, 0.00018680348875932395f, 0.00011288461246294901f, 8.611355588072911e-05f, 0.00011758330947486684f, 0.00011161719157826155f, 0.00012911019439343363f, 0.00013571561430580914f, 0.0001306064223172143f, 0.00015352210903074592f, 0.00016290931671392173f, 0.00017782478244043887f, 0.00013432977721095085f, 0.00011440924572525546f, 0.00011042315600207075f, 0.00012036572297802195f, 0.00010344454494770616f, 0.0001093320461222902f, 9.914336260408163e-05f, 0.00010040299821412191f, 6.444945029215887e-05f, 0.00014345190720632672f, 0.000159170274855569f, 0.00011142620496684685f, 0.00015277454804163426f, 0.00019933583098463714f, 0.00012490953668020666f, 0.00015829320182092488f, 0.00011729947436833754f, 0.00012529631203506142f, 0.000103610975202173f, 0.00016603789117652923f, 8.952288771979511e-05f, 0.00011967192403972149f, 0.0001442394423065707f, 0.00014113068755250424f, 0.0001390654215356335f, 0.00015307829016819596f, 0.00011593426461331546f, 0.00012509663065429777f, 0.00016253255307674408f, 8.76552949193865e-05f, 0.00013957401097286493f, 0.0001440162886865437f, 0.0001098262655432336f, 0.00012571307888720185f, 0.00010326502524549142f, 0.00013617695367429405f, 0.00015858850383665413f, 0.0001009158295346424f, 0.00015547322982456535f, 0.000127644365420565f, 0.00017946251318790019f, 0.0001123088804888539f, 0.00012002002040389925f, 7.728870696155354e-05f, 0.00011669913510559127f, 0.00011944885045522824f, 0.0001546932471683249f, 0.00017311227566096932f, 7.485450623789802e-05f, 0.00011575276585062966f, 0.00014992814976722002f, 9.148120443569496e-05f, 0.00011329637345625088f, 0.00011844913387903944f, 0.00010206592560280114f, 0.00012278350186534226f, 0.0001466050453018397f, 0.00014534755609929562f, 0.00014587052282877266f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0023903895635157824f, 0.002107997890561819f, 0.0017814494203776121f, 0.0023014433681964874f, 0.001922484254464507f, 0.0016165451379492879f, 0.002009984338656068f, 0.0016193812480196357f, 0.0023639907594770193f, 0.0018643091898411512f, 0.0023442681413143873f, 0.0018592032138258219f, 0.002146600978448987f, 0.0016497313044965267f, 0.002493211766704917f, 0.0018299083458259702f, 0.0019245133735239506f, 0.002788211451843381f, 0.002341850893571973f, 0.0015906721819192171f, 0.0017950708279386163f, 0.0023404646199196577f, 0.001659591100178659f, 0.0019846572540700436f, 0.0021063112653791904f, 0.002062254585325718f, 0.002864338457584381f, 0.0017309085233137012f, 0.0013204163406044245f, 0.0018029556376859546f, 0.0017114746151492f, 0.0019797023851424456f, 0.0020809860434383154f, 0.0020026445854455233f, 0.002354020718485117f, 0.0024979589506983757f, 0.0027266640681773424f, 0.0020597365219146013f, 0.0017542863497510552f, 0.001693165861070156f, 0.0018456195248290896f, 0.0015861598076298833f, 0.0016764354659244418f, 0.0015202079666778445f, 0.001539522549137473f, 0.000988231273368001f, 0.002199609996750951f, 0.002440626500174403f, 0.0017085460713133216f, 0.0023425580002367496f, 0.0030565024353563786f, 0.0019152918830513954f, 0.002427177969366312f, 0.0017986034508794546f, 0.001921222428791225f, 0.0015887117478996515f, 0.002545930678024888f, 0.0013726931065320969f, 0.0018349812598899007f, 0.002211685525253415f, 0.002164017641916871f, 0.0021323501132428646f, 0.0023472155444324017f, 0.0017776701133698225f, 0.0019181605894118547f, 0.0024921817239373922f, 0.0013440564507618546f, 0.0021401485428214073f, 0.002208263846114278f, 0.0016840135212987661f, 0.0019276129314675927f, 0.0015834071673452854f, 0.0020880599040538073f, 0.0024317060597240925f, 0.0015473859384655952f, 0.0023839380592107773f, 0.0019572260789573193f, 0.002751776250079274f, 0.001722080516628921f, 0.0018403187859803438f, 0.0011851011076942086f, 0.0017893982585519552f, 0.0018315607449039817f, 0.002371978247538209f, 0.0026544053107500076f, 0.001147776492871344f, 0.0017748870886862278f, 0.002298912964761257f, 0.0014027208089828491f, 0.0017372221918776631f, 0.0018162316409870982f, 0.0015650208806619048f, 0.0018826924497261643f, 0.002247958444058895f, 0.0022286768071353436f, 0.0022366957273334265f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.290443267673254e-05f, 0.00011033558257622644f, 0.00011311871639918536f, 9.281738311983645e-05f, 9.535549907013774e-05f, 0.00010508432751521468f, 0.00011579073179746047f, 0.00012225814862176776f, 0.000108292319055181f, 0.0001225136948050931f, 9.232694719685242e-05f, 9.355435759061947e-05f, 9.977460285881534e-05f, 8.75365876709111e-05f, 0.00010126589040737599f, 0.00011334575538057834f, 0.00011233781697228551f, 7.007450767559931e-05f, 9.781050903256983e-05f, 9.777866216609254e-05f, 9.126991062657908e-05f, 0.00011652902321657166f, 0.0001201065315399319f, 9.263381798518822e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002874998841434717f, 0.003414419014006853f, 0.003500545397400856f, 0.002872304990887642f, 0.002950849011540413f, 0.0032519150990992785f, 0.0035832328721880913f, 0.0037833722308278084f, 0.0033511887304484844f, 0.003791280323639512f, 0.002857128158211708f, 0.0028951112180948257f, 0.0030876013915985823f, 0.0027088867500424385f, 0.003133750520646572f, 0.003507571294903755f, 0.0034763796720653772f, 0.0021685094106942415f, 0.0030268211849033833f, 0.0030258356127887964f, 0.0028244173154234886f, 0.0036060798447579145f, 0.003716788487508893f, 0.002866624388843775f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011973190703429282f, 0.0002600000298116356f, 0.00018099823500961065f, 0.00018977763829752803f, 0.00021489801292773336f, 0.00013368760119192302f, 0.0002099631674354896f, 0.0001796082651708275f, 0.00010781634045997635f, 0.00019758462440222502f, 0.0002259980683447793f, 0.0002545636671129614f, 0.00018455387908034027f, 0.00022725231247022748f, 0.00019666137814056128f, 0.00013422196207102388f, 0.00048188495566137135f, 0.00016856964793987572f, 0.00021658041805494577f, 9.875578689388931e-05f, 0.00013540474174078554f, 0.00013499190390575677f, 0.00018578408344183117f, 0.00013475885498337448f, 0.00014080350229050964f, 0.0002477678353898227f, 0.00015825610898900777f, 0.0001204569052788429f, 0.00015495502157136798f, 0.00021058309357613325f, 0.00022095235181041062f, 0.00011623690807027742f, 0.0001489635615143925f, 0.00023160767159424722f, 0.0001515145559096709f, 0.00015896171680651605f, 0.00020754014258272946f, 0.00022063405776862055f, 0.0001813364215195179f, 0.0002895016223192215f, 0.00016401370521634817f, 0.00030043305014260113f, 0.00018617897876538336f, 0.00018814489885699004f, 0.00020042594405822456f, 0.0001808521628845483f, 9.443883755011484e-05f, 0.00025542613002471626f, 0.00020812572620343417f, 0.00019194005290046334f, 0.000142146585858427f, 0.00022009566600900143f, 0.00028457926237024367f, 0.0002507385506760329f, 0.0001872936263680458f, 0.0001657847169553861f, 0.00016823339683469385f, 0.00014780749916099012f, 0.0002224389900220558f, 0.00015598602476529777f, 0.00017042002582456917f, 0.0001614323991816491f, 0.00015388154133688658f, 0.00025398717843927443f, 0.00018991292745340616f, 0.00024938458227552474f, 0.00017517436936032027f, 0.00013470201520249248f, 0.00018214739975519478f, 0.00019335751130711287f, 0.00026119229733012617f, 0.0001923010277096182f, 0.00016897209570743144f, 0.00019539357163012028f, 0.0002200494782300666f, 0.00026300785248167813f, 0.00022690808691550046f, 0.00026679158327169716f, 0.0002581088920123875f, 0.0001762806496117264f, 0.00018972315592691302f, 0.00029783209902234375f, 0.00025428575463593006f, 0.00016349962970707566f, 0.00026513979537412524f, 0.0003075468703173101f, 0.00015820417320355773f, 0.00012340256944298744f, 0.0001790166861610487f, 0.00014812330482527614f, 0.00018590553372632712f, 0.00017436275084037334f, 0.00026665840414352715f, 0.0001857354218373075f, 0.00020674440020229667f, 0.0002499389520380646f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004374577198177576f, 0.009499474428594112f, 0.006613030564039946f, 0.006933798547834158f, 0.007851607166230679f, 0.004884468391537666f, 0.0076713054440915585f, 0.0065622455440461636f, 0.003939224872738123f, 0.007219037972390652f, 0.008257163688540459f, 0.009300848469138145f, 0.006742940749973059f, 0.008302989415824413f, 0.007185305934399366f, 0.004903992172330618f, 0.017606358975172043f, 0.006158933974802494f, 0.00791307631880045f, 0.003608184400945902f, 0.004947206471115351f, 0.004932122770696878f, 0.006787888240069151f, 0.004923608154058456f, 0.005144457798451185f, 0.009052553214132786f, 0.005782113876193762f, 0.0044010658748447895f, 0.005661503877490759f, 0.007693955674767494f, 0.008072811178863049f, 0.004246882162988186f, 0.005442597437649965f, 0.008462118916213512f, 0.005535801872611046f, 0.00580789428204298f, 0.007582777179777622f, 0.008061181753873825f, 0.006625386420637369f, 0.01057735737413168f, 0.005992475897073746f, 0.010976752266287804f, 0.006802316289395094f, 0.006874144077301025f, 0.007322849705815315f, 0.006607693620026112f, 0.0034504584036767483f, 0.009332360699772835f, 0.007604171987622976f, 0.007012805435806513f, 0.005193529650568962f, 0.008041511289775372f, 0.010397511534392834f, 0.009161092340946198f, 0.006843041628599167f, 0.006057182792574167f, 0.006146648433059454f, 0.0054003591649234295f, 0.008127127774059772f, 0.005699173081666231f, 0.0062265400774776936f, 0.005898164585232735f, 0.005622283089905977f, 0.009279785677790642f, 0.00693874154239893f, 0.009111623279750347f, 0.0064002471044659615f, 0.004921531304717064f, 0.006655016914010048f, 0.007064593955874443f, 0.009543035179376602f, 0.007025993894785643f, 0.0061736381612718105f, 0.007138984743505716f, 0.008039823733270168f, 0.009609369561076164f, 0.008290412835776806f, 0.009747613221406937f, 0.009430378675460815f, 0.006440666504204273f, 0.006931807845830917f, 0.010881722904741764f, 0.009290695190429688f, 0.005973693914711475f, 0.009687263518571854f, 0.011236666701734066f, 0.005780216306447983f, 0.0045086899772286415f, 0.0065406314097344875f, 0.005411897320300341f, 0.006792325526475906f, 0.006370593328028917f, 0.00974274706095457f, 0.00678611034527421f, 0.0075537036173045635f, 0.00913187861442566f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00013577364734373987f, 0.0001370936370221898f, 0.0002566046023275703f, 0.0001250424247700721f, 0.00018331327009946108f, 0.00013043740182183683f, 0.00018690648721531034f, 0.00015114406414795667f, 0.00017296713485848159f, 0.00011698284652084112f, 0.0002171562664443627f, 0.00015140043979045004f, 0.00021155388094484806f, 0.00015342280676122755f, 0.00014511031622532755f, 0.00014448430738411844f, 0.00015379245451185852f, 0.0001618856767890975f, 0.0001500356156611815f, 0.00018803405691869557f, 0.00018723618995863944f, 0.00021297794592101127f, 0.00014641715097241104f, 0.00014745259250048548f, 0.00018158102466259152f, 0.0001742710155667737f, 0.00014816474867984653f, 0.00014641520101577044f, 0.0001635401276871562f, 0.0001320621813647449f, 0.0002007574075832963f, 0.00019922312640119344f, 0.00019515112217050046f, 0.00018838522373698652f, 0.00016353077080566436f, 0.00013542521628551185f, 0.00017500008107163012f, 0.00016497832257300615f, 0.00023454516485799104f, 6.772335473215207e-05f, 0.00015741701645310968f, 8.181276643881574e-05f, 0.0002900731924455613f, 0.00011806686234194785f, 0.00016532443987671286f, 0.00018900544091593474f, 0.00021316511265467852f, 0.00020908284932374954f, 0.00024142384063452482f, 0.000211344551644288f, 0.0001226594758918509f, 0.000148997365613468f, 0.00012007926125079393f, 0.00021564855705946684f, 0.0001654373190831393f, 0.0001480418723076582f, 0.0001461327774450183f, 0.0001927495759446174f, 0.00017518739332444966f, 0.0001726467307889834f, 0.0002694271388463676f, 0.00013338355347514153f, 0.0002011543547268957f, 0.00016168666479643434f, 0.0001557725336169824f, 0.0001662751892581582f, 0.00014747038949280977f, 0.00014555167581420392f, 0.00013883941574022174f, 0.00018077406275551766f, 0.00021077129349578172f, 0.00022983098460827023f, 0.00017160882998723537f, 0.00021158435265533626f, 0.00021728996944148093f, 0.00012833323853556067f, 0.0001781107857823372f, 0.0001969773875316605f, 8.740316116018221e-05f, 0.00014600454596802592f, 0.00020947067241650075f, 9.224610403180122e-05f, 9.990508988266811e-05f, 0.00018939095025416464f, 0.00020564405713230371f, 0.000152569220517762f, 0.0001494594180257991f, 0.0001370347454212606f, 0.00020633100939448923f, 0.0002074965013889596f, 0.00017951929476112127f, 0.00013826550275553018f, 0.00012963965127710253f, 0.00021480389114003628f, 0.00018132686091121286f, 0.0001795431599020958f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0025267747696489096f, 0.0025513400323688984f, 0.0047754631377756596f, 0.0023270645178854465f, 0.0034114965237677097f, 0.0024274662137031555f, 0.0034783671144396067f, 0.0028128211852163076f, 0.0032189530320465565f, 0.002177074085921049f, 0.004041321575641632f, 0.0028175923507660627f, 0.003937060013413429f, 0.002855229191482067f, 0.0027005320880562067f, 0.002688881941139698f, 0.0028621081728488207f, 0.0030127246864140034f, 0.002792192855849862f, 0.003499351441860199f, 0.003484502900391817f, 0.003963562194257975f, 0.0027248524129390717f, 0.002744122175499797f, 0.0033792590256780386f, 0.003243218408897519f, 0.002757375594228506f, 0.0027248160913586617f, 0.0030435144435614347f, 0.0024577034637331963f, 0.0037361355498433113f, 0.0037075821310281754f, 0.0036318013444542885f, 0.0035058867651969194f, 0.0030433402862399817f, 0.0025202904362231493f, 0.0032567863818258047f, 0.0030702794902026653f, 0.004364932421594858f, 0.0012603451032191515f, 0.0029295622371137142f, 0.001522551872767508f, 0.005398320034146309f, 0.0021972479298710823f, 0.0030767207499593496f, 0.0035174288786947727f, 0.0039670453406870365f, 0.0038910736329853535f, 0.004492945969104767f, 0.003933164291083813f, 0.002282717265188694f, 0.0027728707063943148f, 0.002234698971733451f, 0.004013262689113617f, 0.0030788215808570385f, 0.0027550887316465378f, 0.002719560172408819f, 0.0035871081054210663f, 0.0032602723222225904f, 0.003212990239262581f, 0.00501409312710166f, 0.0024822945706546307f, 0.0037435228005051613f, 0.0030090210493654013f, 0.002898958045989275f, 0.003094414481893182f, 0.0027444534935057163f, 0.002708745887503028f, 0.0025838292203843594f, 0.003364241449162364f, 0.003922495990991592f, 0.004277200438082218f, 0.003193674609065056f, 0.00393762718886137f, 0.004043809603899717f, 0.002388307126238942f, 0.003314677160233259f, 0.0036657885648310184f, 0.0016265902668237686f, 0.0027171738911420107f, 0.0038982911501079798f, 0.0017167184269055724f, 0.001859253621660173f, 0.003524603322148323f, 0.0038270768709480762f, 0.002839343622326851f, 0.0027814696077257395f, 0.002550243865698576f, 0.0038398613687604666f, 0.0038615514058619738f, 0.003340889932587743f, 0.0025731485802680254f, 0.0024126197677105665f, 0.00399754336103797f, 0.0033745290711522102f, 0.0033413339406251907f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(6.692438182653859e-05f, 6.524082709802315e-05f, 8.833830361254513e-05f, 9.299616067437455e-05f, 6.360734550980851e-05f, 9.31229442358017e-05f, 0.00010259148984914646f, 7.884865044616163e-05f, 8.272093691630289e-05f, 8.243555930675939e-05f, 8.026626164792106e-05f, 9.73121277638711e-05f, 0.00010326155461370945f, 8.087880269158632e-05f, 7.15981877874583e-05f, 6.969174137338996e-05f, 9.033169772010297e-05f, 8.916732622310519e-05f, 5.580939614446834e-05f, 0.00010521218064241111f, 6.325903814285994e-05f, 7.189600000856444e-05f, 0.00010336408013245091f, 7.580308738397434e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0018052096711471677f, 0.0017597978003323078f, 0.0023828260600566864f, 0.002508466597646475f, 0.0017157363472506404f, 0.002511886414140463f, 0.0027672897558659315f, 0.002126853447407484f, 0.002231304068118334f, 0.0022236062213778496f, 0.00216509192250669f, 0.002624884946271777f, 0.002785363933071494f, 0.0021816145163029432f, 0.0019312803633511066f, 0.001879856106825173f, 0.0024365957360714674f, 0.0024051880463957787f, 0.001505395513959229f, 0.00283797993324697f, 0.0017063412815332413f, 0.0019393134862184525f, 0.0027881294954568148f, 0.0020447028800845146f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011819724750239402f, 0.00020125083392485976f, 0.00013643504644278437f, 0.00011337344039930031f, 0.00012540214811451733f, 0.0002514407387934625f, 0.00013511892757378519f, 0.0003872292290907353f, 0.00022162694949656725f, 0.00025751846260391176f, 0.00015471878577955067f, 0.000510478625074029f, 0.0001805072242859751f, 0.00023347455135080963f, 0.00014585266762878746f, 0.00039509451016783714f, 0.0001784537307685241f, 0.00027452109497971833f, 0.0001294592657359317f, 0.00019908181275241077f, 0.0003154836595058441f, 0.00021572242258116603f, 0.00024241175560746342f, 0.00023987966415006667f, 0.00034844904439523816f, 0.00012745366257149726f, 0.00011328902473906055f, 0.0001222412975039333f, 0.00014885669224895537f, 0.00020330159168224782f, 0.00015580088074784726f, 0.00023665423213969916f, 0.00017415301408618689f, 0.00020608492195606232f, 0.0001462446671212092f, 0.0001666700409259647f, 0.00015467546472791582f, 0.0002166191698051989f, 0.00033046765020117164f, 0.0003509136731736362f, 0.00016529791173525155f, 0.00011500049731694162f, 0.00024389127793256193f, 9.965101344278082e-05f, 0.0003401123103685677f, 0.0002855084021575749f, 0.00021152012050151825f, 0.00018140840984415263f, 0.00021998074953444302f, 0.00023564958246424794f, 0.0001992317265830934f, 0.0003035382542293519f, 0.000263246736722067f, 0.0001774187694536522f, 0.0001993833138840273f, 0.0003452734381426126f, 0.00019904352666344494f, 0.0003054701955989003f, 0.00028233538614585996f, 0.0001975487102754414f, 0.00017151591600850224f, 0.00016841982142068446f, 0.00019310825155116618f, 0.00016229022003244609f, 0.0004359479062259197f, 0.00019332724332343787f, 0.0003651181177701801f, 0.0001329137448919937f, 0.00021625106455758214f, 0.000170378087204881f, 0.00020081919501535594f, 0.00037621072260662913f, 0.00018376257503405213f, 0.00022976455511525273f, 0.0001778950245352462f, 0.00012193228030810133f, 0.00017223563918378204f, 0.0002631450188346207f, 0.00039073015796020627f, 0.00020549690816551447f, 0.00019908638205379248f, 0.0002785425167530775f, 0.00021032692166045308f, 0.00024131608370225877f, 0.00017488375306129456f, 0.00011840789375128224f, 0.0003430844808463007f, 0.00025800871662795544f, 0.0001717247359920293f, 0.00022201292449608445f, 0.0001774974662112072f, 0.0002900049730669707f, 0.00021567739895544946f, 0.00014677528815809637f, 0.00014871094026602805f, 0.00011467545118648559f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004479049239307642f, 0.007626339793205261f, 0.005170165095478296f, 0.004296252503991127f, 0.00475207669660449f, 0.009528270922601223f, 0.005120290908962488f, 0.014673935249447823f, 0.00839848630130291f, 0.009758584201335907f, 0.005863022059202194f, 0.019344434142112732f, 0.0068402667529881f, 0.008847448043525219f, 0.005527042783796787f, 0.014971987344324589f, 0.006762450560927391f, 0.010402894578874111f, 0.004905819892883301f, 0.007544145453721285f, 0.011955158784985542f, 0.008174736052751541f, 0.009186120703816414f, 0.009090167470276356f, 0.013204371556639671f, 0.00482981838285923f, 0.004293053410947323f, 0.004632297437638044f, 0.005640879739075899f, 0.007704052608460188f, 0.005904027260839939f, 0.00896794069558382f, 0.006599476095288992f, 0.0078095258213579655f, 0.0055418978445231915f, 0.006315911188721657f, 0.005861380137503147f, 0.00820871815085411f, 0.01252297218888998f, 0.01329776830971241f, 0.0062639145180583f, 0.004357909318059683f, 0.009242186322808266f, 0.0037762450519949198f, 0.012888453900814056f, 0.010819255374372005f, 0.00801549106836319f, 0.006874416954815388f, 0.008336104452610016f, 0.008929870091378689f, 0.007549826055765152f, 0.011502491310238838f, 0.009975655935704708f, 0.006723230704665184f, 0.0075555709190666676f, 0.013084032572805882f, 0.007542694453150034f, 0.011575701646506786f, 0.01069901417940855f, 0.007486049085855484f, 0.0064995442517101765f, 0.006382218562066555f, 0.007317779120057821f, 0.006149939261376858f, 0.016520114615559578f, 0.0073260776698589325f, 0.01383604109287262f, 0.0050367265939712524f, 0.00819476880133152f, 0.006456426344811916f, 0.00760998297482729f, 0.014256391674280167f, 0.00696362741291523f, 0.00870685838162899f, 0.00674127833917737f, 0.004620586987584829f, 0.0065268175676465034f, 0.009971801191568375f, 0.014806601218879223f, 0.007787243463099003f, 0.007544318679720163f, 0.010555285029113293f, 0.007970275357365608f, 0.009144600480794907f, 0.006627167109400034f, 0.004487031605094671f, 0.01300108339637518f, 0.009777163155376911f, 0.006507457233965397f, 0.008413112722337246f, 0.00672621326521039f, 0.010989651083946228f, 0.008173029869794846f, 0.005562005564570427f, 0.005635356530547142f, 0.0043455916456878185f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002022827393375337f, 0.00021021424618083984f, 0.0002159159630537033f, 0.0001781055616447702f, 0.00024829269386827946f, 0.00016787632193882018f, 0.00023248730576597154f, 7.784552872180939e-05f, 0.00014315717271529138f, 0.00011875871859956533f, 0.00014631368685513735f, 7.280133286258206e-05f, 0.0001646882010390982f, 0.00017473180196247995f, 0.00020384261733852327f, 0.00010370194650022313f, 0.0001554745394969359f, 0.0002542764414101839f, 0.00019985598919447511f, 0.0001696132676443085f, 0.00021409230248536915f, 0.00023306810180656612f, 0.00019028279348276556f, 0.00022501108469441533f, 0.00010503041266929358f, 0.00018349618767388165f, 0.00018662092043086886f, 0.0002158835413865745f, 0.00013145602133590728f, 0.00019727837934624404f, 0.00017389720596838742f, 0.00025342023582197726f, 0.00018288135470356792f, 0.00020109140314161777f, 0.0002460055111441761f, 0.00016627743025310338f, 0.00019499020709190518f, 0.00021631887648254633f, 0.00012147354573244229f, 0.00016812217654660344f, 0.00017733800632413477f, 0.00024631081032566726f, 0.0001432702410966158f, 0.00021397483942564577f, 0.00015318821533583105f, 0.00010767758794827387f, 0.00011747911776183173f, 0.0001959178625838831f, 0.0001444969093427062f, 0.00012701735249720514f, 0.00022537131735589355f, 0.00012606104428414255f, 0.00015943364996928722f, 0.00018284277757629752f, 0.00022271300258580595f, 0.00019934328156523407f, 0.00014026583812665194f, 0.00011891190661117435f, 0.00012557623267639428f, 0.00022101489594206214f, 0.00021703392849303782f, 0.00014480498794000596f, 0.0001342982577625662f, 0.00011438272485975176f, 0.00011149074998684227f, 0.0001424133952241391f, 0.00014838531205896288f, 9.374818182550371e-05f, 0.0001795006828615442f, 0.0001835819275584072f, 0.0001677317195571959f, 0.00010942776862066239f, 0.00012730630987789482f, 0.00015123332559596747f, 0.00013582587416749448f, 0.00023839548521209508f, 0.00020493744523264468f, 0.0001092470483854413f, 9.596604650141671e-05f, 0.0002006087452173233f, 0.00013255031080916524f, 0.00015225283277686685f, 8.325636736117303e-05f, 0.00016887417586985976f, 0.0002442265104036778f, 0.000280026433756575f, 0.0002636139979586005f, 0.00020558568940032274f, 0.00012174266157671809f, 0.00011438346700742841f, 0.00025974991149269044f, 0.0001090718069463037f, 0.00010923871741397306f, 0.00017700815806165338f, 0.0002046229928964749f, 0.00021336364443413913f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004709022119641304f, 0.004893662873655558f, 0.005026395432651043f, 0.004146191757172346f, 0.005780106410384178f, 0.00390806095674634f, 0.0054121664725244045f, 0.0018121976172551513f, 0.003332613967359066f, 0.00276463245972991f, 0.0034060957841575146f, 0.0016947718104347587f, 0.003833843395113945f, 0.004067652393132448f, 0.004745334852486849f, 0.0024141196627169847f, 0.0036193549167364836f, 0.005919404327869415f, 0.004652528557926416f, 0.00394849618896842f, 0.004983941558748484f, 0.005425686948001385f, 0.004429670516401529f, 0.005238124169409275f, 0.0024450456257909536f, 0.0042716823518276215f, 0.004344424232840538f, 0.005025640595704317f, 0.0030602181795984507f, 0.004592523444443941f, 0.004048223607242107f, 0.005899472162127495f, 0.0042573693208396435f, 0.00468128826469183f, 0.005726861767470837f, 0.0038708397187292576f, 0.0045392559841275215f, 0.005035774782299995f, 0.0028278320096433163f, 0.003913784399628639f, 0.0041283234022557735f, 0.005733969621360302f, 0.003335246117785573f, 0.004981207195669413f, 0.00356613053008914f, 0.0025066703092306852f, 0.002734844107180834f, 0.004560851491987705f, 0.003363802330568433f, 0.0029568886384367943f, 0.0052465102635324f, 0.0029346260707825422f, 0.0037115204613655806f, 0.004256471060216427f, 0.005184626206755638f, 0.004640593193471432f, 0.0032653051894158125f, 0.0027681984938681126f, 0.002923340070992708f, 0.0051450952887535095f, 0.005052420776337385f, 0.0033709739800542593f, 0.00312638352625072f, 0.0026627618353813887f, 0.002595438389107585f, 0.0033152992837131023f, 0.0034543219953775406f, 0.0021824019495397806f, 0.004178669303655624f, 0.004273678176105022f, 0.003904694691300392f, 0.002547413343563676f, 0.0029636153485625982f, 0.003520621918141842f, 0.0031619456131011248f, 0.005549705121666193f, 0.004770821891725063f, 0.002543206326663494f, 0.0022340326104313135f, 0.004670052323490381f, 0.003085692413151264f, 0.003544355509802699f, 0.001938158762641251f, 0.003931290470063686f, 0.0056854477152228355f, 0.006518849171698093f, 0.0061367773450911045f, 0.004785912577062845f, 0.002834096783772111f, 0.002662779064849019f, 0.006046823691576719f, 0.0025391269009560347f, 0.0025430123787373304f, 0.004120644647628069f, 0.004763501696288586f, 0.004966978915035725f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001771563256625086f, 0.00020493743068072945f, 0.0003032090316992253f, 0.00028449136880226433f, 0.0002281908964505419f, 0.0001625696022529155f, 0.00022569438442587852f, 0.0002171179949073121f, 0.00020759980543516576f, 0.00019511832215357572f, 0.00017739755276124924f, 0.0001912601146614179f, 0.000193118627066724f, 0.0001876269088825211f, 0.00024190951080527157f, 0.00022574140166398138f, 0.00017321355699095875f, 0.00018891127547249198f, 0.00021348595328163356f, 0.00015021090803202242f, 0.00020466091518756002f, 0.00018365427968092263f, 0.0002158987772418186f, 0.00023703846090938896f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0014642541063949466f, 0.0016938738990575075f, 0.002506120363250375f, 0.0023514130152761936f, 0.0018860712880268693f, 0.0013436902081593871f, 0.0018654369050636888f, 0.0017945502186194062f, 0.0017158793052658439f, 0.0016127158887684345f, 0.0014662479516118765f, 0.001580826472491026f, 0.0015961877070367336f, 0.0015507969073951244f, 0.0019994601607322693f, 0.001865825499407947f, 0.0014316658489406109f, 0.001561412587761879f, 0.0017645301995798945f, 0.0012415415840223432f, 0.0016915884334594011f, 0.0015179618494585156f, 0.0017844729591161013f, 0.001959199318662286f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002572986122686416f, 0.0002752307045739144f, 0.00023712633992545307f, 0.0008689086535014212f, 0.000648672052193433f, 0.00023848940327297896f, 0.00016865141515154392f, 0.00039791446761228144f, 0.0004178398521617055f, 0.0004896632162854075f, 0.0003039397415705025f, 0.00016965983377303928f, 0.00032410002313554287f, 0.00038829728146083653f, 0.0004509657446760684f, 0.00024727536947466433f, 0.0002720426127780229f, 0.00022165112022776157f, 0.000355123687768355f, 0.00029271651874296367f, 0.00048093259101733565f, 0.00032207483309321105f, 0.0005960563430562615f, 0.00019122571393381804f, 0.0005946359597146511f, 0.00041956285713240504f, 0.00040576301398687065f, 0.0002546736504882574f, 0.00036449049366638064f, 0.00023995141964405775f, 0.0002862408000510186f, 0.00014227611245587468f, 0.0002791508741211146f, 0.0003232314484193921f, 0.000255063729127869f, 0.0006992983398959041f, 0.0005204988992772996f, 0.00045646747457794845f, 0.000381621066480875f, 0.0005246084765531123f, 0.00021171360276639462f, 0.0003690385783556849f, 0.0002913818752858788f, 0.0003693179751280695f, 0.0002512402134016156f, 0.00027802010299637914f, 0.0002359494537813589f, 0.00024341062817256898f, 0.0003114092396572232f, 0.0003438081475906074f, 0.00024310968001373112f, 0.0002332982257939875f, 0.0004019708721898496f, 0.00022769105271436274f, 0.00017015778576023877f, 0.000282600405625999f, 0.0005515679367817938f, 0.00039696122985333204f, 0.0002445409190841019f, 0.0002355271572014317f, 0.0009484913316555321f, 0.00040653502219356596f, 0.0006274027400650084f, 0.00043728729360736907f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006086518056690693f, 0.0065107098780572414f, 0.005609333515167236f, 0.0205544363707304f, 0.01534463744610548f, 0.005641577299684286f, 0.003989527467638254f, 0.009412851184606552f, 0.009884195402264595f, 0.011583210900425911f, 0.007189835421741009f, 0.004013381898403168f, 0.007666736375540495f, 0.009185352362692356f, 0.010667803697288036f, 0.005849413573741913f, 0.006435294169932604f, 0.005243259947746992f, 0.00840061530470848f, 0.0069243451580405235f, 0.011376683600246906f, 0.007618829142302275f, 0.014099989086389542f, 0.004523532930761576f, 0.014066389761865139f, 0.009924953803420067f, 0.009598512202501297f, 0.0060244230553507805f, 0.008622191846370697f, 0.005676161963492632f, 0.006771158427000046f, 0.0033656074665486813f, 0.0066034430637955666f, 0.007646189536899328f, 0.006033650599420071f, 0.0165422260761261f, 0.01231264229863882f, 0.010797949507832527f, 0.009027423337101936f, 0.012409856542944908f, 0.005008183419704437f, 0.008729778230190277f, 0.006892773322761059f, 0.008736387826502323f, 0.005943203344941139f, 0.006576694082468748f, 0.005581493489444256f, 0.005757991224527359f, 0.007366530131548643f, 0.008132941089570522f, 0.005750872194766998f, 0.005518777761608362f, 0.009508807212114334f, 0.005386137403547764f, 0.004025161266326904f, 0.006685043219476938f, 0.013047594577074051f, 0.009390302002429962f, 0.005784729029983282f, 0.00557150412350893f, 0.022437002509832382f, 0.009616774506866932f, 0.014841502532362938f, 0.010344233363866806f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005619705771096051f, 0.0002682883059605956f, 0.0002859713858924806f, 0.00030036730458959937f, 0.00028225750429555774f, 0.0004751060623675585f, 0.0003073819971177727f, 0.00015649237320758402f, 0.00023153808433562517f, 0.0002795252948999405f, 0.00017252172983717173f, 0.0004606491420418024f, 0.00035202217986807227f, 0.00021448168263304979f, 0.0005306316306814551f, 0.000359333265805617f, 0.0002510844205971807f, 0.0003613278968259692f, 0.0003284518315922469f, 0.00026988537865690887f, 0.0003537498414516449f, 0.0002601734595373273f, 0.00035975518403574824f, 0.00036800463567487895f, 0.000336911209160462f, 0.0002674644347280264f, 0.00030290140421129763f, 0.0002548564807511866f, 0.0003477101563476026f, 0.00038162292912602425f, 0.00032150125480256975f, 0.00031271512852981687f, 0.0002603078610263765f, 0.00035916626802645624f, 0.00022608775179833174f, 0.0001494533644290641f, 0.0002763180818874389f, 0.00016181096725631505f, 0.0002748037513811141f, 0.0002758181362878531f, 0.0003506199282128364f, 0.00018891434592660517f, 0.0004213679349049926f, 0.0005062224809080362f, 0.0002505129377823323f, 0.0003436699917074293f, 0.00034633788163773715f, 0.0002846204151865095f, 0.0003446011687628925f, 0.0002469804312568158f, 0.00029916519997641444f, 0.0004856271843891591f, 0.0004633182834368199f, 0.00027173946727998555f, 0.0003853582020383328f, 0.0005185789195820689f, 0.000183670170372352f, 0.0002950149937532842f, 0.0003983870556112379f, 0.00043534961878322065f, 0.0003522640618029982f, 0.0002845406997948885f, 0.0003346708544995636f, 0.00019465663353912532f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004616959486156702f, 0.002204165793955326f, 0.002349443966522813f, 0.0024677158799022436f, 0.0023189319763332605f, 0.0039033102802932262f, 0.0025253461208194494f, 0.001285688253119588f, 0.001902238349430263f, 0.0022964850068092346f, 0.0014173799427226186f, 0.0037845370825380087f, 0.002892094664275646f, 0.0017621087608858943f, 0.004359489306807518f, 0.002952160080894828f, 0.002062824321910739f, 0.002968547400087118f, 0.002698448719456792f, 0.0022172867320477962f, 0.002906288718804717f, 0.0021374968346208334f, 0.0029556264635175467f, 0.0030234011355787516f, 0.0027679482009261847f, 0.0021973969414830208f, 0.0024885351303964853f, 0.0020938143134117126f, 0.0028566685505211353f, 0.003135284408926964f, 0.002641345141455531f, 0.002569161355495453f, 0.0021386011503636837f, 0.0029507882427424192f, 0.001857460243627429f, 0.0012278581270948052f, 0.002270135562866926f, 0.001329384045675397f, 0.0022576942574232817f, 0.0022660281974822283f, 0.0028805744368582964f, 0.0015520561719313264f, 0.003461815882474184f, 0.00415895227342844f, 0.0020581292919814587f, 0.002823475981131196f, 0.0028453944250941277f, 0.0023383446969091892f, 0.002831126330420375f, 0.002029107417911291f, 0.0024578396696597338f, 0.003989748191088438f, 0.003806465771049261f, 0.0022325192112475634f, 0.003165972186252475f, 0.0042604682967066765f, 0.0015089717926457524f, 0.0024237430188804865f, 0.00327301281504333f, 0.00357668474316597f, 0.0028940821066498756f, 0.002337689744308591f, 0.0027495422400534153f, 0.0015992328990250826f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00026328497915528715f, 0.00033764197723940015f, 0.0002845512644853443f, 0.0004681423888541758f, 0.00027943155146203935f, 0.0002700787445064634f, 0.0002557287225499749f, 0.0004685539461206645f, 0.00035373345599509776f, 0.0003052486281376332f, 0.00028636775095947087f, 0.00024467729963362217f, 0.00031385492184199393f, 0.0003961608454119414f, 0.00030843180138617754f, 0.0005259179160930216f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004085210617631674f, 0.005238956306129694f, 0.00441518472507596f, 0.007263840641826391f, 0.004335745703428984f, 0.004190624691545963f, 0.003967965487390757f, 0.0072702267207205296f, 0.005488636903464794f, 0.004736331291496754f, 0.004443369805812836f, 0.003796488046646118f, 0.004869868978857994f, 0.006146952975541353f, 0.004785722587257624f, 0.008160303346812725f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0014621192822232842f, 0.000319182057864964f, 0.00031816301634535193f, 0.0014253449626266956f, 0.00116101058665663f, 0.00021699669014196843f, 0.00025372777599841356f, 0.00046658958308398724f, 0.00026744636124931276f, 0.0007418111781589687f, 0.0009840477723628283f, 0.0007447862881235778f, 0.0005136356339789927f, 0.0002959116536658257f, 0.00019570176664274186f, 0.0004962824168615043f, 0.00041380029870197177f, 0.0003451997763477266f, 0.0005489525501616299f, 0.0005439526285044849f, 0.0008654423290863633f, 0.0004862862697336823f, 0.0007890586857683957f, 0.0004534949257504195f, 0.0007016700692474842f, 0.0005783510277979076f, 0.0009930942906066775f, 0.0003630336432252079f, 0.0011785031529143453f, 0.0006810463964939117f, 0.0005873780464753509f, 0.0006294750492088497f, 0.0003485269262455404f, 0.000982517609372735f, 0.0004215843800920993f, 0.000395263428799808f, 0.0005090617341920733f, 0.00029640141292475164f, 0.0005157616105861962f, 0.0007704452145844698f, 0.0003947830991819501f, 0.0009959361050277948f, 0.0006211977452039719f, 0.00022104753588791937f, 0.00026382680516690016f, 0.00029870952130295336f, 0.00043158652260899544f, 0.001118335290811956f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.033659256994724274f, 0.007347848732024431f, 0.007324389647692442f, 0.032812681049108505f, 0.026727473363280296f, 0.004995452705770731f, 0.00584103399887681f, 0.010741298086941242f, 0.006156847812235355f, 0.017077138647437096f, 0.02265363559126854f, 0.017145628109574318f, 0.01182433869689703f, 0.0068121436052024364f, 0.004505224991589785f, 0.011424853466451168f, 0.009526043199002743f, 0.007946799509227276f, 0.012637365609407425f, 0.012522263452410698f, 0.019923236221075058f, 0.01119473297148943f, 0.01816481724381447f, 0.010439847595989704f, 0.016153056174516678f, 0.013314143754541874f, 0.022861896082758904f, 0.008357350714504719f, 0.027130167931318283f, 0.01567828096449375f, 0.013521953485906124f, 0.014491063542664051f, 0.008023393340408802f, 0.022618411108851433f, 0.009705238975584507f, 0.009099308401346207f, 0.011719044297933578f, 0.006823418661952019f, 0.011873280629515648f, 0.017736319452524185f, 0.009088250808417797f, 0.022927315905690193f, 0.01430051214993f, 0.005088706500828266f, 0.006073522847145796f, 0.006876552943140268f, 0.009935497306287289f, 0.025745052844285965f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002606708148960024f, 0.0006669667782261968f, 0.0002928980684373528f, 0.0002063051360892132f, 0.00033851625630632043f, 0.0006641439395025373f, 0.000345726526575163f, 0.0007078006747178733f, 0.0006030559889040887f, 0.0002459656971041113f, 0.00020115217193961143f, 0.0010403933702036738f, 0.0004977575154043734f, 0.0008754237205721438f, 0.0007052008295431733f, 0.00034212294849567115f, 0.00044440318015404046f, 0.00034631331800483167f, 0.0004264950111974031f, 0.0005856840871274471f, 0.0003965563955716789f, 0.00033756266930140555f, 0.00028354270034469664f, 0.0005361378425732255f, 0.0005821527447551489f, 0.0002892320917453617f, 0.0005124341696500778f, 0.000373431685147807f, 0.00026583013823255897f, 0.00024193177523557097f, 0.0003918676229659468f, 0.0006338486564345658f, 0.0003423768503125757f, 0.0004976607742719352f, 0.0004068033304065466f, 0.0004979536170139909f, 0.0005179933505132794f, 0.0008036720100790262f, 0.00039984009345062077f, 0.0005145395989529788f, 0.000387105654226616f, 0.00024045498867053539f, 0.0005456162616610527f, 0.0006779975956305861f, 0.0005835253978148103f, 0.0006952788098715246f, 0.00067017792025581f, 0.0002684173232410103f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002141583012416959f, 0.005479572806507349f, 0.0024063510354608297f, 0.001694933045655489f, 0.0027811345644295216f, 0.005456381011754274f, 0.0028403718024492264f, 0.005815050099045038f, 0.004954503383487463f, 0.0020207706838846207f, 0.001652598031796515f, 0.008547518402338028f, 0.004089406691491604f, 0.007192184217274189f, 0.0057936906814575195f, 0.002810765989124775f, 0.0036510657519102097f, 0.0028451927937567234f, 0.00350393820554018f, 0.004811781924217939f, 0.003257972886785865f, 0.002773300278931856f, 0.00232949061319232f, 0.004404726438224316f, 0.004782769363373518f, 0.002376232761889696f, 0.00420998502522707f, 0.003067987971007824f, 0.002183970296755433f, 0.001987629337236285f, 0.0032194515224546194f, 0.005207485519349575f, 0.00281285191886127f, 0.004088612273335457f, 0.0033421581611037254f, 0.004091017879545689f, 0.0042556575499475f, 0.006602696608752012f, 0.0032849505078047514f, 0.0042272829450666904f, 0.003180328756570816f, 0.001975496532395482f, 0.004482598043978214f, 0.005570197943598032f, 0.004794046748429537f, 0.0057121748104691505f, 0.005505954381078482f, 0.0022052256390452385f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00019828928634524345f, 0.00033333624014630914f, 0.000308690476231277f, 0.00037600594805553555f, 0.0001972139289136976f, 0.00034648782457225025f, 0.00023324592621065676f, 0.0002310279232915491f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0012240071082487702f, 0.002057629870250821f, 0.0019054955337196589f, 0.0023210227955132723f, 0.0012173691065981984f, 0.0021388123277574778f, 0.0014397887280210853f, 0.0014260973548516631f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 4,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000630368769634515f, 0.0011225645430386066f, 0.0008031547768041492f, 0.0008758376934565604f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 4,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0066169085912406445f, 0.01178343128412962f, 0.008430623449385166f, 0.00919356755912304f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0010713734664022923f, 0.0013077141484245658f, 0.003615345573052764f, 0.0003065546043217182f, 0.0007463032961823046f, 0.0008311430574394763f, 0.0004102798120584339f, 0.00029580245609395206f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007123698480427265f, 0.008695158176124096f, 0.0240388922393322f, 0.0020383205264806747f, 0.004962265491485596f, 0.005526375956833363f, 0.0027280026115477085f, 0.0019668282475322485f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002932770876213908f, 0.0003669751458801329f, 0.00028402061434462667f, 0.001196481753140688f, 0.0005499411490745842f, 0.00030312917078845203f, 0.0010178997181355953f, 0.0008647586219012737f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002778134308755398f, 0.003476256038993597f, 0.0026904502883553505f, 0.011333947069942951f, 0.005209443159401417f, 0.0028714605141431093f, 0.009642288088798523f, 0.008191623724997044f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #50 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002815812185872346f, 0.00027342617977410555f, 6.476511771325022e-05f, 0.00020328353275544941f, 8.11338031780906e-05f, 0.0003272874455433339f, 7.712531078141183e-05f, 0.0003045308112632483f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #51 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07180320471525192f, 0.06972367316484451f, 0.016515104100108147f, 0.05183729901909828f, 0.020689118653535843f, 0.0834582969546318f, 0.01966695301234722f, 0.0776553526520729f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conversion_0_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10556620359420776f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.15039567649364471f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09526635706424713f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #56 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16200010478496552f),
    AI_PACK_INTQ_ZP(18)))

/* Int quant #57 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12171875685453415f),
    AI_PACK_INTQ_ZP(-11)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04343884438276291f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06444832682609558f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #60 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12171875685453415f),
    AI_PACK_INTQ_ZP(-11)))

/* Int quant #61 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_12_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12171875685453415f),
    AI_PACK_INTQ_ZP(-11)))

/* Int quant #62 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04227353259921074f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1209874153137207f),
    AI_PACK_INTQ_ZP(-32)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04295642301440239f),
    AI_PACK_INTQ_ZP(5)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02638891525566578f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.037072911858558655f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.025713913142681122f),
    AI_PACK_INTQ_ZP(-4)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_20_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05373397469520569f),
    AI_PACK_INTQ_ZP(8)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.027369938790798187f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03231459856033325f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.046910472214221954f),
    AI_PACK_INTQ_ZP(-2)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_24_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06521697342395782f),
    AI_PACK_INTQ_ZP(7)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02088555321097374f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.030263522639870644f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06112173944711685f),
    AI_PACK_INTQ_ZP(7)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_28_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1209874153137207f),
    AI_PACK_INTQ_ZP(-32)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_29_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1209874153137207f),
    AI_PACK_INTQ_ZP(-32)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02288578636944294f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #79 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_32_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04190770909190178f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #80 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0490342453122139f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #81 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03777362406253815f),
    AI_PACK_INTQ_ZP(8)))

/* Int quant #82 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_35_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.19731007516384125f),
    AI_PACK_INTQ_ZP(0)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1374, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1374, 1374),
  1, &conv2d_35_scratch0_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2816, 2816),
  1, &conv2d_34_scratch0_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1152, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1152, 1152),
  1, &conv2d_33_scratch0_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4737, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4737, 4737),
  1, &conv2d_32_scratch0_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1632, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1632, 1632),
  1, &conv2d_30_scratch0_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 624, 1, 1), AI_STRIDE_INIT(4, 1, 1, 624, 624),
  1, &conv2d_27_scratch0_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_26_scratch0_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1056, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1056, 1056),
  1, &conv2d_25_scratch0_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 624, 1, 1), AI_STRIDE_INIT(4, 1, 1, 624, 624),
  1, &conv2d_23_scratch0_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_22_scratch0_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1056, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1056, 1056),
  1, &conv2d_21_scratch0_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 624, 1, 1), AI_STRIDE_INIT(4, 1, 1, 624, 624),
  1, &conv2d_19_scratch0_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_18_scratch0_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1056, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1056, 1056),
  1, &conv2d_17_scratch0_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 496, 1, 1), AI_STRIDE_INIT(4, 1, 1, 496, 496),
  1, &conv2d_16_scratch0_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &conv2d_15_scratch1_array, &conv2d_15_scratch1_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2369, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2369, 2369),
  1, &conv2d_15_scratch0_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 736, 1, 1), AI_STRIDE_INIT(4, 1, 1, 736, 736),
  1, &conv2d_13_scratch0_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 352, 1, 1), AI_STRIDE_INIT(4, 1, 1, 352, 352),
  1, &conv2d_11_scratch0_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1777, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1777, 1777),
  1, &conv2d_10_scratch0_array, NULL)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_9_scratch0_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 20, 20), AI_STRIDE_INIT(4, 1, 1, 8, 160),
  1, &conv2d_8_scratch1_array, &conv2d_8_scratch1_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 832, 1, 1), AI_STRIDE_INIT(4, 1, 1, 832, 832),
  1, &conv2d_8_scratch0_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 72, 1, 1), AI_STRIDE_INIT(4, 1, 1, 72, 72),
  1, &conv2d_6_scratch0_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 297, 1, 1), AI_STRIDE_INIT(4, 1, 1, 297, 297),
  1, &conv2d_5_scratch0_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 112, 1, 1), AI_STRIDE_INIT(4, 1, 1, 112, 112),
  1, &conv2d_3_scratch0_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 292, 1, 1), AI_STRIDE_INIT(4, 1, 1, 292, 292),
  1, &conv2d_2_scratch0_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 35, 1, 1), AI_STRIDE_INIT(4, 4, 4, 140, 140),
  1, &conv2d_35_bias_array, &conv2d_35_bias_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 256, 1, 1, 35), AI_STRIDE_INIT(4, 1, 256, 256, 256),
  1, &conv2d_35_weights_array, &conv2d_35_weights_intq)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv2d_34_bias_array, &conv2d_34_bias_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 1, 1, 256), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &conv2d_34_weights_array, &conv2d_34_weights_intq)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_33_bias_array, &conv2d_33_bias_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 64), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_33_weights_array, &conv2d_33_weights_intq)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_32_bias_array, &conv2d_32_bias_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_32_weights_array, &conv2d_32_weights_intq)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_30_bias_array, &conv2d_30_bias_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 88, 1, 1, 128), AI_STRIDE_INIT(4, 1, 88, 88, 88),
  1, &conv2d_30_weights_array, &conv2d_30_weights_intq)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_27_bias_array, &conv2d_27_bias_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 24), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &conv2d_27_weights_array, &conv2d_27_weights_intq)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_26_bias_array, &conv2d_26_bias_intq)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 288, 864),
  1, &conv2d_26_weights_array, &conv2d_26_weights_intq)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_25_bias_array, &conv2d_25_bias_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 96), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_25_weights_array, &conv2d_25_weights_intq)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_23_bias_array, &conv2d_23_bias_intq)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 24), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &conv2d_23_weights_array, &conv2d_23_weights_intq)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_22_bias_array, &conv2d_22_bias_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 288, 864),
  1, &conv2d_22_weights_array, &conv2d_22_weights_intq)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_21_bias_array, &conv2d_21_bias_intq)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 96), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_21_weights_array, &conv2d_21_weights_intq)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_19_bias_array, &conv2d_19_bias_intq)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 24), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &conv2d_19_weights_array, &conv2d_19_weights_intq)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_18_bias_array, &conv2d_18_bias_intq)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 288, 864),
  1, &conv2d_18_weights_array, &conv2d_18_weights_intq)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_17_bias_array, &conv2d_17_bias_intq)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 96), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_17_weights_array, &conv2d_17_weights_intq)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_16_bias_array, &conv2d_16_bias_intq)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 1, 1, 24), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &conv2d_16_weights_array, &conv2d_16_weights_intq)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_15_bias_array, &conv2d_15_bias_intq)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 3, 3, 1), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_15_weights_array, &conv2d_15_weights_intq)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_13_bias_array, &conv2d_13_bias_intq)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 64), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_13_weights_array, &conv2d_13_weights_intq)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_11_bias_array, &conv2d_11_bias_intq)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 48, 1, 1, 16), AI_STRIDE_INIT(4, 1, 48, 48, 48),
  1, &conv2d_11_weights_array, &conv2d_11_weights_intq)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_10_bias_array, &conv2d_10_bias_intq)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 48, 3, 3, 1), AI_STRIDE_INIT(4, 1, 48, 144, 432),
  1, &conv2d_10_weights_array, &conv2d_10_weights_intq)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_9_bias_array, &conv2d_9_bias_intq)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &conv2d_9_weights_array, &conv2d_9_weights_intq)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_8_bias_array, &conv2d_8_bias_intq)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 4, 3, 3, 8), AI_STRIDE_INIT(4, 1, 4, 12, 36),
  1, &conv2d_8_weights_array, &conv2d_8_weights_intq)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 1, 1), AI_STRIDE_INIT(4, 4, 4, 16, 16),
  1, &conv2d_6_bias_array, &conv2d_6_bias_intq)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 4), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &conv2d_6_weights_array, &conv2d_6_weights_intq)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_5_bias_array, &conv2d_5_bias_intq)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 3, 3, 1), AI_STRIDE_INIT(4, 1, 8, 24, 72),
  1, &conv2d_5_weights_array, &conv2d_5_weights_intq)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_3_bias_array, &conv2d_3_bias_intq)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 8), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &conv2d_3_weights_array, &conv2d_3_weights_intq)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_2_bias_array, &conv2d_2_bias_intq)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 8), AI_STRIDE_INIT(4, 1, 1, 3, 9),
  1, &conv2d_2_weights_array, &conv2d_2_weights_intq)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_image_input0_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 160, 160), AI_STRIDE_INIT(4, 4, 4, 4, 640),
  1, &serving_default_image_input0_output_array, NULL)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  conversion_0_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 160, 160), AI_STRIDE_INIT(4, 1, 1, 1, 160),
  1, &conversion_0_output_array, &conversion_0_output_intq)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 80, 80), AI_STRIDE_INIT(4, 1, 1, 8, 640),
  1, &conv2d_2_output_array, &conv2d_2_output_intq)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 80, 80), AI_STRIDE_INIT(4, 1, 1, 8, 640),
  1, &conv2d_3_output_array, &conv2d_3_output_intq)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 40, 40), AI_STRIDE_INIT(4, 1, 1, 8, 320),
  1, &conv2d_5_output_array, &conv2d_5_output_intq)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 40, 40), AI_STRIDE_INIT(4, 1, 1, 4, 160),
  1, &conv2d_6_output_array, &conv2d_6_output_intq)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 20, 20), AI_STRIDE_INIT(4, 1, 1, 8, 160),
  1, &conv2d_8_output_array, &conv2d_8_output_intq)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 20, 20), AI_STRIDE_INIT(4, 1, 1, 48, 960),
  1, &conv2d_9_output_array, &conv2d_9_output_intq)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 20, 20), AI_STRIDE_INIT(4, 1, 1, 48, 960),
  1, &conv2d_10_output_array, &conv2d_10_output_intq)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 20, 20), AI_STRIDE_INIT(4, 1, 1, 16, 320),
  1, &conv2d_11_output_array, &conv2d_11_output_intq)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  concat_12_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 20, 20), AI_STRIDE_INIT(4, 1, 1, 24, 480),
  1, &concat_12_output_array, &concat_12_output_intq)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 20, 20), AI_STRIDE_INIT(4, 1, 1, 64, 1280),
  1, &conv2d_13_output_array, &conv2d_13_output_intq)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 10, 10), AI_STRIDE_INIT(4, 1, 1, 64, 640),
  1, &conv2d_15_output_array, &conv2d_15_output_intq)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &conv2d_16_output_array, &conv2d_16_output_intq)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 10), AI_STRIDE_INIT(4, 1, 1, 96, 960),
  1, &conv2d_17_output_array, &conv2d_17_output_intq)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 10), AI_STRIDE_INIT(4, 1, 1, 96, 960),
  1, &conv2d_18_output_array, &conv2d_18_output_intq)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &conv2d_19_output_array, &conv2d_19_output_intq)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_20_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &eltwise_20_output_array, &eltwise_20_output_intq)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 10), AI_STRIDE_INIT(4, 1, 1, 96, 960),
  1, &conv2d_21_output_array, &conv2d_21_output_intq)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 10), AI_STRIDE_INIT(4, 1, 1, 96, 960),
  1, &conv2d_22_output_array, &conv2d_22_output_intq)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &conv2d_23_output_array, &conv2d_23_output_intq)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_24_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &eltwise_24_output_array, &eltwise_24_output_intq)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 10), AI_STRIDE_INIT(4, 1, 1, 96, 960),
  1, &conv2d_25_output_array, &conv2d_25_output_intq)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 10, 10), AI_STRIDE_INIT(4, 1, 1, 96, 960),
  1, &conv2d_26_output_array, &conv2d_26_output_intq)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &conv2d_27_output_array, &conv2d_27_output_intq)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_28_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 10, 10), AI_STRIDE_INIT(4, 1, 1, 24, 240),
  1, &eltwise_28_output_array, &eltwise_28_output_intq)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  concat_29_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 88, 10, 10), AI_STRIDE_INIT(4, 1, 1, 88, 880),
  1, &concat_29_output_array, &concat_29_output_intq)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 10, 10), AI_STRIDE_INIT(4, 1, 1, 128, 1280),
  1, &conv2d_30_output_array, &conv2d_30_output_intq)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 5, 5), AI_STRIDE_INIT(4, 1, 1, 128, 640),
  1, &conv2d_32_output_array, &conv2d_32_output_intq)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 5, 5), AI_STRIDE_INIT(4, 1, 1, 64, 320),
  1, &conv2d_33_output_array, &conv2d_33_output_intq)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 5, 5), AI_STRIDE_INIT(4, 1, 1, 256, 1280),
  1, &conv2d_34_output_array, &conv2d_34_output_intq)

/* Tensor #108 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 35, 5, 5), AI_STRIDE_INIT(4, 1, 1, 35, 175),
  1, &conv2d_35_output_array, &conv2d_35_output_intq)

/* Tensor #109 */
AI_TENSOR_OBJ_DECLARE(
  conversion_36_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 35, 5, 5), AI_STRIDE_INIT(4, 4, 4, 140, 700),
  1, &conversion_36_output_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_image_input0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_0_layer, 0,
  NL_TYPE,
  nl, node_convert,
  &AI_NET_OBJ_INSTANCE, &conv2d_2_layer, AI_STATIC,
  .tensors = &conversion_0_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_2_weights, &conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 2,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_3_layer, AI_STATIC,
  .tensors = &conv2d_2_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_3_weights, &conv2d_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_3_layer, 3,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_5_layer, AI_STATIC,
  .tensors = &conv2d_3_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_5_weights, &conv2d_5_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_5_layer, 5,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_6_layer, AI_STATIC,
  .tensors = &conv2d_5_chain, 
  .groups = 8, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_6_weights, &conv2d_6_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_6_layer, 6,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_8_layer, AI_STATIC,
  .tensors = &conv2d_6_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_i8 conv2d_8_nl_params_data[] = { -11 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_8_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_8_nl_params_data, conv2d_8_nl_params_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_8_weights, &conv2d_8_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_8_scratch0, &conv2d_8_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_8_layer, 8,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_9_layer, AI_STATIC,
  .tensors = &conv2d_8_chain, 
  .groups = 1, 
  .nl_params = &conv2d_8_nl_params, 
  .nl_func = nl_func_relu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_9_weights, &conv2d_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_layer, 9,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_10_layer, AI_STATIC,
  .tensors = &conv2d_9_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_10_weights, &conv2d_10_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_10_layer, 10,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_11_layer, AI_STATIC,
  .tensors = &conv2d_10_chain, 
  .groups = 48, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_11_weights, &conv2d_11_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_11_layer, 11,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &concat_12_layer, AI_STATIC,
  .tensors = &conv2d_11_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_11_output, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_12_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_12_layer, 12,
  CONCAT_TYPE,
  concat, forward_concat,
  &AI_NET_OBJ_INSTANCE, &conv2d_13_layer, AI_STATIC,
  .tensors = &concat_12_chain, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_13_weights, &conv2d_13_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_13_layer, 13,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_15_layer, AI_STATIC,
  .tensors = &conv2d_13_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_i8 conv2d_15_nl_params_data[] = { -32 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_15_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_15_nl_params_data, conv2d_15_nl_params_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_15_weights, &conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_15_scratch0, &conv2d_15_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_15_layer, 15,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_16_layer, AI_STATIC,
  .tensors = &conv2d_15_chain, 
  .groups = 64, 
  .nl_params = &conv2d_15_nl_params, 
  .nl_func = nl_func_relu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_16_weights, &conv2d_16_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_16_layer, 16,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_17_layer, AI_STATIC,
  .tensors = &conv2d_16_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_17_weights, &conv2d_17_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_17_layer, 17,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_18_layer, AI_STATIC,
  .tensors = &conv2d_17_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_18_weights, &conv2d_18_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_18_layer, 18,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_19_layer, AI_STATIC,
  .tensors = &conv2d_18_chain, 
  .groups = 96, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_19_weights, &conv2d_19_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_19_layer, 19,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &eltwise_20_layer, AI_STATIC,
  .tensors = &conv2d_19_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_16_output, &conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_20_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_20_layer, 20,
  ELTWISE_TYPE,
  eltwise, forward_add_integer_INT8,
  &AI_NET_OBJ_INSTANCE, &conv2d_21_layer, AI_STATIC,
  .tensors = &eltwise_20_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_21_weights, &conv2d_21_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_21_layer, 21,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_22_layer, AI_STATIC,
  .tensors = &conv2d_21_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_22_weights, &conv2d_22_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_22_layer, 22,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_23_layer, AI_STATIC,
  .tensors = &conv2d_22_chain, 
  .groups = 96, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_23_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_23_weights, &conv2d_23_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_23_layer, 23,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &eltwise_24_layer, AI_STATIC,
  .tensors = &conv2d_23_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_20_output, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_24_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_24_layer, 24,
  ELTWISE_TYPE,
  eltwise, forward_add_integer_INT8,
  &AI_NET_OBJ_INSTANCE, &conv2d_25_layer, AI_STATIC,
  .tensors = &eltwise_24_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_25_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_25_weights, &conv2d_25_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_25_layer, 25,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_26_layer, AI_STATIC,
  .tensors = &conv2d_25_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_26_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_26_weights, &conv2d_26_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_26_layer, 26,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_27_layer, AI_STATIC,
  .tensors = &conv2d_26_chain, 
  .groups = 96, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_27_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_27_weights, &conv2d_27_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_27_layer, 27,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &eltwise_28_layer, AI_STATIC,
  .tensors = &conv2d_27_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_28_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_24_output, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_28_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_28_layer, 28,
  ELTWISE_TYPE,
  eltwise, forward_add_integer_INT8,
  &AI_NET_OBJ_INSTANCE, &concat_29_layer, AI_STATIC,
  .tensors = &eltwise_28_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_29_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_28_output, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_29_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_29_layer, 29,
  CONCAT_TYPE,
  concat, forward_concat,
  &AI_NET_OBJ_INSTANCE, &conv2d_30_layer, AI_STATIC,
  .tensors = &concat_29_chain, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_30_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_30_weights, &conv2d_30_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_30_layer, 30,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_32_layer, AI_STATIC,
  .tensors = &conv2d_30_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_32_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_32_weights, &conv2d_32_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_32_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_32_layer, 32,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_33_layer, AI_STATIC,
  .tensors = &conv2d_32_chain, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_33_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_33_weights, &conv2d_33_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_33_layer, 33,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_34_layer, AI_STATIC,
  .tensors = &conv2d_33_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_34_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_34_weights, &conv2d_34_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_34_layer, 34,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_35_layer, AI_STATIC,
  .tensors = &conv2d_34_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_35_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_35_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_35_weights, &conv2d_35_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_35_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_35_layer, 35,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conversion_36_layer, AI_STATIC,
  .tensors = &conv2d_35_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_36_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_35_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_36_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_36_layer, 36,
  NL_TYPE,
  nl, node_convert,
  &AI_NET_OBJ_INSTANCE, &conversion_36_layer, AI_STATIC,
  .tensors = &conversion_36_chain, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 74364, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 53116, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_PERSON_YOLO_IN_NUM, &serving_default_image_input0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_PERSON_YOLO_OUT_NUM, &conversion_36_output),
  &conversion_0_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool person_yolo_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, AI_PERSON_YOLO_ACTIVATIONS_ALIGNMENT));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    conv2d_35_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_35_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_34_scratch0_array.data = AI_PTR(activations + 2752);
    conv2d_34_scratch0_array.data_start = AI_PTR(activations + 2752);
    conv2d_33_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_33_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_32_scratch0_array.data = AI_PTR(activations + 14432);
    conv2d_32_scratch0_array.data_start = AI_PTR(activations + 14432);
    conv2d_30_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_30_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_27_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_27_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_26_scratch0_array.data = AI_PTR(activations + 24772);
    conv2d_26_scratch0_array.data_start = AI_PTR(activations + 24772);
    conv2d_25_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_25_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_23_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_23_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_22_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_22_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_21_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_21_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_19_scratch0_array.data = AI_PTR(activations + 2896);
    conv2d_19_scratch0_array.data_start = AI_PTR(activations + 2896);
    conv2d_18_scratch0_array.data = AI_PTR(activations + 2896);
    conv2d_18_scratch0_array.data_start = AI_PTR(activations + 2896);
    conv2d_17_scratch0_array.data = AI_PTR(activations + 2896);
    conv2d_17_scratch0_array.data_start = AI_PTR(activations + 2896);
    conv2d_16_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_16_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_15_scratch1_array.data = AI_PTR(activations + 2372);
    conv2d_15_scratch1_array.data_start = AI_PTR(activations + 2372);
    conv2d_15_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_15_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_13_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_13_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_11_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_11_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_10_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_10_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_9_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_9_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_8_scratch1_array.data = AI_PTR(activations + 832);
    conv2d_8_scratch1_array.data_start = AI_PTR(activations + 832);
    conv2d_8_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_8_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_6_scratch0_array.data = AI_PTR(activations + 12800);
    conv2d_6_scratch0_array.data_start = AI_PTR(activations + 12800);
    conv2d_5_scratch0_array.data = AI_PTR(activations + 51528);
    conv2d_5_scratch0_array.data_start = AI_PTR(activations + 51528);
    conv2d_3_scratch0_array.data = AI_PTR(activations + 52176);
    conv2d_3_scratch0_array.data_start = AI_PTR(activations + 52176);
    conv2d_2_scratch0_array.data = AI_PTR(activations + 52824);
    conv2d_2_scratch0_array.data_start = AI_PTR(activations + 52824);
    serving_default_image_input0_output_array.data = AI_PTR(NULL);
    serving_default_image_input0_output_array.data_start = AI_PTR(NULL);
    conversion_0_output_array.data = AI_PTR(activations + 27224);
    conversion_0_output_array.data_start = AI_PTR(activations + 27224);
    conv2d_2_output_array.data = AI_PTR(activations + 976);
    conv2d_2_output_array.data_start = AI_PTR(activations + 976);
    conv2d_3_output_array.data = AI_PTR(activations + 328);
    conv2d_3_output_array.data_start = AI_PTR(activations + 328);
    conv2d_5_output_array.data = AI_PTR(activations + 0);
    conv2d_5_output_array.data_start = AI_PTR(activations + 0);
    conv2d_6_output_array.data = AI_PTR(activations + 12872);
    conv2d_6_output_array.data_start = AI_PTR(activations + 12872);
    conv2d_8_output_array.data = AI_PTR(activations + 4032);
    conv2d_8_output_array.data_start = AI_PTR(activations + 4032);
    conv2d_9_output_array.data = AI_PTR(activations + 7232);
    conv2d_9_output_array.data_start = AI_PTR(activations + 7232);
    conv2d_10_output_array.data = AI_PTR(activations + 26432);
    conv2d_10_output_array.data_start = AI_PTR(activations + 26432);
    conv2d_11_output_array.data = AI_PTR(activations + 7232);
    conv2d_11_output_array.data_start = AI_PTR(activations + 7232);
    concat_12_output_array.data = AI_PTR(activations + 13632);
    concat_12_output_array.data_start = AI_PTR(activations + 13632);
    conv2d_13_output_array.data = AI_PTR(activations + 23232);
    conv2d_13_output_array.data_start = AI_PTR(activations + 23232);
    conv2d_15_output_array.data = AI_PTR(activations + 8772);
    conv2d_15_output_array.data_start = AI_PTR(activations + 8772);
    conv2d_16_output_array.data = AI_PTR(activations + 496);
    conv2d_16_output_array.data_start = AI_PTR(activations + 496);
    conv2d_17_output_array.data = AI_PTR(activations + 15172);
    conv2d_17_output_array.data_start = AI_PTR(activations + 15172);
    conv2d_18_output_array.data = AI_PTR(activations + 24772);
    conv2d_18_output_array.data_start = AI_PTR(activations + 24772);
    conv2d_19_output_array.data = AI_PTR(activations + 3520);
    conv2d_19_output_array.data_start = AI_PTR(activations + 3520);
    eltwise_20_output_array.data = AI_PTR(activations + 5920);
    eltwise_20_output_array.data_start = AI_PTR(activations + 5920);
    conv2d_21_output_array.data = AI_PTR(activations + 15172);
    conv2d_21_output_array.data_start = AI_PTR(activations + 15172);
    conv2d_22_output_array.data = AI_PTR(activations + 24772);
    conv2d_22_output_array.data_start = AI_PTR(activations + 24772);
    conv2d_23_output_array.data = AI_PTR(activations + 624);
    conv2d_23_output_array.data_start = AI_PTR(activations + 624);
    eltwise_24_output_array.data = AI_PTR(activations + 3024);
    eltwise_24_output_array.data_start = AI_PTR(activations + 3024);
    conv2d_25_output_array.data = AI_PTR(activations + 15172);
    conv2d_25_output_array.data_start = AI_PTR(activations + 15172);
    conv2d_26_output_array.data = AI_PTR(activations + 28328);
    conv2d_26_output_array.data_start = AI_PTR(activations + 28328);
    conv2d_27_output_array.data = AI_PTR(activations + 624);
    conv2d_27_output_array.data_start = AI_PTR(activations + 624);
    eltwise_28_output_array.data = AI_PTR(activations + 5424);
    eltwise_28_output_array.data_start = AI_PTR(activations + 5424);
    concat_29_output_array.data = AI_PTR(activations + 15172);
    concat_29_output_array.data_start = AI_PTR(activations + 15172);
    conv2d_30_output_array.data = AI_PTR(activations + 1632);
    conv2d_30_output_array.data_start = AI_PTR(activations + 1632);
    conv2d_32_output_array.data = AI_PTR(activations + 19172);
    conv2d_32_output_array.data_start = AI_PTR(activations + 19172);
    conv2d_33_output_array.data = AI_PTR(activations + 1152);
    conv2d_33_output_array.data_start = AI_PTR(activations + 1152);
    conv2d_34_output_array.data = AI_PTR(activations + 5568);
    conv2d_34_output_array.data_start = AI_PTR(activations + 5568);
    conv2d_35_output_array.data = AI_PTR(activations + 1376);
    conv2d_35_output_array.data_start = AI_PTR(activations + 1376);
    conversion_36_output_array.data = AI_PTR(NULL);
    conversion_36_output_array.data_start = AI_PTR(NULL);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool person_yolo_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    conv2d_35_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_35_bias_array.data = AI_PTR(weights + 74224);
    conv2d_35_bias_array.data_start = AI_PTR(weights + 74224);
    conv2d_35_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_35_weights_array.data = AI_PTR(weights + 65264);
    conv2d_35_weights_array.data_start = AI_PTR(weights + 65264);
    conv2d_34_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_bias_array.data = AI_PTR(weights + 64240);
    conv2d_34_bias_array.data_start = AI_PTR(weights + 64240);
    conv2d_34_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_weights_array.data = AI_PTR(weights + 47856);
    conv2d_34_weights_array.data_start = AI_PTR(weights + 47856);
    conv2d_33_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_bias_array.data = AI_PTR(weights + 47600);
    conv2d_33_bias_array.data_start = AI_PTR(weights + 47600);
    conv2d_33_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_weights_array.data = AI_PTR(weights + 39408);
    conv2d_33_weights_array.data_start = AI_PTR(weights + 39408);
    conv2d_32_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_32_bias_array.data = AI_PTR(weights + 38896);
    conv2d_32_bias_array.data_start = AI_PTR(weights + 38896);
    conv2d_32_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_32_weights_array.data = AI_PTR(weights + 37744);
    conv2d_32_weights_array.data_start = AI_PTR(weights + 37744);
    conv2d_30_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_bias_array.data = AI_PTR(weights + 37232);
    conv2d_30_bias_array.data_start = AI_PTR(weights + 37232);
    conv2d_30_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_weights_array.data = AI_PTR(weights + 25968);
    conv2d_30_weights_array.data_start = AI_PTR(weights + 25968);
    conv2d_27_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_bias_array.data = AI_PTR(weights + 25872);
    conv2d_27_bias_array.data_start = AI_PTR(weights + 25872);
    conv2d_27_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_weights_array.data = AI_PTR(weights + 23568);
    conv2d_27_weights_array.data_start = AI_PTR(weights + 23568);
    conv2d_26_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_26_bias_array.data = AI_PTR(weights + 23184);
    conv2d_26_bias_array.data_start = AI_PTR(weights + 23184);
    conv2d_26_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_26_weights_array.data = AI_PTR(weights + 22320);
    conv2d_26_weights_array.data_start = AI_PTR(weights + 22320);
    conv2d_25_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_bias_array.data = AI_PTR(weights + 21936);
    conv2d_25_bias_array.data_start = AI_PTR(weights + 21936);
    conv2d_25_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_weights_array.data = AI_PTR(weights + 19632);
    conv2d_25_weights_array.data_start = AI_PTR(weights + 19632);
    conv2d_23_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_bias_array.data = AI_PTR(weights + 19536);
    conv2d_23_bias_array.data_start = AI_PTR(weights + 19536);
    conv2d_23_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_weights_array.data = AI_PTR(weights + 17232);
    conv2d_23_weights_array.data_start = AI_PTR(weights + 17232);
    conv2d_22_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_bias_array.data = AI_PTR(weights + 16848);
    conv2d_22_bias_array.data_start = AI_PTR(weights + 16848);
    conv2d_22_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_weights_array.data = AI_PTR(weights + 15984);
    conv2d_22_weights_array.data_start = AI_PTR(weights + 15984);
    conv2d_21_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_bias_array.data = AI_PTR(weights + 15600);
    conv2d_21_bias_array.data_start = AI_PTR(weights + 15600);
    conv2d_21_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_weights_array.data = AI_PTR(weights + 13296);
    conv2d_21_weights_array.data_start = AI_PTR(weights + 13296);
    conv2d_19_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_bias_array.data = AI_PTR(weights + 13200);
    conv2d_19_bias_array.data_start = AI_PTR(weights + 13200);
    conv2d_19_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_weights_array.data = AI_PTR(weights + 10896);
    conv2d_19_weights_array.data_start = AI_PTR(weights + 10896);
    conv2d_18_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_bias_array.data = AI_PTR(weights + 10512);
    conv2d_18_bias_array.data_start = AI_PTR(weights + 10512);
    conv2d_18_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_weights_array.data = AI_PTR(weights + 9648);
    conv2d_18_weights_array.data_start = AI_PTR(weights + 9648);
    conv2d_17_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_bias_array.data = AI_PTR(weights + 9264);
    conv2d_17_bias_array.data_start = AI_PTR(weights + 9264);
    conv2d_17_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_weights_array.data = AI_PTR(weights + 6960);
    conv2d_17_weights_array.data_start = AI_PTR(weights + 6960);
    conv2d_16_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_bias_array.data = AI_PTR(weights + 6864);
    conv2d_16_bias_array.data_start = AI_PTR(weights + 6864);
    conv2d_16_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_weights_array.data = AI_PTR(weights + 5328);
    conv2d_16_weights_array.data_start = AI_PTR(weights + 5328);
    conv2d_15_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_bias_array.data = AI_PTR(weights + 5072);
    conv2d_15_bias_array.data_start = AI_PTR(weights + 5072);
    conv2d_15_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_weights_array.data = AI_PTR(weights + 4496);
    conv2d_15_weights_array.data_start = AI_PTR(weights + 4496);
    conv2d_13_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_bias_array.data = AI_PTR(weights + 4240);
    conv2d_13_bias_array.data_start = AI_PTR(weights + 4240);
    conv2d_13_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_weights_array.data = AI_PTR(weights + 2704);
    conv2d_13_weights_array.data_start = AI_PTR(weights + 2704);
    conv2d_11_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_bias_array.data = AI_PTR(weights + 2640);
    conv2d_11_bias_array.data_start = AI_PTR(weights + 2640);
    conv2d_11_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_weights_array.data = AI_PTR(weights + 1872);
    conv2d_11_weights_array.data_start = AI_PTR(weights + 1872);
    conv2d_10_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_bias_array.data = AI_PTR(weights + 1680);
    conv2d_10_bias_array.data_start = AI_PTR(weights + 1680);
    conv2d_10_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_weights_array.data = AI_PTR(weights + 1248);
    conv2d_10_weights_array.data_start = AI_PTR(weights + 1248);
    conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_bias_array.data = AI_PTR(weights + 1056);
    conv2d_9_bias_array.data_start = AI_PTR(weights + 1056);
    conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_weights_array.data = AI_PTR(weights + 672);
    conv2d_9_weights_array.data_start = AI_PTR(weights + 672);
    conv2d_8_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_bias_array.data = AI_PTR(weights + 640);
    conv2d_8_bias_array.data_start = AI_PTR(weights + 640);
    conv2d_8_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_weights_array.data = AI_PTR(weights + 352);
    conv2d_8_weights_array.data_start = AI_PTR(weights + 352);
    conv2d_6_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_bias_array.data = AI_PTR(weights + 336);
    conv2d_6_bias_array.data_start = AI_PTR(weights + 336);
    conv2d_6_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_weights_array.data = AI_PTR(weights + 304);
    conv2d_6_weights_array.data_start = AI_PTR(weights + 304);
    conv2d_5_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_bias_array.data = AI_PTR(weights + 272);
    conv2d_5_bias_array.data_start = AI_PTR(weights + 272);
    conv2d_5_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_weights_array.data = AI_PTR(weights + 200);
    conv2d_5_weights_array.data_start = AI_PTR(weights + 200);
    conv2d_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_bias_array.data = AI_PTR(weights + 168);
    conv2d_3_bias_array.data_start = AI_PTR(weights + 168);
    conv2d_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_weights_array.data = AI_PTR(weights + 104);
    conv2d_3_weights_array.data_start = AI_PTR(weights + 104);
    conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_bias_array.data = AI_PTR(weights + 72);
    conv2d_2_bias_array.data_start = AI_PTR(weights + 72);
    conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_weights_array.data = AI_PTR(weights + 0);
    conv2d_2_weights_array.data_start = AI_PTR(weights + 0);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_person_yolo_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_PERSON_YOLO_MODEL_NAME,
      .model_signature   = AI_PERSON_YOLO_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = {AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR,
                            AI_TOOLS_API_VERSION_MICRO, 0x0},

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 6317709,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if ( !ai_platform_api_get_network_report(network, &r) ) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_person_yolo_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_person_yolo_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_person_yolo_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_person_yolo_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= person_yolo_configure_weights(net_ctx, &params->params);
  ok &= person_yolo_configure_activations(net_ctx, &params->activations);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_person_yolo_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_person_yolo_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}




#undef AI_PERSON_YOLO_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

