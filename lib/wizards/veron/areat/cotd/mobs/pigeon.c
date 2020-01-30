inherit "obj/monster";

reset(arg) {
    
   
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_undead(1);
    set_level(random(5)+10);
    set_str(query_str()+5);
    set_str(query_con()+3);
    set_name("zombie");
    set_alias("pigeon");
    set_short("A zombie of a pigeon");
    set_long("A small zombie of a pigeon. The pigeon has been killed not a\n"+
             "long while ago and it's flesh has already started to rot. Chunks\n"+
 	     "of flesh have fallen out of it's body. It's lidless eyes burn red\n");
           
             
    set_al(0);
    set_aggressive(0);
    set_animal(1);
  

   
}