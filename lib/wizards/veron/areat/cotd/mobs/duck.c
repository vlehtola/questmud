inherit "obj/monster";

reset(arg) {
    
   
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_undead(1);
    set_level(random(5)+10);
    set_str(query_str()+5);
    set_str(query_con()+3);
    set_name("skeleton");
    set_alias("duck");
    set_short("A skeleton of a duck");
    set_long("A small skeleton of a duck swimming in the pond  The duck\n"+
             "has been killed at least a month ago and it has stayed\n"+
 	     "here haunting. It flaps it's bony wings trying not to sink\n"+
             "in the pond.\n");
          
           
             
    set_al(0);
    set_aggressive(0);
    set_animal(1);
  

   
}