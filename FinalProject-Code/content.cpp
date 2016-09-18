#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<string.h>
using namespace std;
char* toLowerCase(char* str)
{	
	int differ = 'A'-'a';
	char ch;
	int ii = strlen(str);
	for (int i=0; i <ii;i++)
	{
		strncpy(&ch,str+i,1);
		if (ch>='A' && ch<='Z')
		{
			ch = ch-differ;
			memcpy(str+i,&ch,1);
		}
	}
	return str;
}
int main()
{
  char f[100][100];
  int count=0;
  ifstream fp("content.txt");
  string str;
  if(fp==NULL)
  {
	cout<<"content.txt not found\n";
    exit(1);
  }
  while(fp>>str)
  {
    strcpy(f[count],str.c_str());
    //printf("%s\n",f[count]);   
    count++;
  }
  //printf("%d\n",count);   
  fp.close();
  string s,s1,s2,cmn[100];
  char *m1,*m2;
  int count1,count2,count3,i,j,sim;
  double simi[count][count];
  for(int m=0;m<count;m++)
	    for(int n=0;n<count;n++)
          simi[m][n]=0;
  for(i=0;i<count-1;i++)
  {
    for(j=i+1;j<count;j++)
    {
      sim=0;    
      count1=0;
      ifstream fp1(f[i]);
      if(fp1==NULL)
      {
        cout<<f[i]<<" does not exist\n";
        exit(1);
      }
      ifstream fp("stopwords.txt");
      if(fp==NULL)
      {
        cout<<"stopwords.txt does not exist\n";
        exit(1);
      }
//stop: 
      while(fp1>>s1)
      {
          /*m1= toLowerCase((char*)s1.c_str());               
          while(fp>>s)
          {
          m2= toLowerCase((char*)s.c_str());
          cout<<m1<<"\t"<<m2<<"ashok"<<endl;
          if(strcmp(m2,m1)==0)
          {
          cout<<s1<<"ashok1"<<endl;
          system("pause");
          fp.close();
          goto stop;
          }
          }
          fp.close();*/
          count1++;
          count2=0;
          count3=0;
          //cout<<s1<<endl;
          //system("pause");
          ifstream fp2(f[j]);
          if(fp2==NULL)
          {
           cout<<f[j]<<" does not exist\n";
           exit(1);
          }
         while(fp2>>s2)
         {
                       count2++;
                       //cout<<s2<<endl;
                       if(s1==s2)
                       {
                       count3++;
                       continue;
                       }
         }
         if(count3!=0)
         {
                      sim++;
                      //cout<<s1<<endl;
                      fp2.close();
         }  
         simi[i][j]=(sim*1.0)/(count1+count2-sim);
         
      }
      /*printf("%s has",f[i]);
      cout<<count1<<"words"<<endl;
      printf("%s has",f[j]);
      cout<<count2<<"words"<<endl;
      system("pause");
      printf("%s %s cmn words ",f[i],f[j]);
      cout<<sim<<endl;*/
      //system("pause");
      fp1.close();
    }
    cout<<i<<endl;
    //system("pause");
  }
    FILE *m4 = fopen("content_sim.txt","w" );//similarity matrix
  for(i=0;i<count;i++)
  {
	for(j=0;j<count;j++)
	{
	    if(i==j)
	    {
         simi[i][j]=1.0;
         printf("%f\t",1-simi[i][j]);
         fprintf(m4,"%f\t",simi[i][j]);
        }
        else if(i>j)
        {
        simi[i][j]=simi[j][i];
        printf("%f\t",1-simi[i][j]);
        fprintf(m4,"%f\t",simi[i][j]);
        //cout<<" --------";
        }
        else
		{
        printf("%f\t",1-simi[i][j]);   
        fprintf(m4,"%f\t",simi[i][j]);
        }
    } 
    fprintf(m4,"\n");
    cout<<endl;  
  }
  fclose(m4);
  FILE *ml = fopen("results_content.txt","w" );
  for(i=0;i<count;i++)
  {
  for(j=0;j<count;j++)
  {
  if(i<j)
  fprintf(ml,"%f\n",1-simi[i][j]);     
  } 
  } 
    fclose(ml); 
    system("pause");
    return 0;
    exit(0);
}
