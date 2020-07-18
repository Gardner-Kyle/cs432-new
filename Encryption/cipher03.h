//
//  cipher03.h
//  CIpherLab
//
//  Created by Joseph Everett on 7/17/20.
//  Copyright © 2020 Joseph Everett. All rights reserved.
//

/*********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H

#include <string>
#include "cipher.h"
#include <map>
#include <iostream>

using namespace std;

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
    virtual std::string getPseudoAuth()  { return "Joe Everett"; }
    virtual std::string getCipherName()  { return "Baconian Cipher"; }
    virtual std::string getEncryptAuth() { return "Joe Everett"; }
    virtual std::string getDecryptAuth() { return "Joe Everett"; }

    /***********************************************************
     * GET CIPHER CITATION
     * Returns the citation from which we learned about the cipher
     ***********************************************************/
    virtual std::string getCipherCitation()
    {
        return std::string("Crypto. (n.d.). Retrieved July 18, 2020, from http://practicalcryptography.com/ciphers/classical-era/baconian/");
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
        str =  "Get User Input \n";
        str += "Create Alphabet \n";
        str += "Encode Message\n";

        // The decrypt pseudocode
        str += "insert the decryption pseudocode\n";

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
        map <char, string>::iterator pair;
        
        //Create Alphabet
        char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        
        string code[] = {"abcda", "abcdb", "abcdc", "abcdd", "abcde", "abcea", "abceb", "abcec", "abced", "abcee", "abdaa", "abdab", "abdac", "abded", "abdae", "abdba", "abdbb", "abdbc", "abdbd", "abdbe", "abeaa", "abeab", "abeac", "abead", "abeae", "abeba", "abebb", "abebc", "abebd", "abebe", "abeca", "abecb", "abecc", "abecd", "abece", "abeda", "abedb", "abedc", "abedd", "abede", "abeea", "abeeb", "abeec", "abeed", "abeee", "acaaa", "acaab", "acaac", "acaad", "acaae", "acaba", "acabb", "acabc", "acabd", "acabe", "acaca", "acacb", "acacc", "acacd", "acace", "acada", "acadb"};
        map<char, string> codex;
        //build out the map
        for (int i = 0; i < 62; i++){
            codex[alphabet[i]] = code[i];
        }
        string temp = "";
        //loop through plaintext and convert to ciphertext
        for(int i = 0; i < plainText.length(); i++)
        {
            pair = codex.find(plainText[i]);
            temp += pair->second;
            temp += " ";
        }
        cipherText = temp;
        return cipherText;
    }

    /**********************************************************
     * DECRYPT
     * TODO: ADD description
     **********************************************************/
    virtual std::string decrypt(const std::string & cipherText,
                                const std::string & password)
    {
        std::string plainText = cipherText;
       
        string temp = "";
        string message = "";
        map<char, string> codex;
        map <char, string>::iterator pair;
        
        //Create Alphabet
        char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        
        string code[] = {"abcda", "abcdb", "abcdc", "abcdd", "abcde", "abcea", "abceb", "abcec", "abced", "abcee", "abdaa", "abdab", "abdac", "abded", "abdae", "abdba", "abdbb", "abdbc", "abdbd", "abdbe", "abeaa", "abeab", "abeac", "abead", "abeae", "abeba", "abebb", "abebc", "abebd", "abebe", "abeca", "abecb", "abecc", "abecd", "abece", "abeda", "abedb", "abedc", "abedd", "abede", "abeea", "abeeb", "abeec", "abeed", "abeee", "acaaa", "acaab", "acaac", "acaad", "acaae", "acaba", "acabb", "acabc", "acabd", "acabe", "acaca", "acacb", "acacc", "acacd", "acace", "acada", "acadb"};
        
        
        //build out the map
        for (int i = 0; i < 62; i++){
            codex[alphabet[i]] = code[i];
        }
        
        //loop through ciphertext and convert to plaintext
        for(int i = 0; i < (plainText.length()-6); i=i+6)
            if(i == plainText.length()-5) {
                temp = plainText.substr(i, i+5);
                if (pair->second == temp){
                    message += pair->first;
                }
                i = i+5;
            }
        else
            {
                temp = plainText.substr(i, i+5);
                cout << temp;
                if(pair->second == temp) {
                    message += pair->first;
            }

        }
        plainText = message;
        
        return plainText;
    }
};

#endif // CIPHER03_H
