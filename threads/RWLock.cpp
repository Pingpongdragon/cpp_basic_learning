#include <mutex>
#include <condition_variable>

class RWLock{
public :
    RWLock() : read_count(0),write_count(0) {}
    ~RWLock() = default;

    void read_lock(){
        std::unique_lock<std::mutex> lock(mtx);
        while(write_count > 0){
            cv.wait(lock);
        }
        read_count++;
    }

    void write_lock(){
        std::unique_lock<std::mutex> lock(mtx);
        while(read_count > 0 || write_count > 0){
            cv.wait(lock);
        }
        write_count++;
    }

    void unlock(){
        std::unique_lock<std::mutex> lock(mtx);
        if(write_count > 0){
            write_count--;
        }else{
            read_count--;
        }
        if(write_count == 0 && read_count == 0){
            cv.notify_all();
        }else{
            cv.notify_one();
        }
    }
private:
    std::mutex mtx;
    std::condition_variable cv;
    int read_count;
    int write_count;
};