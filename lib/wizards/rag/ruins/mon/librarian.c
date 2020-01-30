inherit "obj/monster";

reset(arg) {
	string chat_str, a_chat_str;
        ::reset(arg);
	if(arg) { return; }
        set_level(69);
        set_name("librarian");
        set_gender(2);
        set_short("The librarian sits here smiling at you");
        set_long("The librarian is an elderly woman. She has brown hair which\n"+
		 "is nicely tied to the back of her head. She is wearing simple\n"
		 "grey robes. She looks perfectly calm. You get the feeling that\n"+
		 "she doesn't realize that she is dead. Her death must have been\n"+
		 "a tragic one.\n");

        set_undead(1);
        set_al(0);
        set_aggressive(0);
        set_al_aggr(400);

        if (!chat_str) {
                chat_str = allocate(4);
		chat_str[0] = "The librarian says: 'Please don't touch the books, dear.'\n";
		chat_str[1] = "The librarian hums happily.\n";
		chat_str[2] = "The librarian dusts the shelves.\n";
		chat_str[3] = "The librarian says sadly: 'The priest hasn't visited me in ages...'\n";
        }
        load_chat(5, chat_str);
                                                                                                
        if (!a_chat_str) {
		a_chat_str = allocate(1);
		a_chat_str[0] = "The librarian looks very sad and disappointed.\n";
	}
        load_a_chat(5, a_chat_str);
}

ask_question(str) {
	object room;
	room = environment(this_object());
	if(str == "quest") {
		tell_room(room,"The librarian says: 'Are you on a quest? That's nice, dear.'\n");
		return 1;
	}
	if(str == "scroll" || str == "book" || str == "instructions" || str == "help") {
		tell_room(room,"The librarian says: 'You can use the scroll to 'chant' magical words.'\n");
		if(!present("book123",this_player() )) {
			tell_room(room,"The librarian says: 'You might need this book.'\n");
			tell_room(room,"The librarian takes a dusty book from the shelf and gives it to "+
			this_player()->query_name()+".\n", ({ this_player() }) );
			tell_object(this_player(),"The librarian takes a dusty book from the shelf and gives it to you.\n");
			move_object(clone_object("/wizards/rag/ruins/obj/book"),this_player());
			this_player()->fix_weight();
		}
		return 1;
	}
	if(str == "words" || str == "magic word" || str == "magic words" || str == "magic") {
		tell_room(room,"The librarian says: 'Oh, it's all in the book, dear.'\n");
		return 1;
	}
	if(str == "priest") {
		tell_room(room,"The librarian says: 'The priest is a very lovely man, and a very holy one too.'\n");
		return 1;
	}
	tell_room(room,"The librarian says: 'How would I know something about that, dear?'\n");
	return 1;
}