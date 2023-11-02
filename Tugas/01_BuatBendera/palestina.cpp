#include <GL/glut.h>

void benderaPalestina() {
    // Garis bendera hitam (di atas)
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.0, 0.66);
    glVertex2f(1.0, 0.66);
    glVertex2f(1.0, 1.0);
    glVertex2f(0.0, 1.0);
    glEnd();

    // Garis bendera putih (di tengah)
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.0, 0.33);
    glVertex2f(1.0, 0.33);
    glVertex2f(1.0, 0.66);
    glVertex2f(0.0, 0.66);
    glEnd();

    // Garis bendera hijau (hijau tua) (di bawah)
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.4, 0.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(1.0, 0.33);
    glVertex2f(0.0, 0.33);
    glEnd();

    // Segitiga merah muda (lebih besar)
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.3, 0.3); // Warna merah muda (rose)
    glVertex2f(0.0, 1);
    glVertex2f(0.350, 0.495); // Posisi sudut runcing segitiga yang lebih besar
    glVertex2f(0.0, 0.0);
    glEnd();
}

void display() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Latar belakang putih (RGBA: 1.0, 1.0, 1.0, 1.0)
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    benderaPalestina();
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0); // Skala bendera Palestina tetap 1:1
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Bendera Palestina");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}