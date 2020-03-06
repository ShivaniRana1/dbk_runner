#ifndef VARIABLES_H
  #define VARIABLES_H
  #include"variables.h"
#endif

void drawFood(int number){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.0,1.0,10.0);
    glRotatef(angleFood,0.0,1.0,0.0);
    glutSolidTorus(0.1,0.5,4,4);
    glPopMatrix();
}

void rotateFood(){
    angleFood += 5.0;
    printf("%f\n",angleFood);

}