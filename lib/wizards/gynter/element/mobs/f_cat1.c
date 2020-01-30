inherit "obj/monster";

reset(arg) {
  int i;
  object money, item;
  ::reset(arg);
  if(arg) { return; }
set_race("cat");
  i = random(2);
  set_level(10+i*5);
  set_name("cat");
  set_alias("cat");
  set_short("A fire cat");
  set_long("These are the pets of the fire demons.\n" +
  "They look exactly like a normal cat, except that they are burning!\n");
  set_al(50);
  set_aggressive(0);

  item = clone_object("/wizards/gynter/element/eq/key");
  move_object(item, this_object());
}
