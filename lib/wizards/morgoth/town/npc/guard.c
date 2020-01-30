inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(30);
  set_race("human");
  set_name("guard");
  set_alias("guard");
  set_gender(2);
  set_short("Muscular guard");
  set_long("This man guards the entrance to the city of Hooroomoo. \n");
  set_al(9);
 }
