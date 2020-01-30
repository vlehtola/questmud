mapping lista;

vote(sub,num) {
  object ob;
  string str;
  if(!sub) {
    write("Usage: vote <subject> <number>\n");
    return 1;
  }
  if(!num) {
    remove_vote(sub);
    return 1;
  }
  if(!check_valid_sub(sub,num)) { return 1; }
}
check_valid_sub(sub,num) {
  if(sub) {
    if(sub[num]) return 1;
  }
}
reset(arg) {
  if(arg) return;
  lista = ([ ]);
  /* lista: ([ subject: votes;name,name2,name3,name4,name5 ]) */
  if(!restore_object("world/objects/vote_data"))
    save_object("world/objects/vote_data");
}

init() {
  add_action("vote", "vote");
  add_action("list", "list");
}
short() { return "A voting table"; }
long() {
  write("This is a voting table. Players over level 15 can vote.\n");
  write("Available commands: vote <subject> <number>, list [ <subject> ]\n");
  write("'vote' without an argument removes your vote from specified subject.\n");
}


