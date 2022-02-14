#This script works with nvim and should be placed in /usr/local/bin directory. It creates a new templated cpp and a run script for clang to compile and run this cpp file.

#!/usr/bin/fish

cd /mnt/d/coding/c++/tmp
set name (date +%s)
mkdir $name
cd $name
set file ./$name.cpp
printf '#include <iostream>\n\nusing namespace std;\n\nint main(){\n\t\n\n\treturn 0;\n}' > ./$file
set executable $name
printf "#!/usr/bin/fish\n\nclang.exe -std=c++17 -Wall -Wpedantic -Wextra -o $name.exe $name.cpp\n./$name.exe" > ./run
chmod +x ./run
nvim +6 ./$file
