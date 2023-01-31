# CRYPTOGRAPHY-using-C-
A C++ Program to perform cryptography. It Encrypts and Decrypts the text through file operations. 
In today’s modern world confidential and classified documents are difficult to be kept secret especially in computers.

CRYPTOGRAPHY: It is the art and science of creating secret writing via making them unreadable by scrambling the Symbols of the message 
in such a way that only the intended receiver can read it by knowing the method used to scramble the message.

PROGRAM SPECIFICATION:
1) Using the techniques presented during this semester to create a complete C++ program to emulate an Encryption/Decryption Machine.
The program will be capable of the following:
--> Encrypt a file provided by the user
--> Choose between two different encryption methods
--> Decrypt a file by the user
--> Choose between two different decryptions methods
--> Decrypt without knowing the encryption method
2) The interface must be professional and fully intuitive to the user
3) The program will be menu driven.
4) The program will use a function(s) to define and implement each of the methods and store the original file and the encrypted/decrypted file.
5) In addition to using a function we have:
    ➢ Selection statements (if, if-else, switch)
    ➢ Loops (while, for, do-while)
    ➢ Standard Libraries (don’t recreate the wheel)
    ➢ Functions
    ➢ Arrays
6) The two encryption/decryption methods are:
    1. Transposition
    2. Caesar Cipher

TRANSPOSITION:
In this type of encryption, the sentence or data is encrypted in a laterally inverted way.
The positions of the letters get swapped from last to first position.
EX: ABCDE would be encrypted as EDCBA.

CAESAR-CIPHER:
Here ASCII values are taken into consideration. 
The characters are replaced by 25 (as KEY in code is set to 25) characters after the entered character.
Briefly, the letters in the file are added 25 numbers ahead.
EX: If letter A is entered then Z is displayed.
ABCDE is encrypted as Z[\]^.

When a huge amount of data is encrypted in this way, it would bedifficult to decode it without decrypting it.
