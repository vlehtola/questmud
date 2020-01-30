inherit "obj/monster";

reset(arg) {

 object weapon;
 ::reset(arg);
 if(arg) { return; }
 set_level(1);
 set_name("dwarf");
 set_alias("miner");
 set_short("A tiny dwarf digging for gold vein");
 set_long("A tiny dwarf miner is digging for gold vain. He has been searching it\n"+
          "for all his life, but up to now, he hasen't even touched a gold piece.\n"+
          "He's sweaty, all over covered with dirt and earth. His teeth are\n"+
          "black, atleast them, which haven't come out yet from his mouth.\n");
 set_al(10);
 set_aggressive(0);
 set_block_dir("east");
 set_race("dwarf");
 set_gender(1);

    weapon = clone_object("/wizards/duncan/dwarf/eq/pick.c");
    move_object(weapon, this_object());
    init_command("wield hatchet");
}
                                                                                                               
                                                                                                               
                                                                                                               
                                                                                                                       
