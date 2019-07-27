DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
GENERAL="'$DIR/General.cpp'"
RESTAURANT="'$DIR/Restaurant.cpp'"
MAIN="'$DIR/main.cpp'"
EXECUTABLE="restaurant.out"
OUTPUT_FILE="'$DIR/$EXECUTABLE'"
COMMAND="g++ $GENERAL $RESTAURANT $MAIN -lncurses -o $OUTPUT_FILE"

echo $COMMAND
echo Note : Copy the generated command line above to compile this restaurant-project
echo To run the compiled executable, run cd "'$DIR'" and "'./$EXECUTABLE'"