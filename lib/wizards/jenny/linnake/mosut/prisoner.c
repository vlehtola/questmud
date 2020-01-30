inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_level(44);
    set_exp(3924532);
    set_str(query_str()+500);
    set_dex(query_dex()+50);
    set_name("prisoner");
    set_alias("prisoner");
    set_race("human");
    set_short("Ugly looking prisoner");
    set_long("Dirty and ugly looking man is here whining about life.\n"+
              "He is very strong looking, but obviously he is very stupid\n"+
              "because he is in jail. He smells disgusting.\n");
             
    set_al(-20);
    set_aggressive(0);
   
   set_skills("critical",100);
   set_skills("doublehit",100);
   set_skills("dodge",100);
   set_skills("alertness",100);
   set_skills("stun",100);
   set_skills("slash",100);
   set_skills("enhance criticals",100);
   set_skills("find weakness",100);
   set_skills("tumble",100);

}
