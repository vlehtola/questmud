inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_gender(2);
    set_level(15+random(5));
    set_name("maid");
    set_alias("chambermaid");
    set_race("human");
    set_short("Cute brunette chambermaid is mopping here");
    set_long("Cute girl with long brown hair and tight outfit.\n"+
              "She has big green eyes and she is wearing tights,\n"+
              "tight dress and shoes with high heels. It seems\n"+
              "like this girl takes her work seriously.\n");
             
    set_al(0); 
    set_aggressive(0);
   
}
