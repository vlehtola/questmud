cmd_halt() {
	object *ob;
	int i;
	ob = all_inventory(environment(this_player()));
	for(i=0;i<sizeof(ob);i++) {
	if(ob[i]->query_attacker()) {
		ob[i]->stop_all();
		ob[i]->stop_fight();
		ob[i]->reset_hunger_list();
	}
}
	write("Halting combat.\n");
	say(this_player()->query_name()+" halts the combat.\n");
	return 1;
}