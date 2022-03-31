#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
double Px, Py, phi, a1, a2, a3, pi=22/7, Wx, Wy, theta1, theta2, theta3 ;

double toRadians(double phi)
{
    phi=(phi*pi)/180;
    return phi;
}

double getTheta2(double Wx,double Wy,double a1,double a2)
{
    double c2= (((Wx*Wx))+((Wy*Wy))-((a1*a1))-((a2*a2)))/(2*a1*a2);
    double s2= sqrt(1-(c2*c2));
    double tan=s2/c2;
    theta2= atan(tan);
    return(theta2);
}
int main()
{
cout<<"Enter x co-ordinate of the final position of the 3-R manipulator";
cin>>Px;
cout<<"\nEnter the y co-Ordinate of the final position of the 3-R manipulator";
cin>>Py;
cout<<"\nEnter the orientation of the end effector";
cin>>phi;
cout<<"\nEnter the 3 link lenghts";
cin>>a1>>a2>>a3;

phi=toRadians(phi);
Wx=Px-(a3*(cos(phi)));
Wy=Py-(a3*(sin(phi)));

theta2=getTheta2(Wx,Wy,a1,a2);

double s1=(Wy*(a1+a2*cos(theta2))-(a2*sin(theta2)*Wx))/(a1*a1 + a2*a2 + 2*a1*a2*cos(theta2));
double c1=(Wx*(a1+a2*cos(theta2)+(a2*sin(theta2)*Wy)))/(a1*a1 + a2*a2 + 2*a1*a2*cos(theta2));

theta1= atan(s1/c1);
theta3=phi-theta2-theta1;

cout<<"\nTheta 1 is "<< theta1;
cout<<"\nTheta 2 is "<< theta2;
cout<<"\nTheta 3 is "<< theta3;
}