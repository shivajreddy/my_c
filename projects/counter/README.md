
raylib files are inside 'lib' folder

# WINDOWS
- open command prompt, in the 'counter' project directory, and hit 'build',
  this runs the build.bat file, and pastes the output binary in the 'build' 
  folder
# UNIX
- open the 'counter' app directory in terminal, run the 'build.sh', if the 
  build.sh file doesnt have permission give by 'chdmod +x ./build.sh'

(this command is same for both windows & Unix)
  - build           # runs with default timer set in main.c which is 10minutes
  - build   1 2 3   # 1hr 2mins 3seconds
  - build   4 5     # 4mins 5seconds
  - build   6       # 6seconds
  so basically 1arg is seconds, 2arg is min-secs, 3args are hh-mm-ss

