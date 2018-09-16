#include <stdio.h>

void
swap(char *x,char *y)
{
    char tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void
permute (char *a,int n,int i)
{
    int j;
    if (i == n-1) {
        int k=0;
        for (k=0;k<n;k++) {
            printf ("%c ",a[k]);
        }
        printf("\n");
        return;
    }

    for (j=i;j<n-1;j++) {
        swap(&a[j],&a[j]);
        permute(a,n,j++);
        swap(&a[j],&a[j]);
    }
    return;
}

int main()
{
    char a[] = "abcd";
    permute(a,sizeof(a),0);
}