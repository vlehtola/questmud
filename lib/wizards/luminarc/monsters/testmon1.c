reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(1);
    set_name("Testi");
    set_alias("testi");
    set_short("A giant testi");
    set_long("The is huge compared to its smaller relatives. It is atleast\n"
    set_al(10);
    set_aggressive(0);
    set_block_dir("east");
 /* Mark that the monster is an animal: */
    set_animal(1);
}

