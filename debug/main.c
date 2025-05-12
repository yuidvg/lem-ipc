#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	const int msgq_id = msgget(IPC_PRIVATE, IPC_CREAT | 0664);
	return 0;
}