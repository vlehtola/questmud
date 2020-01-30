inherit "obj/monster";
object item;
reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    
    set_level(50);
    set_name("umathra");
    set_alias("demon");
    set_short("Umathra the ugly two headed demon");
    set_long("This muscular demon is huge-sized. Its skin is emitting\n"+
             "some hot air, which makes the demon look like it would be\n"+
             "gloving.\n"); 
    set_al(-40);
    set_aggressive(0);
    item = clone_object("/wizards/luminarc/wizcastle/armours/stone.c");
    move_object(item, this_object());

}

