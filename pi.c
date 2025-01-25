#include <stdio.h>                                                            
                                                                              
int main() {                                                                  
    double pi = 0.0;                                                          
    int n_terms = 1000000; // Number of terms for better accuracy             
                                                                              
    for (int i = 0; i < n_terms; i++) {                                       
        if (i % 2 == 0) {                                                     
            pi += 1.0 / (2 * i + 1);                                          
        } else {                                                              
            pi -= 1.0 / (2 * i + 1);                                          
        }                                                                     
    }                                                                         
                                                                              
    pi *= 4;                                                                  
                                                                              
    printf("Calculated value of Pi: %.15f\n", pi);                            
                                                                              
    return 0;                                                                 
}                                                                             
