inherit "obj/monster";

reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_level(1);
    set_name("ant");
    set_alias("worker");
    set_short("A giant ant worker");
    set_long("The is huge compared to its smaller relatives. It is atleast\n" +
             "one and a half meters long and one meter high.It is digging the\n" +
             "wall and your presence doesn't seem to distracting it in its work.\n");
    set_al(10);
    set_aggressive(0);
    set_block_dir("east");
 /* Mark that the monster is an animal: */
    set_animal(1);
    
    armour = clone_object("/world/mine/eq/shell");
    move_object(armour, this_object());
    init_command("wear shell");

}
