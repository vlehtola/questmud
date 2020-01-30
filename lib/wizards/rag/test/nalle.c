inherit "obj/monster";

reset(arg) {
        ::reset(arg);
        if(arg) { return; }
        set_name("nalle");
        set_level(50);
        set_short("A terrible NALLE");
        set_long("A fearsome and bloodthirsty NALLE roams here.\n");
        move_object(clone_object("/guilds/artists/wepat/gm"),this_object());
        init_command("wield knuckles");
        move_object(clone_object("/guilds/artists/wepat/gm"),this_object());
        init_command("wield knuckles");

        set_skill("martial arts",100);
        set_skill("advanced martial arts",100);
}
