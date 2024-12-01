#include <iostream>
#include <string>
#include <openssl/evp.h>
#include <openssl/md5.h>

using namespace std;

string md5(string input) {
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned int md_len;

    md = EVP_get_digestbyname("md5");
    if(!md) {
        cout << "Unknown message digest " << endl;
        return 0;
    }

    mdctx = EVP_MD_CTX_create();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, input.c_str(), input.length());
    EVP_DigestFinal_ex(mdctx, md_value, &md_len);
    EVP_MD_CTX_destroy(mdctx);

    string md_string;

    for (auto i = 0; i < md_len; i++) {
        char buf[3];
        sprintf(buf, "%02x", md_value[i]);
        md_string += buf;
    }

    return md_string;
}

int main() {

    string input = "ckczppom";

    int i = 0;

    while (true) {
        string hash = md5(input + to_string(i));
        if (hash.substr(0, 6) == "000000") {
            cout << "Answer: " << i << endl;
            break;
        }
        i++;
    }

    return 0;
}