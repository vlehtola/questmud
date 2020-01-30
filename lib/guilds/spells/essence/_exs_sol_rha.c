resolve(bonus, target, caster_ob) {
  object ob;
  int skills;
  ob = present("box", environment(caster_ob) );
  if(!ob) {
    tell_object(caster_ob, "You don't see any boxes here.\n");
    return 1;
  }

  skills = caster_ob->query_skills("cast trade")+caster_ob->query_skills("mastery of commerce")*2;

  skills += caster_ob->query_int()/2;

  skills /= 6;

  if(skills < random(70) || !random(13)) {
        tell_object(caster_ob, "You don't manage to unlock the box.\n");
        tell_room(environment(caster_ob), caster_ob->query_name()+" doesn't manage to "+
        "unlock the box.\n", ({ caster_ob }));
        return 1;
  }

  tell_object(caster_ob, "You magically unlock the box.\n");
  tell_room(environment(caster_ob), caster_ob->query_name()+" magically unlocks the box.\n", ({caster_ob}));
  if(ob) ob->force_unlock();
}
