#include <yolo_layer.h>
#include <math.h>
#include <rtthread.h>
#include <stdlib.h>
#include <math.h>
static int anchor[5][2]=
{
//    {30, 29},  {49, 50},  {64, 77},  {95, 95}, {119,135}
  {33, 37}, {52, 52}, {69, 81}, {95,122}, {135,141}
};

static int input_dims[2] ={160,160};


int nms_comparator(void *pa, void *pb)
{
    obj_key a = *(obj_key *)pa;
    obj_key b = *(obj_key *)pb;
    float diff = a.obj - b.obj;
    if (diff < 0)
        return 1;
    else if (diff > 0)
        return -1;
    return 0;
}

static float overlap(float x1, float w1, float x2, float w2)
{
    float l1 = x1 - w1/2;
    float l2 = x2 - w2/2;
    float left = l1 > l2 ? l1 : l2;
    float r1 = x1 + w1/2;
    float r2 = x2 + w2/2;
    float right = r1 < r2 ? r1 : r2;

    return right - left;        // return the x-axis overlap distance
}


static float box_intersection(yolo_box a, yolo_box b)
{
    float w = overlap(a.x, a.w, b.x, b.w);
    float h = overlap(a.y, a.h, b.y, b.h);

    if (w < 0 || h < 0)
        return 0;
    return w * h;               // return the intersection area
}

static float box_union(yolo_box a, yolo_box b)
{
    float i = box_intersection(a, b);
    float u = a.w * a.h + b.w * b.h - i;

    return u;                   // return the union area
}

float box_iou(yolo_box a, yolo_box b)
{
    return box_intersection(a, b) / box_union(a, b);
}



int yolo_decode(float *out_data)
{
  int j=0,k=0,l=0;
  for(int i=0; i<5*5*5; i++)
  {
    // yolo obtains the relative loaction of the center of prediction to the center of anchor
    float x_tmp = 1 / (1 + exp(-out_data[i*7+0])); // sigmoid decode
    float y_tmp = 1 / (1 + exp(-out_data[i*7+1]));
    float box_x = (x_tmp + k) / 5;                 //
    float box_y = (y_tmp + l) / 5;
    
    float box_w = (exp(out_data[i*7+2])*anchor[j][0])/ input_dims[0];
    float box_h = (exp(out_data[i*7+3])*anchor[j][1])/ input_dims[1];
    
    float objectness = 1 / (1 + exp(-out_data[i*7+4]));
    
    float class_scores0 = 1 / (1 + exp(-out_data[i*7+5]));
    float class_scores1 = 1 / (1 + exp(-out_data[i*7+6]));
    
    out_data[i*7+0] = box_x;
    out_data[i*7+1] = box_y;
    out_data[i*7+2] = box_w;
    out_data[i*7+3] = box_h;
    out_data[i*7+4] = objectness;
    out_data[i*7+5] = class_scores0;
    out_data[i*7+6] = class_scores1;
    
    if(j++>=4)
    {
      j = 0;
      if(k++>=4)
      {
        k = 0;
        if(l++>=4)
        {
          l = 0;
        }
      }
    }
  }
  return 0;
}


int yolo_region_layer_init(yolo_region_layer *region_layer, float threshold, int boxes_number, float nms_value, int anchor_number){
    region_layer->threshold = threshold;
    region_layer->boxes_number = boxes_number;
    region_layer->nms_value = nms_value;
    region_layer->anchor_number = anchor_number;
    
    return 0;
}

