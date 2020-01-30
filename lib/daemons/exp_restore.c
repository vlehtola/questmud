#define DATA "/data/old_exp_data"
#define PLAQUE_SIZE 301

string list,exps;
int levels;

reset(arg) {
  if(arg) return;
  list = allocate(PLAQUE_SIZE);
  exps = allocate(PLAQUE_SIZE);
  levels = allocate(PLAQUE_SIZE);
  if(!restore_object(DATA)) {
    write("Fail.\n");
  }
}

query_old_totals(string player) {
  int i;
  while(i< sizeof(list)) {
    if(list[i] == capitalize(player)) break;
    i++;
  }
  if(i == sizeof(list)) return -1;
  return exps[i];
}
