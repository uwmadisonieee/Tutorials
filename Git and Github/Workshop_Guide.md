# Git and GitHub Workshop Guide

Find a partner and give each other either `Person A` or `Person B` and follow direction for your letter. Feel free to help your partner as well, it's the way to best learn.

* Note you don't need to know any programming to use git, so don't be freaked out
* Feel free to run any of the code or deviate from guide a little.
* **WARNING** DO NOT copy and paste the git command
	1. Its good practice to type and know the commands
	2. sometimes the `"` and `'` in windows can be different then linux and then your commands don't work
	3. PLEASE feel free to copy and paste the code into files though

1. [**A** and **B**] Create a new git repo and push a initital commit to GitHub
	1. Make a new folder on your local computer
	2. Open that folder inside your terminal
	3. Run `git init` to inititalize this folder as a git repo
	4. Create a file called `main.c`
	```
	#include <stdio.h>

	int main() {
		printf("Hello Git Workshop\n");
	}
	```
	5. To see the untracked file run `git status`
	6. Now to add file run `git add main.c`
	7. Run `git status` again to see your file ready for committing by being in green
	8. To make the commit run `git commit -m "init commit" -m "git is easy"`
		- The `-m` stands for *message* and the first
		- The first message is your git commit summary
		- The second message is **optional** and where you would add more details about your message
	9. To see the commit you made run `git log`
2. [**B**] We are going to use `Person A` repo so you can discard this folder if you want and help `A` with next step
3. [**A**] Go to GitHub and create a new repo
	1. Give it any name you want
	2. Make it public
	3. Don't worry about a README, .gitignore, or license
	4. We need to tell our current repo on our local computer were we want to push our changes to with
	5. We then can push our changes up to GitHub with
	6. Go to GitHub and refresh page and see everything is there from your commit
	7. Now to allow `B` to push changes you need set them a `Collaborator` on GitHub
4. [**B**]
	1. We need to clone a repo `git clone <THEIR_REPO_URL>`
	2. Open the repo folder in your terminal and run `git log`
	3. Make a new file called `main.h` and add this to it
	```
	#ifndef GIT_WORKSHOP_MAIN_H
	#define GIT_WORKSHOP_MAIN_H

	#define PI 3.14

	#endif
	```
	4. Also change `main.c`
	```
	#include <stdio.h>
	#include "main.h"

	int main() {
		if (PI > 3) {
			printf("I Like Pi\n");
		} else {
			printf("No Pi For You\n");
		}
	}
	```
	5. Add the files to be staged for committing with `git add -A`
		- The `-A` says to add all files to be staged
		- Has to be a captial "A"
	6. To commit run `git commit -m "I Like Pi"`
	7. If `Person A` did not set you as a "collaborator" on GitHub make sure you do that first
	8. To push your changes run `git push` and use your GitHub name and password
5. [**A**] We are going to get the new changes
	1. To pull the changes from `Person B` run `git pull`
	2. Run `git log` to see the changes
	3. Add a new subfolder called `memes`
		- You can run `mkdir memes`
	4. Find and save a jpeg or png of a meme in this folder
	5. Add the folder to be commited `git add memes/`
	6. Make your commit `git commit -m "memes for days"`
	7. Make a push with `git push`
6. [**B**] Do **NOT** pull the new meme folder commit... not yet
	1. Make a new *branch* called "pi" with `git branch pi`
	2. If you run `git branch` you will see the branches you have
	3. To *checkout* the new pi branch run `git checkout pi`
	4. Make a new subfolder called `basic`
	5. Find a picture of a pumpkin spice latte and add it to this folder
	6. Now change the print statment in `main.c` from `"I Like Pi\n"` to `I LOVE Pi\n"`
	7. Add all these changes with `git add -A`
	8. Now make the commit `git commit -m "super basic"`
	9. Push changes with `git push`
7. [**A**] Pull in the new branch from `Person B` `git pull`
8. [**B**] Switch back to the Master branch `git checkout master`
	1. Pull down the memes changes from before with `git pull`
9. [**A** and **B**] Look at your file explore and the `main.c` file
	- Try switching between branches and note how it changes your folders and files for you
	- `git checkout pi` and `git checkout master`
10. [**A**] Time to merge to branch into master`
	