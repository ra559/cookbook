---
layout: page
title: Github 
---

* **How to push an existing git repository to GitHub?**
	* Assuming your ssh key and user is already setup.
	* 1. create the GitHub repository
	* 2. Initialize your git local repository if you have not done so
	* 3. Add github as a remote repository: `git remote add origin git@github.com:your-username/your-repo-name.git`
	* 4. Push local commits to GitHub main branch: `git push -u origin main`
* **How to setup README, .gitignore, and GitHub Actions**
	* A readme file is just a markdown file in the root of your repository. It contains a description of your project.
	* The purpose of the gitignore file is to prevent sensitive information from being commited to your github repository. Examples: logs, local files, compiled binaries etc..)
	* Here is some examples of what you can add to your gitignore:


```bash
# Compiled source
*.class
*.o
*.so

# Logs
*.log

# OS junk
.DS_Store
Thumbs.db

# Node/Ruby/Python package stuff
node_modules/
vendor/
.env
__pycache__/
*.pyc
```

* GitHub Actions are part of your CD/CI pipeline. This automates testing and deployment when push and pull requests are made. These are project specific.
