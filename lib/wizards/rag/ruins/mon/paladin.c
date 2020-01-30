inherit "obj/monster";
string master;
int kingcheck;

reset(arg) {
        ::reset(arg);
        if(arg) { return; }
        set_level(80);
        set_name("paladin");
        set_gender(1);
        set_short("The Paladin of Goodness (holy)");
        set_long("The paladin radiates goodness. His entire body is surrounded by a holy aura.\n"+
                 "He has curly blond hair and crystal-blue eyes. His muscular body is wrapped\n"+
                 "in a sky-blue plate mail. His features seem humble yet lordly. The paladin\n"+
                 "might just be the only one with enough strength to defeat the evil Lich King.\n");
        
        set_al(100);
        set_aggressive(0);
        set_al_aggr(400);
        set_extra(1);
        set_log();
        kingcheck = 0;
}

extra() {
        if(attacker_ob) {
                say("\n  The paladin looks "+attacker_ob->query_name()+" in the eyes and thunders:\n");
                say("  'If this is your will, then I shall not be of any help to you!'\n");
                say("  The paladin slowly fades out of existence...\n\n");
                attacker_ob->hard_add_alignment(-5);
                destruct(this_object());
                return 1;
        }
        return 1;
}

set_master(str) {
        master = lower_case(str);
        return;
}

catch_tell(str) {
        string tmp1,tmp2;
         ::catch_tell(str);
                                                                                                         
        if (sscanf(str, "%s leaves %s.", tmp1, tmp2) == 2) {
                if(lower_case(tmp1) == master) {
                        call_out("move",1,tmp2);
                        return 1;
                }
                return 1;
        
        }
}

move(str) {
        string env, dir;
        dir = str;
        env = file_name(environment(find_player(master)));
        if(env == "/wizards/rag/ruins/tunnel3" && !kingcheck) {
                kingcheck = 1;
                call_out("king",1);
                say("The Paladin leaves "+dir+".\n");
                move_object(this_object(),"/wizards/rag/ruins/tunnel3");
                say("The Paladin arrives.\n");
                return 1;
        }
        if(env[0..18] == "/wizards/rag/ruins/") {
                say("The Paladin leaves "+dir+".\n");
                move_object(this_object(),env);
                say("The Paladin arrives.\n");
        } else {
                tell_object(find_player(master),"You hear the Paladin's voice in you head 'I'm sorry, but I"+
                " cannot leave the church.'\n");
        }
        if(env == "/wizards/rag/ruins/tunnel4") {
                call_other(env,"battle");
        }
        return 1;
}

king() {
        move_object(this_object(),"/wizards/rag/ruins/tunnel3");
        if(file_name(environment(find_player(master))) != "/wizards/rag/ruins/tunnel3") {
                tell_object(find_player(master),"The Paladin summons you!\n");
                find_player(master)->move_player("X#/wizards/rag/ruins/tunnel3");
        }
        say("The Paladin says: 'I sense that the Lich King is near. I need your help in the battle.\n"+
            "Use the scroll to help me defeat the Lich King.'\n");
        call_out("king2",2);
        return;
}

king2() {
        call_other(environment(this_object()),"add");
        return;
}
