inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(30);
    set_name("monk");
    set_short("A thin monk");
    set_long("A thin monk with a bald head. He is holding some prayer beads and \n" +
             "his lips are chanting a silent prayer. His robes look new and have a \n" +
             "strange sign sewn into them.\n");
    set_block_dir("northwest");
    set_al(-50);
    set_aggressive(0);
}
