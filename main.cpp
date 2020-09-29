#include<windows.h>
#include <GL/glut.h>

#include<bits/stdc++.h>
using namespace std;

#define PI acos(-1.0)  // 3.1415926535897932






/** Array For keeping data from File.txt **/


double tiles[4][2];

double pool_bed[3][6][2];

double bed_color[5][4];
double bed [5][4][2];
double bb[4];

double pool_1[34][2];
double pool_2[38][2];





/** Basic Circle Making Function **/

void circle(double r, double cx, double cy, double R, double G, double B, double O)
{
    glColor4d(R/255.0,G/255.0,B/255.0,O);
    glBegin(GL_POLYGON);
    for(int i =0 ; i <= 360 ; i ++)
        glVertex2d( cx +( cos(i*(PI/180.0))*r ), cy+( sin(i*(PI/180.0))*r ) );
    glEnd();
}




void init(void)
{
    /** For Opacity Enable **/
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );

    glClearColor(255/255.0,200/255.0,167/255.0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,420, 0,380);
}



void ZakariaHossainFoysal(void)
{
    glClear(GL_COLOR_BUFFER_BIT);




    /** Tiles **/


    for(int i = 0 ; i < 29 ; i ++)
    {
        for(int j = 0 ; j < 29 ; j ++)
        {
            glColor4d(255/255.0,219/255.0,183/255.0,1);

            glBegin(GL_POLYGON);
            for(int k = 0 ; k < 4 ; k ++)
                glVertex2d(tiles[k][0]+(18.5*j),tiles[k][1]-(20*i));
            glEnd();
        }
    }



    /** Beds **/

    for(int ii = 0 ; ii < 4 ; ii++)
    {
        glColor4d(0,0,0,.2);
        glBegin(GL_POLYGON);
        for(int i = 0 ; i < 4 ; i++)glVertex2d( bed[0][i][0]+3,bed[0][i][1]+bb[ii]+3);
        glEnd();

        for(int i = 0 ; i < 10 ; i ++)
        {
            if(i<5)
            {
                glColor4d(bed_color[i%5][0]/255.0,bed_color[i%5][1]/255.0,bed_color[i%5][2]/255.0,bed_color[i%5][3]);
                glBegin(GL_POLYGON);
            }
            else
            {

                glColor4d(0,0,0,1);
                glBegin(GL_LINE_LOOP);
            }
            for(int j = 0 ; j < 4 ; j ++)glVertex2d(bed[i%5][j][0],bed[i%5][j][1]+bb[ii]);
            glEnd();
        }
        glColor3d(1,1,1);
        glBegin(GL_POLYGON);
        for(int i = 0 ; i < 4 ; i++)glVertex2d( bed[4][i][0],bed[4][i][1]+bb[ii]);
        glEnd();
    }





    /** pool **/

    glColor3d(251/255.0,254/255.0,255/255.0);
    glBegin(GL_POLYGON);
    for(int k = 0 ; k < 34 ; k ++)
        glVertex2d( (pool_1[k][0]*1.05)-16.5, (pool_1[k][1]*1.03)-6.5 );
    glEnd();

    glColor3d(0,139/255.0,157/255.0);
    glBegin(GL_POLYGON);
    for(int k = 0 ; k < 34 ; k ++)
        glVertex2d(pool_1[k][0],pool_1[k][1]);
    glEnd();


    glColor4d(107/255.0,250/255.0,250/255.0,.5);
    glBegin(GL_POLYGON);
    for(int k = 0 ; k < 38 ; k ++)
        glVertex2d(pool_2[k][0],pool_2[k][1]);
    glEnd();







    /** table **/

    circle(11.47,136.66+1.5,111.65+1.5,0,0,0,.2);
    circle(11.47,136.66,111.65,255,255,255,1);
    circle(11.47,139.95+1.5,276.85+1.5,0,0,0,.2);
    circle(11.47,139.95,276.85,255,255,255,1);





    /** Umbrella **/

    double cx,cy,r =43.21;
    for(int j = 0 ; j < 2 ; j ++)
    {

        if(!j)
        {
            cx=89.46;
            cy=95.53;
        }
        else
        {
            cx=85.57;
            cy=250.22;
        }

        glBegin(GL_TRIANGLE_FAN);

        glColor4d(0,0,0,.2);
        glVertex2d(cx,cy);
        for(int i = 0 ; i <=360 ; i +=45)
            glVertex2d(cos(i*(PI/180.0))*r  + cx+5,sin(i*(PI/180.0))*r+cy+5);

        glEnd();



        glColor3d(1,1,1);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2d(cx,cy);
        for(int i = 0 ; i <=360 ; i +=45)
        {
            if(j == 0)glColor3d((i%255)/255.0,0,0);
            else glColor3d(0,0,(i%255)/255.0);
            glVertex2d(cos(i*(PI/180.0))*r  + cx,sin(i*(PI/180.0))*r+cy);
        }
        glEnd();

    }



    /** Ball **/


    double R = 233, G = 188, B = 11;
    cx = 36.5 ;
    cy = 176.06;
    for(double i = 11.35 ; i <= 21.73 ; i +=.5)
    {
        R = (i < (11.35+21.73)/2.0) ? R-( (255-233) / (21.73-11.35) / .5 / 2 ) : R+( (255-233) / (21.73-11.35) / .5 / 2);
        G = (i < (11.35+21.73)/2.0) ? G-( (255-188) / (21.73-11.35) / .5 / 2 ) : G+( (255-188) / (21.73-11.35) / .5 / 2);
        B = (i < (11.35+21.73)/2.0) ? B-( (255-11) / (21.73-11.35) / .5 / 2 ) : B+( (255-11) / (21.73-11.35) / .5 / 2);

        glColor3d(R/255.0,G/255.0,B/255.0);

        glBegin(GL_LINE_LOOP);
        for(int j = 0 ; j <= 360 ; j ++)
            glVertex2d( cos( j*(PI/180.0) )*i+cx, sin( j*(PI/180.0) )*i+cy );
        glEnd();
    }

    for(double i = 11.35 ; i <= 21.73 ; i +=.5)
    {
        glColor4d(0,0,0.0,.2);
        glBegin(GL_LINE_LOOP);
        for(int j = 0 ; j <= 360 ; j ++)
            glVertex2d( cos( j*(PI/180.0) )*i+cx+3.5, sin( j*(PI/180.0) )*i+cy+2 );
        glEnd();
    }


    /** pool_Bed **/

    for(int i = 0 ; i < 3 ; i ++){

        if(!i){
            glBegin(GL_POLYGON);
            glColor4d( 0,0,0,.15  );
            for(int j= 0 ; j < 6; j ++)glVertex2d(pool_bed[i][j][0]+8,pool_bed[i][j][1]-1);
            glEnd();
        }

        glBegin(GL_POLYGON);
        glColor3ub( 255, !i ? 244 : 255 , !i ? 4 : 255  );
        for(int j= 0 ; j < 4+(!i ? 2 : 0); j ++)glVertex2d(pool_bed[i][j][0],pool_bed[i][j][1]);
        glEnd();

        if(!i){
            glColor3ub(255,204,0);
            glBegin(GL_LINES);
            glVertex2d(pool_bed[i][2][0],pool_bed[i][2][1]);
            glVertex2d(pool_bed[i][5][0],pool_bed[i][5][1]);
            glEnd();
        }
    }





    glFlush();

}



void import_data()
{
    /** importing coordinates from a file **/

    freopen("D:\\code\\cpp\\OpenGL\\LabFinal_1\\data.txt","r",stdin);



    for(int i = 0 ; i < 4 ; i ++)cin >> tiles[i][0] >> tiles[i][1];
    for(int i = 0 ; i < 5 ; i ++)
    {
        for(int j = 0 ; j < 4 ; j ++)cin >> bed_color[i][j];
        for(int j = 0 ; j < 4 ; j ++)cin >> bed[i][j][0] >> bed[i][j][1];
    }
    for(int i = 0 ; i < 4 ; i ++)cin >> bb[i];

    for(int i = 0 ; i < 34 ; i ++)cin >> pool_1[i][0] >> pool_1[i][1];
    for(int i = 0 ; i < 38 ; i ++)cin >> pool_2[i][0] >> pool_2[i][1];

    for(int i = 0 ; i < 3 ; i ++)
        for(int j = 0 ; j < 4+(!i ? 2 : 0) ; j ++)cin >> pool_bed[i][j][0] >> pool_bed[i][j][1];
}





int main(int argc, char* argv[])
{
    import_data();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);

    glutInitWindowPosition(350, 35);
    glutInitWindowSize(756,684);
    glutCreateWindow("171-15-9556");

    init();
    glutDisplayFunc(ZakariaHossainFoysal);
    glutMainLoop();

    return 0;
}
