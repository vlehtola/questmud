#define MAP "/room/out/outmap"
#define FILE "/wizards/rag/events/teleport/start"
#define DELAY 35
inherit "obj/monster";
int phaze;

reset(arg) {
        string chat_str;
        string a_chat_str;
        if(arg) return;
        ::reset(arg);
        set_level(24);
        set_name("zadax");
        set_alias("traveller");
        set_gender(1);
        set_short("Zadax, the traveller between worlds");
        set_long("Zadax is traveller from another world. He uses his his magics\n"+
                 "to teleport between worlds and within a world. The air around\n"+
                 "quivers in a magical way and he is constanly looking around\n"+
                 "perhaps exploring this world. He is a very tall man clad in grey\n"+
                 "robes. He is wielding a long staff which he seems to be using\n"+
                 "in his spells. His necklace radiates with a magenta light telling\n"+
                 "that it is magical, too. He looks a bit like a human but you can\n"+
                 "tell that indeed is not from this world.\n");

        set_al(0);
        set_log();
        set_aggressive(0);
        set_al_aggr(400);
        set_extra(1);

//Mage without offensive spells
        set_skill("cast essence",100);
        set_skill("cast fire",100);
        set_skill("cast ice",100);
        set_skill("cast teleport",100);
        set_skill("cast locate",100);
        set_skill("chanting",100);
        set_skill("mana control",100);

        set_int(query_int()*5);
        set_max_sp(query_max_sp()*15);
        set_sp(query_max_sp());
        set_regen(1); 

        set_exp(1500000);

        if (!chat_str) {
                chat_str = allocate(3);
                chat_str[0] = "Zadax says: 'This world is boring!'\n";
                chat_str[1] = "Zadax says: 'Why are you all teleporting all the time?!'\n";
                chat_str[2] = "Zadax says: 'How can I leave...'\n";
        }
        load_chat(10, chat_str);
        if (!a_chat_str) {
                a_chat_str = allocate(3);
                a_chat_str[0] = "Zadax chants magical words. The air quivers.\n";
                a_chat_str[1] = "Zadax says: 'Stop bugging me!\n";
                a_chat_str[2] = "Zadax says: 'I'll be on my way out soon!\n";
        }
        load_a_chat(10, a_chat_str);

        move_object(clone_object("/wizards/rag/events/teleport/staff"),this_object());
        //Tuned, I don't want it to break
        //Tuned, monsters shouldn't be able to break their weapons
        init_command("wield staff");

        move_object(clone_object("/wizards/rag/events/teleport/neck"),this_object());
        init_command("wear necklace");

        set_dead_ob(this_object());
}

//Just a little something :)
query_skills(arg) {
        if(arg == "navigation mastery") return 200;
        return ::query_skills(arg);
}

monster_died() {
        object ob;
        ob = this_object()->query_attacker();
        ob->set_party_quest("Get rid of Zadax");
        shout(ob->query_name()+" saves Deleria from the disrupting magic of Zadax!\n");
        tell_object(ob,"You save Deleria from the disrupting magic of Zadax!\n");
        FILE->end_event();      
        return 0;
}

extra() {
        int hp;
        hp = query_hp()*100/query_max_hp();

        if(!phaze && hp < 100) {
                phaze++;
                teleport();
                return 1;
        } else if(phaze == 1 && hp < 81) {
                phaze++;
                teleport();
                return 1;
        } else if(phaze == 2 && hp < 76) {
                phaze++;
                teleport();
                return 1;
        } else if(phaze == 3 && hp < 51) {
                phaze++;
                teleport();
                return 1;
        } else if(phaze == 4 && hp < 34) {
                phaze++;
                teleport();
                return 1;
        } else if(phaze == 5 && hp < 21) {
                phaze++;
                teleport();
                return 1;
        } else if(phaze == 6 && hp < 14) {
                phaze++;
                teleport();
                set_extra(0);
                return 1;
        }
}
 
teleport(arg) {
        int x, y;
        x = random(300);
        y = random(300);

        if(MAP->check_no_walk(MAP->get_map_char(x,y))) {
                teleport(arg);
                return 1;
        }

        if(this_object()->query_stunned()) {
                tell_room(environment(this_object()),"Zadax tries to flee, but he's stunned!\n");
                return 1;
        }
        
        if(this_object()->query_spell()) {
                this_object()->query_spell()->interrupt_spell(1);
        }
        
        if(!arg) {
         tell_room(environment(this_object()),"Zadax chants 'exs fla loc' very quickly and suddenly vanishes!\n");
        } else {
         call_out("disrupt",DELAY);
        }
        this_object()->move_player("XX#virtual /room/out/outmap "+x+" "+y);
        return 1;
}

disrupt() {
        object ob;
        string spell_words, target_name;
        call_out("disrupt",DELAY);

        ob = get_random_user();
        if(!ob) return 1;

        target_name = lower_case(ob->query_name());

        if(this_object()->query_spell()) return 1;

        if(!random(4)) {
                spell_words = "exs brr trn";
        } else if(!random(15)) {
                spell_words = "exs fla trn";
        } else {
                spell_words = "exs fla loc";
        }

        if(find_player("rag")) {
         tell_object(find_player("rag"),spell_words+" at "+target_name+"\n");
        }

        this_object()->set_spell(clone_object("/guilds/obj/spell"));
        this_object()->query_spell()->start_spell(spell_words + " at " + target_name, this_object());
        return 1;
}

get_random_user() {
        object *us;
        us = filter_array(users(), "wiz");
        us = filter_array(us, "idle");

        if( sizeof(us) ) {
         return us[random(sizeof(us))];
        } else {
         return 0;
        }
}

status wiz(object ob) {
        if(!ob->query_wiz()) return 1;
        return 0;
}

status idle(object ob) {
        if(query_idle(ob) < 45) return 1;
        return 0;
}
