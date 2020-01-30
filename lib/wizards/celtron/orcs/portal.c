string name;
int sp_to_destroyed;
query_name() { return name; }
short() { return "Dark portal"; }
long() {
  write("Orcs come through this portal to devastate the human kingdoms.\n");
  write("You can use your mental power to 'destroy' it.\n");
}
id(str) { return str == name; }
reset(arg) {
  if(arg)
    return;
  sp_to_destroyed = 6000;
  name = "portal";
  call_out("lisaa_orkkeja", 10);
}

lisaa_orkkeja() {
  int i,ii;
  if (!present("orc 2")) { i = random(4)+1; }
  while(ii<i) {
   move_object(clone_object("/wizards/celtron/orcs/orc_soldier"),environment());
   ii += 1;
  }
  call_out("lisaa_orkkeja", 20);
  return 1;
}

init() {
  add_action("destroy", "destroy");
}

destroy(str) {
  int sp;
  if(str != name) { write("Destroy what?\n"); return 1; }
  if(present("orc")) {
    write("Orc stops your attempt!\n");
    return 1;
  }
  if(this_player()->query_spell_points() < 1) {
    write("You are too low in power.\n");
    return 1;
  }
  sp = this_player()->query_sp();
  this_player()->reduce_sp(sp);
  write("You channel some of your power to weaken the portal.\n");
  sp_to_destroyed -= sp;
  if(sp_to_destroyed < 1) {
    write(" ..and succesfully destroy the portal!\n");
    say("Just before the portal vanishes, a HUGE orc jumps out of it!\n");
    this_player()->add_exp(10000000);
    move_object(clone_object("/wizards/celtron/orcs/orc_boss"),environment(this_object()));
    destruct(this_object());
  }
  return 1;
}  


