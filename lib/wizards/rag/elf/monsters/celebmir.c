inherit "obj/monster";

int q;

reset(arg) {
        string chat_str, a_chat_str;
        object ring, weapon, belt;
        ::reset(arg);
        if(arg) { return; }
        q = 0;

        set_name("celebmir");
        set_alias("advisor");
        set_alt_name("bard");
        set_alt_alias("elf");
        set_race("high elf");

        set_level(55);
        set_dex(query_dex()*2);
        set_int(query_int()*3);
        set_wis(query_wis()*3);

        set_al(60);
        set_al_aggr(200);
        set_aggressive(0);

        set_special(33);

        set_log();

        set_mage(1);
        set_gender(1);

        set_short("Celebmir, master bard and royal advisor");
        set_long("Celebmir is a very tall elf. He has blond hair and blue eyes.\n"+
                "You can see in his eyes that he seen many years and will see\n"+
                "many more. He is wearing silvery robes. He is the advisor of\n"+
                "the royal elven family and, with his aid, things are better now.\n"+
                "He is known for his unrivalled intelligence and knowledge of\n"+
                "ancient lore. He is also a very skilled bard and many have spend\n"+
                "countless hours lost in his songs.\n");

        ring = clone_object("/wizards/rag/elf/eq/ring");
        move_object(ring,this_object());
        init_command("wear ring");

        belt = clone_object("/wizards/rag/elf/eq/belt");
        move_object(belt,this_object());
        init_command("wear belt");

        weapon = clone_object("/wizards/rag/elf/weapons/dagger");
        move_object(weapon,this_object());
        init_command("wield dagger");

        if (q==0) {
                if (!chat_str) {
                        chat_str = allocate(3);
                        chat_str[0] = "Celebmir says: 'I don't understand where my amulet is.'\n";
                        chat_str[1] = "Celebmir says: 'If only someone could find my amulet...'\n";
                        chat_str[2] = "Celebmir says: 'I can't continue my work without my amulet.'\n";
                }
        load_chat(5, chat_str);
        }

        if (!a_chat_str) {
                a_chat_str = allocate(2);
                a_chat_str[0] = "Celebmir says: 'What are you doing?!'\n";
                a_chat_str[1] = "Celebmir says: 'Mrr! I can't believe that you actually attacked me!'\n";
        }
        load_a_chat(10, a_chat_str);
}

catch_tell(str) {
        string tmp1,tmp2,chat_str;
        object ob;
        ::catch_tell(str);

        if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
                ob = present("quest_amulet", this_object());
                if (ob && this_player()->query_name() == tmp1) {
                        tell_room(environment(this_object()),"Celebmir says: 'Oh my amulet! Thank you very much!'\n");
                        write("You have completed the quest!\n");
                        this_player()->set_quest("Return Celebmir's amulet");
                        destruct(ob);
                        q = 1;
                        chat_str = allocate(3);
                        chat_str[0] = "Celebmir says: '" + this_player()->query_name() +
                        " found my amulet. Now I can complete my work'.\n";
                        chat_str[1] = "Celebmir says: 'I have a lot of work to do.'\n";
                        chat_str[2] = "Celebmir says: 'There is still goodness in the world.'\n";
                        load_chat(5, chat_str);
                        return 1;
                }
        }
        return 1;
}

special_move() {
        object room, players;
        int i;

        room = environment(this_object());
        players = all_inventory(room);

        tell_room(room,"Celebmir stars singing an enchanting song. You feel very sleepy...\n");

        for(i = 0;i<sizeof(players);i++) {
                if(living(players[i])) {
                        if(!players[i]->query_npc()) {
                                tell_object(players[i],"You are STUNNED by Celebmir's song!\n");
                                players[i]->set_stunned(1+random(5));
                        }
                }
        }
}

ask_question(str) {
        object room;
        room = environment(this_object());
        if(str == "amulet") {
                if (!q) {
                        tell_room(room,"Celebmir says: 'I lost my amulet somewhere. Have you seen it?\n"+
                        "It has been in my family for hundreds of years.'\n");
                        return 1;
                }
                tell_room(room,"Celebmir says: 'The amulet has been in my family for hundreds of years.'\n");
                return 1;
        }
        if(str == "orc" || str == "orcs" || str == "cave") {
                tell_room(room,"Celebmir says: 'Damned orcs. There's nothing more to say!'\n");
                return 1;
        }
        if(str == "forest") {
                tell_room(room,"Celebmir says: 'This is a beautiful and peaceful forest.'\n");
                return 1;
        }
        if(str == "bard") {
                tell_room(room,"Celebmir says: 'As a bard, I know many songs and ancient tales.'\n");
                return 1;
        }
        if(str == "pond") {
                tell_room(room,"Celebmir says: 'There's something evil in that pond...'\n");
                return 1;
        }
        if(str == "tale" || str == "tales" || str == "songs" || str == "song" || str == "story") {
                if (!q) { tell_room(room,"Celebmir says: 'Not now, I want my amulet...'\n"); }
                if (q) { tell_room(room,"Celebmir says: 'Not now, I must continue my work.'\n"); }
                return 1;
        }
        tell_room(room,"Celebmir says: 'This is awkward. I'm the master bard and I know nothing of "+str+".'\n");
        return 1;
}
