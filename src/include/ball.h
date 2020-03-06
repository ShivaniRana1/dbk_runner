#include<stdio.h>

#ifndef VARIABLES_H
  #define VARIABLES_H
  #include"variables.h"
#endif

#ifndef FOOD_H
  #include"food.h"
  #define FOOD_H
#endif

#ifndef OBSTACLE_H
  #include"obstacles.h"
  #define OBSTACLE_H
#endif


void moveBall()
{
  float ballAcc; // Ball acceleration
  if(ballz > roadLength*0.75){
      ballAcc=SPEED_4;
  }else if(ballz > roadLength*0.50){
    ballAcc=SPEED_3;
   
  }else if(ballz > roadLength* 0.25){
    ballAcc=SPEED_2 ;
  
  }else{
    ballAcc =SPEED_1;

         // The character array to hole the string
    char text[20] = "The text I want to print";
        // The color, red for me
      glColor3f(0, 0, 0);
        // Position of the text to be printer
        glRasterPos3f(0.0f, 2.0f, 1.0f);
      for(int i = 0; text[i] != '\0'; i++){
          glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
          }

  }
  ballz = ballz + ballAcc;
  //printf("Ballz: %f \t | \t Speed: %f\n",ballz,ballAcc);
}

void drawSphere()
{

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f); 
    glTranslatef(ballx,0.5f,ballz);
    glutSolidSphere(.4, 50,50);
    glPopMatrix();
}

void feelCollision(){
  foodCollision();
  obstacleCollision();
}
