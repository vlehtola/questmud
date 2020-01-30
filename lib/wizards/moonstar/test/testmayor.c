inherit "obj/monster";
reset(arg) {

int wring, fring;
string chat_str;
        ::reset(arg);
        if(arg) { return; }
        set_level(40);
        set_name("mayor");
        set_gender(1);

        set_short("The mayor of the town Giadi");
        set_long("The mayor is an old man. His been here where long time.\n"+
                "He is wearing green shirt and black cloak.\n"+
                "You can see that his not happy at all. Anger fills his eyes as you\n"+
                "look in his dark brown eyes. You notice that he is crying.\n");

        set_race("human");
        set_al(50);
        set_aggressive(0);

        if (!chat_str) {
                chat_str = allocate(5);
                chat_str[0] = "The mayor mumbles: 'Someday the brotherhood of fire and water shall end!'\n";
                chat_str[1] = "The mayor sighs sadly.\n";
                chat_str[2] = "The mayor mumbles: 'Please help us!'\n";
chat_str[3] = "The mayor mumbles: 'You have to kill them both to free my people!'\n";
chat_str[4] = "The mayor says: 'Krazzt and Drazil should be killed!'\n";
 
        load_chat(25, chat_str);
}
ask_question(str) {
        if(str == "brotherhood") {
                say("The mayor says: 'I need someone to help me to kill Krazzt and Drazil so\n"+
                    "My people shall be free from their slavery. They have hunted us too many years!\n"+
                    "Will you help me?'\n");
                return 1;
        }

if(str == "help") {
say("The mayor says: 'Yes I need help to kill them both, Krazzt and Drazil.'\n");
return 1;
}
        if(str == "Drazil") {
                say("The mayor says: 'Yes, yes... Drazil is the ranger who lives in the black tower\n"+
                    "in the dark forest. You must go and find him!'\n");
                return 1;
        }
        if(str == "Krazzt") {
                say("The mayor says: 'Oh Krazzt is the older one and he is the magician.\n"+
                    "He is very powerful and lives somewhere in the Wastelands...'\n");
                return 1;
        }
        if(str == "wastelands") {
                say("The mayor says: 'Wastelands use to be our home until Krazzt come there.'\n"+
                    "It is located near the mountains far south from here.'\n");
                return 1;
        }
 say("The mayor says: 'I'm sorry, I don't know the answer.'\n");
        return 1;
}




catch_tell(str) {
        string tmp1,tmp2;
        object ob;
        ::catch_tell(str);

        if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
                ob = present("firering", this_object());
                if (ob) {
                        fring = 1;
                        say("The mayor puts the ring in his locker.\n");
                        check_items();
                        destruct(ob);
                        return 1;
                }
                ob = present("waterring", this_object());
                if (ob) {
                        wring = 1;
                        say("The mayor kisses the ring and puts it in his locker.\n");
                        check_items();
                        destruct(ob);
                        return 1;

        }

}

check_items() {
 tell_object(this_player(), "mayor says: 'Yes! You have killed them both and you shall be rewarded!.'\n");
         tell_object(this_player()b, "You complete the 'End the brotherhood of fire and water' quest.\n");
         call_other(this_player(), "set_quest", "End the brotherhood of fire and water");
    }
}
