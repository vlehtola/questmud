inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(20);
  set_race("ogre");
  set_name("child");
  set_alias("servant");
  set_short("Ogre child");
  set_long("This small ogre child is the servant of these nobles. He looks pleasant and\n"+
           "has quite clean clothes on him. While all the other ogre children are trained\n"+
           "to kill from the day they are born, this child seems to be educated.\n");
  set_al(-1);
  set_gender(1);
}
