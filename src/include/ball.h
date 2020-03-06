float ballx=0.0;
float ballz=-1.5f;

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
