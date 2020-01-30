inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(21);
    set_name("guard");
    set_alias("templeguard");
    set_gender(1);
    set_short("A templeguard");
    set_long("tanne tulee myohemmin\n"+
             "joku vahan parempi\n"+
             "long desci.\n");
    set_al(-21);
    set_aggressive(0);
    
}
