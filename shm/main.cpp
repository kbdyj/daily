#include <iostream>

using namespace std;

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
bool full = false;

void producer(int count)
{
    for (int i=0; i<count; i++) {
        //if ((in + 1) % BUFFER_SIZE == out) {
        if (full) {
            cout << "[error] full! in: " << in << ", out: " << out << "(" << i << "/" << count << ")" << endl;
            break;
        }
        buffer[in] = i;
        in = (in + 1) % BUFFER_SIZE;
        full = in == out;
    }
}

void consumer(int count)
{
    for (int i=0; i<count; i++) {
        if (!full && (in == out)) {
            cout << "[error] empty! in == out: " << in << "(" << i << "/" << count << ")" << endl;
            break;
        }
        cout << "[" << i << "]: " << buffer[i] << endl;
        out = (out + 1) % BUFFER_SIZE;
        full = false;
    }
}

int main()
{
    producer(10);
    consumer(11);

    return 0;
}
