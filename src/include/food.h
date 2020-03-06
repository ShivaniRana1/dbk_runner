
#include<GL/glut.h>

#ifndef VARIABLES_H
  #define VARIABLES_H
  #include"variables.h"
#endif

float foodMat[200][2];
int isInitialized =0;

void initFood(){

    float zLocation;
    float xLocation;
   

    for(int i =0; i < 200; i++){
        zLocation = rand() % roadLength;
        xLocation = (rand() % 3) -1;

        foodMat[i][0] = xLocation;
        foodMat[i][1] = zLocation;
    }
    isInitialized =1;
}

void drawFood(int number){
    if(!isInitialized){
        initFood();
    }
    for(int i =0; i < 20; i++){
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glPushMatrix();
        glTranslatef(foodMat[i][0] ,1.0,foodMat[i][1]);
        glRotatef(angleFood,0.0,1.0,0.0);
        glutSolidTorus(0.1,0.5,4,4);
        glPopMatrix();
       // printf("Z locations:%f\n",foodMat[i][1]);
    }

}

void rotateFood(){
    angleFood += 5.0;
    //printf("%f\n",angleFood);
}

void foodCollision(){
    for(int i =0; i < 20; i++){
        if((int)ballx == (int)foodMat[i][0] && (int)ballz == (int)foodMat[i][1]){
            //printf("Food collision at: (%f,%f)\n",ballx,ballz);
            totalPoints++;
          if(ballz<roadLength){
          glLoadIdentity();
    glTranslatef(-3, 0.5, ballz);
        int num = totalPoints;
            char text[10]={'\0'};
                sprintf(text, "%d", num); //%d is for integers 
                    glColor3f(0.0, 0.0, 0.0);
                         glRasterPos3f( 0.3 , 3.0 , ballz);
                                for(int i = 0; text[i] != '\0'; i++)
                                     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);   
                                   
          }
        }
    }
}