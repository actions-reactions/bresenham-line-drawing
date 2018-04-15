#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

int x1, y1, x2, y2, dx, dy, x, y, p0, p;

void display(void)
{
    /* clear all pixels */
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255, 0, 0);

    /* draw white polygon (rectangle) with corners at
     * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
     */

    int i;


    glColor3ub(255, 0, 0);


    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();

    p=p0;


    for(i=0; i<dx; i++)
    {
        printf("\nm= %f\n\n",(float)((y2-y1)/(x2-x1)));

        printf("dx= %d\n",dx);
        printf("dy= %d\n",dy);

        printf("(x,y): (%d,%d)",x,y);

        printf("\np= %d",p);

        glBegin(GL_POINTS);
        glVertex2d(x, y);
        glEnd();
        if (p < 0)
        {

            x = x + 1;
            y = y;
            p=p+2*dy;


        }
        else
        {


            x = x + 1;
            y = y + 1;
            p=p+2*dy-2*dx;



        }
    }






    /* don't wait!
     * start processing buffered OpenGL routines
     */
    glFlush();
}

void init(void)
{
    /* select clearing (background) color */
    glClearColor(0, 0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 800);
}

/*
 * Declare initial window size, position, and display mode
 * (single buffer and RGBA). Open window with "hello"
 * in its title bar. Call initialization routines.
 * Register callback function to display graphics.
 * Enter main loop and process events.
 */
int main(int argc, char** argv)
{

    printf("x1: ");
    scanf("%d", &x1);
    printf("y1: ");
    scanf("%d", &y1);
    printf("x2: ");
    scanf("%d", &x2);
    printf("y2: ");
    scanf("%d", &y2);

    x = x1;
    y = y1;

    dx = x2 - x1;
    dy = y2 - y1;

    p0 = 2*(y2-y1)-dx;



    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
