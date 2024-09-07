## Part 1. Installation of the OS

- Check Ubuntu version by running the command \
  `cat /etc/issue`

![Part-1](images/Part-1.jpg)

## Part 2. Creating a user

1. Add a screenshot of command call to create user. USE adduser!!!

![Part-2-1](images/Part-2.1.jpg)

2. The new user must be in the output of the command: \
  `cat /etc/passwd`

![Part-2-2](images/Part-2.2.jpg)

## Part 3. Setting up the OS network

##### Set the machine name as user-1

![Part-3-1](images/Part-3.1.jpg)

##### Set the time zone corresponding to your current location.

![Part-3-2](images/Part-3.2.jpg)

##### Output the names of the network interfaces using a console command.

![Part-3-3](images/Part-3.3.jpg)

A loopback device in Linux is a virtual device that can be used like any other media device.

##### Use the console command to get the ip address of the device you are working on from the DHCP server.

![Part-3-4](images/Part-3.4.jpg)

DHCP - Dynamic Host Configuration Protocol.

##### Define and display the external ip address of the gateway (ip) and the internal IP address of the gateway, aka default ip address (gw).

![Part-3-5](images/Part-3.5.jpg)

##### Set static (manually set, not received from DHCP server) ip, gw, dns settings (use public DNS servers, e.g. 1.1.1.1 or 8.8.8.8).

![Part-3-6-1](images/Part-3.6.1.jpg)

##### Reboot the virtual machine. Make sure that the static network settings (ip, gw, dns) correspond to those set in the previous point.

![Part-3-6-2](images/Part-3.6.2.jpg)

![Part-3-6-3](images/Part-3.6.3.jpg)

- Successfully ping 1.1.1.1 and ya.ru.

![Part-3-8](images/Part-3.8.jpg)

## Part 4. OS Update

![Part-4](images/Part-4.jpg)

## Part 5. Using the **sudo** command

##### Allow user created in [Part 2](#part-2-creating-a-user) to execute sudo command.

![Part-5-1](images/Part-5.1.jpg)

sudo (/suːduː/[4]) is a program for Unix-like computer operating systems that enables users to run programs with the security privileges of another user, by default the superuser. It originally stood for "superuser do", as that was all it did, and it is its most common usage; however, the official Sudo project page lists it as "su 'do' ". The current Linux manual pages for su define it as "substitute user", making the correct meaning of sudo "substitute user, do", because sudo can run a command as other users as well.

![Part-5-2](images/Part-5.2.jpg)

![Part-5-3](images/Part-5.3.jpg)


## Part 6. Installing and configuring the time service

##### Set up the automatic time synchronisation service.

![Part-6-1](images/Part-6.1.jpg)

- The output of the following command must contain `NTPSynchronized=yes`: \
  `timedatectl show`

![Part-6-2](images/Part-6.2.jpg)

![Part-6-3](images/Part-6.3.jpg)

## Part 7. Installing and using text editors

##### Install **VIM** text editor (+ any two others if you like **NANO**, **MCEDIT**, **JOE** etc.)

##### Using each of the three selected editors, create a *test_X.txt* file, where X is the name of the editor in which the file is created. Write your nickname in it, close the file and save the changes.

![Part-7-1-1](images/Part-7.1.1.jpg)

![Part-7-1-2](images/Part-7.1.2.jpg)

![Part-7-1-3](images/Part-7.1.3.jpg)

##### Using each of the three selected editors, open the file for editing, edit the file by replacing the nickname with the "21 School 21" string, close the file without saving the changes.

![Part-7-2-1](images/Part-7.2.1.jpg)

![Part-7-2-2](images/Part-7.2.2.jpg)

![Part-7-2-3](images/Part-7.2.3.jpg)

![Part-7-2-4](images/Part-7.2.4.jpg)

##### Using each of the three selected editors, edit the file again (similar to the previous point) and then master the functions of searching through the contents of a file (a word) and replacing a word with any other one.

![Part-7-3-1](images/Part-7.3.1.jpg)

![Part-7-3-2](images/Part-7.3.2.jpg)

![Part-7-3-3](images/Part-7.3.3.jpg)

## Part 8. Installing and basic setup of the **SSHD** service

##### Add an auto-start of the service whenever the system boots.

![Part-8-1](images/Part-8.1.jpg)

##### Reset the SSHd service to port 2022.

![Part-8-2](images/Part-8.2.jpg)

##### Show the presence of the sshd process using the ps command. To do this, you need to match the keys to the command.

![Part-8-3](images/Part-8.3.jpg)

##### Reboot the system.

![Part-8-4-1](images/Part-8.4.1.jpg)

![Part-8-4-2](images/Part-8.4.2.jpg)

![Part-8-4-3](images/Part-8.4.3.jpg)

![Part-8-4-4](images/Part-8.4.4.jpg)

## Part 9. Installing and using the **top**, **htop** utilities

##### Install and run the top and htop utilities.

**top**

![Part-9-1](images/Part-9.1.jpg)

**htop**

![Part-9-2-1](images/Part-9.2.1.jpg)

![Part-9-2-2](images/Part-9.2.2.jpg)

![Part-9-2-3](images/Part-9.2.3.jpg)

![Part-9-2-4](images/Part-9.2.4.jpg)

![Part-9-3](images/Part-9.3.jpg)

![Part-9-4](images/Part-9.4.jpg)

![Part-9-5](images/Part-9.5.jpg)

## Part 10. Using the **fdisk** utility

##### Run the fdisk -l command.

![Part-10-1](images/Part-10.1.jpg)

##### Run the swapon --show command.

![Part-10-1](images/Part-10.2.jpg)

## Part 11. Using the **df** utility

##### Run the df command.

![Part-11-1](images/Part-11.1.jpg)

##### Run the df -Th command.

![Part-11-2](images/Part-11.2.jpg)

Ext4 is an advanced level of the ext3 filesystem which incorporates scalability and reliability enhancements for supporting large filesystems (64 bit) in keeping with increasing disk capacities and state-of-the-art feature requirements.

## Part 12. Using the **du** utility

##### Output the size of the /home, /var, /var/log folders (in bytes, in human readable format)

![Part-12-1-1](images/Part-12.1.1.jpg)

![Part-12-1-2](images/Part-12.1.2.jpg)

![Part-12-1-3](images/Part-12.1.3.jpg)

![Part-12-1-4](images/Part-12.1.4.jpg)

![Part-12-1-5](images/Part-12.1.5.jpg)

![Part-12-1-6](images/Part-12.1.6.jpg)

##### Output the size of all contents in /var/log (not the total, but each nested element using *)

![Part-12-2](images/Part-12.2.jpg)

## Part 13. Installing and using the **ncdu** utility

##### Output the size of the /home, /var, /var/log folders.

![Part-13-1](images/Part-13.1.jpg)

![Part-13-2](images/Part-13.2.jpg)

![Part-13-3](images/Part-13.3.jpg)

## Part 14. Working with system logs

##### 1. /var/log/dmesg

![Part-14-1](images/Part-14.1.jpg)

##### 2. /var/log/syslog

![Part-14-2](images/Part-14.2.jpg)

##### 3. /var/log/auth.log

![Part-14-3](images/Part-14.3.jpg)

`sudo service ssh restart`

![Part-14-4](images/Part-14.4.jpg)

## Part 15. Using the **CRON** job scheduler

##### Using the job scheduler, run the uptime command in every 2 minutes.

![Part-15-1](images/Part-15.1.jpg)

![Part-15-2](images/Part-15.2.jpg)

![Part-15-3](images/Part-15.3.jpg)

##### Remove all tasks from the job scheduler.

![Part-15-4](images/Part-15.4.jpg)

## THANK U 4 CHECKING

![Final](images/Final.jpg)