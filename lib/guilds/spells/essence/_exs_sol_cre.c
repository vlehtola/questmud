resolve(bonus, target, caster_ob) {
    if(!caster_ob)caster_ob=this_player();
    tell_object(caster_ob, "You create some food.\n");
    tell_room(environment(caster_ob), caster_ob->query_name()+" creates some food.\n", ({ caster_ob }));
    if (bonus > 200) {
	move_object(clone_object("/world/objects/ham"), caster_ob);
	return 1;
    }
    if (bonus > 100) {
	move_object(clone_object("/world/objects/bread"), caster_ob);
	return 1;
    }
    move_object(clone_object("/world/objects/cheese"), caster_ob);
}
