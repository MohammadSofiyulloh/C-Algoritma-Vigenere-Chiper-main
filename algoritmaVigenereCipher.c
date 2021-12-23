#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // input kunci
    char key_str[25];
    printf("Enter key: ");
    gets(key_str);

    // input plaintext
    char plain[77];
    printf("Enter plain text: ");
    gets(plain);

    // inisialisasi cipher sama dengan 0
    int cipher = 0;
    
    // variabel untuk menandakan indeks pada kunci
    int j = 0;

    printf("Cipher text: ");
    for (int i = 0; i < strlen(plain); i++)
    {
        // indeks (huruf ke-i) pada kunci yang digunakan untuk mengenkripsi plainteks
        int index = j % strlen(key_str);
        int key = key_str[index];

        // karena huruf alphabet berjumlah 26, maka kunci dikurangi dengan 65(huruf kapital)
        if (key_str[index] >= 'A' && key_str[index] <= 'Z')
        {
            key = key - 'A';
        }
        
        // karena huruf alphabet berjumlah 26, maka kunci dikurangi dengan 97(huruf kecil)
        else if (key_str[index] >= 'a' && key_str[index] <= 'z')
        {
            key = key - 'a';
        }

        // jangan pindah ke huruf selanjutnya pada key jika huruf pada plaintext adalah selain alphabet
        if ((plain[i] >= 'A' && plain[i] <= 'Z') || (plain[i] >= 'a' && plain[i] <= 'z'))
        {
            j++;
        }

        cipher = plain[i];
        
        // jangan di-enkripsi jika huruf pada plaintext adalah spasi
        if (plain[i] == ' ')
        {
            cipher = ' ';
        }
        
        // jangan di-enkripsi jika huruf pada plaintext adalah selain huruf alphabet
        else if (plain[i] < 'A' || (plain[i] > 'Z' && plain[i] < 'a') || plain[i] > 'z')
        {
            cipher = plain[i];
        }
        
        // perkondisian untuk mengenkripsi huruf alphabet
        else if (plain[i] >= 'A' && plain[i] <= 'Z')
        {
            cipher = ((plain[i] + key - 'A') % 26) + 'A';
        }
        else if (plain[i] >= 'a' && plain[i] <= 'z')
        {
            cipher = ((plain[i] + key - 'a') % 26) + 'a';
        }

        printf("%c", cipher);
    }

    printf("\n");

    return 0;
}