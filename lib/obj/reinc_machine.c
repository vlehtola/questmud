reset(arg) {
  if(arg) { return; }
}

id(str) { return str == "machine"; }

short() { return "A free reinc machine"; }

long() { 
  write("'pull' lever if you want to comit a free reinc.\n");
}

init() {
  add_action("pull", "pull");
}

pull(st) {
  string str;
  int i,cost;
  this_player()->end_berserk();
  if(st == "lever") {
    write("You pull the lever and feel that something happened.\n");
    comit_reinc();
    return 1;
  }
  if(st == "lever 2") {
    write("You pull the lever and feel that something happened.\n");
    str = this_player()->query_total_string();
    if(strlen(str) < 11) {
	write("Too low worth.\n");
	return 1;
    }
    str = extract(str,0,1);
    if(strlen(str) > 11) str += 0;
    sscanf(str, "%d", i);
    cost = i*1000000;
    write("Reinc cost: "+cost+" xp\n");
    this_player()->reduce_total_worth(i*1000000);
    comit_reinc(1);
    return 1;
  }
  write("Pull what?\n");
  return 1;
}

comit_reinc(arg) {
  int i;
  object ob;
  if(strlen(this_player()->query_total_string()) > 10 && !arg) {
    write("You have more than 10G worth. Use lever 2. (Cost 5%)\n");
    return 1;
  }
  this_player()->save_me(1);
  if(!this_player()->reinc()) return 1;
  ob = all_inventory(this_player());
  while(i<sizeof(ob)) {
    if(ob[i] && ob[i]->short()) { destruct(ob[i]); }
    i += 1;
  }
  move_object(this_player(), "/obj/race_selection");
}






