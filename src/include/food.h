#ifndef VARIABLES_H
  #define VARIABLES_H
  #include"variables.h"
#endif

float foodMat[200][2];
int isInitialized =0;
void initFood(){
   
    foodMat[0][0] = 0; // initializing the matrix so that it can be checked below if the value has been placed or not
 
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