inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_gender(2);
    set_level(17+random(5));
    set_name("maid");
    set_alias("chambermaid");
    set_race("human");
    set_short("Cute young chambermaid");
    set_long("Cute girl with long blond hair and tight outfit.\n"+
              "She has big brown eyes and she is wearing tights,\n"+
              "tight dress and shoes with high heels.\n");
             
    set_al(0);
    set_aggressive(0);
   
}
