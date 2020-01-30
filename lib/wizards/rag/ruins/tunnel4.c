inherit "room/room";
object monster;
int kingscore, paladinscore;
int god, poison;

reset(arg) {
        if(arg) return;
        if(!monster) {
                monster = clone_object("/wizards/rag/ruins/mon/lichking");
                move_object(monster,this_object());
        }

        short_desc = "A dark chamber";
        long_desc =     "This is a dark chamber. It has been made of the same rocks as the\n"+
			"tunnel. There is a large stone throne in the middle of this room.\n"+
			"Some torches are burning on the walls. A large bookshelf is located\n"+
			"in the back of the chamber.\n";

        items = allocate(8);
        items[0] = "throne";
        items[1] = "Evil forces seem to flow from this massive throne";
        items[2] = "books";
        items[3] = "You get a really bad feeling about these books";
        items[4] = "bookshelf";
        items[5] = "There are some books concerning dark magicks";
        items[6] = "shelf";
        items[7] = items[5];

        set_not_out(1);
	set_light(3);

	kingscore = 1;
	paladinscore = 0;
	god = 0;
	poison = 0;
}

add() {
	tell_room(this_object(),"Suddenly a doorway opens, leading east.\n");
	add_exit("east","/wizards/rag/ruins/tunnel3");
	return 1;
}

rem() {
	remove_exit("east");
	tell_room(this_object(),"Suddenly the doorway closes and only a wall remains.\n");
	return 1;
}

chant(str) {
  if((str == "deus" || str == "pater" || str == "lux" || str == "pax") && !god) {
    tell_room(this_object(),"\nA shimmering light appears and rays of golden light shower the Lich King with Holy Might.\n");
    tell_room(this_object(),"The Lich King cringes in pain!\n");
    paladinscore += 2;
    god = 1;
  }
  if(str == "venenum" && !poison) {
    tell_room(this_object(),"\nA green cloud appears over the Paladin who looks very sick.\n");
    tell_room(this_object(),"The Paladin whimpers in pain!\n");
    kingscore++;
    poison = 1;
  }
  return 1;
}

battle() {
	call_other("/wizards/rag/ruins/tunnel3","rem");
	tell_room(this_object(),"\nThe Lich King cackles diabolically and attacks the Paladin!\n");
	tell_room(this_object(),"The Paladin parries and ripostes with a fierce strike!\n");
	call_out("event1",1);
	return 1;
}

event1() {
	tell_room(this_object(),"\nThe Lich King starts chanting!\n");
	tell_room(this_object(),"The Paladin screams to the Heavens and a ray of light pierces the King!\n");
	call_out("event1a",4);
	return 1;
}


event1a() {
	tell_room(this_object(),"\nThe Paladin chants a silent prayer and strikes with divine Might!\n");
	tell_room(this_object(),"The Lich King forms a barrier with unholy magicks!\n");
	tell_room(this_object(),"A golden ray seems to strike againts the black barrier of the Lich King!\n");
	call_out("event2",3);
	return 1;
}

event2() {
	tell_room(this_object(),"\nA choir of angels appears and they sing to destroy the Lich King's barrier!\n");
	tell_room(this_object(),"The Lich King swings his Sceptre and he seems to be replenished!\n");
	tell_room(this_object(),"The paladin shouts: 'Use the scroll!'\n");
	call_out("event3",5);
	return 1;
}


event3() {
	tell_room(this_object(),"\nSome lich mages arrive in a puff of smoke!\n");
	tell_room(this_object(),"The Paladin is hit by a Fire Bolt but the bolt is reflected.\n");
	tell_object(this_player(),"Lich's Fire Bolt hits YOU in the torso\n");
	this_player()->hit_with_spell(this_player()->query_hp()/2,"fire");
	call_out("event4",6);
	return 1;
}

event4() {
	object paladin, lich;
	object *players;
	string *quests;
	int i, j, done;
	
	players = all_inventory(this_object());
	
	paladin = present("paladin");
	lich = present("lich");
	
	if(kingscore > paladinscore) {
		tell_room(this_object(),"\nThe Lich King reaches out his arm and grasps the heart of the Paladin!\n");
		tell_room(this_object(),"The Paladin gasps for air but the Lich King's lifeless hand squeezes hard!\n");
		tell_room(this_object(),"Suddenly the Paladin stops breathing and vanishes from this world!\n");
		destruct(paladin);
		tell_room(this_object(),"The Lich King cackles malevolently and grasps your throat!\n");
		for(i = 0;i<sizeof(players);i++) {
			if(living(players[i]) && !players[i]->query_npc()) {
				tell_object(players[i],"You can't breath!\n");
				players[i]->death();
			}
		}
		return 1;
	}
	tell_room(this_object(),"\nThe Paladin raises his sword high and strikes with unearthly precision!\n");
	tell_room(this_object(),"The sword impales the Lich King's heart and with a huge implosion, the\n"+
				"Lich King vanishes from this world!\n");
	destruct(present("sceptre",lich));
	destruct(lich);
	
	done = 0;
	if(this_player()->query_quests()) {
		quests = explode(this_player()->query_quests(),"#");
		for(j = 0;j<sizeof(quests);j++) {
			if(quests[j] == "Vanquish the Lich King")
				done = 1;
		}
	}
	
	if(!done) {
		move_object(clone_object("/wizards/rag/ruins/eq/sceptre"),this_object());
	}
	tell_room(this_object(),"The Paladin says: 'The Lich King is dead, now I can rest.'\n");
	destruct(paladin);
	shout("\n  A huge ray of light can be seen striking into the Ancient church.\n");
        shout(  "  A choir of Angels praise "+this_player()->query_name()+" for vanquishing a great evil.\n\n");
        tell_object(this_player(),"\n  A huge ray of light can be seen striking into the Ancient church.\n");
        tell_object(this_player(),  "  A choir of Angels praise "+this_player()->query_name()+" for vanquishing a great evil.\n\n");
	tell_object(this_player(),"Congratulations! You have just completed the quest 'Vanquish the Lich King'\n");
	this_player()->set_quest("Vanquish the Lich King");
	call_other("/wizards/rag/ruins/tunnel3","add");
	return 1;
}