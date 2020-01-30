resolve(bonus, target, caster_ob) {
  object ob;
  int time;
  string tmp;
  if(call_other("/guilds/spell_obj/valid_ffield_room", "query_invalid")) return 1;

  ob = clone_object("/guilds/spell_obj/force_field");
  time = (bonus * 5 + caster_ob->query_skills("knowledge of heat")*8)/2;
  if(time > 20*60) time = 20*60;
  ob->start(time);
  move_object(ob, environment(caster_ob));
  tell_object(caster_ob, "You create a bright red force field.\n");
  tell_room(environment(caster_ob),ob->short()+" appears from nowhere!\n", ({caster_ob}));
  return 1;
}
