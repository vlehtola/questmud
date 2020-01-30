cmd_cast(str) {
    int sp_boost;
    string class;
    if (!this_player()->check_condis()) { return 1; }
    if (!str) {
	write("You are boosting offensive spells with "+
		this_player()->query_sp_boost(1)+ " sp.\n");
	write("See 'help cast' for more information.\n");
	return 1;
    }

  // added by C 20.5.04
    if(this_player()->query_max_death_legacy_time() *6/7 < this_player()->query_death_legacy_time()) {
      write("You are still not fully recovered from resurrection.\n");
      return 1;
    }

    if (str == "stop") {
        if (this_player()->query_spell()) {
            write("You interrupt your spell.\n");
            this_player()->query_spell()->interrupt_spell();
            return 1;
        }
        else {
            write("You are not casting anything.\n");
            return 1;
        }
    }
    if (sscanf(str, "%s %d", class, sp_boost) == 2) {
        if (class == "offensive") {
	   if (sp_boost < 1 || sp_boost > this_player()->query_max_sp()/4) {
             write("Your minimum sp boost is 1 and maximum is "+(this_player()->query_max_sp()/4)+".\n");
             return 1;
           }
           if(this_player()->query_spell()) {
		write("Cannot change boost while casting.\n");
		return 1;
	   }
	   this_player()->set_sp_boost("offensive", sp_boost);
           write("Setting your offensive boost to "+sp_boost+" sp.\n");
	   call_other("/guilds/obj/boost.c", "offensive_boost", sp_boost, 1);
           return 1;
        }
	write("No such a boost class. See 'help cast'.\n");
	return 1;
    }
    if (environment(this_player())->query_property("no_spell") ||
	present("amf",environment(this_player())) &&
	present("amf",environment(this_player()))->query_amf()) {
      write("A mystical force interrupts your concentration.\n");
      return 1;
    }
    if (this_player()->query_spell()) {
        write("You interrupt your previous spell and start a new one.\n");
        destruct(this_player()->query_spell());
    }
    if(this_player()->query_use_skill()) {
        write("You interrupt your skill and start casting a spell.\n");
	destruct(this_player()->query_use_skill());
    }
    this_player()->remove_invisibility();
    this_player()->set_spell(clone_object("/guilds/obj/spell"));
    if(this_player()->query_spell())
       this_player()->query_spell()->start_spell(str);
    return 1;
}

