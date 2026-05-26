void test_consumer_producer();
void test_shm();
int test_pipe();
int test_fork();
void test_pthread(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    //test_consumer_producer();
    //test_shm();
    //test_pipe();
    //test_fork();

    test_pthread(argc, argv);

    return 0;
}
