// Finding the mode or modes in a data set

#include <iostream>
#include <stdlib.h>

using namespace std;

#define N 100
void mode (double x[],int n);//prototype for mode function

int main (void)
{

        double x[N];
        int n=0,i=0;

    cout<<"Enter in as many as 100 values, when finished enter in -99"<<endl;
while(1)
       {
           n++;

           cin>>x[i];
           if (x[i]==-99)
           {
               break;
           }
            i++;
       }

        mode(x,n);//send the values of x[] and n to mode function

system ("PAUSE");
return (0);
}

//function defintion

void mode (double x[],int n)
{
    int y[N]={0};//Sets all arrays equal to 0
    int i,j,k,m,cnt,max=0,no_mode=0,mode_cnt=0;
    double num;

    for(k=0; k<n; k++)//Loop to count an array from left to right
{
    cnt=0;
    num=x[k];//Num will equal the value of array x[k]

    for(i=k; i<n; i++)//Nested loop to search for a value equal to x[k]
    {
        if(num==x[i])
            cnt++;//if a number is found that is equal to x[k] count will go up by one

    }
    y[k]=cnt;//The array y[k] is initialized the value of whatever count is after the nested loop
    if(cnt>=2)//If cnt is greater or equal to two then there must be atleast one mode, so no_mode goes up by one
    {
        no_mode++;
    }
}

if(no_mode==0)//after the for loops have excuted and still no_mode hasn't been incremented, there mustn't be a mode
{
    //Print there in no mode and return control to main
    cout<<"This data set has no modes\n"<<endl;
    return;
}
    for(j=0; j<n; j++)
//A loop to find the highest number in the array
    {
		if(y[j]>max)
        max=y[j];
    }
 for(m=0; m<n; m++)//This loop finds how many modes there are in the data set
{
    //If the max is equal to y[m] then that is a mode and mode_cnt is incremeted by one
    if(max==y[m])
        mode_cnt++;
}
cout<<"This data set has "<<mode_cnt<<" mode(s)"<<endl;//Prints out how many modes there are
    for(m=0; m<n; m++)
    {
        if(max==y[m])//If max is equal to y[m] then the same sub set of array x[] is the actual mode
        {

            cout<<"The value "<<x[m]<<" appeared "<<y[m]<<" times in the data set\n"<<endl;
        }
    }
return;
}
