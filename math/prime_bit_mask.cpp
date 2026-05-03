
// This algorithm is used to generate a bitmask of all the primes of an odd power that make up number


long long generate_power_bitmask(int num) {
    long long mask = 1;
    
    // only iterating up thte square root since more than the square squared will be > n
    for (int p = 2; p * p <= num; ++p) {
        if (num % p == 0) {
            int cnt = 0;
            // while we can factorize with the current prime
            // also taking advantage of the sieve trick since where if we do 2 then 4, 8, 16 will auto fail
            while (num % p == 0) {
                num /= p;
                cnt++;
            }
            
            // there is only one distinct combination of prime numbers (and using the sieve trick from above) we generate a unique mask
            if (cnt % 2 == 1) { // keep prime if exponent is odd
                mask *= p;
            }
        }
    }

    // leftover prime
    // reduduancy
    if (num > 1) {
        mask *= num;
    }

    return mask;
}


