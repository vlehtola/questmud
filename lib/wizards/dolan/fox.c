inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("fox");
    set_alias("fox");
    set_short("A small fox is running here.");
    set_long("You can see a small sized fox who is running wildly.\n"+
             "Fox has small green eyes and grey fur.\n");
    set_al(0);
    set_level(10);
    set_gender(1);
set_animal();
}
