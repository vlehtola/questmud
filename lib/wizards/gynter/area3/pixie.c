inherit "/obj/monster";

reset(arg) {
  int i;
  ::reset(arg);
  if(arg) return;
  i = random(2);
  set_level(10+i*5);
  set_name("pixie");
  set_short("A green little pixie");
  set_long("A small pixie is sitting here looking\nfor something to eat.\n");
  set_gender(1);
}

