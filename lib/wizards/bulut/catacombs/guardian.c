inherit "/obj/monster";

object ob;

init() {
::init();
if(present("soul")) {
this_object()->kill("soul");

	}
}

object ob;

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(58);
    set_name("guardian");
    set_alias("man");
    set_short("The Guardian of souls is here, blocking the escape of cursed ones.");
    set_long("You have no doubt that this dark, caped figure can't block the escape\n" +
	     "attempts of the cursed souls here. Hopefully it won't missplace\n" +
	     "you with the cursed souls here.\n");
    set_al(0);
    set_aggressive(0);
    set_gender(1);
    set_block_dir("west");
    ob = clone_object("/wizards/bulut/catacombs/flail");
    move_object(ob,this_object());
    init_command("wield flail");
    set_log();
        set_undead(1);
    set_race("human");
        chat_str = allocate(1);
         chat_str[0] =
          "Guardian says 'One who has sealed its eternity must stay here.'\n";
    load_chat(2, chat_str);

}               

                                
