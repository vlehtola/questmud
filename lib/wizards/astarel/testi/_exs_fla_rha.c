status disc_filter(object ob) {
	if(ob->query_disc_owner() == this_player()->query_name()) return 1;
	return 0;
}

resolve(int bonus,string str) {
	object ob;
	object *obs;
	
	int i;


	obs = all_inventory(environment(this_player()));
	obs = filter_array(obs,"disc_filter");

	if(sizeof(obs) == 0) {
		ob = clone_object("/guilds/spell_obj/floating_disc");
		move_object(ob, environment(this_player()));
		ob->set_power(bonus, this_player());
		write("You summon your floating disc.\n");	
		return 1;
		} 	
	
	else {
		ob = obs[0];
		ob->set_power(bonus, this_player(),1);
        write("You refresh your floating disc.\n");
        say(this_player()->query_name()+" refreshes "+
		this_player()->query_possessive()+" floating disc.\n");
		return 1;
	}
}
	

			



