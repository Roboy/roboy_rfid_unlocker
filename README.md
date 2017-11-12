### roboy_rfid_unlocker
nodemcu code reading rfid tag, unlocking sudo 
### installation
```
catkin_make 
sudo ln -s /path/to/roboy_rfid_unlocker/devel/lib/common_utilities/rfid_unlocker /usr/local/bin/rfid_unlocker
printf '#!/bin/bash\n/usr/local/bin/rfid_unlocker&' | sudo tee /etc/network/if-up.d/rfid_unlocker
```
* this will build the rfid_unlocker
* symoblic link it to /usr/local/bin
* make it execute as root when networking becomes available

### IP
you will probably need to change the ip settings in both the esp code and the host code
