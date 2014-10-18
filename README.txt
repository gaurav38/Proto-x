gaurav@gaurav-VirtualBox:~/Documents/Proto-X$ g++ Dijkstras.cpp -o Dijkstras
gaurav@gaurav-VirtualBox:~/Documents/Proto-X$ ./Dijkstras Dijkstras.graph aa:bb:cc:dd:ee:00 aa:bb:cc:dd:ee:05
Path from source aa:bb:cc:dd:ee:00 to destination node aa:bb:cc:dd:ee:05:
aa:bb:cc:dd:ee:00,aa:bb:cc:dd:ee:01,aa:bb:cc:dd:ee:05
gaurav@gaurav-VirtualBox:~/Documents/Proto-X$


gaurav@gaurav-VirtualBox:~/Documents/Proto-X$ g++ lsdb_map.cpp -o lsdb
gaurav@gaurav-VirtualBox:~/Documents/Proto-X$ ./lsdb switch.info 
Number of networks = 14
LSDB entry: 10.10.9.0
aa:bb:cc:dd:ee:04 eth2 aa:bb:cc:dd:ee:07 eth2
aa:bb:cc:dd:ee:07 eth2 aa:bb:cc:dd:ee:04 eth2
LSDB entry: 10.10.2.0
aa:bb:cc:dd:ee:01 eth1 aa:bb:cc:dd:ee:02 eth0
aa:bb:cc:dd:ee:02 eth0 aa:bb:cc:dd:ee:01 eth1
LSDB entry: 10.10.11.0
aa:bb:cc:dd:ee:05 eth3 aa:bb:cc:dd:ee:06 eth1
aa:bb:cc:dd:ee:06 eth1 aa:bb:cc:dd:ee:05 eth3
LSDB entry: 10.10.6.0
aa:bb:cc:dd:ee:03 eth3 aa:bb:cc:dd:ee:06 eth0
aa:bb:cc:dd:ee:06 eth0 aa:bb:cc:dd:ee:03 eth3
LSDB entry: 10.10.5.0
aa:bb:cc:dd:ee:03 eth2 aa:bb:cc:dd:ee:05 eth2
aa:bb:cc:dd:ee:05 eth2 aa:bb:cc:dd:ee:03 eth2
LSDB entry: 10.10.1.0
Host address: 10.10.1.0
LSDB entry: 10.10.7.0
aa:bb:cc:dd:ee:02 eth2 aa:bb:cc:dd:ee:05 eth1
aa:bb:cc:dd:ee:05 eth1 aa:bb:cc:dd:ee:02 eth2
LSDB entry: 10.10.10.0
aa:bb:cc:dd:ee:06 eth2 aa:bb:cc:dd:ee:07 eth0
aa:bb:cc:dd:ee:07 eth0 aa:bb:cc:dd:ee:06 eth2
LSDB entry: 10.10.3.0
aa:bb:cc:dd:ee:01 eth2 aa:bb:cc:dd:ee:03 eth0
aa:bb:cc:dd:ee:03 eth0 aa:bb:cc:dd:ee:01 eth2
LSDB entry: 10.10.13.0
aa:bb:cc:dd:ee:04 eth1 aa:bb:cc:dd:ee:05 eth0
aa:bb:cc:dd:ee:05 eth0 aa:bb:cc:dd:ee:04 eth1
LSDB entry: 10.10.4.0
aa:bb:cc:dd:ee:02 eth1 aa:bb:cc:dd:ee:03 eth1
aa:bb:cc:dd:ee:03 eth1 aa:bb:cc:dd:ee:02 eth1
LSDB entry: 10.10.14.0
Host address: 10.10.14.0
LSDB entry: 10.10.12.0
aa:bb:cc:dd:ee:05 eth4 aa:bb:cc:dd:ee:07 eth1
aa:bb:cc:dd:ee:07 eth1 aa:bb:cc:dd:ee:05 eth4
LSDB entry: 10.10.8.0
aa:bb:cc:dd:ee:02 eth3 aa:bb:cc:dd:ee:04 eth0
aa:bb:cc:dd:ee:04 eth0 aa:bb:cc:dd:ee:02 eth3
gaurav@gaurav-VirtualBox:~/Documents/Proto-X$ 
