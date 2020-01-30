inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_level(8);
  set_name("fox");
  set_short("A fox with a long tail");
  set_long("The fox seems to be looking after some small animals to eat.\n");
  set_gender(random(2)+1);
  set_animal(1);
}
