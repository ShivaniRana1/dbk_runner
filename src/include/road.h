#ifndef VARIABLES_H
  #define VARIABLES_H
  #include"variables.h"

#endif

void drawRoadSegment(int* roadPos)
{
  glPushMatrix();
  glTranslatef(0.0f, 0.0f, 0.0f);

  glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(-2,0,*roadPos+1);
    glVertex3f(2,0,*roadPos+1);
    glVertex3f(2,0,*roadPos);
    glVertex3f(-2,0,*roadPos);
    glColor3f(1,0.8,0.4);
    glVertex3f(-2,0,*roadPos+2);
    glVertex3f(2,0,*roadPos+2);
    glVertex3f(2,0,*roadPos+1);
    glVertex3f(-2,0,*roadPos+1);
  glEnd();

  glBegin(GL_QUADS);
    glVertex3f(-2.1,0,*roadPos+1);
    glVertex3f(-2,0,*roadPos+1);
    glVertex3f(-2,2,*roadPos);
    glVertex3f(-2,2,*roadPos);
  glEnd();

  glBegin(GL_QUADS);
    glVertex3f(2.1,0,*roadPos+1);
    glVertex3f(2,0,*roadPos+1);
    glVertex3f(2,2,*roadPos);
    glVertex3f(2,2,*roadPos);
  glEnd();
  *roadPos = *roadPos+2;
  glPopMatrix();
  
}

void drawRoad(int length)
{
    roadLength = length * 2;
  GLint roadPos=0;
  int i =0;
  while(i < length){
      drawRoadSegment(&roadPos);
      i++;
  }
}
