resolve(bonus, target, caster_ob) {
  int tmp;
  object ob;
  if(!target || !sscanf(target,"%d",tmp) == 1) {
    tell_object(caster_ob, "Usage: cast exs zzt cre at <spboost>\n");
    return 1;
  }
  if(tmp > caster_ob->query_sp()) {
    tell_object(caster_ob, "You don't have enough sp.\n");
    return 1;
  }
  caster_ob->reduce_sp(tmp);
  tell_object(caster_ob, "You create an amulet.\n");
  tell_room(environment(caster_ob),caster_ob->query_name()+" creates a shining amulet.\n", ({caster_ob}));
  move_object(ob = clone_object("/guilds/spell_obj/amulet"),caster_ob);
  ob->make_me(bonus,tmp);
  return 1;
}
