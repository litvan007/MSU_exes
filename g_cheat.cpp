#include <iostream>

#include <cmath>

using namespace std;



int main()

{

    double x0,y0,r,A,B,C,x1,x2,y1,y2,x,y,D;

    cin>>x0>>y0>>r>>A>>B>>C;

    if (B!=0)

    {

            if (A!=0)

              {

             D = pow((2*C*A/(B*B)-2*x0+(2*y0*A/B)),2)-4*(x0*x0+C*C/(B*B)+2*C*y0/B+y0*y0-r*r)*(A*A/(B*B)+1);

            //cout<<D<<endl;

            if (D>=0){

                x1=(-(2*C*A/(B*B)-2*x0+2*A*y0/B)+sqrt(D))/(2*(A*A/(B*B)+1));

            x2=(-(2*C*A/(B*B)-2*x0+2*A*y0/B)-sqrt(D))/(2*(A*A/(B*B)+1));

            y1=(-C-A*x1)/B;

            y2=(-C-A*x2)/B;

            if (x1==x2)

                printf("%d \n%.5lf %.5lf",1,x1,y1);

            else

                printf("%d \n%.5lf %.5lf \n%.5lf %.5lf",2,x1,y1,x2,y2);

            }

            else

                cout<<0;

            }

      else

        {

            //cout<<"here"<<endl;

            y=-C/B;

            D=4*x0*x0-4*(x0*x0-r*r+pow(y-y0,2));

            if (D>=0)

            {

                if (D==0)

                    printf("%d \n%.5lf %.5lf",1,x0,y);

                else

                {

                    x1=(2*x0+sqrt(D))/2;

                    x2=(2*x0-sqrt(D))/2;

                    printf("%d \n%.5lf %.5lf \n%.5lf %.5lf",2,x1,y,x2,y);

                }

            }

            else

                cout<<0;

        }

    }

    else

    {

        if (A!=0)

        {

        x=-C/A;

        D = 4*y0*y0-4*(y0*y0-r*r+pow(x-x0,2));

        if (D>=0)

        {

            if (D==0)

                printf("%d \n%.5lf %.5lf",1,x,y0);

            else

            {

                y1=(2*y0+sqrt(D))/2;

                y2=(2*y0-sqrt(D))/2;

                printf("%d \n%.5lf %.5lf \n%.5lf %.5lf",2,x,y1,x,y1);

            }

                }

        else

            cout<<0;

        }

        else

            cout<<0;

    }

    return 0;

}


