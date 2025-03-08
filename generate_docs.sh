#!/bin/bash

# Steps
# 1. stash changes if any are present
# 2. switch to gh-pages branch
# 3. generate docs
# 5. commit & push
# 6. reapply changes to working directory

set -e

{
	ROOT_DIR="/Users/cameron/git/concurrent"
	cd ${ROOT_DIR}
	
	STASH=false
	if [[ -n $(git status -s) ]]; then
		echo "Stashing changes on current branch..."
	
		STASH=true
		git stash -u -a
	fi
	
	
	git branch -D gh-pages || echo "gh-pages branch doesn't exist"
	git checkout --orphan gh-pages
	
	
	echo "Generating docs..."
	doxygen "${ROOT_DIR}/Doxyfile" &> /dev/null
	make clean -C "${ROOT_DIR}/docs/sphinx" &> /dev/null
	sphinx-build --quiet -b html "${ROOT_DIR}/docs/sphinx" "${ROOT_DIR}/docs/sphinx/_build" &> /dev/null
	
	
	mkdir -p ${ROOT_DIR}/archive
	mv ${ROOT_DIR}/docs/* ${ROOT_DIR}/archive
	cp -a ${ROOT_DIR}/archive/sphinx/_build/* ${ROOT_DIR}/docs/


	touch ${ROOT_DIR}/docs/.nojekyll


	# echo "Removing unncessary files..."
	ls | grep -xvF docs | xargs rm -rf --
	
	
	git add .
	git commit -m "Updating documentation"
	git push --force -u origin gh-pages
	
	git checkout main
	
	
	if [[ ${STASH} == true ]]; then
		echo "Applying stashed changes..."
		git stash pop
	fi
} || {
	git checkout -f main
	git stash pop
}

