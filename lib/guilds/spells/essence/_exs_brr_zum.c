resolve(bonus, target, caster_ob) {
  object ob;
  int time;
  string tmp;
  if(call_other("/guilds/spell_obj/valid_ffield_room", "query_invalid")) return 1;
  if(!caster_ob)caster_ob=this_player();
  ob = clone_object("/guilds/spell_obj/anti_magic_field");
  time = (bonus * 5 + caster_ob->query_skills("lore of cold")*8)/2;
  if(time > 60*20) time = 60*20;
  ob->start(time);
  move_object(ob, environment(caster_ob));
  tell_object(caster_ob, "You create a purple force field.\n");
  tell_room(environment(caster_ob), ob->short()+" appears from nowhere!\n");
  return 1;
}
