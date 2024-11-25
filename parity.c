#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void calculate_parity_bits(int data[], int m, int r, int encoded[]) {
    int i,j = 0, k = 0;
    for (i = 1; i <= m + r; i++) {
        if (i == (1 << j)) {
            encoded[i] = 0; 
            j++;
        } else {
            encoded[i] = data[k]; 
            k++;
        }
    }
    
    for (i = 0; i < r; i++) {
        int parity_pos = (1 << i);
        int parity_value = 0;
        for (j = 1; j <= m + r; j++) {
            if (j & parity_pos) {
                parity_value ^= encoded[j]; 
            }
        }
        encoded[parity_pos] = parity_value; 
    }
}

int main() {
    int i,data1[] = {1, 0, 0, 1, 1, 0, 1}; 
    printf("\n enter the data \n");	
    char data[100];
	scanf("%s",data);

    int m = strlen(data); 
    int r = 0; 
    for(r=1;r<m;r++)
	{
		if(pow(2,r)>(m+1+r))
			break;
	}
    for(i=0;i<m;i++)
	{
		data1[i]=data[i]-48;
	}
	int encoded[100] = {0}; 

    calculate_parity_bits(data, m, r, encoded);

    // Print the encoded data
    printf("Encoded data: ");
    for (i = 1; i <= m + r; i++) {
        printf("%d", encoded[i]);
    }
    printf("\n");

    return 0;
}
