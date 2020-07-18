//
//  main.cpp
//  Cipher02
//
//  Created by Joseph Everett on 7/15/20.
//  Copyright © 2020 Joseph Everett. All rights reserved.
//


/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

#include <string>
#include "cipher.h"

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
    virtual std::string getPseudoAuth()  { return "Joe Everett"; }
    virtual std::string getCipherName()  { return "Railfence Cipher"; }
    virtual std::string getEncryptAuth() { return "Joe Everett"; }
    virtual std::string getDecryptAuth() { return "Joe Everett"; }

    /***********************************************************
     * GET CIPHER CITATION
     * Returns the citation from which we learned about the cipher
     ***********************************************************/
    virtual std::string getCipherCitation()
    {
        return std::string("Crypto. (n.d.). Retrieved July 15, 2020, from http://practicalcryptography.com/ciphers/classical-era/rail-fence");
    }

    /**********************************************************
     * GET PSEUDOCODE
     * Returns the pseudocode as a string to be used by the caller.
     **********************************************************/
    virtual std::string getPseudocode()
    {
        std::string str;

        // TODO: please format your pseudocode
        // The encrypt pseudocode
        str = "1. Prompt user for plaintext \n";
        str += "2. Prompt user for password. \n";
        str += "3. Prompt user for number of rows < 10. \n";
        str += "4. Construct ciphertext using plaintext and password. \n";
        str += "5. Display ciphertext to user. \n";
        

        // The decrypt pseudocode
        str += "6. Construct plaintext from ciphertext \n";
        str += "7. Display reconstructed plaintext to user.";

        return str;
    }

    /**********************************************************
     * ENCRYPT
     * TODO: ADD description
     **********************************************************/
    virtual std::string encrypt(const std::string & plainText,
                                const std::string & password)
    {
        std::string cipherText = plainText;
        int key = (int)(cipherText.length()/password.length());
        char railfence[key][cipherText.length()];
        
        for (int i=0; i < key; i++)
        for (int j = 0; j < cipherText.length(); j++)
            railfence[i][j] = '\n';
        
        bool dir_down = false;
        int row = 0, col = 0;
        
        for (int i=0; i < cipherText.length(); i++)
        {
            if (row == 0 || row == key-1)
                dir_down = !dir_down;
        
        railfence[row][col++] = cipherText[i];
        
        dir_down?row++ : row--;
        }
        
        std::string result = "";
        for (int i=0; i < key; i++)
                for (int j=0; j < cipherText.length(); j++)
                    if (railfence[i][j]!='\n')
                        result.push_back(railfence[i][j]);
          
            return result;
        }

    /**********************************************************
     * DECRYPT
     * TODO: ADD description
     **********************************************************/
    virtual std::string decrypt(const std::string & cipherText,
                                const std::string & password)
    {
        std::string plainText = cipherText;
        int key = (int)(cipherText.length()/password.length());
        
        char railfence[key][cipherText.length()];
        
        for (int i=0; i < key; i++)
               for (int j=0; j < cipherText.length(); j++)
                   railfence[i][j] = '\n';
       
        bool dir_down;
        
        int row = 0, col = 0;
        
        for (int i=0; i < cipherText.length(); i++)
        {
            // check the direction of flow
            if (row == 0)
                dir_down = true;
            if (row == key-1)
                dir_down = false;
        
        
            railfence[row][col++] = '*';

            dir_down?row++ : row--;
        }
        
        int index = 0;
        for (int i=0; i<key; i++)
            for (int j=0; j<cipherText.length(); j++)
                if (railfence[i][j] == '*' && index<cipherText.length())
                    railfence[i][j] = cipherText[index++];
        
        std:: string result = "";
        
        row = 0, col = 0;
        for (int i=0; i< cipherText.length(); i++)
          {
              // check the direction of flow
              if (row == 0)
                  dir_down = true;
              if (row == key-1)
                  dir_down = false;
        
              // place the marker
              if (railfence[row][col] != '*')
                  result.push_back(railfence[row][col++]);
        
              // find the next row using direction flag
              dir_down?row++: row--;
          }
          return result;
        
    }
};

#endif // CIPHER02_H
