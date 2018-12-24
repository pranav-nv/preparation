#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <new>

void
printSubset (char *str,
             int len,
             int start,
             char *str_out,
             int str_out_len,
             char **string_array_out,
             int *result_size)
{
    if (start >= len ) {
        str_out[str_out_len] = 0;
        char *s_copy_out = (char *)malloc(strlen(str_out+1));
        strcpy(s_copy_out,str_out);
        string_array_out[*result_size] = s_copy_out;
        (*result_size)++;
        return;
    }
    str_out[str_out_len] = str[start]; //include char
    printSubset(str, len, start + 1, str_out, str_out_len+1,string_array_out,result_size);
    str_out[str_out_len] = 0;
    printSubset(str, len, start + 1, str_out, str_out_len,string_array_out,result_size);
}

char **
generate_all_subsets (char* s, int* result_size)
{
    int len = strlen(s);
    char *string_out = (char *)malloc(len+1);
    char **string_array_out = (char **)malloc((2 << len)*sizeof(char *));
    *result_size = 0;
    printSubset(s, len, 0, string_out, 0,string_array_out,result_size);
    return string_array_out;
}

int
main (int argc, char *argv[])
{
    char *string = argv[1];
    int result_size = 0;
    char **subset_list;

    subset_list =
    generate_all_subsets(string,&result_size);
    for (int i=0; i< result_size;i++){
        printf("%s\n",subset_list[i]);
    }

}
