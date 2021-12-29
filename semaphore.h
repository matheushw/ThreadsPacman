#include <mutex>
#include <condition_variable>

using namespace std;
        
class Semaphore {
    public:
        Semaphore (int _count = 0) : count(_count) {}
        
        void notify() {
            unique_lock<mutex> lock(mtx);
            count++;
            cv.notify_one();
        }

        void wait() {
            unique_lock<mutex> lock(mtx);
            while(count == 0) {
                cv.wait(lock);
            }
            count--;
        }

    private:
        mutex mtx;
        condition_variable cv;
        int count;
};
