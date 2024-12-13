c:
	@g++  main.cpp 
git-push: 
	@git pull
	@git add .
	@git commit -m "wait for tests"
	@git push -u origin fearowpi
	@git status

style:
	@clang-format --style=Google -i  *.cpp *.h 
	@echo "Don't panic! Clang is fine :)"
