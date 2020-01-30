inherit "obj/armour";
int stored;

start() {
set_class(20);
  set_slot("torso");
    set_name("robes");
    set_alias("grey robes");
    set_short("Grey robes of the Nine Moons");
    set_long("These robes are made of fine grey silk. Pictures of nine moons,\n"+
	     "each in a different lunar state have been sewn into them. The pictures\n"+
             "radiate slightly and you get a strange urge to touch them.\n");
    set_value(5000);
    set_stats("int",5);
    set_stats("spr",10);
    set_weight(2);
    set_resists(1,1,1);
}

init() {
add_action("touch","touch");
::init();
}

touch(str) {
	if(str!="full moon" && str!="new moon" && str!="robes") {
		write("Touch what?\n");
		return 1;
	}

	if(this_object()->query_worn() == 0) {
		write("The robes burn your fingers!\n");
		say(this_player()->query_name()+" burns "+this_player()->query_possessive()+
		    " fingers while fiddling with "+this_player()->query_possessive()+" robes!\n");
		this_player()->hit_with_spell(50,"fire");
		return 1;
	}
	if(str=="full moon" && stored==0) {
		write("Nothing happens.\n");
		return 1;
	}
	if(str=="full moon" && stored!=0) {
		write("You touch the picture of the full moon and feel your magical power returning!\n");
		say(this_player()->query_name()+" fiddles with "+this_player()->query_possessive()+" robes.\n");
		this_player()->add_sp(stored);
		stored=0;
		return 1;
	}
	if(str=="new moon" && stored>=1000) {
		write("Nothing happens.\n");
		return 1;
	}
	if(str=="new moon" && stored<1000) {
		write("You touch the picture of the new moon and feel your magical power draining away!\n");
		say(this_player()->query_name()+" fiddles with "+this_player()->query_possessive()+" robes.\n");
		stored=stored+(this_player()->query_sp()/2);
		if(stored>1000) stored=1000;
		this_player()->set_sp(0);
		return 1;
	}
	if(str=="robes") {
		say(this_player()->query_name()+" fiddles with "+this_player()->query_possessive()+" robes.\n");
		switch(stored) {
		 case 0:
		  write("The robes contain no magical power.\n");
		  break;
		 case 1 .. 250:
		  write("The robes contain a bit of magical power.\n");
		  break;
		 case 251 .. 500:
		  write("The robes contain some magical power.\n");
		  break;
		 case 501 .. 750:
		  write("The robes contain a large amount of magical power.\n");
		  break;
		 case 751 .. 999:
		  write("The robes contain a lot of magical power.\n");
		  break;
		 case 1000:
		  write("The robes are full of magical power.\n");
		  break;
		 }
	return 1;
	}
}
