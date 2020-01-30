inherit "obj/monster";

reset(arg) {
object armour;
    ::reset(arg);
    if(arg) { return; }
    set_level(35);
    set_name("phantom");
    set_alias("undead");
    set_short("An amorphous Phantom");
    set_long("The phantom is formed of bones only, it has no skin or organs,\n"+
             "therefore it has a hideous, skeletal-look. Its bones are pure\n"+
             "white, shining through the white cape, which it's wearing. The\n"+
             "phantom spreads terror among the adventurers.\n");

    set_al(10);
    set_undead(1);
    set_block_dir("east");

    armour = clone_object("/wizards/irmeli/valley/eq/cape.c");
    move_object(armour, this_object());
    init_command("wear cape");

}

void init() {
 ::init();
 add_action("block_it","north");
 add_action("block_it","south");
 add_action("block_it","west");
 add_action("block_it","east");

}
status block_it() {
write("The Phantom blocks your flee attempt!\n");
return 1;
}
