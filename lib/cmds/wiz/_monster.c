//Command to clone a testmonster of level arg, by Rag
cmd_monster(arg) {
        object monster;
        if(!arg) {
                write("Use: monster <level|remove>\n");
                return 1;
        }
        if(arg == "remove") {
                monster = present("testmonster",environment(this_player()));
                if(monster) {
                        destruct(monster);
                        write("Testmonster destroyed.\n");
                        return 1;
                }
                write("Testmonster not present.\n");
                return 1;
        }
        if(to_int(arg) < 1 || to_int(arg) > 100) {
                write("Use a proper level, 1-100.\n");
                return 1;
        }
        monster = clone_object("/wizards/rag/misc/testmonster");
        monster->lvl(arg);
        move_object(monster,environment(this_player()));
        write("Monster cloned, level "+arg+"\n");
        return 1;
}
