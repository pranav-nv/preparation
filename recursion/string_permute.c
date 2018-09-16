
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
print_a(char a[],int n)
{
    int k=0;
    for (k=0;k<n;k++) {
        printf ("%c ",a[k]);
    }
    printf("\n");
}

void
permute (char *a,int n,int i)
{
    int j;

    if (i == n-1) {
        print_a(a,n);
        return;
    }

    for (j=i;j<n;j++) {
        swap(&a[j],&a[i]);
        permute(a,n,i+1);
        swap(&a[j],&a[i]);
    }
    return;
}

int main()
{
    char a[] = "abcd";
    permute(a,4,0);
}
