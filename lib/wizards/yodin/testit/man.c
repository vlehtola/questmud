inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(100);
    set_name("man");
    set_alias("man");
    set_short("A huge man is here to kill you");
    set_long("This man will kick your butt.\n");
   
remove_limb("head")
}
