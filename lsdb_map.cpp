#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <utility>
#include <tr1/unordered_map>
#include <netinet/in.h>
#include <vector>
#include <sstream>
#include <sys/types.h>
#include <arpa/inet.h>

using namespace std;
typedef pair<string, string> SwitchIDInt;
typedef vector<SwitchIDInt> SwitchIntVector;
typedef tr1::unordered_map<string, SwitchIntVector> Table;

void getNetworkAddr(string IP, string netmask, string &networkAddr) {
	int ip[4];
	int mask[4];
	int netaddr[4];
	
	sscanf(IP.c_str(), "%d.%d.%d.%d", ip, ip+1, ip+2, ip+3);
	sscanf(netmask.c_str(), "%d.%d.%d.%d", mask, mask+1, mask+2, mask+3);
	for(int i = 0; i < 4; i++) {
		netaddr[i] = ip[i] & mask[i];
		ostringstream oss;
		oss << netaddr[i];
		networkAddr.append(oss.str());
		networkAddr.append(".");
	}
	networkAddr.erase(networkAddr.end()-1);
}

int main() {

	string filename = "switch.info";
	Table TopologyTable;
	string line, intIP, switchID, netmask, interface;
	ifstream fin(filename.c_str());
	if(fin.is_open()) {
		while(getline(fin, line)) {	
			istringstream iss(line);
			iss>>switchID>>intIP>>netmask>>interface;
			string net_addr;
			getNetworkAddr(intIP, netmask, net_addr);
			
			if(TopologyTable.count(net_addr) > 0) 
				TopologyTable[net_addr].push_back(make_pair(switchID, interface));
			else {
				SwitchIntVector switchInt;
				switchInt.push_back(make_pair(switchID, interface));
				TopologyTable.insert(make_pair(net_addr, switchInt));
			}
		}
		fin.close();
	} else
		perror("File not opened");

	cout<<"Number of networks = "<<TopologyTable.size()<<endl;
	
	/*********************** Prepare LSDB and Host-Network Map ***********************/
	Table::iterator it;
	for(it = TopologyTable.begin(); it != TopologyTable.end(); ++it) {
		string net_addr = it->first;
		cout<<"LSDB entry: "<<net_addr<<endl;
		if(it->second.size() == 2) {
			cout<<it->second.at(0).first<<" "<<it->second.at(0).second<<" "<<it->second.at(1).first<<" "<<it->second.at(1).second<<endl;
			 cout<<it->second.at(1).first<<" "<<it->second.at(1).second<<" "<<it->second.at(0).first<<" "<<it->second.at(0).second<<endl;
		}
		else
			cout<<"Host address: "<<net_addr<<endl;
	}
	
	return(0);
}
