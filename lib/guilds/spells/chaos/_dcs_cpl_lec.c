resolve(bonus, target, caster_ob) {
	if(!caster_ob)caster_ob=this_player();
    if (present("teleport lock", caster_ob)) {
     tell_object(caster_ob, "Your teleport lock prevents you from teleporting.\n");
      return 1;
    }
    if(environment(caster_ob)->query_property("no_summon")) {
	tell_object(caster_ob, "A planar aura prevents you from entering that place.\n");
	return 1;
	}
    tell_object(caster_ob, "You teleport yourself back to the guild.\n");
    caster_ob->move_player("in the void leaving only a small puff of smoke behind#/guilds/warlock/warlock");
}
