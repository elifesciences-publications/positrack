/*
Code dealing with the tracked_object
 */
#include "main.h"

int tracked_object_init(struct tracked_object *tob)
{

  tob->position_invalid=0;
  tob->head_direction_invalid=0;
  tob->num_samples=0;
  tob->percentage_position_invalid_total=0;
  tob->percentage_position_invalid_last_100=0;
  tob->travelled_distance=0;
  tob->samples_per_seconds=0;
  tob->buffer_length=TRACKED_OBJECT_BUFFER_LENGTH; 
  tob->pixels_per_cm=-1.0;
  
  double* x; // given by traking_interface
  double* y; // given by tracking interface
  double* head_direction; // given by tracking interface
  double* movment_heading;
  double* speed;

  if((tob->x=malloc(sizeof(double)*tob->buffer_length))==NULL)
    {
      fprintf(stderr, "problem allocating memory for tob->x\n");
      return -1;
    }
  if((tob->y=malloc(sizeof(double)*tob->buffer_length))==NULL)
    {
      fprintf(stderr, "problem allocating memory for tob->y\n");
      return -1;
    }
  if((tob->head_direction=malloc(sizeof(double)*tob->buffer_length))==NULL)
    {
      fprintf(stderr, "problem allocating memory for tob->head_direction\n");
      return -1;
    }
  if((tob->movement_heading=malloc(sizeof(double)*tob->buffer_length))==NULL)
    {
      fprintf(stderr, "problem allocating memory for tob->movment_heading\n");
      return -1;
    }
  if((tob->speed=malloc(sizeof(double)*tob->buffer_length))==NULL)
    {
      fprintf(stderr, "problem allocating memory for tob->speed\n");
      return -1;
    }
  tob->is_initialized=1;
  return 0;
}
int tracked_object_free(struct tracked_object *tob)
{
  if(tob->is_initialized==0)
    return 0;
     
  free(tob->x);
  free(tob->y);
  free(tob->head_direction);
  free(tob->movement_heading);
  free(tob->speed);  
  return 0;
}
int tracked_object_update_position(struct tracked_object* tob,double x, double y, double head_direction, int frame_duration_ms)
{
  
  return 0;
}