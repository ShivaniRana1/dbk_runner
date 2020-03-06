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
  ballz = ballz+0.0999;
}

void drawSphere()
{

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f); 
    glTranslatef(ballx,0.5f,ballz);
    glutSolidSphere(.5, 50,50);
    glPopMatrix();
}

void feelCollision(){
  foodCollision();
  obstacleCollision();
}
