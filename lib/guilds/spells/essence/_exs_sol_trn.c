resolve(bonus, target, caster_ob) {
    object ob;
    string target2;
    if(!target) {
      tell_object(caster_ob, "You must direct this spell at someone.\n");
      return 1;
    }
    ob = present(target, environment(caster_ob));
    if (!ob) {
        tell_object(caster_ob, "No '"+capitalize(target)+"' here.\n");
        return 1;
    }
    if (ob->query_heavy_weight()) {
        tell_object(caster_ob, capitalize(target) +" already has a teleport lock.\n");
        return 1;
    }
       target2 = target;
           if (target) { target = capitalize(target); }
           if (target2) { target2 = capitalize(target2); }
           if (ob == caster_ob) {
           target = "yourself";
           target2 = caster_ob->query_objective()+"self";
           }
    move_object(clone_object("/guilds/spell_obj/teleport_lock.c"), ob);
    tell_object(caster_ob, "You cast a teleport lock on "+target+".\n");
    tell_room(environment(caster_ob),caster_ob->query_name()+" casts a teleport lock on "+target2+".\n", ({caster_ob, ob}));
       if(ob != caster_ob) {
    tell_object(ob, caster_ob->query_name()+" casts a teleport lock on you.\n");
}
    return 1;
}
