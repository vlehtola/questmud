resolve(bonus, target, caster_ob) {
    object ob;
    ob = find_player(target);
    if(!caster_ob)caster_ob=caster_ob;
    if (!ob) {
        tell_object(caster_ob, "No such a player.\n");
        return 1;
    }
    if(ob->query_wiz()) {
        tell_object(caster_ob, "You feel like you did something wrong.\n");
        caster_ob->reduce_hp(caster_ob->query_hp()-1);
        return 1;
    }
    if(environment(ob)->query_property("no_summon") || environment(caster_ob)->query_property("no_summon")) {
      tell_object(caster_ob, "A planar aura prevents you from entering that place.\n");
      return 1;
    }
    if (environment(ob)->query_not_out()) {
        tell_object(caster_ob, "You can't locate "+ob->query_name()+".\n");
        if (caster_ob->query_skills("navigation mastery") > random(120)) {
           tell_object(caster_ob, "...but due to your supreme knowledge of navigation you succeed.\n");
        } else { return 1; }
    }
    if (present("teleport lock", ob)) {
      tell_object(caster_ob, "You locate "+ob->query_name()+ ", but "+ob->query_pronoun()+" is locked beyond your reach.\n");
      return 1;
    }
    if (caster_ob->query_heavy_weight()) {
      tell_object(caster_ob, "Your teleport lock prevents you from teleporting.\n");
      return 1;
    }

    caster_ob->move_player("XX",environment(ob));
}
