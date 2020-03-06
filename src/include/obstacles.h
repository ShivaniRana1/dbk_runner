#ifndef VARIABLES_H
  #define VARIABLES_H
  #include"variables.h"

#endif

float obsMat[200][2];
int isInit=0;

void initobs(){
   
   // foodMat[0][0] = 0; // initializing the matrix so that it can be checked below if the value has been placed or not
 
    float zLocation;
    float xLocation;
   

    for(int i =0; i < 200; i++){
        zLocation = rand() % roadLength;
        xLocation = (rand() % 3) -1;

        obsMat[i][0] = xLocation;
        obsMat[i][1] = zLocation;
    }
    isInit =1;
}

void drawObstacleBlock(int number)
{

  if(!isInit){
        initobs();
    }
  for(int i =0; i < 20; i++){
  glPushMatrix();
   glTranslatef(obsMat[i][0] ,1.0,obsMat[i][1]);

  glBegin(GL_POLYGON);
  glVertex3f( -0.5, -0.5, -0.5);       // P1
  glVertex3f( -0.5,  0.5, -0.5);       // P2
  glVertex3f(  0.5,  0.5, -0.5);       // P3
  glVertex3f(  0.5, -0.5, -0.5);       // P4

  glEnd();
    // White side - BACK
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 1.0);
  glVertex3f(  0.5, -0.5, 0.5);
  glVertex3f(  0.5,  0.5, 0.5);
  glVertex3f( -0.5,  0.5, 0.5);
  glVertex3f( -0.5, -0.5, 0.5);
  glEnd();

  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor3f(  1.0,  0.0,  1.0);
  glVertex3f( 0.5, -0.5, -0.5);
  glVertex3f( 0.5,  0.5, -0.5);
  glVertex3f( 0.5,  0.5,  0.5);
  glVertex3f( 0.5, -0.5,  0.5);
  glEnd();

  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  1.0,  0.0);
  glVertex3f( -0.5, -0.5,  0.5);
  glVertex3f( -0.5,  0.5,  0.5);
  glVertex3f( -0.5,  0.5, -0.5);
  glVertex3f( -0.5, -0.5, -0.5);
  glEnd();

  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  1.0);
  glVertex3f(  0.5,  0.5,  0.5);
  glVertex3f(  0.5,  0.5, -0.5);
  glVertex3f( -0.5,  0.5, -0.5);
  glVertex3f( -0.5,  0.5,  0.5);
  glEnd();

  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0);
  glVertex3f(  0.5, -0.5, -0.5);
  glVertex3f(  0.5, -0.5,  0.5);
  glVertex3f( -0.5, -0.5,  0.5);
  glVertex3f( -0.5, -0.5, -0.5);
  glEnd();
  
  glPopMatrix();
  }
}

void obstacleCollision(){
    for(int i =0; i < 20; i++){
        if((int)ballx == (int)obsMat[i][0] && (int)ballz == (int)obsMat[i][1]){
            printf("Obstacle collision at: (%f,%f)\n",ballx,ballz);
            totalPoints--;
        }
    }
}