#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;
int main( )
{
int i=0,z=0,v=0,s=0;
float content_si=0.0,structure_si=0.0;
int lvl[100],lvl1[100][100],h[100];
char line[50];//node length < 50
char node[50][100],parent[50][100],node1[50][100][100],parent1[50][100][100],f[50][100];
float mat[100][100]={0},u;
FILE *fi = fopen ("structure.txt","r" );
//cout<<"Enter the value of structure weightage of dataset between 0 and 1 "<<endl;
//cin>>u;
if ( fi != NULL )
{
while ( fgets ( line, sizeof line, fi ) != NULL ) 
{
char *x;
x=&line[0];
while(*x!='\n')
x++;
*x='\0';
strcpy(f[z],line);
//printf("%s%d\n",f[z],z);//file names(exe. tot files 100 file name len <50)f[50][100]
z++;
}
fclose ( fi );
//system("pause");
}
else
{
printf("structure.txt file not found\n");
}
//printf("%d\n",z);//tot no of files(exe. 100)
//system("pause");
int j;
FILE *file1;
//for(int k=0;k<z;k++)
//printf("%s %d\n",f[k],k);
//system("pause");
for(int k=0;k<z;k++)
{
file1= fopen (f[k],"r" );
j=0;
if ( file1 != NULL )
{
//printf("%s file found %df\n",f[k],k);
//system("pause");
while ( fgets ( line, sizeof line, file1 ) != NULL ) 
{
lvl1[v][j]=atoi(line);
fgets ( line, sizeof line, file1 );
strcpy(node1[v][j],line);      
fgets ( line, sizeof line, file1 );
strcpy(parent1[v][j],line);      
//printf("%d\t%s\t%s\n",lvl1[v][j],node1[v][j],parent1[v][j]);//100 files 100 nodes in each 50 max len. of node 50X100X100
//system("pause");
j++;
}
fclose ( file1 );
h[v]=j;
//printf("%d\n",h[v]);//h[v] is the tot no of nodes in vth file
//system("pause");
v++;//tot no of files
}
else
{
printf("%s file not found%dn\n",f[k],k);
system("pause");
}
}
//system("pause");
//printf("%d\n",v);//tot no of files
int maxlvl1[100]={0};
for(int d=0;d<z;d++)
{
for(int k=0;k<h[d];k++)
{
if(lvl1[d][k]>maxlvl1[d])
maxlvl1[d]=lvl1[d][k];//max lvl in doc d
}
//printf("%d\n",maxlvl1[d]);
}
int l=1,tot1[100][5];
for(int d=0;d<v;d++)
{
for(int k=0;k<h[d];k++)
{
if(lvl1[d][k]==lvl1[d][k+1])
l++;
else
{
tot1[d][lvl1[d][k]]=l;//tot no of nodes in each lvl of doc d max lvls 5 5X100
//printf("%d\n",l);
l=1;
}
}
}
/*for(int k2=0;k2<v;k2++)
for(int k=0;k<maxlvl1[k2];k++)
{
printf("%d\n",tot1[k2][k+1]);
}*/
//FILE *m5 = fopen ("pro.txt","w" );
FILE *file;
ashok:
file=fopen (f[s],"r" );
//printf("%s\n",f[s]);
i=0;
if ( file != NULL )
{
while ( fgets ( line, sizeof line, file ) != NULL ) 
{
lvl[i]=atoi(line);
fgets ( line, sizeof line, file );
strcpy(node[i],line);      
fgets ( line, sizeof line, file );
strcpy(parent[i],line);      
//printf("%d\t%s\t%s\n",lvl[i],node[i],parent[i]);
i++;
}
fclose ( file );
}
else
{
printf("no3");
}
//printf("%d\n",i);//tot no of nodes in doc f[s]
int maxlvl=0;
for(int k=0;k<i;k++)
if(lvl[k]>maxlvl)
maxlvl=lvl[k];
//printf("%d\n",maxlvl);//max lvl in doc f[s]
int tot[5];
l=1;
for(int k=0;k<i;k++)
{
if(lvl[k]==lvl[k+1])
l++;
else
{
tot[lvl[k]]=l;//tot no of nodes in each lvl of doc f[s]
//printf("%d\n",l);
l=1;
}
}
/*for(int k=0;k<maxlvl;k++)
{
printf("%d\n",tot[k+1]);
}*/
int cmn[100][5]={0},diff[100][5]={0};
for(int k2=0;k2<v;k2++)
for(int k=0;k<i;k++)
{
for(int k1=0;k1<h[k2];k1++)
{
if((lvl[k]==lvl1[k2][k1])&&(strcmp(node[k],node1[k2][k1])==0)&&(strcmp(parent[k],parent1[k2][k1])==0))
{
cmn[k2][lvl[k]]++;
}
}
}
/*for(int k2=0;k2<v;k2++)
for(int k=0;k<maxlvl1[k2];k++)
{
printf("%d\n",cmn[k2][k+1]);
}*/
for(int k2=0;k2<v;k2++)
{
//printf("%s\n",f[k2]);
//fprintf(m5,"%s\n",f[k2]);
for(int k=0;(k<maxlvl)||(k<maxlvl1[k2]);k++)
{
diff[k2][k+1]=tot[k+1]+tot1[k2][k+1]-cmn[k2][k+1];
//printf("%d\t%d\t%d\n",k,cmn[k2][k+1],diff[k2][k+1]);
//system("pause");
//fprintf(m5,"%d\t%d\t%d\n",k,cmn[k2][k+1],diff[k2][k+1]);
}
}
int pwr;
float num[100]={0},dnum[100]={0};
for(int k2=0;k2<v;k2++)
for(int k=0;(k<maxlvl)&&(k<maxlvl1[k2]);k++)
{
pwr=maxlvl>maxlvl1[k2]?maxlvl1[k2]:maxlvl;
num[k2]=num[k2]+(cmn[k2][k+1])*(pow(2,pwr-1-k));
}
for(int k2=0;k2<v;k2++)
for(int k=0;(k<maxlvl)||(k<maxlvl1[k2]);k++)
{
pwr=maxlvl<maxlvl1[k2]?maxlvl1[k2]:maxlvl;
diff[k2][k+1]=tot[k+1]+tot1[k2][k+1]-cmn[k2][k+1];
dnum[k2]=dnum[k2]+(diff[k2][k+1])*(pow(2,pwr-1-k));
}
for(int k2=0;k2<v;k2++)
{     
//printf("%f\n",(num[k2])/(dnum[k2]));
mat[s][k2]=(num[k2])/(dnum[k2]);
if(s==k2)
mat[s][k2]=1.000000;
}
s++;
if(s<z)
goto ashok;
float flt;
FILE *m1 = fopen ("clusters.m","w" );
FILE *m2 = fopen ("results_content.txt","r");
FILE *m3 = fopen ("results_structure.txt","w");
FILE *m4 = fopen ("structure_sim.txt","w");//similarity matrix
FILE *m5 = fopen ("combined_sim.txt","w");
fprintf(m1,"%s\n","%n=input('Enter threshold value ')");
fprintf(m1,"%s\n","n=0.8");
fprintf(m1,"%s","A1 = [");
for(int k1=0;k1<v;k1++)
{
for(int k2=0;k2<v;k2++)
{
if(k1<k2)
{
fscanf(m2,"%f",&flt);
content_si+=1-flt;
fprintf(m1,"%f\t",flt);
fprintf(m3,"%f\n",1-mat[k1][k2]);
structure_si+=mat[k1][k2];
}
printf("%f\t",1-mat[k1][k2]);
}
printf("\n");
}
fclose(m2);
fclose(m3);
content_si=2*content_si+v;
structure_si=2*structure_si+v;
u=structure_si/(structure_si+content_si);
fprintf(m1,"%s\n"," ]");
fprintf(m1,"%s\n","squareform(A1)");
fprintf(m1,"%s\n","B1 = linkage(A1)");
//fclose(m2);
fprintf(m1,"%s","A2 = [");
for(int k1=0;k1<v;k1++)
{
for(int k2=0;k2<v;k2++)
{
fprintf(m4,"%f\t",mat[k1][k2]);
if(k1<k2)
{
fprintf(m1,"%f\t",1-mat[k1][k2]);
}
}
fprintf(m4,"\n");
}
fclose(m4);
fprintf(m1,"%s\n"," ]");
fprintf(m1,"%s\n","squareform(A2)");
fprintf(m1,"%s\n","B2 = linkage(A2)");
m2 = fopen ("results_content.txt","r");
fprintf(m1,"%s","A3 = [");
for(int k1=0;k1<v;k1++)
{
for(int k2=0;k2<v;k2++)
{
if(k1<k2)
{
fscanf(m2,"%f",&flt);
//fprintf(m4,"%f\n",(flt+1-mat[k1][k2])/2);
//fprintf(m1,"%f\t",(flt+1-mat[k1][k2])/2);
fprintf(m1,"%f\t",((1-u)*(flt))+((u)*(1-mat[k1][k2])));
fprintf(m5,"%f\t",((1-u)*(1-flt))+((u)*(mat[k1][k2])));

//fprintf(m1,"%f\t",flt);
//fprintf(m1,"%f\t",1-mat[k1][k2]);
}
}
fprintf(m5,"\n");
}
fclose(m5);
fprintf(m1,"%s\n"," ]");
fprintf(m1,"%s\n","squareform(A3)");
fprintf(m1,"%s\n","B3 = linkage(A3)");
fprintf(m1,"%s\n","subplot(3,1,1);");
fprintf(m1,"%s\n","[H1,T1] = dendrogram(B1,'colorthreshold','default');");
fprintf(m1,"%s\n","set(H1,'LineWidth',2)");
fprintf(m1,"%s\n","T1 = cluster(B1,'cutoff',n)");
fprintf(m1,"%s\n","x=[0:51]");
fprintf(m1,"%s\n","y=[n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n]");
fprintf(m1,"%s\n","line(x,y,'Color',[1 0 1],'LineWidth',1)");
fprintf(m1,"%s\n","xlabel('Document Indices')");
fprintf(m1,"%s\n","ylabel('1-Similarity Index')");
fprintf(m1,"%s\n","title('Content Based', 'FontWeight','bold')");
fprintf(m1,"%s\n","subplot(3,1,2);");
fprintf(m1,"%s\n","[H2,T2] = dendrogram(B2,'colorthreshold','default');");
fprintf(m1,"%s\n","set(H2,'LineWidth',2)");
fprintf(m1,"%s\n","T2 = cluster(B2,'cutoff',n)");
fprintf(m1,"%s\n","x=[0:51]");
fprintf(m1,"%s\n","y=[n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n]");
fprintf(m1,"%s\n","line(x,y,'Color',[1 0 1],'LineWidth',1)");
fprintf(m1,"%s\n","xlabel('Document Indices')");
fprintf(m1,"%s\n","ylabel('1-Similarity Index')");
fprintf(m1,"%s\n","title('Structure Based', 'FontWeight','bold')");
fprintf(m1,"%s\n","subplot(3,1,3);");
fprintf(m1,"%s\n","[H3,T3] = dendrogram(B3,'colorthreshold','default');");
fprintf(m1,"%s\n","set(H3,'LineWidth',2)");
fprintf(m1,"%s\n","T3 = cluster(B3,'cutoff',n)");
fprintf(m1,"%s\n","x=[0:51]");
fprintf(m1,"%s\n","y=[n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n n]");
fprintf(m1,"%s\n","line(x,y,'Color',[1 0 1],'LineWidth',1)");
fprintf(m1,"%s\n","xlabel('Document Indices')");
fprintf(m1,"%s\n","ylabel('1-Similarity Index')");
fprintf(m1,"%s\n","title('Combined Approach', 'FontWeight','bold')");
fclose(m1);
printf("content fraction %f\nstructure fraction %f\n",content_si/(content_si+structure_si),structure_si/(content_si+structure_si));
system("pause");
return 0;
}
















