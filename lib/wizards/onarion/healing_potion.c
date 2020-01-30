string short_desc, long_desc, alias, name;
int value, weight, heal;

reset() {
  name = "potion";
  alias = "healing potion";
  short_desc = "A blue healing potion";
  long_desc = "This is a healing potion. Maybe you could 'drink' it.\n";
  value = 100;
  weight = 20;
  heal = 100;
}

get() { return 1; }

id(str) { return str == name || str == alias || str == short_desc; }

short() { return short_desc; }

long() { write(long_desc); }

init() {
  add_action("drink","drink");
}

drink(str) {
  object ob;
  if (!str) { return 0; }
  if (this_object() != present(str)) { return 0; }
  write("You start drinking the potion.\n");
  call_out("real_drink", 2, this_player());
  return 1;
}

real_drink(tp) {
  write("You drink the potion and feel better.\n");
  tp->heal_hp(heal);
  destruct(this_object());
}

