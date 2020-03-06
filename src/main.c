#include<GL/glut.h>


#ifndef FOOD_H
  #include"food.h"
  #define FOOD_H
#endif

#ifndef OBSTACLE_H
  #include"obstacles.h"
  #define OBSTACLE_H
#endif

#include"road.h"

#include"ball.h"

#define GL_SILENCE_DEPRECATION  1
GLfloat x,y,z;
int _h,_w;
float camz;
float xrot = -1.0, yrot = 0.50, zoom = 2.0;

void init()
{
  glClearColor(1.0f, 0.5f, 0.5f, 1.0f); 
  glClearDepth(1.0f);                   
  glEnable(GL_DEPTH_TEST);   
  glDepthFunc(GL_LEQUAL);    
  glShadeModel(GL_SMOOTH); 
}



void text()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

 glLoadIdentity();

    glTranslatef(3, 0.5, ballz);

    // Write the text before any transformation or rotation
    // Or the text will change its position with the models

  if(ballz> roadLength*0.75){
    char text4[32];
    sprintf(text4, "LEVEL 4", xrot, yrot);
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f( 0.3 , 3.0 , ballz);
    for(int i = 0; text4[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text4[i]);
  }
   if(ballz > roadLength*0.5){
    char text3[32];
    sprintf(text3, "LEVEL 3", xrot, yrot);
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f( 0.3 , 3.0 , ballz);
    for(int i = 0; text3[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text3[i]);
  }

   if(ballz > roadLength*0.25){
    char text2[32];
    sprintf(text2, "LEVEL 2", xrot, yrot);
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f( 0.3 , 3.0 , ballz);
    for(int i = 0; text2[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text2[i]);
  }
   else {
    char text[32];
    sprintf(text, "LEVEL 1", xrot, yrot);
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f( 3.0 , 3.0 , ballz);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
  }
 
}


void gradientBackground() // call this function and make bring this to the backgrounds
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING);

  glBegin(GL_QUADS);
  //red color
  glColor3f(1.0,0.0,0.0);
  glVertex2f(-1.0, 1.0);
  glVertex2f(-1.0,-1.0);
  //blue color
  glColor3f(0.0,0.0,1.0);
  glVertex2f(1.0,-1.0);
  glVertex2f(1.0, 1.0);
  glEnd();
  glEnable(GL_DEPTH_TEST);
}


void render()
{

  camz=ballz-5.5;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

    // Write the text before any transformation or rotation
    // Or the text will change its position with the models
    text();

  glLoadIdentity();

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, ((GLdouble)_w/_h), 0.1f, 1000.0f);

  gluLookAt(0.0,3.0,camz,0.0,0.0,ballz,0.0,1.0,0.0);
  drawRoad(1000);
  drawObstacleBlock(10);
  drawSphere();
  drawFood(10);
  feelCollision();
  glFlush();
  glutTimerFunc(1500,moveBall,0);
    glutTimerFunc(2500,rotateFood,0);

  glutPostRedisplay();
  glutSwapBuffers();  
}

void reshape(GLsizei width, GLsizei height)
{  
  if (height == 0) height = 1;              
  GLfloat aspect = (GLfloat)width / (GLfloat)height;
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);  
  glLoadIdentity(); 
  gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}


void keyboardEvent(char key, int xm, int ym){
  if(key == GLUT_KEY_RIGHT)
  {
      ballx=ballx-1.0;
  }else if( key == GLUT_KEY_LEFT)
  {
      ballx=ballx+1.0;
  }


if(ballx>1.0){
      ballx = 1.0;
    }else if(ballx < -1.0){
      ballx = -1.0;
    }else{
      //
    }
}

int main(int argc, char** argv)
{
  _h=1080;
  _w=1920;
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(_w, _h);
  glutCreateWindow("DBK Runner");
  glutReshapeFunc(reshape);       // Register callback handler for window re-size event
  glutSpecialFunc(keyboardEvent);
  glutDisplayFunc(render);
  init();
  glutMainLoop();
  return 0;   
}