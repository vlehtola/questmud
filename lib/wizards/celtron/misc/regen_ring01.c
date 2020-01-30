inherit "obj/armour";

/* ring converts hp regen to sp regen */
int regen;

start() {
  set_short("A silver ring with a strange blue-glowing jewel");
  set_long("The ring is well polished and reflects light so well\n"+
	   "it might be used as a mirror if it had any straight surface.\n"+
	   "The jewel embedded on it seems to have a light source\n"+
	   "of it's own. Some runes are carved on it.\n");
  set_name("ring");
  set_slot("finger");
}

init() {
::init();
add_action("read", "read");
}

read(string str) {
  if(str != "runes") return 0;
  write("The runes say: 'The healthier you get the weaker you are. Real turns into ethereal.'\n");
  return 1;
}

wear(string str) {
  ::wear(str);
  if(!worn_by) return 0;
  if(this_player()->query_wiz())
    write("Wizinfo: ring activated.\n");
  regen = worn_by->query_hp_regen();
  call_out("sp_transfer", 40);
  return 1;
}

sp_transfer() {
  if(!worn_by) return 0;
  tell_room(environment(worn_by), "The jewel on silver ring emits a sudden burst of light and then goes dark again.\n");
  worn_by->reduce_hp(regen);
  worn_by->add_sp(regen);
  call_out("sp_transfer", 20+random(20));
}
