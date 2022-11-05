#include<iostream>
#include<stdlib.h>
#include<windows.h>
using namespace std;

int main()
{
	SetConsoleTitleA("FT300-Test3");
	int walls;
	float T1,T2,flux;
	char check='y';
	
	while((check=='y')||(check=='Y'))
	{
		system("CLS");
		cout<<"\t\t--------------------------------\n";
		cout<<"\t\t|     Assignment For Test-3    |\n";
		cout<<"\t\t|         Submitted by-        |\n";
		cout<<"\t\t|         Arindom Aich         |\n";
		cout<<"\t\t|       Roll No- CSB20072      |\n";
		cout<<"\t\t|Question: Find the temperature|\n";
		cout<<"\t\t|   at the junctions of walls  |\n"; 
		cout<<"\t\t|  using Fourier's Law of Heat |\n";
		cout<<"\t\t|          Conduction          |\n";
		cout<<"\t\t--------------------------------\n"; 
		cout<<"No. of walls:";
		cin>>walls;
		cout<<"\nTemperature 1(higher temp)(in deg C):";
		cin>>T1;
		cout<<"Temperature 2(lower temp)(in deg C):";
		cin>>T2;
			
		
		float *temp= new float(walls+1);
		float *r= new float(walls);
		float *l= new float(walls);
		float *k= new float(walls);
		float r_tot;
		//r= resistance     l=thickness		k=coefficient of thermal conductivity
			
		temp[0]=T1;
		temp[walls]=T2;
		r_tot=0;
			
		for(int i=0;i<walls;i++)
		{
			cout<<"\nthickness of wall "<<i+1<<"(in m): ";
			cin>>l[i];
			cout<<"conductivity of wall "<<i+1<<"(in W/m deg C): ";
			cin>>k[i];
				
			r[i]=l[i]/k[i];
				
		}
			
		for(int i=0;i<walls;i++)
			r_tot+=r[i];
				
		flux= (T1-T2)/r_tot;
			
		for(int i=1;i<walls;i++)
			temp[i]=temp[i-1]- (flux*r[i-1]);
			
		cout<<"\n";
		for(int i=1;i<walls;i++)
			cout<<"temperature of junction "<<i<<": "<<temp[i]<<" deg C\n";
		
		cout<<"\nDo you want to calculate again?(y/n): ";
		cin>>check;		
	}
	char ch;
	getchar();
	getchar();
	return 0;
	
}
