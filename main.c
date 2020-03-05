#include<GL/glut.h>
#define GL_SILENCE_DEPRECATION  1
GLfloat x,y,z;

void init()
{
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
  glClearDepth(1.0f);                   
  glEnable(GL_DEPTH_TEST);   
  glDepthFunc(GL_LEQUAL);    
  glShadeModel(GL_SMOOTH); 
}

void obstacles()
{
  z = z+0.0999;
}


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
  GLint roadPos=0;
  int i =0;
  while(i < length){
      drawRoadSegment(&roadPos);
      i++;
  }
}

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


void drawSphere()
{
 glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 1.0f); 
    glTranslatef(0.0f +x,0.5f+y,-1.5f+z);
   	glutSolidSphere(.5, 50,50);
    glPopMatrix();
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
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, 1.77f, 0.1f, 1000.0f);

  gluLookAt(0.0,3.0,z-5.5,0.0,0.0,z,0.0,1.0,0.0);
  drawRoad(1000);
  drawObstacleBlock();
  drawSphere();
  glFlush();
  glutTimerFunc(1500,obstacles,0);

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
      x=x-1.0;
  }else if( key == GLUT_KEY_LEFT)
  {
      x=x+1.0;
  }
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(1920, 1080);
  glutCreateWindow("DBK Runner");
  glutReshapeFunc(reshape);       // Register callback handler for window re-size event
  glutSpecialFunc(keyboardEvent);
  glutDisplayFunc(render);
  init();
  glutMainLoop();
  return 0;   
}