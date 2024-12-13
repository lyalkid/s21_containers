c:
	@g++  main.cpp 
git-push: clean style
	@git pull
	@git add .
	@git commit -m $(GIT_MESSAGE)
	@git push -u origin sionapae
	@git status

