inherit "obj/monster";

reset(arg) {
  ::reset(arg);   
  if(arg) { return; }
  set_level(random(5) + 25);
  set_animal(1);
  set_name("deer");
  set_alias("animal");
  set_short("A wild, big antlered forest deer");
  set_long("A wild deer with two, big, finely arched antlers. It's quite strong,\n"+
           "muscular and big-sized. Furry and brown fur coat is covering the\n"+
           "deer, giving warmth and protection from cold, rainy days.\n");
  set_al(0);
  set_skill("kick", 100);
  set_skill_chance("kick", 5);
  set_max_hp(query_hp() + 1000);
  set_hp(query_max_hp());
}
