inherit "obj/monster";

int sword, water, cross, soul;

init() {
        add_action("accept","accept");
        ::init();
}

reset(arg) {
        string chat_str, a_chat_str;
        ::reset(arg);
	if(arg) { return; }
        set_level(76);
        set_name("priest");
        set_gender(1);
        set_short("The priest of the lost church");
        set_long("The priest is an old man. His hair is grey and his face is wrinkled.\n"+
                "He is wearing simple white robes which are covered with holy symbols.\n"+
                "You can see great sadness in his grey eyes but his eyes also seem to\n"+
                "have a spark of insanity. Perhaps his death was too horrible to bear\n"+
                "without the loss of mental health.\n");

        set_undead(1);
        set_al(50);
        set_aggressive(0);
        set_al_aggr(400);
        
        if (!chat_str) {
                chat_str = allocate(15);
                chat_str[0] = "The priest mumbles: 'The evil was too great.'\n";
                chat_str[1] = "The priest sighs sadly.\n";
                chat_str[2] = "The priest mumbles: 'Where is my flock?'\n";
                chat_str[3] = "The priest mutters something to himself.\n";
                chat_str[4] = "The priest mumbles: 'The paladin is vanquished. Who shall save us now?'\n";
                chat_str[5] = "The priest whispers: 'Maybe I could resurrect him...\n";
                chat_str[6] = "The priest seems detached from this world.\n";
                chat_str[7] = "The priest reads something from the Holy book.\n";
                chat_str[8] = "The priest chants some prayers silently.\n";
                chat_str[9] = "The priest whispers: 'One could use the scroll to get to the evil.'\n";
                chat_str[10] = "The priest exclaims: 'We need someone to save us!'\n";
                chat_str[11] = "The priest chants: 'Pater noster...'\n";
                chat_str[12] = "The priest says sadly: 'One could call my quest hopeless...'\n";
                chat_str[13] = "The priest whispers: 'A new champion might want to accept my quest...'\n";
                chat_str[14] = "The priest chants: 'In nomine Patri et Filii et Spiritus Sancti.'\n";
        }
        load_chat(25, chat_str);
                                                                                                
        if (!a_chat_str) {
                a_chat_str = allocate(5);
                a_chat_str[0] = "The priest screams: 'The undead are back!'\n";
                a_chat_str[1] = "The priest yells: 'Not again!'\n";
                a_chat_str[2] = "The priest screams to the heavens: 'End this madness, Cyral!'\n";
                a_chat_str[3] = "The priest yells: 'Burn in hell, you infernal creature!'\n";
                a_chat_str[4] = "The priest shouts: 'In nomine Patri et Filii et Spiritus Sancti!'\n";
        }
        load_a_chat(15, a_chat_str);
}

ask_question(str) {
        if(str == "quest") {
                say("The priest says: 'I need someone to help me find some items so that\n"+
                    "I can resurrect the Paladin of Goodness. Then the Lich King can be destroyed!\n"+
                    "Are you willing to accept my quest?'\n");
                return 1;
        }
        if(str == "items") {
                say("The priest says: 'I need some water to make Holy water... Then I need the\n"+
                    "Paladin's sword... And my cross has been stolen... Yes, those I need.'\n");
                return 1;
        }
        if(str == "scroll") {
                say("The priest says: 'You can chant magical words with the help of the scroll.\n"+
                    "Ask the librarian for instructions.'\n");
                return 1;
        }
        if(str == "portal") {
                say("The priest says: 'Yes, they went to the portal... So you must go there too!\n"+
                    "The portal appeared in the middle of my beautiful church.'\n");
                return 1;
        }
        if(str == "library" || str == "librarian") {
                say("The priest says: 'The librarian lives on top of the church. She can help you.'\n");
                return 1;
        }
        if(str == "paladin") {
                say("The priest says: 'He is the only one that can help us!'\n");
                return 1;
        }
        if(str == "evil") {
        	say("The priest says: 'The evil ones came from the portal... The destroyed everything!'\n");
        	return 1;
        }
        if(str == "sword") {
        	say("The priest says: 'I believe it was burried with Him.'\n");
        	return 1;
        }
        if(str == "cross") {
        	say("The priest says: 'Darkness... Stolen...'\n");
        	return 1;
        }
        if(str == "water") {
        	say("The priest says: 'Any water will do, I can bless it!'\n");
        	return 1;
        }
        if(str == "accept") {
        	say("The priest says: 'Yes, accept quest.'\n");
        	return 1;
        }
        say("The priest says: 'I'm sorry, my child. I can't help you on that subject.'\n");
        return 1;
}

accept(str) {
        if(str == "quest") {
                if(!present("scroll123",this_player())) {
                        say("The priest says: 'Ah... A new Champion arises!\n");
                        say(this_player()->query_name()+" accepts the priest's quest!\n", this_player());
                        say("The priest rips a page from the Holy Book.\n");
                        say("The priest says: 'Here, take this scroll, you'll need it. Ask the librarian for instructions.'\n");
                        move_object(clone_object("/wizards/rag/ruins/obj/scroll"),this_player());
                        this_player()->fix_weight();
                        return 1;
                } else {
                        write("The priest looks a bit confused an says: 'But you already have the scroll...\n"+
                                "Is there something that you want to ask?'\n");
                return 1;
                }
        }
}

catch_tell(str) {
        string tmp1,tmp2;
        object ob;
        ::catch_tell(str);

        if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
                ob = present("bucket_f", this_object());
                if (ob) {
                        water = 1;
			say("The priest blesses the water in the bucket.\n");
                        check_items();
                        destruct(ob);
                        return 1;
                }
                ob = present("cross123", this_object());
                if (ob) {
                        cross = 1;
			say("The priest kisses the cross and blesses it.\n");
                        check_items();
                        destruct(ob);
                        return 1;                                                                                                         
                }
                ob = present("sword123", this_object());
                if (ob) {
                        sword = 1;
			say("The priest places the sword on the altar.\n");
                        check_items();
                        destruct(ob);
                        return 1;                                                                                                         
                }
                ob = present("soul123", this_object());
                if(ob) {
                        soul = 1;
                        check_items();
                        destruct(ob);
                        return 1;
               }
        }
        if(sscanf(str, "%s says 'yes'",tmp1) == 1) {
        	say("The priest says: 'Then accept my quest!'\n");
        	return 1;
        }
}

check_items() {
        if(sword && cross && water && !soul) {
                say("The priest says: 'Now I can start the resurrection!'\n");
                say("The priest reads the Holy Book and starts chanting.\n");
                call_out("do_chant",6);
                call_out("do_chant",14);
                call_out("not_soul",22);
                return 1;
        }
        if(sword && cross && water && soul) {
                say("The priest says: 'Now the resurrection can proceed!'\n");
                say("The priest reads the Holy Book and starts chanting.\n");
                call_out("do_chant",6);
                call_out("do_chant",14);
                call_out("resurrect",22);
                return 1;
        }
        say("The priest says: 'Ah, very good... One item closer to redemption!'\n");
        return;
}

do_chant() {
        say("The priest chants divine words with his eyes burning brightly!\n");
        return;
}

not_soul() {
        say("The priest screams to the Heavens and chants Holy Words: 'Come to this place, Champion Of Light!'\n");
        say("The priest suddenly looks very shocked, looks you directly in the eyes and says: 'His soul has \n"+
        "been captured! You must help him! I see a burning lake! It must be there! Go NOW!'\n");
        return 1;
}

resurrect() {
        object room;
        room = environment(this_object());
        say("The priest screams to the Heavens and chants Holy Words: 'Come to this place, Champion Of Light!'\n");
	say("The shimmering ball shines with divine glory and you have to close your eyes because of the light.\n");
	say("Suddenly a being of pure light appears. It takes the rusty sword from the altar and the sword  starts\n");
	say("to shine with the same light. The ball enters the being and with a bright flash, the Paladin stands\n");
	say("before your very eyes!\n");
        move_object(clone_object("/wizards/rag/ruins/mon/paladin"),room);
        present("paladin")->set_master(this_player()->query_name());
	say("The paladin says: '"+this_player()->query_name()+", lead me to the Lich King!'\n");
        return 1;
}
