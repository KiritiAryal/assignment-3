module load gnu/5.4.0
touch a3_results.txt
echo Kiriti Aryal > a3_results.txt 
echo R11722758 >> a3_results.txt
cd code/decrypt
./decrypt /lustre/work/errees/courses/cs4352/assignment3/input/encrypted.txt
../transform/transform 11722758
sed -n '5{p;q}' /lustre/work/errees/courses/cs4352/assignment3/input/.hidden_file >> ../../a3_results.txt 
cd ~
