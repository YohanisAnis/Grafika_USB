#include <iostream>
#include <GL/freeglut.h>
#include <cmath>

const int lebarJendela = 500;
const int tinggiJendela = 300;

void tampilan() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Setel warna latar belakang ke merah

    // Gambar latar belakang merah
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(lebarJendela, 0);
    glVertex2f(lebarJendela, tinggiJendela);
    glVertex2f(0, tinggiJendela);
    glEnd();

    glColor3f(1.0, 1.0, 0.0); // Setel warna ke kuning

    // Gambar bintang kuning
    glPushMatrix();
    glTranslatef(lebarJendela / 2, tinggiJendela / 2, 0); // Translasi ke tengah
    const float radiusLuar = 30;
    const float radiusDalam = 10;
    const int jumlahPoin = 5;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0); // Pusat bintang

    // Hitung koordinat titik-titik bintang
    for (int i = 0; i <= jumlahPoin; ++i) {
        float sudut = i * 2 * M_PI / jumlahPoin;
        float x = cos(sudut) * ((i % 2 == 0) ? radiusLuar : radiusDalam);
        float y = sin(sudut) * ((i % 2 == 0) ? radiusLuar : radiusDalam);
        glVertex2f(x, y);
    }

    glEnd();
    glPopMatrix();

    glFlush();
}

void inisialisasi() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Setel warna bersih ke hitam
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, lebarJendela, 0.0, tinggiJendela);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(lebarJendela, tinggiJendela);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bendera Vietnam");
    glutDisplayFunc(tampilan);

    inisialisasi();
    glutMainLoop();

    return 0;
}
