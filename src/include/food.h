void drawFood(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0,1.0,2.0);
    glutSolidTorus(0.1,0.5,4,4);
}