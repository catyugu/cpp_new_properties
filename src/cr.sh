# Compile and run a certain cpp file using g++
full_file_name=$1
out_file_name=~/project/cpp_new_properties/obj/${full_file_name%.*}
g++ -std=c++17 $full_file_name -o $out_file_name
echo "Compiled $full_file_name"
echo "Running $out_file_name"
$out_file_name
echo "Done"
