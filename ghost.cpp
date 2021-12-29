#include <utility>
#include "campo.hpp"

using namespace std;

class Ghost {
    public:
        Ghost (int _id, pair<int, int> _position) {
            id = _id;
            position = _position;
            previousPosition = make_pair(-1, -1);
        }

        int getId() { 
            return id; 
        }

        pair<int, int> getPosition() {
            return position;
        }

        // void move(int campo[LINES][COLUMNS]){

        // }

    private:
        int id;
        pair<int, int> previousPosition;
        pair<int, int> position;
};
