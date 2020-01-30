object master_ob;

get_master_ob() {
  master_ob = find_object("/wizards/bulut/event/pkobj");
  if(!master_ob) {
    destruct(this_object());
    return 0;
  }
  return 1;
}

short() {
  return("A small paper (glowing)"); 
}


init() { 
  add_action("living","living");
}


long() {
  write("living = show who's still alive\n");
}

living() {
  if(!get_master_ob()) {
    write(short()+" vanishes.\n");
    return 0;
  }
  write("Still alive: " + master_ob->query_players());
  write("\n");
  return 1;
}

id(str) {
return str == "paper";
}

