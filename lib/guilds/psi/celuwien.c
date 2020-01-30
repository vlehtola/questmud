inherit "obj/monster";
object neck;
reset(arg) {
        string chat_str;
        ::reset(arg);
        if(arg) {return; }
        set_name("celuwien");
        set_alias("psionic");
        set_level(46+random(5));
        set_gender(2);
        set_race("dark elf");
        set_short("A Celuwien the dark elf psionic");
        set_long("The Celuwien is thin dark elf, with a long blond curly hair.\n"+
                 "She has blue eyes which looks like a two blue crystals. She\n"+
                 "have to be one of the prettyes't persons you have ever meet.\n");
        set_log();
        set_max_hp(query_hp()+150000+random(200000));
        set_hp(query_max_hp());
        set_regen(10000);
        if(!chat_str) {
  chat_str = allocate(3);
  chat_str[0] = "Celuwien says 'I can give you advice if you ever need one'\n";
  chat_str[1] = "Celuwien says 'Concentrate yourself on the wise side and you will be fine'\n";
  chat_str[2] = "Celuwien says 'You can 'Ask me about advice' if you want to learn something'\n";
}
load_chat(2, chat_str);
neck = clone_object("/guilds/psi/necklace");
move_object(neck, this_object());
init_command("wear necklace");
}

ask_question(str) {
        if(str == "guild") {
                say("Celuwien says: 'Yes, this is the psionic guild'\n");
                return 1;
        }
        if(str == "help") {
                        say("Celuwien says: 'Try develop your mind power's by training the mental strike and other skills.\n");
                        return 1;
                }
                if(str == "advice") {
                        say("Celuwien says: '"+get_advice(random(10))+"'\n");
                        return 1;
                }
        write("Celuwien says: 'I don't know anything about that'.\n");
        return 1;
}

get_advice(int i) {
        switch(i) {
                case 0: return "Undeads can be quite deadly in fight";
                case 1: return "Remeber always use the iron will skill, it can be your savior";
                case 2: return "It all starts from your knowledge of mind, so develope it";
                case 3: return "Sometimes confusing or charming your opponent can be rewarding";
                case 4: return "When the dark comes remember to use your mental light";
                case 5: return "With mental scan you can check your enemy's weakness";
                case 6: return "If your spell points becomes too minimal try to drain your opponents mental power";
                case 7: return "If ever your opponent becomes too powerfull it's not a shame to retreat";
                case 8: return "Intelligence and wisdom helps you to concentrate more powerfull things";
                case 9: return "Sometimes it's good to be mentaly balanced";
        }
        return "Hmpf, not today my lord";
}
