module load gnu/5.4.0
touch a3_results.txt
echo Arogya Bhatta > a3_results.txt 
quanah:/work3$ echo R11594739>>a3_results.txt
cd code/decrypt
./decrypt /lustre/work/errees/courses/cs4352/assignment3/input/encrypted.txt
../transform/transform 11594739
sed -n '57{p;q}' /lustre/work/errees/courses/cs4352/assignment3/input/.hidden_file >> ../../a3_results.txt 
cd ~
