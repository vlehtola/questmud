#define WARLOCK_D "/daemons/warlock_d"
resolve(bonus, target, caster_ob) {
	object tgt;
	if(!caster_ob)caster_ob=this_player();
    if (present("teleport lock", caster_ob)) {
      tell_object(caster_ob, "Your teleport lock prevents you from teleporting.\n");
      tell_room(environment(caster_ob), "Teleport lock.\n");
      return 1;
    }
    if(caster_ob->query_demon()) {
	tgt = find_player(caster_ob->query_demon_master());
    } else if(!caster_ob->query_demon()) {
	tgt = WARLOCK_D->query_demon(caster_ob->query_real_name());
}
if(!tgt) {
tell_object(caster_ob, "You don't have demon summoned.\n");
tell_room(environment(caster_ob), "You don't have demon summoned.\n");
return 1;
}
if(environment(tgt)->query_property("no_summon") || environment(caster_ob)->query_property("no_summon")) {
tell_object(caster_ob, "A planar aura prevents you from entering that place.\n");
return 1;
}
tell_object(caster_ob, "As you create a void here, your environment suddenly changes.\n");
tell_room(environment(caster_ob), caster_ob->query_name()+" leaves in a puff of smoke.\n", ({ caster_ob }));
move_object(caster_ob, environment(tgt));
tell_room(environment(caster_ob), caster_ob->query_name()+" arrives in a puff of smoke.\n", ({ caster_ob }));
return 1;
}
