#include <fstream>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main()
{
	// variable to store name of domain to block
	string site;

	// localhost's IP
	string redirect = "127.0.0.1";

	// opening list of websites to block
	ifstream adblock;
	adblock.open("adblock.txt");

	// make sure the user ran it as root
	cout << "script ran as uid: " << getuid() << '\n';

	// root user has uid of 0, so don't run if that's not the current uid
	if (getuid() != 0) {
		// notify the user
		cout << "please run as root\n";
		// exit
		exit(1);
	} else {
		cout << "ran as root!\n";
		exit(0);
	}

	if (adblock.is_open()) {
		ofstream host;
		host.open("/etc/hosts");

		while (getline(adblock, site)) {
			host << redirect << " " << site << endl;
		}

		host.close();
		adblock.close();
	} else {
		cout << "Could not open file with list of websites.";
		return 1;
	}

	return 0;
}

// vim: ft=cpp sts=4 ts=4 sw=4 et
