#include<GL/glut.h>
#include"food.h"
#include"road.h"
#include"obstacles.h"
#include"ball.h"

#define GL_SILENCE_DEPRECATION  1
GLfloat x,y,z;
int _h,_w;
float camz;

void init()
{
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
  glClearDepth(1.0f);                   
  glEnable(GL_DEPTH_TEST);   
  glDepthFunc(GL_LEQUAL);    
  glShadeModel(GL_SMOOTH); 
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
  glLoadIdentity();

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, ((GLdouble)_w/_h), 0.1f, 1000.0f);

  gluLookAt(0.0,3.0,camz,0.0,0.0,ballz,0.0,1.0,0.0);
  drawRoad(1000);
  drawObstacleBlock(10);
  drawSphere();
  drawFood(10);
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