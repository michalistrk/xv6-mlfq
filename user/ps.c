#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  struct pstat st;

  if(getpinfo(&st) < 0){
    printf("ps: getpinfo failed\n");
    exit(1);
  }

  printf("PID PPID STATE LVL TICKS WAIT SIZE NAME\n");

  for(int i = 0; i < NPROC; i++){
    if(st.inuse[i] == 0)
      continue;

    printf("%d %d %d %d %d %d %d %s\n",
      st.pid[i],
      st.ppid[i],
      st.state[i],
      st.level[i],
      st.ticks_used[i],
      st.wait_ticks[i],
      (int)st.sz[i],
      st.name[i]
    );
  }

  exit(0);
}
