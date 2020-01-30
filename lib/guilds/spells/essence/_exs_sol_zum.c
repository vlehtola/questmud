resolve(bonus, target, caster_ob) {
  object ob;
  int time;
  string tmp;
  if(call_other("/guilds/spell_obj/valid_ffield_room", "query_invalid")) return 1;

  ob = clone_object("/guilds/spell_obj/shelter");
  move_object(ob, environment(caster_ob));
  time = (bonus * 5 + caster_ob->query_skills("cast earth")*8)/2;
  if(time > 20*60) time = 20*60;
  time = time/3;

  if(this_player()->query_real_name() == "golthar") time = 10;

  ob->start(time);
  tell_object(caster_ob, "You create a yellow force field.\n");
  tell_room(environment(caster_ob),ob->short()+" appears from nowhere!\n", ({caster_ob}));
  return 1;
}
