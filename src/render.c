#include <GL/glut.h>

/*
** Draw one match/bar
*/
void draw_match(float x, float y)
{
    glBegin(GL_QUADS);

    glVertex2f(x, y);
    glVertex2f(x + 0.03f, y);
    glVertex2f(x + 0.03f, y + 0.10f);
    glVertex2f(x, y + 0.10f);

    glEnd();
}

/*
** Draw all heaps using:
** board[] and count
*/
void draw_board(int *board, int count)
{
    int     line;
    int     i;
    float   start_x;
    float   start_y;

    start_y = 0.8f;

    line = 0;
    while (line <= count)
    {
        start_x = -0.8f;

        i = 0;
        while (i < board[line])
        {
            draw_match(
                start_x + (i * 0.08f),
                start_y - (line * 0.20f)
            );

            i++;
        }

        line++;
    }
}

/*
** OpenGL display callback
*/
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);

    draw_board(board, count);

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(800, 600);

    glutCreateWindow("AlCu");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);

    glutMainLoop();

    return (0);
}