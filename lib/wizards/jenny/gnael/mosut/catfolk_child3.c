inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("catfolk");
    set_level(10+random(5));
    set_name("kid");
    set_alias("child");
    set_short("A black haired catfolk child");
    set_long("A black haired catfolk child is playing some\n"+
              "unfamiliar game here. He is not wearing anything\n"+
              "else than his fur. His sharp teeth and nails look a\n"+
              "bit scary, but afterall he is just a kid.\n");
             
    set_al(0); 
    set_aggressive(0);
   
}
