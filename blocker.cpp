#include <iostream>
#include <fstream>

using namespace std;

    int main() {
    
    //variable to store name of domain to block
    string site;
  
    //localhost's IP 
    string redirect = "127.0.0.1";

    //opening list of websites to block
    ifstream adblock;
    adblock.open("adblock.txt");

    //can i find a way to give permission to host file within program?
    //sudo chown username host

    if (adblock.is_open())
    {
        ofsteam host;
        host.open("/etc/hosts");

        while (getline(adblock, site))
        {
            host << redirect << " " << site << endl;

        }

        host.close();
        adblock.close();
    }

    else
    {
        cout << "Could not open file with list of websites.";
    }
    
    return 0;
}