#define PATH "/cmds/emotes/"

void init() {
  add_action("pnp","",1);
}

status pnp() {
  string str;
  str = lower_case(query_verb());
  if(file_size(PATH+str+".c") < 10) return 0;
  call_other(PATH+str+".c","cmd_"+str);
  return 1;
}
