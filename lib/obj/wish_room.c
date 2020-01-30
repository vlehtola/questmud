inherit "room/room";

#define CLEARCOST 50000

static mapping lesser, greater, minor;

reset(arg) {
  if (arg) { return; }
  add_exit("north", "/world/city/adventurers_hall");
//  add_exit("west", "/world/special/free_reinc_room");
  short_desc = "Wish room";
  long_desc =
"This is the wish room. You can buy special abilities with Task Points.\n"+
"See 'help donate' to get more info.\n"+
"Available commands:\n"+
"   list [minor/lesser/greater]\n"+
"   select [minor/lesser/greater] [number]\n"+
"   clear wishes [clears your wishes for "+CLEARCOST/1000+"k bronze coins]\n";
  set_light(3);
  lesser = ([ ]);
  greater = ([ ]);

    property = allocate(4);
    property[0] = "no_kill";
    property[1] = "no_skill";
    property[2] = "no_spell";
    property[3] = "no_summon";

}

init() {
  ::init();
  add_action("list","list");
  add_action("select","select");
  add_action("clear","clear");
}

list(arg) {
   if (arg == "minor") {
	write("1.  Free reincarnation (disabled)\n");
	write("2.  +50 Maximum level.\n");
	write("NB! The maximum level wish is permanent.\n");
	write("    It isn't cleared on reincarnation.\n");
	return 1;
   }
   if (arg == "lesser") {
	write("List of lesser wishes:\n");
	write("1.  +15% Exprate\n");
	write("2.  +10% Skillmax (disabled)\n");
	write("3.  +10% Spellmax (disabled)\n");
	write("4.  +25% All stats\n");
	write("5.  +40% Str\n");
	write("6.  +40% Dex\n");
	write("7.  +40% Con\n");
	write("8.  +40% Int\n");
	write("9.  +40% Wis\n");
	return 1;
   }
   if (arg == "greater") {
	write("List of greater wishes:\n");
	write("1.  +30% Exprate\n");
	write("2.  +20% Skillmax (disabled)\n");
	write("3.  +20% Spellmax (disabled)\n");
	write("4.  +50% All stats\n");
	write("5.  +80% Str\n");
	write("6.  +80% Dex\n");
	write("7.  +80% Con\n");
	write("8.  +80% Int\n");
	write("9.  +80% Wis\n");
	return 1;
   }
   write("Syntax: list [minor/lesser/greater]\n");
   return 1;
}

select(arg) {
   int num, cost, much;
   string type;
   if (!arg) {
	write("Syntax: select [minor/lesser/greater] [number]\n");
	return 1;
   }
   if (sscanf(arg, "%s %d", type, num) != 2) {
	write("Syntax: select [minor/lesser/greater] [number]\n");
	return 1;
   }
   if (type == "minor") {
	if (this_player()->query_task_points() < 50) {
	  write("You don't have enough task points.\n");
	  return 1;
	}
	if (num == 1) {
          write("This option is disabled.\n");
          return 1;
	  if (this_player()->query_free_exp() != "0") {
	    write("You have free exp, spend them first.\n");
	    return 1;
	  }
	  this_player()->remove_task_points(50);
	  this_player()->reinc();
	  move_object(this_player(), "/obj/race_selection");
	  write("You reincarnate.\n");
	  return 1;
	}
	if (num == 2) {
	    if (!this_player()->add_max_level(50)) {
		write("You already have a maximum level available.\n");
		return 1;
	    }
            this_player()->remove_task_points(50);
	    write("You now have a maximum level of "+
		this_player()->query_max_level()+".\n");
	    return 1;
	}
   }
   if (type == "lesser") {
	cost = 100 + this_player()->query_lesser_wish() * 25;
	if (num < 1 || num > 9) { write("No such number.\n"); return 1; }
	if (this_player()->query_task_points() < cost) {
		write("You don't have enough tps.\n");
		return 1;
	}
	if (this_player()->query_lesser_wish(num)) {
		write("You already have that wish.\n");
		return 1;
	}

	if (num == 1) { this_player()->add_pros(15, "exp_rate"); }
	if (num == 2) { this_player()->add_pros(10, "skill_max"); }
	if (num == 3) { this_player()->add_pros(10, "spell_max"); }

	much = 25;
	if (num == 4) {
	   this_player()->add_pros(much,"str");
	   this_player()->add_pros(much,"dex");
	   this_player()->add_pros(much,"con");
	   this_player()->add_pros(much,"int");
	   this_player()->add_pros(much,"wis");
	}

	much = 40;
	if (num == 5) { this_player()->add_pros(much,"str"); }
	if (num == 6) { this_player()->add_pros(much,"dex"); }
	if (num == 7) { this_player()->add_pros(much,"con"); }
	if (num == 8) { this_player()->add_pros(much,"int"); }
	if (num == 9) { this_player()->add_pros(much,"wis"); }

	this_player()->set_lesser_wish(num);
	this_player()->reduce_task_points(cost);
	this_player()->update_stats();

	write("You get lesser wish number "+num+".\n");
	return 1;
   }
   if (type == "greater") {
	cost = 200 + this_player()->query_greater_wish() * 50;
	if (num < 1 || num > 10) { write("No such number.\n"); return 1; }
	if (this_player()->query_task_points() < cost) {
		write("You don't have enough tps.\n");
		return 1;
	}
	if (this_player()->query_greater_wish(num)) {
		write("You already have that wish.\n");
		return 1;
	}
	if (num == 1) { this_player()->add_pros(30, "exp_rate"); }
	if (num == 2) { this_player()->add_pros(20, "skill_max"); }
	if (num == 3) { this_player()->add_pros(20, "spell_max"); }

	much = 50;
	if (num == 4) {
	   this_player()->add_pros(much,"str");
	   this_player()->add_pros(much,"dex");
	   this_player()->add_pros(much,"con");
	   this_player()->add_pros(much,"int");
	   this_player()->add_pros(much,"wis");
	}

	much = 80;
	if (num == 5) { this_player()->add_pros(much,"str"); }
	if (num == 6) { this_player()->add_pros(much,"dex"); }
	if (num == 7) { this_player()->add_pros(much,"con"); }
	if (num == 8) { this_player()->add_pros(much,"int"); }
	if (num == 9) { this_player()->add_pros(much,"wis"); }

	this_player()->set_greater_wish(num);
	this_player()->reduce_task_points(cost);
	this_player()->update_stats();

	write("You get greater wish number "+num+".\n");
	return 1;
   }
}

clear(str) {
	int i,much;

  /* return 0; fixed 01022009 //Kaappi */
  /* removed this func since it bugs. //Celtron */

	if ( !str ) {
		write("Clear what?\n");
		return 1;
	}
	if ( this_player()->query_money(3) < CLEARCOST ) {
		write("You don't have enough money.\n");
		return 1;
	}
	this_player()->reduce_money(CLEARCOST,3);
	
	for (i = 1; i < 10; i++ ) {
		if ( this_player()->query_lesser_wish(i) ) {
			if (i == 1) { this_player()->add_pros(-15, "exp_rate"); }
			if (i == 2) { this_player()->add_pros(-10, "skill_max"); }
			if (i == 3) { this_player()->add_pros(-10, "spell_max"); }

			much = -25;
			if (i == 4) {
	   		this_player()->add_pros(much,"str");
	   		this_player()->add_pros(much,"dex");
	   		this_player()->add_pros(much,"con");
	   		this_player()->add_pros(much,"int");
	   		this_player()->add_pros(much,"wis");
			}

			much = -40;
			if (i == 5) { this_player()->add_pros(much,"str"); }
			if (i == 6) { this_player()->add_pros(much,"dex"); }
			if (i == 7) { this_player()->add_pros(much,"con"); }
			if (i == 8) { this_player()->add_pros(much,"int"); }
			if (i == 9) { this_player()->add_pros(much,"wis"); }
		}
	}

  for (i = 1; i < 10; i++) {
   if ( this_player()->query_greater_wish(i) ) {
			if (i == 1) { this_player()->add_pros(-30, "exp_rate"); }
			if (i == 2) { this_player()->add_pros(-20, "skill_max"); }
			if (i == 3) { this_player()->add_pros(-20, "spell_max"); }

			much = -50;
			if (i == 4) {
	   		this_player()->add_pros(much,"str");
	   		this_player()->add_pros(much,"dex");
	   		this_player()->add_pros(much,"con");
	   		this_player()->add_pros(much,"int");
	   		this_player()->add_pros(much,"wis");
			}

			much = -80;
			if (i == 5) { this_player()->add_pros(much,"str"); }
			if (i == 6) { this_player()->add_pros(much,"dex"); }
			if (i == 7) { this_player()->add_pros(much,"con"); }
			if (i == 8) { this_player()->add_pros(much,"int"); }
			if (i == 9) { this_player()->add_pros(much,"wis"); }
		}
	}
	
	this_player()->reset_wishes();
	this_player()->update_stats();
	write("Wishes are now cleared.\n");
	return 1;
}
