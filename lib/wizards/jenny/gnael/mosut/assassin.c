inherit "obj/monster";

reset(arg) {
    object robe,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    set_level(random(10)+35);
    set_name("assassin");
    set_alias("human");
    set_short("A "+({ "dark", "big", "small", "great", "mean",})[random(5)]+" assassin is here ambushing you");
    set_long("A very mean looking assassin dressed in a black robe ambushes\n"+ 
              "stupid people that try to enter the hideout without permission.\n"+
              "He is wielding a deadly looking short sword and he is moving\n"+
              "hastily. The assassin is grinning madly as he tries to\n"+
              "kill you.\n");

    set_block_dir("out");
    set_al(-5);
    set_aggressive(1);
   
   robe = clone_object("/wizards/jenny/gnael/rojut/robe");
    move_object(robe, this_object());
    init_command("wear robe");      
   
   sword = clone_object("/wizards/jenny/gnael/rojut/short_sword");
    move_object(sword, this_object());
    init_command("wield sword");     
 
}

void init() {
 ::init();
 add_action("block_it","south");
 add_action("block_it","southwest");
 add_action("block_it","west");
 add_action("block_it","out");

}
status block_it() {
write("Assassin grabs your neck, you can't flee!\n");
return 1;
}
