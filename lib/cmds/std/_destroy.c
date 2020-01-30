//Destruct corpse command for whiny second rebirthers

cmd_destroy(str) {
        object ob;

        if(this_player()->query_rebirth() < 2 && !this_player()->query_wiz()) return;

        if(!str) {
                str = "corpse";
        }

        ob = present(str,environment(this_player()));
        if(!ob) {
                ob = present(str,this_player());
        }

        if(!ob) {
                write("Destroy what?\n");
                return 1;
        }

        if(!ob->query_corpse()) {
                write("You can only use this on corpses.\n");
                return 1;
        }

        write("You destroy the corpse with your mental powers.\n");
        say(this_player()->query_name()+" destroys the corpse with "+
        this_player()->query_possessive()+" mental powers.\n");

        this_player()->reduce_sp(10);
        ob->autoextract_obj(ob);
        destruct(ob);
        return 1;
}

