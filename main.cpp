#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>


using namespace  std;
bool ca1=false;
bool ca2=false;
bool ca3=false;
bool ca4=false;
bool ro1=false;
bool ro2=false;
bool ro3=false;
bool ro4=false;
bool fullScreen=false;

// angle of rotation for the camera direction
float angle=0.0;
float _angle=90.0;
// actual vector representing the camera’s direction
float lx=0.0,lz=-1.0;
// XZ position of the camera
float x=16.0,z=28.0;

float b,c1,c2,c3,c4,r1,r2,r3,r4,bldl=0,s=1,ll=0.5,m=0,m1=0,bl1=1,bl2=1,bl3=1,bl4=1,z1=0,z2=0;



void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


void drawCircle(int x1, int y1, int radius)
{
	float x2, y2;
	float angle;
	glBegin(GL_POLYGON);
	for (angle = .1f; angle<360.0f; angle += 1.0f)
	{
		x2 = x1 + sin(angle)*radius;
		y2 = y1 + cos(angle)*radius;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void moon(){
    glPushMatrix();
    glColor3f(1, 1, s);
    glTranslatef(19, 0.7, -14.0);
	drawCircle(1, 5, 1);
	glPopMatrix();


}

void car1(){

glPushMatrix();

    glPushMatrix(); //Save the current state of transformations
    glTranslatef(18.3, 0.3, 1.0);
    glTranslatef(0.0, 0.0, c1); //Move to the center of the triangle
    glRotatef(180,0.0,1.0,0.0);


//Car body
         glBegin(GL_QUADS);        // Draw The Cube Using quads


    glPushMatrix();
    glColor3f(1.0,0.6,0.6);     // Color Blue
    glVertex3f( 0.15, 0.3,0.8);    // Top Right Of The Quad (Top)
    glVertex3f(-0.15, 0.3,0.8);    // Top Left Of The Quad (Top)
    glVertex3f(-0.15, 0.05, 0.8);    // Bottom Left Of The Quad (Top)
    glVertex3f( 0.15, 0.05, 0.8);    // Bottom Right Of The Quad (Top)

   glColor3f(1.0,0.6,0.6);   // Color Orange
    glVertex3f( 0.15, 0.3,-0.3);    // Top Right Of The Quad (Bottom)
    glVertex3f(-0.15, 0.3,-0.3);    // Top Left Of The Quad (Bottom)
    glVertex3f(-0.15, 0.05,-0.3);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( 0.15, 0.05,-0.3);    // Bottom Right Of The Quad (Bottom)

    //glColor3f(1.0f,0.0f,0.0f);    // Color Red
    glVertex3f(-0.15,0.05,0.8);    // Top Right Of The Quad (Front)
    glVertex3f( 0.15,0.05,0.8);    // Top Left Of The Quad (Front)
    glVertex3f( 0.15, 0.05,-0.3);    // Bottom Left Of The Quad (Front)
    glVertex3f(-0.15, 0.05,-0.3);    // Bottom Right Of The Quad (Front)

    glColor3f(0.8,0.8,0.8);    // Color Yellow
    glVertex3f(-0.15,0.3,0.8);    // Top Right Of The Quad (Back)
    glVertex3f(0.15,0.3,0.8);    // Top Left Of The Quad (Back)
    glVertex3f(0.15, 0.3,-0.3);    // Bottom Left Of The Quad (Back)
    glVertex3f( -0.15, 0.3,-0.3);    // Bottom Right Of The Quad (Back)

    glColor3f(1.0,0.4,0.4);    // Color Blue
    glVertex3f(-0.15, 0.3, 0.8);    // Top Right Of The Quad (Left)
    glVertex3f(-0.15, 0.05,0.8);    // Top Left Of The Quad (Left)
    glVertex3f(-0.15,0.05,-0.3);    // Bottom Left Of The Quad (Left)
    glVertex3f(-0.15,0.3, -0.3);    // Bottom Right Of The Quad (Left)

    glColor3f(1.0,0.4,0.4);    // Color Violet
    glVertex3f( 0.15, 0.05,0.8);    // Top Right Of The Quad (Right)
    glVertex3f( 0.15, 0.3, 0.8);    // Top Left Of The Quad (Right)
    glVertex3f( 0.15,0.3, -0.3);    // Bottom Left Of The Quad (Right)
    glVertex3f( 0.15,0.05,-0.3);    // Bottom Right Of The Quad (Right)


    glEnd();
    //Door
    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(-0.055,0.15,0.20);
    glutSolidCube(.2);
    glPopMatrix();

    //back window
    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(0.0,0.24,0.71);
    glScalef(1,0.5,1);
    glutSolidCube(.2);
    glPopMatrix();

    //front window
    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(0.0,0.23,-0.21);
    glScalef(1.12,0.6,1);
    glutSolidCube(.2);
    glPopMatrix();

    //windows l
    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(-0.12,0.20,0.7);
    glutSolidCube(.07);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(-0.12,0.20,0.5);
    glutSolidCube(.07);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(-0.12,0.20,-0.1);
    glutSolidCube(.07);
    glPopMatrix();

    //light back
    glPushMatrix();
    glColor3f(1.0,bl1,0.0);   //yellow light
    glTranslatef(0.11,0.11,0.8);
    glutSolidCube(.04);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,bl1,0.0);   //yellow light
    glTranslatef(-0.09,0.11,0.8);
    glutSolidCube(.04);
    glPopMatrix();

      //light front
    glPushMatrix();
    glColor3f(1.0,1.0,bldl);   //yellow light
    glTranslatef(0.11,0.11,-0.30);
    glutSolidCube(.04);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,bldl);   //yellow light
    glTranslatef(-0.09,0.11,-0.30);
    glutSolidCube(.04);
    glPopMatrix();

    //windows r
    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(0.12,0.20,0.7);
    glutSolidCube(.07);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(0.12,0.20,0.5);
    glutSolidCube(.07);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(0.12,0.20,0.1);
    glutSolidCube(.07);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(0.12,0.20,-0.1);
    glutSolidCube(.07);
    glPopMatrix();

    //wheel_left
     glPushMatrix();
    glColor3f(0.27,0.27,0.27);
    glTranslatef(-0.13,0.0,0.0);
    //glRotatef(-90,1.0,1.0,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutSolidTorus(.05, .05, 30, 30); //(GLdouble innerRadius,GLdouble outerRadius,GLint nsides, GLint rings);
    glPopMatrix();

    //wheel_right
     glPushMatrix();
    glColor3f(0.27,0.27,0.27);
    glTranslatef(0.13,0.0,0.0);
    //glRotatef(-90,1.0,1.0,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutSolidTorus(.05, .05, 30, 30); //(GLdouble innerRadius,GLdouble outerRadius,GLint nsides, GLint rings);
    glPopMatrix();

    //wheel_left1
     glPushMatrix();
    glColor3f(0.27,0.27,0.27);
    glTranslatef(-0.13,0.0,0.5);
    //glRotatef(-90,1.0,1.0,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutSolidTorus(.05, .05, 30, 30); //(GLdouble innerRadius,GLdouble outerRadius,GLint nsides, GLint rings);
    glPopMatrix();

    //wheel_right1
     glPushMatrix();
    glColor3f(0.27,0.27,0.27);
    glTranslatef(0.13,0.0,0.5);
    //glRotatef(-90,1.0,1.0,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutSolidTorus(.05, .05, 30, 30); //(GLdouble innerRadius,GLdouble outerRadius,GLint nsides, GLint rings);
    glPopMatrix();


if(m1==0){
        //light on
      glPushMatrix();
      glTranslatef(-0.09,0.11,-0.3);


      glColor4f(1.0, 1.0,0.0,0.8);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.1,-0.1,-0.5);
    glVertex3f(-0.1,-0.1,-0.5);

    glEnd();

    glPopMatrix();
     //light on
      glPushMatrix();
      glTranslatef(0.11,0.11,-0.3);


      glColor4f(1.0, 1.0,0.0,0.8);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.1,-0.1,-0.5);
    glVertex3f(-0.1,-0.1,-0.5);

    glEnd();

    glPopMatrix();



   glPopMatrix();
   }
   if(m1==1){
    glPopMatrix();
   }
glPopMatrix();
}

void car2(){

    glPushMatrix(); //Save the current state of transformations
    glTranslatef(15, 0.3, 1.0);
    glTranslatef(0.0, 0.0, c2); //Move to the center of the triangle


//Car body
         glBegin(GL_QUADS);        // Draw The Cube Using quads


    glPushMatrix();
    glColor3f(1.0,0.6,0.6);     // Color Blue
    glVertex3f( 0.15, 0.3,0.8);    // Top Right Of The Quad (Top)
    glVertex3f(-0.15, 0.3,0.8);    // Top Left Of The Quad (Top)
    glVertex3f(-0.15, 0.05, 0.8);    // Bottom Left Of The Quad (Top)
    glVertex3f( 0.15, 0.05, 0.8);    // Bottom Right Of The Quad (Top)

   glColor3f(1.0,0.6,0.6);   // Color Orange
    glVertex3f( 0.15, 0.3,-0.3);    // Top Right Of The Quad (Bottom)
    glVertex3f(-0.15, 0.3,-0.3);    // Top Left Of The Quad (Bottom)
    glVertex3f(-0.15, 0.05,-0.3);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( 0.15, 0.05,-0.3);    // Bottom Right Of The Quad (Bottom)

    //glColor3f(1.0f,0.0f,0.0f);    // Color Red
    glVertex3f(-0.15,0.05,0.8);    // Top Right Of The Quad (Front)
    glVertex3f( 0.15,0.05,0.8);    // Top Left Of The Quad (Front)
    glVertex3f( 0.15, 0.05,-0.3);    // Bottom Left Of The Quad (Front)
    glVertex3f(-0.15, 0.05,-0.3);    // Bottom Right Of The Quad (Front)

    glColor3f(0.8,0.8,0.8);    // Color Yellow
    glVertex3f(-0.15,0.3,0.8);    // Top Right Of The Quad (Back)
    glVertex3f(0.15,0.3,0.8);    // Top Left Of The Quad (Back)
    glVertex3f(0.15, 0.3,-0.3);    // Bottom Left Of The Quad (Back)
    glVertex3f( -0.15, 0.3,-0.3);    // Bottom Right Of The Quad (Back)

    glColor3f(1.0,0.4,0.4);    // Color Blue
    glVertex3f(-0.15, 0.3, 0.8);    // Top Right Of The Quad (Left)
    glVertex3f(-0.15, 0.05,0.8);    // Top Left Of The Quad (Left)
    glVertex3f(-0.15,0.05,-0.3);    // Bottom Left Of The Quad (Left)
    glVertex3f(-0.15,0.3, -0.3);    // Bottom Right Of The Quad (Left)

    glColor3f(1.0,0.4,0.4);    // Color Violet
    glVertex3f( 0.15, 0.05,0.8);    // Top Right Of The Quad (Right)
    glVertex3f( 0.15, 0.3, 0.8);    // Top Left Of The Quad (Right)
    glVertex3f( 0.15,0.3, -0.3);    // Bottom Left Of The Quad (Right)
    glVertex3f( 0.15,0.05,-0.3);    // Bottom Right Of The Quad (Right)


    glEnd();
    //Door
    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(-0.055,0.15,0.20);
    glutSolidCube(.2);
    glPopMatrix();

    //back window
    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(0.0,0.24,0.71);
    glScalef(1,0.5,1);
    glutSolidCube(.2);
    glPopMatrix();

    //front window
    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(0.0,0.23,-0.21);
    glScalef(1.12,0.6,1);
    glutSolidCube(.2);
    glPopMatrix();

    //windows l
    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(-0.12,0.20,0.7);
    glutSolidCube(.07);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(-0.12,0.20,0.5);
    glutSolidCube(.07);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(-0.12,0.20,-0.1);
    glutSolidCube(.07);
    glPopMatrix();

    //light back
    glPushMatrix();
    glColor3f(1.0,bl2,0.0);   //yellow light
    glTranslatef(0.11,0.11,0.8);
    glutSolidCube(.04);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,bl2,0.0);   //yellow light
    glTranslatef(-0.09,0.11,0.8);
    glutSolidCube(.04);
    glPopMatrix();

      //light front
    glPushMatrix();
    glColor3f(1.0,1.0,bldl);   //yellow light
    glTranslatef(0.11,0.11,-0.30);
    glutSolidCube(.04);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,bldl);   //yellow light
    glTranslatef(-0.09,0.11,-0.30);
    glutSolidCube(.04);
    glPopMatrix();

    //windows r
    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(0.12,0.20,0.7);
    glutSolidCube(.07);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(0.12,0.20,0.5);
    glutSolidCube(.07);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(0.12,0.20,0.1);
    glutSolidCube(.07);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,0.9,0.9);
    glTranslatef(0.12,0.20,-0.1);
    glutSolidCube(.07);
    glPopMatrix();

    //wheel_left
     glPushMatrix();
    glColor3f(0.27,0.27,0.27);
    glTranslatef(-0.13,0.0,0.0);
    //glRotatef(-90,1.0,1.0,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutSolidTorus(.05, .05, 30, 30); //(GLdouble innerRadius,GLdouble outerRadius,GLint nsides, GLint rings);
    glPopMatrix();

    //wheel_right
     glPushMatrix();
    glColor3f(0.27,0.27,0.27);
    glTranslatef(0.13,0.0,0.0);
    //glRotatef(-90,1.0,1.0,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutSolidTorus(.05, .05, 30, 30); //(GLdouble innerRadius,GLdouble outerRadius,GLint nsides, GLint rings);
    glPopMatrix();

    //wheel_left1
     glPushMatrix();
    glColor3f(0.27,0.27,0.27);
    glTranslatef(-0.13,0.0,0.5);
    //glRotatef(-90,1.0,1.0,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutSolidTorus(.05, .05, 30, 30); //(GLdouble innerRadius,GLdouble outerRadius,GLint nsides, GLint rings);
    glPopMatrix();

    //wheel_right1
     glPushMatrix();
    glColor3f(0.27,0.27,0.27);
    glTranslatef(0.13,0.0,0.5);
    //glRotatef(-90,1.0,1.0,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutSolidTorus(.05, .05, 30, 30); //(GLdouble innerRadius,GLdouble outerRadius,GLint nsides, GLint rings);
    glPopMatrix();


if(m1==0){
        //light on
      glPushMatrix();
      glTranslatef(-0.09,0.11,-0.3);


      glColor4f(1.0, 1.0,0.0,0.8);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.1,-0.1,-0.5);
    glVertex3f(-0.1,-0.1,-0.5);

    glEnd();

    glPopMatrix();
     //light on
      glPushMatrix();
      glTranslatef(0.11,0.11,-0.3);


      glColor4f(1.0, 1.0,0.0,0.8);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.1,-0.1,-0.5);
    glVertex3f(-0.1,-0.1,-0.5);

    glEnd();

    glPopMatrix();



   glPopMatrix();
   }
   if(m1==1){
    glPopMatrix();
   }

}

void car4(){

glPushMatrix();

    glPushMatrix(); //Save the current state of transformations
    glTranslatef(15.4, 0.3, 0.0);
    glScalef(.6,.4,.6);
    glTranslatef(0.0, 0.0, c4); //Move to the center of the triangle



//Car body
         glBegin(GL_QUADS);        // Draw The Cube Using quads


    glPushMatrix();
    glColor3f( 0.7,0.7,0.7);     // Color Blue
    glVertex3f( 0.15, 0.25,0.6);    // Top Right Of The Quad (Top)
    glVertex3f(-0.15, 0.25,0.6);    // Top Left Of The Quad (Top)
    glVertex3f(-0.15, 0.05, 0.8);    // Bottom Left Of The Quad (Top)
    glVertex3f( 0.15, 0.05, 0.8);    // Bottom Right Of The Quad (Top)

   glColor3f(0.7,0.7,0.7);   // Color Orange
    glVertex3f( 0.15, 0.25,-0.1);    // Top Right Of The Quad (Bottom)
    glVertex3f(-0.15, 0.25,-0.1);    // Top Left Of The Quad (Bottom)
    glVertex3f(-0.15, 0.05,-0.3);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( 0.15, 0.05,-0.3);    // Bottom Right Of The Quad (Bottom)

       // Color Red
    glVertex3f(-0.15,0.05,0.8);    // Top Right Of The Quad (Front)
    glVertex3f( 0.15,0.05,0.8);    // Top Left Of The Quad (Front)
    glVertex3f( 0.15, 0.05,-0.3);    // Bottom Left Of The Quad (Front)
    glVertex3f(-0.15, 0.05,-0.3);    // Bottom Right Of The Quad (Front)

    glColor3f(1.0,0.3,0.3);    // Color Yellow
    glVertex3f(-0.15,0.25,0.6);    // Top Right Of The Quad (Back)
    glVertex3f(0.15,0.25,0.6);    // Top Left Of The Quad (Back)
    glVertex3f(0.15, 0.25,-0.1);    // Bottom Left Of The Quad (Back)
    glVertex3f( -0.15, 0.25,-0.1);    // Bottom Right Of The Quad (Back)

    glColor3f(1.0,0.0,0.0);    // Color Blue
    glVertex3f(-0.15, 0.25, 0.6);    // Top Right Of The Quad (Left)
    glVertex3f(-0.15, 0.05,0.8);    // Top Left Of The Quad (Left)
    glVertex3f(-0.15,0.05,-0.3);    // Bottom Left Of The Quad (Left)
    glVertex3f(-0.15,0.25, -0.1);    // Bottom Right Of The Quad (Left)

    glColor3f(1.0,0.0,0.0);    // Color Violet
    glVertex3f( 0.15, 0.05,0.8);    // Top Right Of The Quad (Right)
    glVertex3f( 0.15, 0.25, 0.6);    // Top Left Of The Quad (Right)
    glVertex3f( 0.15,0.25, -0.1);    // Bottom Left Of The Quad (Right)
    glVertex3f( 0.15,0.05,-0.3);    // Bottom Right Of The Quad (Right)


    glEnd();

    glPushMatrix();
    glColor3f(1.0,0,0.0);
    glTranslatef(0.00,0.05,0.21);
    glScalef(0.35,0.1,1.2);
    glutSolidCube(.9);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1,1.0);
    glTranslatef(0.00,0.1,0.3);
    glScalef(0.36,0.2,0.2);
    glutSolidCube(.9);
    glPopMatrix();


    //light back
    glPushMatrix();
    glColor3f(1.0,bl4,0.0);   //yellow light
    glTranslatef(0.11,0.11,0.75);
    glutSolidCube(.04);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,bl4,0.0);   //yellow light
    glTranslatef(-0.09,0.11,0.75);
    glutSolidCube(.04);
    glPopMatrix();

      //light front
    glPushMatrix();
    glColor3f(1.0,1.0,bldl);
    glTranslatef(0.11,0.11,-0.28);
    glutSolidCube(.04);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,bldl);   //yellow light
    glTranslatef(-0.09,0.11,-0.28);
    glutSolidCube(.04);
    glPopMatrix();

    //wheel_left
     glPushMatrix();
    glColor3f(0.27,0.27,0.27);
    glTranslatef(-0.13,0.0,0.0);
    //glRotatef(-90,1.0,1.0,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutSolidTorus(.05, .05, 30, 30); //(GLdouble innerRadius,GLdouble outerRadius,GLint nsides, GLint rings);
    glPopMatrix();

    //wheel_right
     glPushMatrix();
    glColor3f(0.27,0.27,0.27);
    glTranslatef(0.13,0.0,0.0);
    //glRotatef(-90,1.0,1.0,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutSolidTorus(.05, .05, 30, 30); //(GLdouble innerRadius,GLdouble outerRadius,GLint nsides, GLint rings);
    glPopMatrix();

    //wheel_left1
     glPushMatrix();
    glColor3f(0.27,0.27,0.27);
    glTranslatef(-0.13,0.0,0.5);
    //glRotatef(-90,1.0,1.0,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutSolidTorus(.05, .05, 30, 30); //(GLdouble innerRadius,GLdouble outerRadius,GLint nsides, GLint rings);
    glPopMatrix();

    //wheel_right1
     glPushMatrix();
    glColor3f(0.27,0.27,0.27);
    glTranslatef(0.13,0.0,0.5);
    //glRotatef(-90,1.0,1.0,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutSolidTorus(.05, .05, 30, 30); //(GLdouble innerRadius,GLdouble outerRadius,GLint nsides, GLint rings);
    glPopMatrix();


if(m1==0){
        //light on
      glPushMatrix();
      glTranslatef(-0.09,0.11,-0.3);


      glColor4f(1.0, 1.0,0.0,0.8);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.1,-0.1,-0.5);
    glVertex3f(-0.1,-0.1,-0.5);

    glEnd();

    glPopMatrix();
     //light on
      glPushMatrix();
      glTranslatef(0.11,0.11,-0.3);


      glColor4f(1.0, 1.0,0.0,0.8);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.1,-0.1,-0.5);
    glVertex3f(-0.1,-0.1,-0.5);

    glEnd();

    glPopMatrix();



   glPopMatrix();
   }
   if(m1==1){
    glPopMatrix();
   }
glPopMatrix();
}

void car3(){

glPushMatrix();

    glPushMatrix(); //Save the current state of transformations
    glTranslatef(17.6, 0.3, 1.0);
    glTranslatef(0.0, 0.0, c3); //Move to the center of the triangle
    glRotatef(180,0.0,1.0,0.0);


//Car body
         glBegin(GL_QUADS);        // Draw The Cube Using quads


    glPushMatrix();
    glColor3f( 0.7,0.7,0.7);     // Color Blue
    glVertex3f( 0.15, 0.25,0.6);    // Top Right Of The Quad (Top)
    glVertex3f(-0.15, 0.25,0.6);    // Top Left Of The Quad (Top)
    glVertex3f(-0.15, 0.05, 0.8);    // Bottom Left Of The Quad (Top)
    glVertex3f( 0.15, 0.05, 0.8);    // Bottom Right Of The Quad (Top)

   glColor3f(0.7,0.7,0.7);   // Color Orange
    glVertex3f( 0.15, 0.25,-0.1);    // Top Right Of The Quad (Bottom)
    glVertex3f(-0.15, 0.25,-0.1);    // Top Left Of The Quad (Bottom)
    glVertex3f(-0.15, 0.05,-0.3);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( 0.15, 0.05,-0.3);    // Bottom Right Of The Quad (Bottom)

       // Color Red
    glVertex3f(-0.15,0.05,0.8);    // Top Right Of The Quad (Front)
    glVertex3f( 0.15,0.05,0.8);    // Top Left Of The Quad (Front)
    glVertex3f( 0.15, 0.05,-0.3);    // Bottom Left Of The Quad (Front)
    glVertex3f(-0.15, 0.05,-0.3);    // Bottom Right Of The Quad (Front)

    glColor3f(1.0,0.3,0.3);    // Color Yellow
    glVertex3f(-0.15,0.25,0.6);    // Top Right Of The Quad (Back)
    glVertex3f(0.15,0.25,0.6);    // Top Left Of The Quad (Back)
    glVertex3f(0.15, 0.25,-0.1);    // Bottom Left Of The Quad (Back)
    glVertex3f( -0.15, 0.25,-0.1);    // Bottom Right Of The Quad (Back)

    glColor3f(1.0,0.0,0.0);    // Color Blue
    glVertex3f(-0.15, 0.25, 0.6);    // Top Right Of The Quad (Left)
    glVertex3f(-0.15, 0.05,0.8);    // Top Left Of The Quad (Left)
    glVertex3f(-0.15,0.05,-0.3);    // Bottom Left Of The Quad (Left)
    glVertex3f(-0.15,0.25, -0.1);    // Bottom Right Of The Quad (Left)

    glColor3f(1.0,0.0,0.0);    // Color Violet
    glVertex3f( 0.15, 0.05,0.8);    // Top Right Of The Quad (Right)
    glVertex3f( 0.15, 0.25, 0.6);    // Top Left Of The Quad (Right)
    glVertex3f( 0.15,0.25, -0.1);    // Bottom Left Of The Quad (Right)
    glVertex3f( 0.15,0.05,-0.3);    // Bottom Right Of The Quad (Right)


    glEnd();

    glPushMatrix();
    glColor3f(1.0,0,0.0);
    glTranslatef(0.00,0.05,0.21);
    glScalef(0.35,0.1,1.2);
    glutSolidCube(.9);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1,1.0);
    glTranslatef(0.00,0.1,0.3);
    glScalef(0.36,0.2,0.2);
    glutSolidCube(.9);
    glPopMatrix();


    //light back
    glPushMatrix();
    glColor3f(1.0,bl3,0.0);   //yellow light
    glTranslatef(0.11,0.11,0.75);
    glutSolidCube(.04);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,bl3,0.0);   //yellow light
    glTranslatef(-0.09,0.11,0.75);
    glutSolidCube(.04);
    glPopMatrix();

      //light front
    glPushMatrix();
    glColor3f(1.0,1.0,bldl);
    glTranslatef(0.11,0.11,-0.28);
    glutSolidCube(.04);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,bldl);   //yellow light
    glTranslatef(-0.09,0.11,-0.28);
    glutSolidCube(.04);
    glPopMatrix();

    //wheel_left
     glPushMatrix();
    glColor3f(0.27,0.27,0.27);
    glTranslatef(-0.13,0.0,0.0);
    //glRotatef(-90,1.0,1.0,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutSolidTorus(.05, .05, 30, 30); //(GLdouble innerRadius,GLdouble outerRadius,GLint nsides, GLint rings);
    glPopMatrix();

    //wheel_right
     glPushMatrix();
    glColor3f(0.27,0.27,0.27);
    glTranslatef(0.13,0.0,0.0);
    //glRotatef(-90,1.0,1.0,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutSolidTorus(.05, .05, 30, 30); //(GLdouble innerRadius,GLdouble outerRadius,GLint nsides, GLint rings);
    glPopMatrix();

    //wheel_left1
     glPushMatrix();
    glColor3f(0.27,0.27,0.27);
    glTranslatef(-0.13,0.0,0.5);
    //glRotatef(-90,1.0,1.0,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutSolidTorus(.05, .05, 30, 30); //(GLdouble innerRadius,GLdouble outerRadius,GLint nsides, GLint rings);
    glPopMatrix();

    //wheel_right1
     glPushMatrix();
    glColor3f(0.27,0.27,0.27);
    glTranslatef(0.13,0.0,0.5);
    //glRotatef(-90,1.0,1.0,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutSolidTorus(.05, .05, 30, 30); //(GLdouble innerRadius,GLdouble outerRadius,GLint nsides, GLint rings);
    glPopMatrix();


if(m1==0){
        //light on
      glPushMatrix();
      glTranslatef(-0.09,0.11,-0.3);


      glColor4f(1.0, 1.0,0.0,0.8);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.1,-0.1,-0.5);
    glVertex3f(-0.1,-0.1,-0.5);

    glEnd();

    glPopMatrix();
     //light on
      glPushMatrix();
      glTranslatef(0.11,0.11,-0.3);


      glColor4f(1.0, 1.0,0.0,0.8);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.1,-0.1,-0.5);
    glVertex3f(-0.1,-0.1,-0.5);

    glEnd();

    glPopMatrix();



   glPopMatrix();
   }
   if(m1==1){
    glPopMatrix();
   }
glPopMatrix();
}
void robot1(){

    glPushMatrix();
    glTranslatef(20.44, 0.4, 10.2);
    glTranslatef(0.0, 0.0, r1);
    glScalef(0.2,0.2,0.2);


    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(-.25, 0.6, 0.0);
    //glRotatef(_angle, 0.0, 1.0, 0.0);
    glutSolidCube(.2);
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-0.05, -0.25, 0.0);
    glutSolidCube(.3);
    glTranslatef(0.1, 0.0, 0.0);
    glutSolidCube(.3);
    glTranslatef(0.0, -0.3, 0.0);
    glutSolidCube(.3);
    glTranslatef(-0.1, 0.0, 0.0);
    glutSolidCube(.3);
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(-0.2, 0.35, 0.0);
    glutSolidCube(.15);
    glTranslatef(0.0, -0.15, 0.0);
    glutSolidCube(.15);
    glTranslatef(0.5, 0.15, 0.0);
    glutSolidCube(.15);
    glTranslatef(0.0, -0.15, 0.0);
    glutSolidCube(.15);
    glColor3f(0.0, 1.0, 1.0);
    glTranslatef(0.01, -0.1, 0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);
    glTranslatef(0.0, -0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);

    glTranslatef(0.0, -0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, -0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, -0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);

    glTranslatef(-0.52, 0.0, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);

    glTranslatef(0.0, 0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);

    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.36, -0.3, -0.015);
    glutSolidCube(.15);
    glTranslatef(0.0, -0.15, 0.0);
    glutSolidCube(.15);

    glTranslatef(-0.2, 0.0, -0.0);
    glutSolidCube(.15);
    glTranslatef(0.0, 0.15, 0.0);
    glutSolidCube(.15);

    glColor3f(1.0, 0.0, 1.0);
    glTranslatef(0.00, -0.25, 0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);


    glTranslatef(0.00, -0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);


    glTranslatef(0.00, -0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);



    glTranslatef(0.00, -0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);



    glTranslatef(0.2, 0.0, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);

    glTranslatef(0.0, 0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);

    glPopMatrix();




    glPopMatrix();


}

void robot2(){

    glPushMatrix();
    glTranslatef(12.6, 0.4, 4);
    glTranslatef(0.0, 0.0, r2);
    glScalef(0.2,0.2,0.2);


    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(-.25, 0.6, 0.0);
    //glRotatef(_angle, 0.0, 1.0, 0.0);
    glutSolidCube(.2);
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-0.05, -0.25, 0.0);
    glutSolidCube(.3);
    glTranslatef(0.1, 0.0, 0.0);
    glutSolidCube(.3);
    glTranslatef(0.0, -0.3, 0.0);
    glutSolidCube(.3);
    glTranslatef(-0.1, 0.0, 0.0);
    glutSolidCube(.3);
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(-0.2, 0.35, 0.0);
    glutSolidCube(.15);
    glTranslatef(0.0, -0.15, 0.0);
    glutSolidCube(.15);
    glTranslatef(0.5, 0.15, 0.0);
    glutSolidCube(.15);
    glTranslatef(0.0, -0.15, 0.0);
    glutSolidCube(.15);
    glColor3f(0.0, 1.0, 1.0);
    glTranslatef(0.01, -0.1, 0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);
    glTranslatef(0.0, -0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);

    glTranslatef(0.0, -0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, -0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, -0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);

    glTranslatef(-0.52, 0.0, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);

    glTranslatef(0.0, 0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);

    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.36, -0.3, -0.015);
    glutSolidCube(.15);
    glTranslatef(0.0, -0.15, 0.0);
    glutSolidCube(.15);

    glTranslatef(-0.2, 0.0, -0.0);
    glutSolidCube(.15);
    glTranslatef(0.0, 0.15, 0.0);
    glutSolidCube(.15);

    glColor3f(1.0, 0.0, 1.0);
    glTranslatef(0.00, -0.25, 0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);


    glTranslatef(0.00, -0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);


    glTranslatef(0.00, -0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);



    glTranslatef(0.00, -0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);



    glTranslatef(0.2, 0.0, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);

    glTranslatef(0.0, 0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);

    glPopMatrix();




    glPopMatrix();


}

void robot3(){

    glPushMatrix();
    glTranslatef(24.1, 0.26, 5.2);
      glTranslatef(0.0, 0.0, r3);
    glScalef(0.2,0.2,0.2);


    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(-.25, 0.6, 0.0);
    //glRotatef(_angle, 0.0, 1.0, 0.0);
    glutSolidCube(.2);
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-0.05, -0.25, 0.0);
    glutSolidCube(.3);
    glTranslatef(0.1, 0.0, 0.0);
    glutSolidCube(.3);
    glTranslatef(0.0, -0.3, 0.0);
    glutSolidCube(.3);
    glTranslatef(-0.1, 0.0, 0.0);
    glutSolidCube(.3);
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(-0.2, 0.35, 0.0);
    glutSolidCube(.15);
    glTranslatef(0.0, -0.15, 0.0);
    glutSolidCube(.15);
    glTranslatef(0.5, 0.15, 0.0);
    glutSolidCube(.15);
    glTranslatef(0.0, -0.15, 0.0);
    glutSolidCube(.15);
    glColor3f(0.0, 1.0, 1.0);
    glTranslatef(0.01, -0.1, 0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);
    glTranslatef(0.0, -0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);

    glTranslatef(0.0, -0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, -0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, -0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);

    glTranslatef(-0.52, 0.0, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);

    glTranslatef(0.0, 0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);

    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.36, -0.3, -0.015);
    glutSolidCube(.15);
    glTranslatef(0.0, -0.15, 0.0);
    glutSolidCube(.15);

    glTranslatef(-0.2, 0.0, -0.0);
    glutSolidCube(.15);
    glTranslatef(0.0, 0.15, 0.0);
    glutSolidCube(.15);

    glColor3f(1.0, 0.0, 1.0);
    glTranslatef(0.00, -0.25, 0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);


    glTranslatef(0.00, -0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);


    glTranslatef(0.00, -0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);



    glTranslatef(0.00, -0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);



    glTranslatef(0.2, 0.0, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);

    glTranslatef(0.0, 0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);

    glPopMatrix();




    glPopMatrix();


}

void robot4(){

    glPushMatrix();
    glTranslatef(12.9d, 0.4, 17.2);
    glTranslatef(0.0, 0.0, r4);
    glScalef(0.2,0.2,0.2);


    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(-.25, 0.6, 0.0);
    //glRotatef(_angle, 0.0, 1.0, 0.0);
    glutSolidCube(.2);
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-0.05, -0.25, 0.0);
    glutSolidCube(.3);
    glTranslatef(0.1, 0.0, 0.0);
    glutSolidCube(.3);
    glTranslatef(0.0, -0.3, 0.0);
    glutSolidCube(.3);
    glTranslatef(-0.1, 0.0, 0.0);
    glutSolidCube(.3);
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(-0.2, 0.35, 0.0);
    glutSolidCube(.15);
    glTranslatef(0.0, -0.15, 0.0);
    glutSolidCube(.15);
    glTranslatef(0.5, 0.15, 0.0);
    glutSolidCube(.15);
    glTranslatef(0.0, -0.15, 0.0);
    glutSolidCube(.15);
    glColor3f(0.0, 1.0, 1.0);
    glTranslatef(0.01, -0.1, 0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);
    glTranslatef(0.0, -0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);

    glTranslatef(0.0, -0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, -0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, -0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);

    glTranslatef(-0.52, 0.0, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);

    glTranslatef(0.0, 0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.03, -0.015);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, -0.025);
    glutSolidCube(.05);
    glTranslatef(0.0, 0.0, 0.09);
    glutSolidCube(.05);

    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.36, -0.3, -0.015);
    glutSolidCube(.15);
    glTranslatef(0.0, -0.15, 0.0);
    glutSolidCube(.15);

    glTranslatef(-0.2, 0.0, -0.0);
    glutSolidCube(.15);
    glTranslatef(0.0, 0.15, 0.0);
    glutSolidCube(.15);

    glColor3f(1.0, 0.0, 1.0);
    glTranslatef(0.00, -0.25, 0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);


    glTranslatef(0.00, -0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);


    glTranslatef(0.00, -0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);



    glTranslatef(0.00, -0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);



    glTranslatef(0.2, 0.0, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);


    glTranslatef(0.0, 0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);

    glTranslatef(0.0, 0.05, 0.1);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);
    glTranslatef(0.00, 0.0, -0.05);
    glutSolidCube(.05);

    glPopMatrix();




    glPopMatrix();


}

void road_dvd(){

glPushMatrix(); //Save the current state of transformations
    glTranslatef(16.74, 0.0, 12.0);
    glScalef(0.5,0.5,1.0);

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,0.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,0.70);
    glutSolidCube(.5);
    glPopMatrix();
 glPopMatrix();

}

void road_cross1(){

glPushMatrix(); //Save the current state of transformations
    glTranslatef(4.6, 0.0, 6.0);
    glScalef(0.3,0.07,1.5);

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.01,0.70);
    glutSolidCube(.5);
    glPopMatrix();
 glPopMatrix();

}
void road_cross2(){

glPushMatrix(); //Save the current state of transformations
    glTranslatef(4.6, 0.0, 26.0);
    glScalef(0.3,0.07,1.5);

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.01,0.70);
    glutSolidCube(.5);
    glPopMatrix();
 glPopMatrix();

}


void footpathL(){

     glPushMatrix(); //Save the current state of transformations
    glTranslatef(12.65, 0.0, 12.0);
    glScalef(1.8,0.5,1.0);

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,0.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,0.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,1.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,1.70);
    glutSolidCube(.5);
    glPopMatrix();
      glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,2.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,2.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,3.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,3.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,4.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,4.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,5.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,5.70);
    glutSolidCube(.5);
    glPopMatrix();
      glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,6.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,6.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,7.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,7.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,8.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,8.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,9.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,9.70);
    glutSolidCube(.5);
    glPopMatrix();
      glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,10.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,10.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,11.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,11.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,12.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,12.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,13.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,13.70);
    glutSolidCube(.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,13.70);
    glutSolidCube(.5);
    glPopMatrix();




glPopMatrix();

glPushMatrix();
    glColor3f(0.6,0,0);
    glTranslatef(12.57, 0.2, 19.0);
    glScalef(1.6,0.1,28.0);
    glutSolidCube(.5);
    glPopMatrix();

}

void footpathR(){

     glPushMatrix(); //Save the current state of transformations
    glTranslatef(20.55, 0.0, 12.0);
    glScalef(1.8,0.5,1.0);

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,-3.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,-2.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,-2.20);
    glutSolidCube(.5);
    glPopMatrix();

   glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,-1.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,-1.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,-0.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,-0.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,0.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,0.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,1.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,1.70);
    glutSolidCube(.5);
    glPopMatrix();
      glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,2.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,2.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,3.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,3.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,4.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,4.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,5.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,5.70);
    glutSolidCube(.5);
    glPopMatrix();
      glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,6.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,6.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,7.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,7.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,8.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,8.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,9.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,9.70);
    glutSolidCube(.5);
    glPopMatrix();
      glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,10.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,10.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,11.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,11.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,12.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,12.70);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-0.055,0.15,13.20);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,13.70);
    glutSolidCube(.5);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.055,0.15,13.70);
    glutSolidCube(.5);
    glPopMatrix();




glPopMatrix();

glPushMatrix();
    glColor3f(0.6,0,0);
    glTranslatef(20.44, 0.2, 17.2);
    glScalef(1.6,0.1,34.9);
    glutSolidCube(.5);
    glPopMatrix();

}

void buildingR1() {

//Right side buildings
//Building 1____________________________________________________________
glPushMatrix();



    glTranslatef(22.0,0.1, 24.0);
    glScalef(3.0,2.0,3.0);
    glPushMatrix();
    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.0,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5);

    glScalef(1.0,0.15,1.0);

    glColor3f(0.0,1.0,0.90);
    glTranslatef(0.0,1.9,0.0);
    glutSolidCube(.5); //(GLdouble size)
    glPopMatrix();

//window1..ok1
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.1,0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.1,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
//door
glPushMatrix();
    glColor3f(0.7,0.7,0.7);
    glTranslatef(-0.153,0.2,0.0);
    glutSolidCube(.2); //(GLdouble size)
glPopMatrix();

//w-----ok1---
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.4,0.12);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.28,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,.25,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,.23,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.4,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.28,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.25,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.23,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
//------ok1----w
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.16,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.0,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();

//w--------
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.06,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.16,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();



	glPopMatrix();

//________________________________________________________________


//Building 2____________________________________________________________
glPushMatrix();



    glTranslatef(22.0,0.1, 22.0);
    glScalef(3.0,1.6,3.0);
    glPushMatrix();
    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.0,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5);

    glScalef(1.0,0.15,1.0);

    glColor3f(0.7,0.7,0.90);
    glTranslatef(0.0,1.9,0.0);
    glutSolidCube(.5); //(GLdouble size)
    glPopMatrix();

//window1..ok1
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.1,0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.1,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
//door
glPushMatrix();
    glColor3f(0.7,0.7,0.7);
    glTranslatef(-0.153,0.2,0.0);
    glutSolidCube(.2); //(GLdouble size)
glPopMatrix();

//w-----ok1---
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.4,0.12);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.28,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,.25,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,.23,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.4,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.28,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.25,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.23,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
//------ok1----w
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.16,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.0,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();

//w--------
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.06,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.16,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();



	glPopMatrix();

//________________________________________________________________


//Building 3____________________________________________________________
glPushMatrix();



    glTranslatef(22.0,0.1, 20.0);
    glScalef(3.0,2.0,3.0);
    glPushMatrix();
    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.0,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5);

    glScalef(1.0,0.15,1.0);

    glColor3f(1.0,0.0,0.3);
    glTranslatef(0.0,1.9,0.0);
    glutSolidCube(.5); //(GLdouble size)
    glPopMatrix();

//window1..ok1
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.1,0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.1,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
//door
glPushMatrix();
    glColor3f(0.7,0.7,0.7);
    glTranslatef(-0.153,0.2,0.0);
    glutSolidCube(.2); //(GLdouble size)
glPopMatrix();

//w-----ok1---
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.4,0.12);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.28,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,.25,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,.23,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.4,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.28,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.25,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.23,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
//------ok1----w
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.16,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.0,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();

//w--------
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.06,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.16,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();



	glPopMatrix();

//________________________________________________________________


//Building 4____________________________________________________________
glPushMatrix();



    glTranslatef(22.0,0.1, 18.0);
    glScalef(3.0,1.6,3.0);
    glPushMatrix();
    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.0,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5);

    glScalef(1.0,0.15,1.0);

    glColor3f(0.7,0.7,0.90);
    glTranslatef(0.0,1.9,0.0);
    glutSolidCube(.5); //(GLdouble size)
    glPopMatrix();

//window1..ok1
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.1,0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.1,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
//door
glPushMatrix();
    glColor3f(0.7,0.7,0.7);
    glTranslatef(-0.153,0.2,0.0);
    glutSolidCube(.2); //(GLdouble size)
glPopMatrix();

//w-----ok1---
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.4,0.12);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.28,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,.25,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,.23,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.4,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.28,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.25,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.23,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
//------ok1----w
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.16,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.0,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();

//w--------
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.06,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.16,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();



	glPopMatrix();

//________________________________________________________________


}

void buildingR2() {

//Building 1____________________________________________________________
glPushMatrix();



    glTranslatef(22.0,0.1, 16.0);
    glScalef(3.0,2.0,3.0);
    glPushMatrix();
    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.0,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5);

    glScalef(1.0,0.15,1.0);

    glColor3f(0.0,1.0,0.90);
    glTranslatef(0.0,1.9,0.0);
    glutSolidCube(.5); //(GLdouble size)
    glPopMatrix();

//window1..ok1
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.1,0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.1,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
//door
glPushMatrix();
    glColor3f(0.7,0.7,0.7);
    glTranslatef(-0.153,0.2,0.0);
    glutSolidCube(.2); //(GLdouble size)
glPopMatrix();

//w-----ok1---
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.4,0.12);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.28,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,.25,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,.23,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.4,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.28,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.25,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.23,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
//------ok1----w
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.16,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.0,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();

//w--------
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.06,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.16,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();



	glPopMatrix();

//________________________________________________________________


//Building 2____________________________________________________________
glPushMatrix();



    glTranslatef(22.0,0.1, 14.0);
    glScalef(3.0,1.6,3.0);
    glPushMatrix();
    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.0,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5);

    glScalef(1.0,0.15,1.0);

    glColor3f(0.7,0.7,0.90);
    glTranslatef(0.0,1.9,0.0);
    glutSolidCube(.5); //(GLdouble size)
    glPopMatrix();

//window1..ok1
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.1,0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.1,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
//door
glPushMatrix();
    glColor3f(0.7,0.7,0.7);
    glTranslatef(-0.153,0.2,0.0);
    glutSolidCube(.2); //(GLdouble size)
glPopMatrix();

//w-----ok1---
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.4,0.12);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.28,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,.25,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,.23,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.4,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.28,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.25,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.23,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();//------ok1----w
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.16,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.0,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();

//w--------
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.06,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.16,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();



	glPopMatrix();

//________________________________________________________________


//Building 3____________________________________________________________
glPushMatrix();



    glTranslatef(22.0,0.1, 12.0);
    glScalef(3.0,2.0,3.0);
    glPushMatrix();
    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.0,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5);

    glScalef(1.0,0.15,1.0);

    glColor3f(1.0,0.0,0.3);
    glTranslatef(0.0,1.9,0.0);
    glutSolidCube(.5); //(GLdouble size)
    glPopMatrix();

//window1..ok1
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.1,0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.1,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
//door
glPushMatrix();
    glColor3f(0.7,0.7,0.7);
    glTranslatef(-0.153,0.2,0.0);
    glutSolidCube(.2); //(GLdouble size)
glPopMatrix();

//w-----ok1---
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.4,0.12);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.28,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,.25,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,.23,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.4,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.28,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.25,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.23,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();//------ok1----w
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.16,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.0,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();

//w--------
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.06,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.16,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();



	glPopMatrix();

//________________________________________________________________


//Building 4____________________________________________________________
glPushMatrix();



    glTranslatef(22.0,0.1, 10.0);
    glScalef(3.0,1.6,3.0);
    glPushMatrix();
    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.0,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5);

    glScalef(1.0,0.15,1.0);

    glColor3f(0.7,0.7,0.90);
    glTranslatef(0.0,1.9,0.0);
    glutSolidCube(.5); //(GLdouble size)
    glPopMatrix();


//window1..ok1
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.2,0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.25,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.2,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.25,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();

//door
glPushMatrix();
    glColor3f(0.7,0.7,0.7);
    glTranslatef(-0.153,0.2,0.0);
    glutSolidCube(.2); //(GLdouble size)
glPopMatrix();

//w-----ok1---
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.4,0.12);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.28,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,.25,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,.23,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.4,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.28,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.25,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.23,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
//------ok1----w
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.16,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.0,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();

//w--------
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.06,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.16,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();



	glPopMatrix();

//________________________________________________________________






}

void buildingL1() {

//Right side buildings
//Building 1____________________________________________________________
glPushMatrix();



    glTranslatef(11.0,0.1, 24.0);
    glScalef(3.0,2.0,3.0);
    glPushMatrix();
    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.0,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5);

    glScalef(1.0,0.15,1.0);

    glColor3f(0.0,1.0,0.90);
    glTranslatef(0.0,1.9,0.0);
    glutSolidCube(.5); //(GLdouble size)
    glPopMatrix();
//door
glPushMatrix();
    glColor3f(0.7,0.7,0.7);
    glTranslatef(0.153,0.2,0.0);
    glutSolidCube(.2); //(GLdouble size)
glPopMatrix();
//window1..ok1
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.5,0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.15,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.25,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.5,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.15,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.25,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
//w-----ok1---
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.3,0.12);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.3,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
//w-----ok1---
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.3,0.12);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.3,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
//------ok1----w
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.16,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.0,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();

//w--------
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.06,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.16,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();



	glPopMatrix();

//________________________________________________________________


//Building 2____________________________________________________________
glPushMatrix();



    glTranslatef(11.0,0.1, 21.0);
    glScalef(3.0,1.6,3.0);
    glPushMatrix();
    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.0,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5);

    glScalef(1.0,0.15,1.0);

    glColor3f(0.7,0.7,0.90);
    glTranslatef(0.0,1.9,0.0);
    glutSolidCube(.5); //(GLdouble size)
    glPopMatrix();
//door
glPushMatrix();
    glColor3f(0.7,0.7,0.7);
    glTranslatef(0.153,0.2,0.0);
    glutSolidCube(.2); //(GLdouble size)
glPopMatrix();
//window1..ok1
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.5,0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.15,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.25,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.5,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.15,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.25,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
//w-----ok1---
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.3,0.12);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.3,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
//w-----ok1---
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.3,0.12);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.3,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
//------ok1----w
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.16,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.0,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();

//w--------
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.06,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.16,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();



	glPopMatrix();

//________________________________________________________________


//Building 3____________________________________________________________
glPushMatrix();



    glTranslatef(11.0,0.1, 17.0);
    glScalef(3.0,2.0,3.0);
    glPushMatrix();
    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.0,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5);

    glScalef(1.0,0.15,1.0);

    glColor3f(1.0,0.0,0.3);
    glTranslatef(0.0,1.9,0.0);
    glutSolidCube(.5); //(GLdouble size)
    glPopMatrix();
//door
glPushMatrix();
    glColor3f(0.7,0.7,0.7);
    glTranslatef(0.153,0.2,0.0);
    glutSolidCube(.2); //(GLdouble size)
glPopMatrix();
//window1..ok1
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.5,0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.15,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.25,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.5,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.15,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.25,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
//w-----ok1---
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.3,0.12);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.3,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
//w-----ok1---
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.3,0.12);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.3,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
//------ok1----w
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.16,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.0,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();

//w--------
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.06,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.16,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();



	glPopMatrix();

//________________________________________________________________


//Building 4____________________________________________________________
glPushMatrix();



    glTranslatef(11.0,0.1, 15.0);
    glScalef(3.0,1.6,3.0);
    glPushMatrix();
    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.0,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5); //(GLdouble size)

    glColor3f(0.85,0.80,0.85);
    glTranslatef(0.0,0.5,0.0);
    glutSolidCube(.5);

    glScalef(1.0,0.15,1.0);

    glColor3f(0.7,0.7,0.90);
    glTranslatef(0.0,1.9,0.0);
    glutSolidCube(.5); //(GLdouble size)
    glPopMatrix();
//door
glPushMatrix();
    glColor3f(0.7,0.7,0.7);
    glTranslatef(0.18,0.2,0.0);
    glutSolidCube(.2); //(GLdouble size)
glPopMatrix();
//window1..ok1
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.5,0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.15,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.25,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.22,0.5,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.15,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.25,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();
//w-----ok1---
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.3,0.12);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.22,0.3,-0.08);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
//------ok1----w
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.16,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();
glPushMatrix();
       glColor3f(0.95,0.95,bldl);
    glTranslatef(0.0,0.2,0.21);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)

glPopMatrix();

//w--------
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(0.06,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
    glPopMatrix();
glPushMatrix();
    glColor3f(0.95,0.95,bldl);
    glTranslatef(-0.16,0.1,-0.22);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.2,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.3,0.0);
    glutSolidCube(.1); //(GLdouble size)

    glTranslatef(0.0,0.35,0.0);
    glutSolidCube(.1); //(GLdouble size)
glPopMatrix();



	glPopMatrix();

//________________________________________________________________

}

void lamp(float b=1.0){
if(m1==0){
glPushMatrix();

    glTranslatef(16.7,0.0, 3.0);
    glScalef(2.0,2.6,0.70);
    glPushMatrix();
    glColor3f(0.69, 0.43, 0.314);


    glScalef(0.5,1,1.0);
    glutSolidCube(.10);

    glTranslatef(0.0,0.1, 0.0);
    glutSolidCube(.10);

    glTranslatef(0.0,0.1, 0.0);
    glutSolidCube(.10);

    glTranslatef(0.0,0.1, 0.0);
    glutSolidCube(.10);

    glTranslatef(0.0,0.1, 0.0);
    glutSolidCube(.10);

    glTranslatef(0.0,0.1, 0.0);
    glutSolidCube(.10);
 glPopMatrix();
glPushMatrix();


glPushMatrix();
     glColor3f(1.0, 0.0, 0.0);
    glTranslatef(-0.06,0.5, 0.0);
    glScalef(1.1,0.6,0.70);
    glutSolidCube(.06);
    glTranslatef(-0.06,0.0, 0.0);
    glutSolidCube(.06);
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(-0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(-0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(-0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(-0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(-0.06,0.0, 0.0);
    glutSolidCube(.06);
     glTranslatef(-0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(-0.06,0.0, 0.0);
    glutSolidCube(.06);
     glTranslatef(-0.06,0.0, 0.0);
    glutSolidCube(.06);
glPopMatrix();
glPushMatrix();

    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(0.06,0.5, 0.0);
    glScalef(1.1,0.6,0.70);
    glutSolidCube(.06);
    glTranslatef(0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(0.05,0.0, 0.0);
    glutSolidCube(.06);
     glTranslatef(0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(0.06,0.0, 0.0);
    glutSolidCube(.06);
     glTranslatef(0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(0.06,0.0, 0.0);
    glutSolidCube(.06);
glPopMatrix();
glPushMatrix();
    glColor3f(1.0, 1.0, b);
    glTranslatef(-0.5,0.47, 0.0);
    glutSolidCube(.04);
    glTranslatef(-0.03,0.0, 0.0);
    glutSolidCube(.04);
    glTranslatef(-0.02,0.0, 0.0);
    glutSolidCube(.04);
glPopMatrix();
glPushMatrix();
     glColor3f(1.0, 1.0, b);
    glTranslatef(0.5,0.47, 0.0);
    glutSolidCube(.04);
    glTranslatef(0.03,0.0, 0.0);
    glutSolidCube(.04);
    glTranslatef(0.02,0.0, 0.0);
    glutSolidCube(.04);
glPopMatrix();
glPopMatrix();
//______________________________
      glPushMatrix();
      glColor4f(1.0, 1.0,0.0,0.5);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.5,0.45,0.0);
    glVertex3f(-0.3,0.0,0.0);
    glVertex3f(-1.1,0.0,0.0);

    glEnd();

    glPopMatrix();

     glPushMatrix();
      glColor4f(1.0, 1.0,0.0,0.5);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.5,0.45,0.0);
    glVertex3f(0.3,0.0,0.0);
    glVertex3f(1.1,0.0,0.0);

    glEnd();

    glPopMatrix();


    glPopMatrix();

}
     if(m1==1){

        glPushMatrix();

    glTranslatef(16.7,0.0, 3.0);
    glScalef(2.0,2.6,0.70);
    glPushMatrix();
    glColor3f(0.69, 0.43, 0.314);


    glScalef(0.5,1,1.0);
    glutSolidCube(.10);

    glTranslatef(0.0,0.1, 0.0);
    glutSolidCube(.10);

    glTranslatef(0.0,0.1, 0.0);
    glutSolidCube(.10);

    glTranslatef(0.0,0.1, 0.0);
    glutSolidCube(.10);

    glTranslatef(0.0,0.1, 0.0);
    glutSolidCube(.10);

    glTranslatef(0.0,0.1, 0.0);
    glutSolidCube(.10);
    glPopMatrix();
    glPushMatrix();
     glColor3f(1.0, 0.0, 0.0);
    glTranslatef(-0.06,0.5, 0.0);
    glScalef(1.1,0.6,0.70);
    glutSolidCube(.06);
    glTranslatef(-0.06,0.0, 0.0);
    glutSolidCube(.06);
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(-0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(-0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(-0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(-0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(-0.06,0.0, 0.0);
    glutSolidCube(.06);
     glTranslatef(-0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(-0.06,0.0, 0.0);
    glutSolidCube(.06);
     glTranslatef(-0.06,0.0, 0.0);
    glutSolidCube(.06);
glPopMatrix();
glPushMatrix();

    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(0.06,0.5, 0.0);
    glScalef(1.1,0.6,0.70);
    glutSolidCube(.06);
    glTranslatef(0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(0.05,0.0, 0.0);
    glutSolidCube(.06);
     glTranslatef(0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(0.06,0.0, 0.0);
    glutSolidCube(.06);
     glTranslatef(0.06,0.0, 0.0);
    glutSolidCube(.06);
    glTranslatef(0.06,0.0, 0.0);
    glutSolidCube(.06);
glPopMatrix();
glPushMatrix();
    glColor3f(1.0, 1.0, b);
    glTranslatef(-0.5,0.47, 0.0);
    glutSolidCube(.04);
    glTranslatef(-0.03,0.0, 0.0);
    glutSolidCube(.04);
    glTranslatef(-0.02,0.0, 0.0);
    glutSolidCube(.04);
glPopMatrix();
glPushMatrix();
     glColor3f(1.0, 1.0, b);
    glTranslatef(0.5,0.47, 0.0);
    glutSolidCube(.04);
    glTranslatef(0.03,0.0, 0.0);
    glutSolidCube(.04);
    glTranslatef(0.02,0.0, 0.0);
    glutSolidCube(.04);
glPopMatrix();


    glPopMatrix();


     }




}

void wall_left(void)
{


    glBegin(GL_QUADS);        // Draw The Cube Using quads


    glPushMatrix();


    glColor3f(0.5,0.0,1.0);    // Color Blue
    glVertex3f(0.0,2.0,30);    // Top Right Of The Quad (Top)
    glVertex3f(0.0,2.0,0.0);    // Top Left Of The Quad (Top)
    glVertex3f(0.2,2.0,0.0);    // Bottom Left Of The Quad (Top)
    glVertex3f(0.2,2.0,30.0);    // Bottom Right Of The Quad (Top)

   // glColor3f(1.0f,0.5f,0.0f);    // Color Orange
    glVertex3f(0.2,2.0,30.0);    // Top Right Of The Quad (Bottom)
    glVertex3f(0.2,0.0,30.0);    // Top Left Of The Quad (Bottom)
    glVertex3f(0.2,0.0,0.0);    // Bottom Left Of The Quad (Bottom)
    glVertex3f(0.2,2.0,0.0);    // Bottom Right Of The Quad (Bottom)

    //glColor3f(1.0f,0.0f,0.0f);    // Color Red
    glVertex3f(0.0,2.0,0.0);    // Top Right Of The Quad (Front)
    glVertex3f(0.0,0.0,0.0);    // Top Left Of The Quad (Front)
    glVertex3f(0.0,0.0,30.0);    // Bottom Left Of The Quad (Front)
    glVertex3f(0.0,2.0,30.0);    // Bottom Right Of The Quad (Front)

    //glColor3f(1.0f,1.0f,0.0f);    // Color Yellow
    glVertex3f(0.0,0.0,0.0);    // Top Right Of The Quad (Back)
    glVertex3f(0.2,0.0,0.0);    // Top Left Of The Quad (Back)
    glVertex3f(0.2,0.0,30.0);    // Bottom Left Of The Quad (Back)
    glVertex3f(0.0,0.0,30.0);    // Bottom Right Of The Quad (Back)

    //glColor3f(0.0f,0.8f,1.0f);    // Color Blue
    glVertex3f(0.0,2.0,0.0);    // Top Right Of The Quad (Left)
    glVertex3f(0.2,2.0,0.0);    // Top Left Of The Quad (Left)
    glVertex3f(0.0,0.0,0.0);    // Bottom Left Of The Quad (Left)
    glVertex3f(0.2,0.0,0.0);    // Bottom Right Of The Quad (Left)

    //glColor3f(1.0f,0.0f,1.0f);    // Color Violet
    glVertex3f(0.0,2.0,30.0);    // Top Right Of The Quad (Right)
    glVertex3f(0.2,2.0,30.0);    // Top Left Of The Quad (Right)
    glVertex3f(0.0,0.0,30.0);    // Bottom Left Of The Quad (Right)
    glVertex3f(0.2,0.0,30.0);    // Bottom Right Of The Quad (Right)


    glEnd();            // End Drawing The Cube
    glPopMatrix();
glFlush();
}

void wall_left1(){

    glPushMatrix(); //Save the current state of transformations
    glTranslatef(11.0, 0.0, 28.0);
    glScalef(0.1,1.8,3.5);

    glPushMatrix();
    glColor3f(0.2,0.4,0.6);
    glTranslatef(-6.9, 0.1, 0.33);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.4,0.6);
     glTranslatef(-6.9, 0.1, -0.75);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.4,0.6);
    glTranslatef(-6.9, 0.1, -1.53);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.4,0.6);
     glTranslatef(-6.9, 0.1, -3.35);
     glScalef(1,1,7.5);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.4,0.6);
    glTranslatef(-6.9, 0.1, -7.0);
    glScalef(1,1,3.5);
    glutSolidCube(.5);
    glPopMatrix();

glPopMatrix();
//Gate1
glPushMatrix();
    glTranslatef(11.0, 0.0, 28.0);

    glPushMatrix();
    glColor3f(0.8,0.4,0.6);
    glTranslatef(-0.68, 0.4, -1.66);
    glScalef(.4,3,.4);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,0.4,0.6);
    glTranslatef(-0.68, 0.4, 0.2);
    glScalef(.4,3,.4);
    glutSolidCube(.5);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.8,0.4,0.6);
    glTranslatef(-0.68, 1.15, -0.68);
    glScalef(1.4,0.1,5);
    glutSolidCube(.5);
    glPopMatrix();

         glPushMatrix();
    glColor3f(0.8,0.4,0.6);
    glTranslatef(-0.68, 1.3, -0.68);
    glScalef(1.4,0.5,3.5);
    glutSolidCube(.5);
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.8,0.4,0.6);
    glTranslatef(-0.68, 1.5, -0.68);
    glScalef(1.4,0.5,2.5);
    glutSolidCube(.5);
    glPopMatrix();


glPopMatrix();

//gate 2
glPushMatrix();
    glTranslatef(11.0, 0.0, 9.25);
     glScalef(1.0,1.2,1.57);

    glPushMatrix();
    glColor3f(0.8,0.4,0.6);
    glTranslatef(-0.68, 0.4, -1.66);
    glScalef(.4,3,.4);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,0.4,0.6);
    glTranslatef(-0.68, 0.4, 0.2);
    glScalef(.4,3,.4);
    glutSolidCube(.5);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.8,0.4,0.6);
    glTranslatef(-0.68, 1.15, -0.68);
    glScalef(1.4,0.1,5);
    glutSolidCube(.5);
    glPopMatrix();

         glPushMatrix();
    glColor3f(0.8,0.4,0.6);
    glTranslatef(-0.68, 1.3, -0.7);
    glScalef(1.4,0.5,3.5);
    glutSolidCube(.5);
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.8,0.4,0.6);
    glTranslatef(-0.68, 1.5, -0.7);
    glScalef(1.4,0.5,2.5);
    glutSolidCube(.5);
    glPopMatrix();


glPopMatrix();

}

void wall_right1(){

    glPushMatrix(); //Save the current state of transformations
    glTranslatef(4, 0.1, -.5);
    glScalef(16.8,1.8,0.1);

    glPushMatrix();
    glColor3f(0.2,0.4,0.6);
    glTranslatef(0, 0.2, 0.0);
    glutSolidCube(.8);
    glPopMatrix();



glPopMatrix();


}

void field(){

    glPushMatrix(); //Save the current state of transformations
    glTranslatef(6, 0.1, 15);
    glScalef(2,0.04,6);

    glPushMatrix();
    glColor3f(0.8,0.7,0.7);
    glTranslatef(0, 0.2, 0.0);
    glutSolidCube(.8);
    glPopMatrix();
glPopMatrix();

  glPushMatrix(); //Save the current state of transformations
    glTranslatef(6, 0.13, 16.9);
    glScalef(2.3,0.04,0.002);

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(0, 0.2, 0.0);
    glutSolidCube(.8);
    glPopMatrix();
glPopMatrix();

 glPushMatrix(); //Save the current state of transformations
    glTranslatef(6, 0.13, 13.9);
    glScalef(2.3,0.04,0.002);

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(0, 0.2, 0.0);
    glutSolidCube(.8);
    glPopMatrix();
glPopMatrix();

 glPushMatrix(); //Save the current state of transformations
    glTranslatef(6, 0.13, 12.9);
    glScalef(0.03,0.6,0.03);

    glPushMatrix();
    glColor3f(1.0,0.0,0.0);
    glTranslatef(0, 0.2, 0.0);
    glutSolidCube(.8);
    glPopMatrix();
glPopMatrix();
//stamp
 glPushMatrix(); //Save the current state of transformations
    glTranslatef(6.1, 0.13, 12.9);
    glScalef(0.03,0.6,0.03);

    glPushMatrix();
    glColor3f(1.0,0.0,0.0);
    glTranslatef(0, 0.2, 0.0);
    glutSolidCube(.8);
    glPopMatrix();
glPopMatrix();

 glPushMatrix(); //Save the current state of transformations
    glTranslatef(6.2, 0.13, 12.9);
    glScalef(0.03,0.6,0.03);

    glPushMatrix();
    glColor3f(1.0,0.0,0.0);
    glTranslatef(0, 0.2, 0.0);
    glutSolidCube(.8);
    glPopMatrix();
glPopMatrix();

//park road
  glPushMatrix(); //Save the current state of transformations
    glTranslatef(24, 0.1, 16);
    glScalef(1,0.04,28);

    glPushMatrix();
    glColor3f(0.8,0.7,0.7);
    glTranslatef(0, 0.2, 0.0);
    glutSolidCube(.8);
    glPopMatrix();
glPopMatrix();

glPushMatrix(); //Save the current state of transformations
    glTranslatef(27, 0.1, 16);
    glScalef(1,0.04,28);

    glPushMatrix();
    glColor3f(0.8,0.7,0.7);
    glTranslatef(0, 0.2, 0.0);
    glutSolidCube(.8);
    glPopMatrix();
glPopMatrix();

glPushMatrix(); //Save the current state of transformations
    glTranslatef(25.5, 0.1, 4.8);
    glScalef(5,0.04,1);

    glPushMatrix();
    glColor3f(0.8,0.7,0.7);
    glTranslatef(0, 0.2, 0.0);
    glutSolidCube(.8);
    glPopMatrix();
glPopMatrix();
glPushMatrix(); //Save the current state of transformations
    glTranslatef(25.5, 0.1, 26.8);
    glScalef(5,0.04,1);

    glPushMatrix();
    glColor3f(0.8,0.7,0.7);
    glTranslatef(0, 0.2, 0.0);
    glutSolidCube(.8);
    glPopMatrix();
glPopMatrix();

}
void wall_right2(){

    glPushMatrix(); //Save the current state of transformations
    glTranslatef(28, 0.1, -.5);
    glScalef(16.8,1.8,0.1);

    glPushMatrix();
    glColor3f(0.2,0.4,0.6);
    glTranslatef(0, 0.2, 0.0);
    glutSolidCube(.8);
    glPopMatrix();

glPopMatrix();

   glPushMatrix(); //Save the current state of transformations
    glTranslatef(30, 0.1, 16.0);
    glScalef(0.1,1.9,40.0);

    glPushMatrix();
    glColor3f(0.2,0.4,0.6);
    glTranslatef(0, 0.2, 0.0);
    glutSolidCube(.8);
    glPopMatrix();

glPopMatrix();

glPushMatrix(); //Save the current state of transformations
    glTranslatef(28, 0.1, 29.5);
    glScalef(16.8,1.8,0.1);

    glPushMatrix();
    glColor3f(0.2,0.4,0.6);
    glTranslatef(0, 0.2, 0.0);
    glutSolidCube(.8);
    glPopMatrix();

glPopMatrix();

glPushMatrix(); //Save the current state of transformations
    glTranslatef(4, 0.1, 29.5);
    glScalef(16.8,1.8,0.1);

    glPushMatrix();
    glColor3f(0.2,0.4,0.6);
    glTranslatef(0, 0.2, 0.0);
    glutSolidCube(.8);
    glPopMatrix();

glPopMatrix();

}


void wall_right(){

    glPushMatrix(); //Save the current state of transformations
    glTranslatef(23.4, 0.0, 28.0);
    glScalef(0.1,1.8,3.5);

    glPushMatrix();
    glColor3f(0.2,0.4,0.6);
    glTranslatef(-6.9, 0.1, 0.33);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.4,0.6);
     glTranslatef(-6.9, 0.1, -0.75);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.4,0.6);
    glTranslatef(-6.9, 0.1, -1.53);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.4,0.6);
     glTranslatef(-6.9, 0.1, -3.35);
     glScalef(1,1,7.5);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.4,0.6);
    glTranslatef(-6.9, 0.1, -6.6);
    glScalef(1,1,5);
    glutSolidCube(.5);
    glPopMatrix();

glPopMatrix();
//Gate1
glPushMatrix();
    glTranslatef(23.4, 0.0, 28.0);

    glPushMatrix();
    glColor3f(0.8,0.4,0.6);
    glTranslatef(-0.68, 0.4, -1.66);
    glScalef(.4,3,.4);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,0.4,0.6);
    glTranslatef(-0.68, 0.4, 0.2);
    glScalef(.4,3,.4);
    glutSolidCube(.5);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.8,0.4,0.6);
    glTranslatef(-0.68, 1.15, -0.68);
    glScalef(1.4,0.1,5);
    glutSolidCube(.5);
    glPopMatrix();

         glPushMatrix();
    glColor3f(0.8,0.4,0.6);
    glTranslatef(-0.68, 1.3, -0.7);
    glScalef(1.4,0.5,3.5);
    glutSolidCube(.5);
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.8,0.4,0.6);
    glTranslatef(-0.68, 1.5, -0.72);
    glScalef(1.4,0.5,2.5);
    glutSolidCube(.5);
    glPopMatrix();


glPopMatrix();


}

void bus_stopR(){

    glPushMatrix(); //Save the current state of transformations


//chauni
glPushMatrix();
    glTranslatef(21.4, 0.0, 6.0);

    glPushMatrix();
    glColor3f(0.8,0.6,0.6);
    glTranslatef(-0.68, 0.4, -2.0);
    glScalef(.4,1.5,.2);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    //glColor3f(0.8,0.4,0.6);
    glTranslatef(-0.68, 0.4, 0.2);
    glScalef(.4,1.5,.2);
    glutSolidCube(.5);
    glPopMatrix();

     glPushMatrix();
    //glColor3f(0.8,0.4,0.6);
    glTranslatef(0.68, 0.4, -2.0);
    glScalef(.4,1.5,.2);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    //glColor3f(0.8,0.4,0.6);
    glTranslatef(0.68, 0.4, 0.2);
    glScalef(.4,1.5,.2);
    glutSolidCube(.5);
    glPopMatrix();
//floor
     glPushMatrix();
    glColor3f(0.3,0.4,0.3);
    glTranslatef(0.0, 0.01, -0.9);
    glScalef(2.9,0.1,5);
    glutSolidCube(.5);
    glPopMatrix();
   //chad
    glPushMatrix();
    glColor3f(0.6,0.6,0.6);
    glTranslatef(0.0, 0.8, -0.9);
    glScalef(3.2,0.1,5);
    glutSolidCube(.5);
    glPopMatrix();

//chair
    glPushMatrix();
    glColor3f(0.4,0.2,0.2);
    glTranslatef(0.0, 0.1, -0.9);
    glScalef(0.1,1.2,4);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,0.2,0.2);
    glTranslatef(0.0, 0.1, -0.9);
    glScalef(0.7,0.5,4);
    glutSolidCube(.5);
    glPopMatrix();




glPopMatrix();
glPopMatrix();


}
void bus_stopL(){

    glPushMatrix(); //Save the current state of transformations


//chauni
glPushMatrix();
    glTranslatef(11.4, 0.0, 6.0);

    glPushMatrix();
    glColor3f(0.8,0.6,0.6);
    glTranslatef(-0.68, 0.4, -2.0);
    glScalef(.4,1.5,.2);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    //glColor3f(0.8,0.4,0.6);
    glTranslatef(-0.68, 0.4, 0.2);
    glScalef(.4,1.5,.2);
    glutSolidCube(.5);
    glPopMatrix();

     glPushMatrix();
    //glColor3f(0.8,0.4,0.6);
    glTranslatef(0.68, 0.4, -2.0);
    glScalef(.4,1.5,.2);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    //glColor3f(0.8,0.4,0.6);
    glTranslatef(0.68, 0.4, 0.2);
    glScalef(.4,1.5,.2);
    glutSolidCube(.5);
    glPopMatrix();
//floor
     glPushMatrix();
    glColor3f(0.3,0.4,0.3);
    glTranslatef(0.0, 0.01, -0.9);
    glScalef(2.9,0.1,5);
    glutSolidCube(.5);
    glPopMatrix();
   //chad
    glPushMatrix();
    glColor3f(0.6,0.6,0.6);
    glTranslatef(0.0, 0.8, -0.9);
    glScalef(3.2,0.1,5);
    glutSolidCube(.5);
    glPopMatrix();

//chair
    glPushMatrix();
    glColor3f(0.4,0.2,0.2);
    glTranslatef(0.0, 0.1, -0.9);
    glScalef(0.1,1.2,4);
    glutSolidCube(.5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,0.2,0.2);
    glTranslatef(0.0, 0.1, -0.9);
    glScalef(0.7,0.5,4);
    glutSolidCube(.5);
    glPopMatrix();




glPopMatrix();
glPopMatrix();


}

void mode(){
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
  if(m==1){
    glClearColor(0.0,0.0,0.0,1.0);
    glClearColor(0.2,0.3,0.8,1.0);
}
  if(m==0){
    glClearColor(0.0,0.0,0.0,1.0);
    glClearColor(0.0,0.0,0.0,1.0);

}
}

void tree1(){

    	 //Move forward 5 units

  glPushMatrix();

      glTranslatef(1.0, 1.3, 1.0);
      glScalef(1.2,2,1.2);

    glPushMatrix();
    glColor3f(0.0,0.50,0.0);
    glTranslatef(0.0,-0.20,0.0);
    glRotatef(-90,1.0,0.0,0.0);
    //glRotatef(_angle,1.0,1.0,0.0);
    glutSolidCone(.25,.50,15,15); //(GLdouble base, GLdouble height,GLint slices, GLint stacks);
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.0,0.50,0.0);
    glTranslatef(0.0,0.0,0.0);
    glRotatef(-90,1.0,0.0,0.0);
    //glRotatef(_angle,1.0,1.0,0.0);
    glutSolidCone(.25,.50,15,15); //(GLdouble base, GLdouble height,GLint slices, GLint stacks);
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.0,0.50,0.0);
    glTranslatef(0.0,0.2,0.0);
    glRotatef(-90,1.0,0.0,0.0);
    //glRotatef(_angle,1.0,1.0,0.0);
    glutSolidCone(.25,.50,15,15); //(GLdouble base, GLdouble height,GLint slices, GLint stacks);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.5,0.50,0.5);
    glTranslatef(0.0,-0.24,0.0);
    glRotatef(-90,1.0,0.0,0.0);
    //glRotatef(_angle,1.0,1.0,0.0);
    glutSolidCube(.12); //(GLdouble base, GLdouble height,GLint slices, GLint stacks);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glTranslatef(0.0,-0.36,0.0);
    glRotatef(-90,1.0,0.0,0.0);
    //glRotatef(_angle,1.0,1.0,0.0);
    glutSolidCube(.12); //(GLdouble base, GLdouble height,GLint slices, GLint stacks);
    glPopMatrix();
     glPushMatrix();
    glColor3f(0.5,0.50,0.5);
    glTranslatef(0.0,-0.48,0.0);
    glRotatef(-90,1.0,0.0,0.0);
    //glRotatef(_angle,1.0,1.0,0.0);
    glutSolidCube(.12); //(GLdouble base, GLdouble height,GLint slices, GLint stacks);
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.5,0.50,0.5);
    glTranslatef(0.0,-0.58,0.0);
    glRotatef(-90,1.0,0.0,0.0);
    //glRotatef(_angle,1.0,1.0,0.0);
    glutSolidCube(.12); //(GLdouble base, GLdouble height,GLint slices, GLint stacks);
    glPopMatrix();


	glPopMatrix();



}

void tree2(){

	glPushMatrix();

	glTranslatef(25.5,0.6,7.0);
	glScalef(.7,0.5,.7);

    glPushMatrix();
    glColor3f(1.0,1,1);
    glColor3f(0.0,.5,.0);
    glTranslatef(0.0,0.0,0.0);
    glRotatef(50,0.0,1.0,0.0);
    glutSolidSphere(.20,07,10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1,1);
    glColor3f(0.0,.5,.0);
    glTranslatef(0.0,0.1,0.0);
    glRotatef(-10,0.0,1.0,1.0);
    glutSolidSphere(.20,13,20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1,1);
    glColor3f(0.0,.5,.0);
    glTranslatef(0.2,0.1,0.0);
    glRotatef(90,0.0,1.0,1.0);
    glutSolidSphere(.20,13,20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1,1);
    glColor3f(0.0,.5,.0);
    glTranslatef(-0.2,0.1,0.0);
    glRotatef(90,0.0,1.0,1.0);
    glutSolidSphere(.20,13,20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1,1);
    glColor3f(0.0,.5,.0);
    glTranslatef(0.0,0.1,0.2);
    glRotatef(90,0.0,1.0,1.0);
    glutSolidSphere(.20,13,20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1,1);
    glColor3f(0.0,.5,.0);
    glTranslatef(0.0,0.1,-0.2);
    glRotatef(90,0.0,1.0,1.0);
    glutSolidSphere(.20,13,20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.6,0.3,0.3);
    glTranslatef(0.0,-0.2,0.0);
    glutSolidCube(.1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.6,0.3,0.3);
    glTranslatef(0.0,-0.3,0.0);
    glutSolidCube(.1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.6,0.3,0.3);
    glTranslatef(0.0,-0.4,0.0);
    glutSolidCube(.1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.6,0.3,0.3);
    glTranslatef(0.0,-0.5,0.0);
    glutSolidCube(.1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.6,0.3,0.3);
    glTranslatef(0.0,-0.6,0.0);
    glutSolidCube(.1);
    glPopMatrix();

 glPopMatrix();



}


void roadside(){

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(18,0.0, 16);
    glutSolidCube(.2);
    glPopMatrix();



}

void renderScene(void) {

// Clear Color and Depth Buffers


 mode();

// Reset transformations
glLoadIdentity();
// Set the camera
gluLookAt( x, 1.1f, z,
x+lx, 1.0f, z+lz,
0.0f, 2.0f, 0.0f);


glPushMatrix();

//car1

 car1();

 car2();
car3();
car4();
//moon

 moon();

 //Robot
 robot1();
 robot2();
 robot3();
 robot4();

field();
//wall left

wall_left();

wall_left1();

wall_right();
wall_right1();
wall_right2();


bus_stopR();
bus_stopL();

// Draw ground
glPushMatrix();
glColor3f(0.0f, 0.9f, 0.0f);
glBegin(GL_QUADS);
glVertex3f(0.0f, 0.0, 0.0f);
glVertex3f(0.0f, 0.0, 30.0f);
glVertex3f( 30.0f, 0.0, 30.0f);
glVertex3f( 30.0f, 0.0, 0.0f);
glEnd();
glPopMatrix();

// Draw road
glPushMatrix();
glColor3f(0.04, 0.04, 0.04);
glBegin(GL_QUADS);
glVertex3f(13.0f, 0.01, 0.0f);
glVertex3f(13.0f, 0.01, 30.0f);
glVertex3f( 20.0f, 0.01, 30.0f);
glVertex3f( 20.0f, 0.01, 0.0f);
glEnd();
glPopMatrix();


// Draw bldng
buildingR1();
buildingR2();
buildingL1();

//Road art right
for(int j=-14; j < 14; j++) {
glPushMatrix();
glTranslatef(1.8,-0.08,j * 1.0);
roadside();

glPopMatrix();
}

//Road art left
for(int j=-14; j < 14; j++) {
glPushMatrix();
glTranslatef(-4.8,-0.08,j * 1.0);
roadside();

glPopMatrix();
}

tree1();

for(int j=-1; j < 18; j++) {
        glPushMatrix();
        glTranslatef(0.0,0,j * 1.0);
        tree2();
        glPopMatrix();
}

// Draw lamp
//for(int i = -1; i < 1; i++)
for(int j=3; j < 7; j++) {
glPushMatrix();
glTranslatef(0.0,0,j * 3.5);
lamp(b);
glPopMatrix();
}
glPushMatrix();
//road devider
for(int j=-4; j < 14; j++) {
    glPushMatrix();
glTranslatef(0.0,0,j * 1.0);
road_dvd();
glPopMatrix();
}

for(int j=-12; j < -6; j++) {
    glPushMatrix();
glTranslatef(0.0,0,j * 1.0);
road_dvd();
glPopMatrix();
}
for(int j=16; j < 18; j++) {
    glPushMatrix();
glTranslatef(0.0,0,j * 1.0);
road_dvd();
glPopMatrix();

}
glPopMatrix();
//road cross
for(int j=12; j < 19; j++) {
    glPushMatrix();
glTranslatef(j*0.8,0,0.0);
road_cross1();
glPopMatrix();
}
//road cross
for(int j=12; j < 19; j++) {
    glPushMatrix();
glTranslatef(j*0.8,0,0.0);
road_cross2();
glPopMatrix();
}


//tree
for(int j=1; j < 16; j++) {
    glPushMatrix();
glTranslatef(j*0.8,0,0.0);
tree1();
glPopMatrix();
}

for(int j=24; j < 36; j++) {
    glPushMatrix();
glTranslatef(j*0.8,0,0.0);
tree1();
glPopMatrix();
}

for(int j=1; j < 37; j++) {
    glPushMatrix();

glTranslatef(28.40,0,j*0.8);
tree1();
glPopMatrix();
}
for(int j=24; j < 36; j++) {
    glPushMatrix();

glTranslatef(j*0.8,0,28.5);
tree1();
glPopMatrix();
}

//footpath left
footpathL();

//footpath Right
footpathR();

glPopMatrix();

glutSwapBuffers();
}

void update(int value) {
 //car 1

    if(!ca1){
        c1+= (0.03f+z1);

    if (c1 > 28) {
        c1 -= 26;

    }
    }
    //car2
    if(!ca2){
    c2-= 0.03f;
    if (c2<1) {
        c2 += 26;
    }
    }
    //car 3

    if(!ca3){
        c3+= 0.04f;

    if (c3 > 28) {
        c3 -= 26;

    }
    }
    //car4
    if(!ca4){
    c4-= (0.06f + z2);
    if (c4<2) {
        c4 += 42;
    }
    }
    //robot 1
    if(!ro1){
        r1+= 0.006f;
    if (r1 > 13) {
        r1 -= 13;

    }
    }
    //robot 2
    if(!ro2){
    r2-= 0.007f;
    if (r2<9) {
        r2 += 13;
    }
    }

    if(!ro3){
    r3-= 0.01f;
    if (r3<4) {
        r3 += 17.6;
    }
    }
     if(!ro4){
        r4+= 0.006f;
    if (r4 > 8) {
        r4 -= 10;

    }
    }

    glutPostRedisplay(); //Tell GLUT that the display has changed

    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(25, update, 0);
}


void keyboard(unsigned char key, int x, int y)
{
if(key=='d'){
    b=1.0;
    bldl=1.0;
    ll=0.0;
    s=0.0;
    m=1;
    m1=1;
}
if(key=='n'){
    b=0.0;
    bldl=0.0;
    ll=0.5;
    s=1.0;
    m=0;
    m1=0;
}
if(key=='p'){
    ca1=true;
    bl1=0.0;
}
if(key=='P'){
    ca1=false;
    bl1=1.0;
}
if(key=='o'){
    ca2=true;
    bl2=0.0;
}
if(key=='O'){
    ca2=false;
    bl2=1.0;
}
if(key=='i'){
    ca3=true;
    bl3=0.0;
}
if(key=='I'){
    ca3=false;
    bl3=1.0;
}
if(key=='u'){
    ca4=true;
    bl4=0.0;
}
if(key=='U'){
    ca4=false;
    bl4=1.0;
}

if(key=='l'){
    ro1=true;
}
if(key=='z'){
    z1=0.04f;
}
if(key=='Z'){
    z1=0;
}
if(key=='x'){
    z2=0.04f;
}
if(key=='X'){
    z2=0;
}


if(key=='L'){
    ro1=false;
}

if(key=='k'){
    ro2=true;
}


if(key=='K'){
    ro2=false;
}

if(key=='j'){
    ro3=true;
}


if(key=='J'){
    ro3=false;
}

if(key=='h'){
    ro4=true;
}


if(key=='H'){
    ro4=false;
}

    if(key=='f'){ //toggle screenmode
    fullScreen = !fullScreen;
    if (!fullScreen) {
        glutFullScreen();
    } else {
        glutReshapeWindow(1200, 900);
        glutPositionWindow(10,50);

    }
    }


//default:
//break;
}



void changeSize(int w, int h) {

// Prevent a divide by zero, when window is too short
// (you cant make a window of zero width).
if (h == 0)
h = 1;
float ratio = w * 1.0 / h;

// Use the Projection Matrix
glMatrixMode(GL_PROJECTION);

// Reset Matrix
glLoadIdentity();

// Set the viewport to be the entire window
glViewport(0, 0, w, h);

// Set the correct perspective.
gluPerspective(45.0f, ratio, 0.1f, 100.0f);

// Get Back to the Modelview
glMatrixMode(GL_MODELVIEW);
}

void processNormalKeys(unsigned char key, int x, int y) {

if (key == 27)
exit(0);
}

void processSpecialKeys(int key, int xx, int yy) {

float fraction = 0.2f;

switch (key) {
case GLUT_KEY_LEFT :
angle -= 0.03f;
lx = sin(angle);
lz = -cos(angle);
break;
case GLUT_KEY_RIGHT :
angle += 0.03f;
lx = sin(angle);
lz = -cos(angle);
break;
case GLUT_KEY_UP :

x += lx * fraction;
z += lz * fraction;
if(x<=3){
    x=3;
}
else if(x>=27){x=27;}
else if(z<=3){z=3;}
else if(z>=27){z=27;}

break;
case GLUT_KEY_DOWN :

x -= lx * fraction;
z -= lz * fraction;
if(x<=3){
        x=3;
}
else if(x>=27){x=27;}
else if(z>=27){z=27;}
else if(z<=3){z=3;}
break;
}


}

int main(int argc, char **argv) {
//to hide console

// init GLUT and create window

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

glutInitWindowSize(1224,1000);
glutCreateWindow("Urvan View");
initRendering();
glutInitWindowPosition(100,100);
// register callbacks
glutDisplayFunc(renderScene);
glutReshapeFunc(changeSize);
glutIdleFunc(renderScene);
glutKeyboardFunc(processNormalKeys);
glutSpecialFunc(processSpecialKeys);
glutKeyboardFunc(keyboard);


glutFullScreen();
glutTimerFunc(25, update, 0); //Add a timer



// OpenGL init
glEnable(GL_DEPTH_TEST);

// enter GLUT event processing cycle
glutMainLoop();

}
