There is a single file for encryption and decryption.

Compile and Execute It:-

gcc 2015KUCP1018_ass10_rsa.c -lm
./a.out


Input: <Plain-TEXT>
<PRIME-1> <PRIME-2>	
Output: <CIPHER-TEXT>

Output: <DECRYPTED-TEXT>
 

Example:

Enter Plain Text: hello  

Enter 2 Prime numbers p and q: 997

Encrypted Message: 92332 53429 14687 14687 7464 

Decrypted Message: hello

Note:- For Prime numbers P and Q both greater than 200 it takes more time to calculate the result (approximately 3-5s).
