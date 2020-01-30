string short_desc, long_desc, alias, name, alt_alias;
int value, weight, heal;

reset() {
  name = "bowl";
  alias = "rabbitsoup";
  alt_alias = "soup";
  short_desc = "A bowl of warm rabbitsoup";
  long_desc = "A wooden bown full of warm rabbitsoup. The smell is\n"+
              "delicious.\n";
  value = 100;
  weight = 3;
  heal = random(10)+20;
}

get() { return 1; }

id(str) { return str == name || str == alias || str == alt_alias ||str == short_desc; }
short() { return short_desc; }

long() { write(long_desc); }

init() {
  add_action("drink","drink");
}

drink(str) {
  object ob;
  if (!str) { return 0; }
  if (this_object() != present(str)) { return 0; }
  write("You drink the entire bowl.\n");
  say(this_player()->query_name()+" drinks something warm from a bowl.\n");
  real_drink(this_player());
  return 1;
}

real_drink(tp) {
  write("You feel warm inside.\n");
  tp->heal_hp(heal);
  
  move_object(clone_object("/wizards/siki/island/obj/bowl"), environment(this_object()));
  destruct(this_object());


}


