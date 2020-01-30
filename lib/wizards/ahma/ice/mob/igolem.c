inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(18 + random(3));
  set_name("ice golem");
  set_alias("golem");
  set_short("An ice golem");
  set_long("Sparkling, cold and hard ice forms this big-sized golem. Golem moves\n" +
           "very softly around the ice because its feet seem to have merged with\n" +
           "it. Golem has many projections, spikes and formations all over its\n" +
           "body, many of the formations represent sturdy muscles. The hard ice\n" +
           "covering the golem make it very painful and merciless opponent if\n" +
           "angered.\n");
  
  set_resists("cold", 85);
}

catch_tell(str) {
  object ob;
  string who, at_who;
  if(sscanf(str, "%s attacks %s", who, at_who) != 2) return;
  if(at_who != "Golem") return;
  if(query_attack()) return;
  ob = find_player(lower_case(who));
  say("Golem grunts at you and attacks!\n");
  attack_object(ob);
  return;
}