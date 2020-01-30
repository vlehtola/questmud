string short() {
  return "A dimensional gate to another world";
}

/* voi lisaa kamaa */
status add_weight(int i) {
  return 1;
}

status can_put_and_get() {
  return 1;
}

void long() {
write("Hard to say anything, bright light is consumed from it.\n"+
      "Maybe you should enter it to take care of the monsters?\n");
}

status id(string str) { return str == "gate" || str == "dimensional gate"; }

void reset(status arg) {
  if(arg) return;
  call_out("vanish",300);
}

void init() {
  add_action("enter","enter");
}

status enter(string str) {
  object ob;
  if(str != "gate" && str != "dimensional gate") return 0;
  ob = this_player();
  say(capitalize(ob->query_real_name())+" jumps into the gate.\n",ob);
  write("You jump into the gate and some force keeps your eyes shut.\n");
  move_object(ob,"/wizards/garath/dimension/dimension.c");
  write("Suddenly your eyes open again and you notice that you aren't at home.\n");
  say(capitalize(ob->query_real_name())+" drops from the gate.\n");
return 1;
}

void vanish() {
  say("The dimensional gate suddenly closes.\n");
  destruct(this_object());
}
