#include <stdio.h>
#include <stdio.h>
int expres[10],coeres[10], n3;
int getPolynomial(int exp[], int coe[]) 
{
int coef, i=0, n;
printf("Enter highest power : ");
scanf("%d", &n);
while(n >= 0) 
{
printf("Enter coefficient of %d : ", n);
scanf("%d", &coef);
if(coef != 0) 
{
exp[i] = n;
coe[i] = coef;
i++;
}
n--;
}
return i;
}

void disp(int exp[],int coe[], int size) {
int i;
for(i=0; i<size; i++){
if(exp[i] == 0) {
printf("%d ", coe[i]);
}
else
{
    printf("%dx^%d ", coe[i], exp[i]);
if(i!=size-1)
{
printf(" + ");
}
}
}
}

void add(int coe1[], int exp1[], int coe2[], int exp2[], int n1, int n2)
{
int i,j,k=0;
for(i=0,j=0; (i<n1 && j<n2) ;)
{
if(exp1[i] == exp2[j]){
expres[k] = exp1[i];
coeres[k] = coe1[i] + coe2[j];
i++;j++;k++;
}
else if (exp1[i] < exp2[j]){
expres[k] = exp2[j];
coeres[k] = coe2[j];
j++;k++;
}
else
{
expres[k] = exp1[i];
coeres[k] = coe1[i];
i++;k++;
}
}
if(i<n1)
{
for( ;i<n1 ; i++,k++){
expres[k] = exp1[i];
coeres[k] = coe1[i];
}
}
else if(j<n2)
{
for( ;j<n2 ; j++,k++){
expres[k] = exp2[j];
coeres[k] = coe2[j];
}
}
n3 = k;
}

void main(){
int exp1[10],exp2[10],coe1[10],coe2[10], n1,n2,i;
printf("polynomial 1\n");
n1 = getPolynomial(exp1,coe1);
printf("polynomial 2\n");
n2 = getPolynomial(exp2,coe2);

printf("\n1st polynomial is \n");
disp(exp1,coe1,n1);
printf("\n2nd polynomial is \n");
disp(exp2,coe2,n2);
add(coe1,exp1,coe2,exp2,n1,n2);
printf("\nResult polynomial is \n");
disp(expres,coeres,n3);
}
