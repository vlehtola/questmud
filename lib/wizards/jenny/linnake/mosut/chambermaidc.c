inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_gender(2);
    set_level(18+random(5));
    set_name("maid");
    set_alias("chambermaid");
    set_race("human");
    set_short("Cute red-haired chambermaid is wiping dust here");
    set_long("Cute red-haired girl likes to wipe dust in this\n"+
              "castle. She is wearing tight dress and shoes with\n"+
              "high heels. She has deep blue eyes and cute little\n"+
              "mouth.\n");
             
    set_al(0); 
    set_aggressive(0);
   
}
