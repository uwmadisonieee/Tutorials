# School Linux Machines

> You are a student, you have free access to almost all software and hardware you could need!

- All **Engineering** students can log into the CAE Linux computers with their CAE accounts.
- All student who took a **Computer Science** course can use their CS account to log into the CS Linux computers.

### Windows

1. Quick [download Putty](https://the.earth.li/~sgtatham/putty/latest/w32/putty.exe)
2. Run the `putty.exe` file
	- ![putty](putty.png)
3. Type in the correct user and hostname
	- **CAE Computers**: `YOURUSERNAME@best-tux.cae.wisc.edu`
		- example: `sjfricke@best-tux.cae.wisc.edu` for the username `sjfricke`
	- **CS Computers**: `YOURUSERNAME@best-linux.cs.wisc.edu`
		- example: `fricke@best-linux.cs.wisc.edu` for the username `fricke`
4. *Pro tip*: if you press "Save" after you type your info in you can just click if next time instead of typing it all out

### Macs and Linux

1. Open the Terminal program on computer
2. run the `ssh` command to log into the account
	- **CAE Computers**: `ssh YOURUSERNAME@best-tux.cae.wisc.edu`
		- example: `ssh sjfricke@best-tux.cae.wisc.edu` for the username `sjfricke`
	- **CS Computers**: `ssh YOURUSERNAME@best-linux.cs.wisc.edu`
		- example: `ssh fricke@best-linux.cs.wisc.edu` for the username `fricke`
3. If it ask about "ECDSA key fingerprint" enter `yes`
4. Type password
	- **NOTE** the password will not show up when you type, but be assure its being typed in

### Note

The `best-tux` and `best-linux` is just a feature the labs have provided. When you log into them, the program finds the "most open" computer for you. You are totally welcome to access a particular machine such as `ssh YOURUSERNAME@royal-05.cs.wisc.edu`. There have been times where the `best-tux` and `best-linux` program have gone down, so knowing a particular computer name as a backup is a good idea.
