//
//  main.cpp
//  testabc
//
//  Created by Serena on 15/4/2018.
//  Copyright © 2018 Serena. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_QUADS);
        glColor3f(0.0f,0.0f,0.0f);
        glVertex2f(-0.5f,-0.5f);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex2f(0.5f,-0.5f);
        glColor3f(0.0f,1.0f,0.0f);
        glVertex2f(0.5f,0.5f);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex2f(-0.5f,0.5f);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex2f(-0.5f,-0.5f);
        glVertex2f(0.5f,-0.5f);
        glVertex2f(0.5f,0.5f);
        glVertex2f(-0.5f,0.5f);
    glEnd();
    
    glFinish();
    
    std::cout << "redisplay\n";
}

void reshape(int w, int h) {
    
    std::cout << "new size:" << w << ", " << h << std::endl;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<h){
        const float aspectRatio = (float)h/(float)w;
        glOrtho(-1.0,1.0,aspectRatio*-1.0,aspectRatio*1.0,-1.0,1.0);
    } else {
        const float aspectRatio = (float)w/(float)h;
        glOrtho(aspectRatio*-1.0,aspectRatio*1.0,-1.0,1.0,-1.0,1.0);
    }
}

void animate(unsigned char key, int x, int y) {
    glMatrixMode(GL_MODELVIEW);
    if(key == 'a') {
        glRotatef(1.0f,0.0f,0.0f,1.0f);
    } else if (key == 'b') {
        glRotatef(-1.0f,0.0f,0.0f,1.0f);
    }
    glutPostRedisplay();
}

int main(int argc, char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    // init the GLUT library and negotiate a session with the window system
    glutInit(&argc, argv);
    glutCreateWindow("Hello");
    // everytime you resize the screen etc.
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(animate);
    // called once. Specify the rgba used when the color buffer are cleared.
    glClearColor(0.0f,0.0f,0.0f,1.0f);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//
    glutMainLoop();
    return 0;
}


