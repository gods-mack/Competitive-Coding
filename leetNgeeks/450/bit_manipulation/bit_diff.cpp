

/*
You are given two numbers A and B. 
The task is to count the number of bits needed
 to be flipped to convert A to B.
*/

int set_bit(int n) {
    
    int count= 0 ;
    while( n > 0) {
        n = n & (n-1);
        count++;
    }
    return count;
}
int countBitsFlip(int a, int b){
    
    // Your logic here
    
    return set_bit(a^b);
}