cmd_search(string arg) {
        object ob,search_ob,room;
        string arg1;
        room = environment(this_player());
        arg1 = arg;
        if (present("search_ob", this_player())) {
            write("You are already searching something.\n");
        return 1;
        }
        if(!arg) {
         write("You start searching around.\n");
         say(this_player()->query_name()+ " starts to search something.\n");
         search_ob = clone_object("/cmds/std/search_ob");
         move_object(search_ob, this_player());
         search_ob->start(room);
        return 1;
}
write("You start to search the " + arg1 + ".\n");
say(this_player()->query_name()+ " starts to search something.\n");
search_ob = clone_object("/cmds/std/search_ob");
move_object(search_ob, this_player());
search_ob->start(room,arg1);
        return 1;
}
