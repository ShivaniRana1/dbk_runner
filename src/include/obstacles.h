#ifndef VARIABLES_H
  #define VARIABLES_H
  #include"variables.h"

#endif

void drawObstacleBlock()
{
  
  glPushMatrix();
  glTranslatef(0.0f, 0.0f, 10.0f);

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

