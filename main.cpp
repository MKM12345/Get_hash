#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <openssl/sha.h>

using namespace std;

string get_hash(string string)
{
    if (!isinstance(string, str))
    {
        throw TypeError("get_hash() cannot get the hash of a non-string.");
    }
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, string.c_str(), string.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

void storepassword()
{
    string password;
    ifstream file("words.txt");
    if (file.is_open())
    {
        srand(time(NULL));
        int line_number = rand() % 10;
        for (int i = 0; i < line_number; i++)
        {
            getline(file, password);
        }
        file.close();
    }
    string pswrd = get_hash(password);
    string userinput;
    cout << "Enter a password:";
    cin >> userinput;
    if (userinput == pswrd)
    {
        cout << "Succesful login!" << endl;
    }
    else
    {
        cout << "Are you trying to log in to account that does not belong to you?" << endl;
    }
}

int main()
{
    storepassword();
    return 0;
}
