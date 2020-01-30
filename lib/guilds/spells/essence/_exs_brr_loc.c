/* Show coordinates */
resolve(bonus, target, caster_ob) {
	int x,y;
	object ob;
	if(!caster_ob)caster_ob=this_player();
	ob = file_name(environment(caster_ob));
	x = ob->query_x();
	y = ob->query_y();
	if(!y || !x) { tell_object(caster_ob, "This spell works only in the outworld.\n"); return 1; }
	tell_object(caster_ob, "You current coordination is: "+x+","+y+".\n");
	tell_room(environment(caster_ob), caster_ob->query_name()+" looks at sky looking for stars to show out the current location.\n", ({caster_ob}));
    return 1;
}
