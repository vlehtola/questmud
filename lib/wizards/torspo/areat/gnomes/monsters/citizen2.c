inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(random(2) + 10);
  set_race("gnome");
  set_name("aristocrat");
  set_gender(1);
  set_short("Gnome aristocrat");
  set_long("This fine and clean looking gnome lives in the better part of the city.\n"+
           "He's wearing some colourful clothes and looks very proud. Everyone can see\n"+
           "that he has done nothing to build this wonderful city better place\n"+
           "to live in.\n");

  set_al(10);
  set_al_aggr(200);
  set_max_hp(query_hp() + 75);
  set_hp(query_max_hp());
}
